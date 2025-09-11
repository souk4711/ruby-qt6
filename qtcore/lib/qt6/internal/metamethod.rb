# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaMethod
      RE = /(\w+)\((.*)\)/

      attr_reader :name
      attr_reader :parameters
      attr_reader :signature

      def initialize(signature, type, underlying)
        matched = signature.match(RE)
        raise ArgumentError if matched.nil?

        @name = Internal.inflector.ruby_fn_name(matched[1])
        @parameters = matched[2].split(",").map(&->(param) { param.delete(" ") })
        @signature = _normalized_signature(@name, @parameters)
        @type = type.to_sym
        @underlying = underlying.to_sym
      end

      def signal?
        @type == :signal
      end

      def qsignature
        signature = _normalized_signature(_qsignature_name(@name), @parameters)
        signal? ? "2#{signature}" : "1#{signature}"
      end

      private

      def _normalized_signature(name, parameters)
        name + "(" + parameters.join(",") + ")"
      end

      def _qsignature_name(name)
        case @underlying
        when :libQt6 then Internal.inflector.libQt6_fn_name(name)
        when :ruby then "rb_#{Internal.inflector.ruby_fn_name(name)}"
        else raise ArgumentError
        end
      end
    end
  end
end
