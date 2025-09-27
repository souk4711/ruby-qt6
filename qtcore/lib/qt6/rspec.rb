# frozen_string_literal: true

require "ostruct"
require_relative "rspec/bando_file_parser"
require_relative "rspec/qlass_file_parser"

module RubyQt6
  # @!visibility private
  module RSpec
    NO_VERIFY_QLASS_INITIALIZE = QlassFileParser::NESTED_QLASSES + [
      "QVariant"
    ]
    NO_VERIFY_QLASS_VIRTUAL_METHODS = {
      "QCoreApplication" => ["post_event", "send_event"]
    }
    NO_VERIFY_QLASS_LEADING_UNDERSCORE_METHODS = {
      "QObject" => ["_connect", "_disconnect"]
    }

    def self.inflector
      @inflector ||= ::Dry::Inflector.new do |inflections|
        inflections.acronym "LongLong"
        inflections.acronym "UInt"
        inflections.acronym "ULongLong"
        inflections.acronym "MSecs"
        inflections.acronym "QBitmap"
        inflections.acronym "QMetaObject"
        inflections.acronym "QObject"
      end
    end

    def self.verify_bando_cppfile(cppfile, qmod)
      parser = BandoFileParser.new(cppfile, qmod)
      bandoes = parser.parse

      rs = {}
      bandoes.each do |bando|
        r = OpenStruct.new(bando:)
        rs[bando.name] = r

        rbfile = "lib/qt6/bando/#{bando.name.downcase}.rb"
        rbfile_contents = File.read(rbfile) if File.exist?(rbfile)

        raise rbfile unless rbfile_contents.include?("class #{bando.name} < RubyQt6::#{qmod.name}::#{bando.name}")
        raise rbfile unless rbfile_contents.include?("Bando.define_bando_qlass Bando::#{bando.name}")
      end
      rs
    end

    def self.verify_qlass_cppfile(cppfile, qmod)
      parser = QlassFileParser.new(cppfile, qmod)
      qlasses = parser.parse

      rs = {}
      qlasses.each do |qlass|
        r = OpenStruct.new(qlass:)
        rs[qlass.name] = r

        rbfile = "lib/qt6/#{qmod.name.downcase}/#{qlass.name.downcase}.rb"
        rbfile_contents = File.read(rbfile) if File.exist?(rbfile)

        unless NO_VERIFY_QLASS_INITIALIZE.include?(qlass.name)
          constructor_methods = qlass.methods.select { |method| method.type == :constructor }
          case constructor_methods.size
          when 2..99
            raise "#{rbfile}: initialize: Missing `# @overload initialize...`" unless rbfile_contents.scan("# @overload initialize").count == constructor_methods.size
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
              case method.cppname
              when /^is[A-Z]/ then "#{inflector.underscore(method.cppname)}?".sub(/^is_/, "")
              else inflector.underscore(method.cppname)
              end
            if expected != method.rbname.sub(/^_/, "")
              raise method.inspect
            end
          end

          # No virtual method
          lambda do
            return if NO_VERIFY_QLASS_VIRTUAL_METHODS[qlass.name]&.include?(method.rbname)
            raise method.inspect if method.rbname.end_with?("_event")
          end.call

          # No unknonwn leading underscore method
          if method.rbname.start_with?("_")
            lambda do
              return if method.type == :rubyqt6_defined_functions
              return if rbfile_contents.include?("def #{method.rbname.sub(/^_/, "")}")
              return if NO_VERIFY_QLASS_LEADING_UNDERSCORE_METHODS[qlass.name]&.include?(method.rbname)
              raise method.inspect
            end.call
          end

          r.verified_methods_count ||= 0
          r.verified_methods_count += 1
        end

        qlass.enums.each do |enum|
          raise "#{rbfile}: #{enum.name}: Missing `# @!parse class ...`" unless rbfile_contents.include?("# @!parse class #{enum.name}")
          raise "#{rbfile}: #{enum.name}: Missing `rubyqt6_include_constants ...`" unless rbfile_contents.include?("rubyqt6_include_constants #{qlass.name}, #{qlass.name}::#{enum.name}")
          r.verified_enums_count ||= 0
          r.verified_enums_count += 1
        end
      end
      rs
    end
  end
end
