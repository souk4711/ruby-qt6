# frozen_string_literal: true

module RubyQt6
  module RSpec
    class QlassFileParser
      NESTED_QLASSES = [
        "QMetaObjectConnection",
        "QPainterPathElement",
        "QFormLayoutTakeRowResult",
        "QTextEditExtraSelection"
      ]

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
        raise MissingLine.new("}", line) unless line == "}"
        @qlasses
      end

      def parse_qlass_variants_declaration
        while line == "" || line.start_with?("#include") || line == "using namespace Rice;"
          take_next_line
        end

        while (matched = line.match(/^Rice::Class rb_c(\w+)/))
          @qlasses << OpenStruct.new(name: matched[1], methods: [], enums: [], flags: [])
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
          if NESTED_QLASSES.include?(qlass.name)
            take_next_line until line == "" || line == "}"
            next
          end
          parse_qlass_definition(qlass)
        end
      end

      def parse_qlass_definition(qlass)
        qmod_name = @qmod.name
        name = qlass.name

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
            qlass.methods.concat parse_qlass_definition_methods(qlass, :rubyqt6_defined_functions)
          when /\/\/ Constructor/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :constructor)
          when /\/\/ Inherits/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :inherits)
          when /\/\/ Public Functions/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :public_functions)
          when /\/\/ Public Slots/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :public_slots)
          when /\/\/ Signals/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :signals)
          when /\/\/ Static Public Members/
            qlass.methods.concat parse_qlass_definition_methods(qlass, :static_public_members)
          when /.define_attr/
            take_next_line
            next
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

        while line == "" || line == "}"
          return if line == "}"
          take_next_line
        end

        while (matched = line.match(/^Data_Type<QFlags.*rb_c#{name}(.*) =/))
          flag = OpenStruct.new(name: matched[1])
          qlass.flags << flag
          parse_qlass_definition_flag(qlass, flag)
        end
      end

      def parse_qlass_definition_methods(qlass, type)
        [].tap do |methods|
          loop do
            take_next_line
            break if line.start_with?(/\/\/ (RubyQt6|Constructor|Inherits|Public|Signals|Static)/) || line == "" || line == "}"

            if line.start_with?("// .define_")
              next
            elsif line.start_with?(".define_")
              methods << parse_qlass_definition_method(line, qlass, type)
            else
              raise MissingLine.new(".define_...", line)
            end
          end
        end
      end

      def parse_qlass_definition_method(line, qlass, type)
        rawline = line
        line = line.sub(".define_constructor", "")
        line = line.sub(".define_singleton_function", "")
        line = line.sub(".define_method", "")
        case line
        when /Constructor<#{qlass.name}.*>/
          rbname = "initialize"
        when /(<.*>)?\("([\w?]+)", \[\]\(/
          rbname = $2
        when /(<.*>)?\("([\w?]+)", [A-Z]/
          rbname = $2
        when /(<.*>)?\("([\w?]+)", &#{qlass.name}::([a-zA-Z0-9_]+)/
          rbname = $2
          cppname = $3
        when /(<.*>)?\("([\W]+)", \[\]/
          rbname = $2
        when /(<.*>)?\("([\W]+)", [A-Z]/
          rbname = $2
        when /(<.*>)?\("([\W]+)", &#{qlass.name}::operator/
          rbname = $2
        else
          raise "Invalid method line: #{line}"
        end
        OpenStruct.new(type:, rbname:, cppname:, rawline:)
      end

      def parse_qlass_definition_enum(qlass, enum)
        qmod_name = @qmod.name
        name = qlass.name
        enum_name = enum.name

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

        expected = "define_qenum_under<#{name}::#{enum_name}>(\"#{enum_name}\", rb_c#{name})"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        while line == "" || line.start_with?(".define_value")
          take_next_line
        end
      end

      def parse_qlass_definition_flag(qlass, flag)
        qmod_name = @qmod.name
        name = qlass.name
        flag_name = flag.name

        expected = /Data_Type<QFlags<#{name}::(.*)>> rb_c#{name}#{flag_name} =/
        if (matched = line.match(expected))
          flag.enum_name = matched[1]
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "// RubyQt6::#{qmod_name}::#{name}::#{flag_name}"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        expected = "define_qflags_under<#{name}::#{flag.enum_name}>(rb_c#{name}, \"#{flag_name}\");"
        if line == expected
          take_next_line
        else
          raise MissingLine.new(expected, line)
        end

        while line == ""
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
