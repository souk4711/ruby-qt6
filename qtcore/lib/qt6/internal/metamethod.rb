# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaMethod
      RE = /(\w+)\((.*)\)/

      attr_reader :name
      attr_reader :parameters
      attr_reader :signature

      def self.normalized_signature(name, parameters)
        name = Internal.inflector.camelize_lower(name)
        name + "(" + parameters.join(",") + ")"
      end

      def initialize(signature, type, underlying)
        matched = signature.match(RE)
        raise ArgumentError if matched.nil?

        @name = Internal.inflector.camelize_lower(matched[1])
        @parameters = matched[2].split(",").map(&->(param) { param.delete(" ") })
        @signature = self.class.normalized_signature(@name, @parameters)
        @type = type.to_sym
        @underlying = underlying.to_sym
      end

      def rb_name
        Internal.inflector.underscore(@name)
      end

      def signal?
        @type == :signal
      end

      def qsignature
        signature = self.class.normalized_signature(_qsignature_name(@name), @parameters)
        signal? ? "2#{signature}" : "1#{signature}"
      end

      private

      def _qsignature_name(name)
        case @underlying
        when :ruby then "rb_#{name}"
        else name
        end
      end
    end
  end
end
