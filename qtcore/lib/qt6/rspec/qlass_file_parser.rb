# frozen_string_literal: true

module RubyQt6
  module RSpec
    class QlassFileParser
      class MissingLine < StandardError
        def initialize(expected, got)
          super("Missing line: expected '#{expected}', but got '#{got}'")
        end
      end

      def initialize(cppfile, qmod)
        @qmod = qmod
        @qlasses = []
        @lines, @lineno = File.read(cppfile).lines, 0
      end

      def parse
        parse_qlass_variants_declaration
        parse_qlass_definitions
        @qlasses
      end

      def parse_qlass_variants_declaration
        while line == "" || line.start_with?("#include") || line == "using namespace Rice;"
          take_next_line
        end

        while (matched = line.match(/^Rice::Class rb_c(\w+)/))
          @qlasses << OpenStruct.new(name: matched[1], enums: [])
          take_next_line
        end

        if @qlasses.length.zero?
          raise MissingLine.new("Rice::Class rb_c...", line)
        end

        until line.start_with?("void Init_q")
          take_next_line
        end

        while line == "" || line.start_with?("void Init_q") || line == "{"
          take_next_line
        end
      end

      def parse_qlass_definitions
        @qlasses.each do |qlass|
          parse_qlass_definition(qlass)
        end
      end

      def parse_qlass_definition(qlass)
        qmod_name = @qmod.name
        name = qlass.name

        while line == ""
          take_next_line
        end

        expected = "rb_c#{name} ="
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "// RubyQt6::#{qmod_name}::#{name}"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        if line.start_with?(/define_class_under<#{name}.*rb_mQt6#{qmod_name}, "#{name}"/)
          take_next_line
        else
          raise MissingLine.new("define_class_under<#{name}...", line)
        end

        loop do
          case line
          when /\/\/ RubyQt6-Defined Functions/
            qlass.methods_rubyqt6_defined_functions = parse_qlass_definition_methods(qlass)
          when /\/\/ Constructor/
            qlass.methods_constructor = parse_qlass_definition_methods(qlass)
          when /\/\/ Public Functions/
            qlass.methods_public_functions = parse_qlass_definition_methods(qlass)
          when /\/\/ Public Slots/
            qlass.methods_public_slots = parse_qlass_definition_methods(qlass)
          when /\/\/ Signals/
            qlass.methods_signals = parse_qlass_definition_methods(qlass)
          when /\/\/ Static Public Members/
            qlass.methods_static_public_members = parse_qlass_definition_methods(qlass)
          when "", "}"
            break
          else
            raise MissingLine.new("// Constructor", line)
          end
        end

        while line == "" || line == "}"
          return if line == "}"
          take_next_line
        end

        while (matched = line.match(/^Enum<.*rb_c#{name}(.*) =/))
          enum = OpenStruct.new(name: matched[1])
          qlass.enums << enum
          parse_qlass_definition_enum(qlass, enum)
        end
      end

      def parse_qlass_definition_methods(qlass)
        [].tap do |methods|
          loop do
            take_next_line
            break if line.start_with?(/\/\/ (RubyQt6|Constructor|Public|Signals|Static)/) || line == "" || line == "}"

            if line.start_with?("// .define_")
              next
            elsif line.start_with?(".define_")
              methods << parse_qlass_definition_method(line, qlass)
            else
              raise MissingLine.new(".define_...", line)
            end
          end
        end
      end

      def parse_qlass_definition_method(line, qlass)
        line = line.sub(".define_constructor", "")
        line = line.sub(".define_singleton_function", "")
        line = line.sub(".define_method", "")
        case line
        when /Constructor<#{qlass.name}.*>/
          rbname = "initialize"
        when /(<.*>)?\("([a-zA-Z0-9_\?]+)", \[\]\(/
          rbname = $2
        when /(<.*>)?\("([a-zA-Z0-9_\?]+)", [A-Z]/
          rbname = $2
        when /(<.*>)?\("([a-zA-Z0-9_\?]+)", &#{qlass.name}::([a-zA-Z0-9]+)/
          rbname = $2
          cppname = $3
        else
          raise "Invalid method line: #{line}"
        end
        OpenStruct.new(rbname:, cppname:)
      end

      def parse_qlass_definition_enum(qlass, enum)
        qmod_name = @qmod.name
        name = qlass.name
        enum_name = enum.name

        while line == ""
          take_next_line
        end

        expected = "Enum<#{name}::#{enum_name}> rb_c#{name}#{enum_name} ="
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "// RubyQt6::#{qmod_name}::#{name}::#{enum_name}"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "define_enum_under<#{name}::#{enum_name}>(\"#{enum_name}\", rb_c#{name})"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        while line.start_with?(".define_value")
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
