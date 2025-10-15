# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qrect.html
    class QRect
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRect]
      #
      # @overload initialize
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
        case args.size
        when 4 then _initialize(*args.map(&:to_i))
        else _initialize(*args)
        end
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
