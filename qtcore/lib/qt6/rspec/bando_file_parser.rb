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
          matched = line.match(/^using Bando_(\w+) = Bando(\w+)<(\w+), (.*)>/)
          if matched.nil?
            take_next_line
            next
          end

          if matched[1] != matched[3]
            expected = "using Bando_#{matched[1]} = Bando#{matched[2]}<#{matched[1]}, ..."
            raise MissingLine.new(expected, line)
          else
            take_next_line
          end

          @bandoes << OpenStruct.new(
            name: matched[1],
            template: matched[2],
            constructor_args: matched[4]
          )
        end

        @bandoes.each do |bando|
          expected = "Rice::Class rb_mBando_c#{bando.name};"
          if line == expected
            take_next_line
          else
            raise MissingLine.new(expected, line)
          end
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

        expected = "define_bando_#{bando.template.downcase}_under<Bando_#{name}, #{name}>(rb_mQt6Bando, \"#{name}\")"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = ".define_constructor(Constructor<Bando_#{name}, #{bando.constructor_args}>()"
        if line.start_with?(expected)
          take_next_line
        else
          raise MissingLine.new(expected, line)
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
