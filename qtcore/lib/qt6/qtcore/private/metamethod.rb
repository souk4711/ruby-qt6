# frozen_string_literal: true

module RubyQt6
  module QtCore
    module Private
      class MetaMethod
        RE = /(\w+ )?(\w+)\((.*)\)/

        attr_reader :name
        attr_reader :parameters
        attr_reader :signature
        attr_reader :return_type
        attr_reader :type

        def self.normalized_name(name)
          QtCore::Private.inflector.underscore(name)
        end

        def self.normalized_parameters(parameters)
          parameters.map(&->(param) { param.delete(" ") })
        end

        def self.normalized_signature(normalized_name, normalized_parameters)
          normalized_name + "(" + normalized_parameters.join(",") + ")"
        end

        def self.normalized_return_type(return_type)
          return nil if return_type.nil?
          return_type.delete(" ")
        end

        def initialize(signature, type, underlying)
          matched = signature.match(RE)
          raise "Invalid metamethod signature: #{signature}" if matched.nil?

          @name = self.class.normalized_name(matched[2])
          @parameters = self.class.normalized_parameters(matched[3].split(","))
          @signature = self.class.normalized_signature(@name, @parameters)
          @return_type = self.class.normalized_return_type(matched[1])
          @type = type.to_sym
          @underlying = underlying.to_sym
        end

        def signal?
          @type == :signal
        end

        def slot?
          @type == :slot
        end

        def qsignature
          signature = self.class.normalized_signature(qsignature_name, @parameters)
          signal? ? "2#{signature}" : "1#{signature}"
        end

        def qsignature_name
          case @underlying
          when :libQt6 then QtCore::Private.inflector.camelize_lower(@name)
          when :ruby then "_rubyqt6_#{QtCore::Private.inflector.underscore(@name)}"
          else raise "Unknown underlying type: #{@underlying}"
          end
        end
      end
    end
  end
end
