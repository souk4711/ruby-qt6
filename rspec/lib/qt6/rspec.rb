# frozen_string_literal: true

require_relative "rspec/bando_file_parser"
require_relative "rspec/qlass_file_parser"
require_relative "rspec/version"

module RubyQt6
  module RSpec
    VERIFY_QLASS_VIRTUAL_METHODS = [
      "event", "event_filter",                      # QObject
      "meta_object",                                # QObject
      "connect_notify", "disconnect_notify",        # QObject
      "paint_engine",                               # QPaintDevice
      "metric",                                     # QPaintDevice
      "has_height_for_width", "height_for_width",   # QWidget
      "input_method_query",                         # QWidget
      "minimum_size_hint", "size_hint",             # QWidget
      "init_painter",                               # QWidget
      "maximum_size", "minimum_size",               # QLayoutItem
      "clone", "swap"                               #
    ]

    NO_VERIFY_QLASS_DOCS = [
      "QMetaMethodBuilder",
      "QMetaObjectBuilder"
    ]
    NO_VERIFY_QLASS_INITIALIZE = QlassFileParser::NESTED_QLASSES + [
      "QVariant"
    ]
    NO_VERIFY_QLASS_VIRTUAL_METHODS = {
      "QCoreApplication" => ["post_event", "send_event"],
      "QLayoutItem" => ["has_height_for_width", "height_for_width", "maximum_size", "minimum_size", "size_hint"],
      "QLayout" => ["maximum_size", "minimum_size"],
      "QWidget" => ["maximum_size", "minimum_size", "minimum_size_hint", "size_hint"],
      "QWindow" => ["maximum_size", "minimum_size"]
    }
    NO_VERIFY_QLASS_LEADING_UNDERSCORE_METHODS = {
      "QObject" => ["_connect", "_disconnect"],
      "QApplication" => ["_all_widgets", "_top_level_widgets"]
    }
    NO_VERIFY_QLASS_OPERATOR_METHODS = {
      "QByteArray" => ["[]"],
      "QString" => ["[]", "[]="],
      "QPoint" => ["*", "+", "-", "/", "+@", "-@"],
      "QPointF" => ["*", "+", "-", "/", "+@", "-@"],
      "QRect" => ["+", "-"],
      "QRectF" => ["+", "-"],
      "QSize" => ["*", "+", "-", "/"],
      "QSizeF" => ["*", "+", "-", "/"],
      "QTextBlock" => ["==", "!=", "<"],
      "QTextStream" => ["<<"]
    }
    NO_VERIFY_QLASS_QOBJECT_INITIALIZE = [
      "QCoreApplication",
      "QGuiApplication",
      "QApplication",
      "QSettings",
      "QAction",
      "QDoubleValidator",
      "QIntValidator",
      "QRegularExpressionValidator",
      "QGraphicsTextItem",
      "QLabel",
      "QPushButton",
      "QRadioButton",
      "QLineEdit",
      "QTextEdit",
      "QToolBar",
      "QSystemTrayIcon",
      "QWebEnginePage",
      "QWebEngineView"
    ]

    ACRONYM = [
      "UInt",
      "ULongLong",
      "ULong",
      "UShort",
      "LongLong",
      "MSecs",
      "QBitmap",
      "QMetaObject",
      "QObject"
    ]

    def self.inflector_underscore(str)
      str = str.dup
      ACRONYM.each { |acronym| str.gsub!(acronym, "_" + acronym.downcase) }
      str.gsub!(/([A-Z\d]+)([A-Z][a-z])/, '\1_\2')
      str.gsub!(/([a-z\d])([A-Z])/, '\1_\2')
      str.downcase!
      str
    end

    def self.verify_bando_cppfile(cppfile, qmod)
      parser = BandoFileParser.new(cppfile, qmod)
      bandoes = parser.parse

      rs = {}
      bandoes.each do |bando|
        r = Struct.new(:bando).new(bando)
        rs[bando.name] = r

        rbfile = "lib/qt6/bando/#{bando.name.downcase}.rb"
        rbfile_contents = File.read(rbfile) if File.exist?(rbfile)

        raise rbfile unless rbfile_contents.include?("class #{bando.name} < RubyQt6::#{qmod.name}::#{bando.name}")
        raise rbfile unless rbfile_contents.match?(/Bando.define_bando_q\w+ Bando::#{bando.name}/)
      end
      rs
    end

    def self.verify_qlass_cppfile(cppfile, qmod)
      parser = QlassFileParser.new(cppfile, qmod)
      qlasses = parser.parse

      rs = {}
      qlasses.each do |qlass|
        r = Struct.new(:qlass, :verified_initialize, :verified_methods_count, :verified_enums_count, :verified_flags_count).new(qlass, 0, 0, 0, 0)
        rs[qlass.name] = r

        rbfile = "lib/qt6/#{qmod.name.downcase}/#{qlass.name.downcase}.rb"
        rbfile_contents = File.read(rbfile) if File.exist?(rbfile)

        verify_qlass_cppfile_qlass_docs(qlass, cppfile, rbfile, rbfile_contents, r)
        verify_qlass_cppfile_qlass_initialize(qlass, cppfile, rbfile, rbfile_contents, r)
        verify_qlass_cppfile_qlass_methods(qlass, cppfile, rbfile, rbfile_contents, r)
        verify_qlass_cppfile_qlass_enums(qlass, cppfile, rbfile, rbfile_contents, r)
        verify_qlass_cppfile_qlass_flags(qlass, cppfile, rbfile, rbfile_contents, r)

        qobject = true if rbfile_contents&.include?("q_object")
        verify_qlass_cppfile_qlass_qobject_initialize(qlass, cppfile, rbfile, rbfile_contents, r) if qobject
        verify_qlass_cppfile_qlass_qobject_methods(qlass, cppfile, rbfile, rbfile_contents, r) if qobject
      end
      rs
    end

    def self.verify_qlass_cppfile_qlass_docs(qlass, cppfile, rbfile, rbfile_contents, r)
      return if NO_VERIFY_QLASS_DOCS.include?(qlass.name)

      return if rbfile_contents.nil?
      return if rbfile_contents.include?("# @see https://doc.qt.io/qt-6/#{qlass.name.downcase}.html")
      raise "#{rbfile}: docs: Missing `# @see https://doc.qt.io/qt-6/...`"
    end

    def self.verify_qlass_cppfile_qlass_initialize(qlass, cppfile, rbfile, rbfile_contents, r)
      return if NO_VERIFY_QLASS_INITIALIZE.include?(qlass.name)

      constructor_methods = qlass.methods.select { |method| method.type == :constructor }
      copy_constructor_method = constructor_methods.find { |method| method.rawline.include?('Arg("other")') }

      constructor_methods.each do |method|
        rawline = method.rawline
        raise "#{cppfile}: Found default value in constructor method" if rawline.include?("nullptr")
        raise "#{cppfile}: Found default value in constructor method" if rawline.include?("static_cast")
      end

      constructor_methods_count = constructor_methods.count
      constructor_methods_count -= 1 if copy_constructor_method
      case constructor_methods_count
      when 2..99
        raise "#{rbfile}: initialize: Missing `# @overload initialize...`" unless rbfile_contents.scan("# @overload initialize").count == constructor_methods_count
        raise "#{rbfile}: initialize: Missing `alias_method :_initialize, :initialize`" unless rbfile_contents.include?("alias_method :_initialize, :initialize")
        raise "#{rbfile}: initialize: Missing `def initialize(*args)`" unless rbfile_contents.include?("def initialize(*args)")
        raise "#{rbfile}: initialize: Missing `_initialize(*args)`" unless rbfile_contents.include?("_initialize(*args)")
        r.verified_initialize = 2
      when 1
        raise "#{rbfile}: initialize: Missing `alias_method :_initialize, :initialize`" unless rbfile_contents.include?("alias_method :_initialize, :initialize")
        raise "#{rbfile}: initialize: Missing `def initialize...`" unless rbfile_contents.include?("def initialize")
        raise "#{rbfile}: initialize: Missing `_initialize...`" unless rbfile_contents.include?("_initialize")
        r.verified_initialize = 1
      end
    end

    def self.verify_qlass_cppfile_qlass_methods(qlass, cppfile, rbfile, rbfile_contents, r)
      qlass.methods.each do |method|
        # Expected 'Arg("name")', but got 'Arg("")'
        if method.rawline.include?('Arg("")')
          raise method.inspect
        end

        # Expected 'to_qvariant', but got 'to_q_variant'
        if method.rbname.include?("q_")
          raise method.inspect
        end

        # Expected 'valid?', but got 'is_valid'
        # Expected 'user_type', but got 'userType'
        if method.cppname
          expected =
            if method.cppname.match?(/^is[A-Z]/) && method.type != :signals
              "#{inflector_underscore(method.cppname)}?".sub(/^is_/, "")
            else
              inflector_underscore(method.cppname)
            end
          if expected != method.rbname.sub(/^_/, "")
            raise method.inspect
          end
        end

        # No virtual method
        lambda do
          return if NO_VERIFY_QLASS_VIRTUAL_METHODS[qlass.name]&.include?(method.rbname)
          raise method.inspect if method.rbname.end_with?("_event")
          raise method.inspect if VERIFY_QLASS_VIRTUAL_METHODS.include?(method.rbname)
        end.call

        # No unknonwn leading underscore method
        if method.rbname.start_with?("_")
          lambda do
            return if method.type == :rubyqt6_defined_functions
            return if rbfile_contents.match?(/def (self.)?#{method.rbname.sub(/^_/, "")}/)
            return if NO_VERIFY_QLASS_LEADING_UNDERSCORE_METHODS[qlass.name]&.include?(method.rbname)
            raise method.inspect
          end.call
        end

        # No unknonwn operator method
        unless method.rbname.start_with?(/_?[a-z]/)
          lambda do
            return if NO_VERIFY_QLASS_OPERATOR_METHODS[qlass.name]&.include?(method.rbname)
            raise method.inspect
          end.call
        end

        r.verified_methods_count ||= 0
        r.verified_methods_count += 1
      end
    end

    def self.verify_qlass_cppfile_qlass_enums(qlass, cppfile, rbfile, rbfile_contents, r)
      qlass.enums.each do |enum|
        raise "#{rbfile}: #{enum.name}: Missing `# @!parse class ...`" unless rbfile_contents.include?("# @!parse class #{enum.name}")
        raise "#{rbfile}: #{enum.name}: Missing `rubyqt6_declare_enum_under ...`" unless rbfile_contents.include?("rubyqt6_declare_enum_under #{qlass.name}, #{qlass.name}::#{enum.name}")
        r.verified_enums_count ||= 0
        r.verified_enums_count += 1
      end
    end

    def self.verify_qlass_cppfile_qlass_flags(qlass, cppfile, rbfile, rbfile_contents, r)
      qlass.flags.each do |flag|
        raise "#{rbfile}: #{flag.name}: Missing `# @!parse class ...`" unless rbfile_contents.include?("# @!parse class #{flag.name}")
        raise "#{rbfile}: #{flag.name}: Missing `rubyqt6_declare_qflags ...`" unless rbfile_contents.include?("rubyqt6_declare_qflags #{qlass.name}::#{flag.name}, #{qlass.name}::#{flag.enum_name}")
        r.verified_flags_count ||= 0
        r.verified_flags_count += 1
      end
    end

    def self.verify_qlass_cppfile_qlass_qobject_initialize(qlass, cppfile, rbfile, rbfile_contents, r)
      constructor_methods = qlass.methods.select { |method| method.type == :constructor }
      return if constructor_methods.size == 0
      raise "#{cppfile}: Too many constructor methods" if constructor_methods.size > 1

      unless NO_VERIFY_QLASS_QOBJECT_INITIALIZE.include?(qlass.name)
        rawline = constructor_methods[0].rawline
        rawargs = rawline.scan(/Arg\("(\w+)"\)/).map { |arg| arg[0] }
        rawargs.each do |arg|
          line = "@param #{arg} ["
          raise "#{rbfile}: initialize: Missing `#{line}`" unless rbfile_contents.include?(line)
        end

        line = "@return [#{qlass.name}]"
        raise "#{rbfile}: initialize: Missing `#{line}`" unless rbfile_contents.include?(line)

        args = rawargs.map { |arg| "#{arg}( = .*)?" }
        line = args.size.zero? ? /def initialize/ : /def initialize\(#{args.join(", ")}\)/
        raise "#{rbfile}: initialize: Mismatch `#{line}`" unless rbfile_contents.match?(line)

        args = rawargs.map { |arg| ".*#{arg}.*" }
        line = args.size.zero? ? /_initialize/ : /_initialize\(#{args.join(", ")}\)/
        raise "#{rbfile}: initialize: Mismatch `#{line}`" unless rbfile_contents.match?(line)
      end
    end

    def self.verify_qlass_cppfile_qlass_qobject_methods(qlass, cppfile, rbfile, rbfile_contents, r)
      metamethods = [].tap do |methods|
        signal_methods = qlass.methods.select { |method| method.type == :signals }
        signal_methods.each { |method| methods << method.cppname }
        slot_methods = qlass.methods.select { |method| method.type == :public_slots }
        slot_methods.each { |method| methods << method.cppname }
      end.uniq

      rbfile_metamethods = rbfile_contents.scan(/(signal|slot) "(.*)"/).map { |method| method[1] }
      rbfile_metamethods = rbfile_metamethods.map { |method| method.split("(")[0] }.uniq
      raise "#{rbfile}: q_object: Mismatch `#{rbfile_metamethods}` != `#{metamethods}`" if rbfile_metamethods != metamethods
    end
  end
end
