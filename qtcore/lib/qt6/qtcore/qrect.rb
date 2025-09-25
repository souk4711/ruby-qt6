# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrect.html
    class QRect
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRect]
      #
      # @overload initialize(x, y, width, height)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param width [Integer]
      #   @param height [Integer]
      #
      # @overload initialize(top_left, bottom_right)
      #   @param top_left [QPoint]
      #   @param bottom_right [QPoint]
      #
      # @overload initialize(top_left, size)
      #   @param top_left [QPoint]
      #   @param size [QSize]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def inspect
        T.q_inspect(self, x: x, y: y, width: width, height: height)
      end
    end
  end
end
