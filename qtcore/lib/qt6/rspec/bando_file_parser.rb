# frozen_string_literal: true

module RubyQt6
  module RSpec
    class BandoFileParser
      def initialize(cppfile, qmod)
        @qmod = qmod
        @bandoes = []
        @lines, @lineno = File.read(cppfile).lines, 0
      end

      def parse
      end
    end
  end
end
