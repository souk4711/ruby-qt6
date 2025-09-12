# frozen_string_literal: true

require "dry/inflector"

module RubyQt6
  module Internal
    def self.inflector
      @inflector ||= Dry::Inflector.new
    end
  end
end
