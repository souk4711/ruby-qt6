# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrectf.html
    class QRectF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRectF]
      #
      # @overload initialize
      #
      # @overload initialize(x, y, width, height)
      #   @param x [Float]
      #   @param y [Float]
      #   @param width [Float]
      #   @param height [Float]
      #
      # @overload initialize(top_left, bottom_right)
      #   @param top_left [QPointF]
      #   @param bottom_right [QPointF]
      #
      # @overload initialize(top_left, size)
      #   @param top_left [QPointF]
      #   @param size [QSizeF]
      #
      # @overload initialize(rect)
      #   @param rect [QRect]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(QtCore::QRect) || other.is_a?(QtCore::QRectF)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, x:, y:, width:, height:)
      end
    end
  end
end
