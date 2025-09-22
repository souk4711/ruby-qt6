# frozen_string_literal: true

require "ostruct"
require_relative "rspec/bando_file_parser"
require_relative "rspec/qlass_file_parser"

module RubyQt6
  module RSpec
    NO_VERIFY_INITIALIZE = QlassFileParser::NESTED_QLASSES + [
      "QStackedLayout",
      "QVariant"
    ]

    def self.inflector
      @inflector ||= ::Dry::Inflector.new do |inflections|
        inflections.acronym "QBitmap"
        inflections.acronym "QMetaObject"
        inflections.acronym "QObject"
      end
    end

    def self.verify_bando_cppfile(cppfile, qmod)
      parser = BandoFileParser.new(cppfile, qmod)
      _ = parser.parse
    end

    def self.verify_qlass_cppfile(cppfile, qmod)
      parser = QlassFileParser.new(cppfile, qmod)
      qlasses = parser.parse

      qlasses.each do |qlass|
        rbfile = "lib/qt6/#{qmod.name.downcase}/#{qlass.name.downcase}.rb"
        rbfile_contents = File.read(rbfile) if File.exist?(rbfile)

        unless NO_VERIFY_INITIALIZE.include?(qlass.name)
          constructor_methods = qlass.methods.select { |method| method.type == :constructor }
          case constructor_methods.size
          when 2..99
            raise rbfile unless rbfile_contents.include?("alias_method :_initialize, :initialize")
            raise rbfile unless rbfile_contents.include?("def initialize(*args)")
            raise rbfile unless rbfile_contents.include?("_initialize(*args)")
          when 1
            raise rbfile unless rbfile_contents.include?("alias_method :_initialize, :initialize")
            raise rbfile unless rbfile_contents.include?("def initialize")
            raise rbfile unless rbfile_contents.include?("_initialize")
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
              when /is[A-Z]/ then "#{inflector.underscore(method.cppname)}?".sub(/^is_/, "")
              else inflector.underscore(method.cppname)
              end
            if expected != method.rbname.sub(/^_/, "")
              raise method.inspect
            end
          end
        end
      end
    end
  end
end
