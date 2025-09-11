# frozen_string_literal: true

require "dry/inflector"

module RubyQt6
  module Internal
    class Inflector
      def initialize
        @inflector = Dry::Inflector.new
      end

      def libQt6_fn_name(name)
        @inflector.camelize_lower(name)
      end

      def ruby_fn_name(name)
        @inflector.underscore(name)
      end
    end

    def self.inflector
      @inflector ||= Internal::Inflector.new
    end
  end
end
