# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrect.html
    class QRect
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param x [Integer]
      # @param y [Integer]
      # @param width [Integer]
      # @param height [Integer]
      # @return [QRect]
      #
      # Constructs a rectangle with (x, y) as its top-left corner and the
      # given width and height.
      def initialize(x, y, width, height)
        _initialize(x, y, width, height)
      end
    end
  end
end
