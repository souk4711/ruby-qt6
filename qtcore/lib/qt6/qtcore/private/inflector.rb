# frozen_string_literal: true

require "dry/inflector"

module RubyQt6
  module QtCore
    module Private
      def self.inflector
        @inflector ||= Dry::Inflector.new
      end
    end
  end
end
