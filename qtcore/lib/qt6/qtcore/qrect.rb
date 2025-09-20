# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrect.html
    class QRect
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param w [Integer]
      # @param y [Integer]
      # @param width [Integer]
      # @param height [Integer]
      # @return [QRect]
      def initialize(x, y, width, height)
        _initialize(x, y, width, height)
      end
    end
  end
end
