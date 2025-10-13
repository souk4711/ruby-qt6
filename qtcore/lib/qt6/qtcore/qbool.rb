# frozen_string_literal: true

module RubyQt6
  module QtCore
    class QBool
      # @!visibility private
      attr_accessor :value

      # @param value [nil, Boolean]
      # @return [QBool]
      def initialize(value = nil)
        @value = value
      end

      # @!visibility private
      def ok?
        !!@value
      end
    end
  end
end
