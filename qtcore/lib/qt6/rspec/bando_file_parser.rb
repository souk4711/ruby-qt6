# frozen_string_literal: true

module RubyQt6
  module RSpec
    class BandoFileParser
      class MissingLine < StandardError
        def initialize(expected, got)
          super("Missing line: expected '#{expected}', but got '#{got}'")
        end
      end

      def initialize(cppfile, qmod)
        @qmod = qmod
        @bandoes = []
        @lines, @lineno = File.read(cppfile).lines, 0
      end

      def parse
        parse_bando_variants_declaration
        parse_bando_definitions
        raise MissingLine.new("}", line) unless line == "}"
        @bandoes
      end

      def parse_bando_variants_declaration
        while line == "" || line.start_with?("#include") || line.start_with?("using ")
          take_next_line
        end

        while (matched = line.match(/^Rice::Class rb_mBando_c(\w+)/))
          @bandoes << OpenStruct.new(name: matched[1])
          take_next_line
        end

        if @bandoes.length.zero?
          raise MissingLine.new("Rice::Class rb_mBando_c...", line)
        end

        while line == "" || line.start_with?("void Init_bando_#{@qmod.name.downcase}") || line == "{"
          take_next_line
        end
      end

      def parse_bando_definitions
        @bandoes.each do |bando|
          parse_bando_definition(bando)
        end
      end

      def parse_bando_definition(bando)
        name = bando.name

        expected = "rb_mBando_c#{name} ="
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "define_class_under<Bando_#{name}, #{name}>(rb_mQt6Bando, \"#{name}\")"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        if line.start_with?(/\.define_constructor\(Constructor<Bando_#{name}, /)
          take_next_line
        else
          raise MissingLine.new(".define_constructor<Constructor<Bando_#{name}, ...", line)
        end

        if line.start_with?(/\.define_method\("_initialize_value", &Bando_#{name}::initializeValue, /)
          take_next_line
        else
          raise MissingLine.new("define_method(\"_initialize_value\", &Bando_#{name}::initializeValue, ...", line)
        end

        while line == "" || line == "}"
          return if line == "}"
          take_next_line
        end
      end

      def take_next_line
        @lineno += 1
      end

      def line
        @lines[@lineno].strip
      end
    end
  end
end
