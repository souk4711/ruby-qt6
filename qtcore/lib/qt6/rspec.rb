# frozen_string_literal: true

require "ostruct"
require_relative "rspec/bando_file_parser"
require_relative "rspec/qlass_file_parser"

module RubyQt6
  module RSpec
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
