# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qline.html
    class QLine
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QLine]
      #
      # @overload initialize
      #
      # @overload initialize(x1, y1, x2, y2)
      #   @param x1 [Integer]
      #   @param y1 [Integer]
      #   @param x2 [Integer]
      #   @param y2 [Integer]
      #
      # @overload initialize(p1, p2)
      #   @param p1 [QPoint]
      #   @param p2 [QPoint]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless [QtCore::QLine, QtCore::QLineF].include?(other.class)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, x1:, y1:, x2:, y2:)
      end
    end
  end
end
