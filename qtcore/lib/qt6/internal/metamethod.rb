# frozen_string_literal: true

module RubyQt6
  module Internal
    class MetaMethod
      RE = /(\w+)\((.*)\)/

      attr_reader :name
      attr_reader :parameters
      attr_reader :signature

      def initialize(signature)
        matched = signature.match(RE)
        raise ArgumentError if matched.nil?

        @name = Internal.inflector.camelize_lower(matched[1])
        @parameters = matched[2].split(",").map(&->(param) { param.delete(" ") })
        @signature = _normalized_signature
      end

      private

      def _normalized_signature
        "#{@name}(#{@parameters.join(",")})"
      end
    end
  end
end
