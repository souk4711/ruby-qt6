# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qlinef.html
    class QLineF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QLineF]
      #
      # @overload initialize
      #
      # @overload initialize(x1, y1, x2, y2)
      #   @param x1 [Float]
      #   @param y1 [Float]
      #   @param x2 [Float]
      #   @param y2 [Float]
      #
      # @overload initialize(p1, p2)
      #   @param p1 [QPointF]
      #   @param p2 [QPointF]
      #
      # @overload initialize(line)
      #   @param line [QLine]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(QLine) || other.is_a?(QLineF)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, x1:, y1:, x2:, y2:)
      end
    end
  end
end
