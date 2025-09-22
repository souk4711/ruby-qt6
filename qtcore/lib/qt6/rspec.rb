# frozen_string_literal: true

require "ostruct"
require_relative "rspec/bando_file_parser"
require_relative "rspec/qlass_file_parser"

module RubyQt6
  module RSpec
    def self.verify_bando_cppfile(cppfile, qmod)
      parser = BandoFileParser.new(cppfile, qmod)
      _ = parser.parse
    end

    def self.verify_qlass_cppfile(cppfile, qmod)
      parser = QlassFileParser.new(cppfile, qmod)
      _ = parser.parse
    end
  end
end
