# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaMethod
      RE = /(\w+)\((.*)\)/

      attr_reader :name
      attr_reader :parameters
      attr_reader :signature

      def self.normalized_name(name)
        Internal.inflector.underscore(name)
      end

      def self.normalized_parameters(parameters)
        parameters.map(&->(param) { param.delete(" ") })
      end

      def self.normalized_signature(normalized_name, normalized_parameters)
        normalized_name + "(" + normalized_parameters.join(",") + ")"
      end

      def initialize(signature, type, underlying)
        matched = signature.match(RE)
        raise ArgumentError if matched.nil?

        @name = self.class.normalized_name(matched[1])
        @parameters = self.class.normalized_parameters(matched[2].split(","))
        @signature = self.class.normalized_signature(@name, @parameters)
        @type = type.to_sym
        @underlying = underlying.to_sym
      end

      def signal?
        @type == :signal
      end

      def qsignature
        signature = self.class.normalized_signature(_qsignature_name(@name), _qsignature_parameters(@parameters))
        signal? ? "2#{signature}" : "1#{signature}"
      end

      private

      def _qsignature_name(name)
        case @underlying
        when :libQt6 then Internal.inflector.camelize_lower(name)
        when :ruby then "rb_#{Internal.inflector.underscore(name)}"
        else raise ArgumentError
        end
      end

      def _qsignature_parameters(parameters)
        parameters
      end
    end
  end
end
