# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qpointf.html
    class QPointF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPointF]
      #
      # @overload initialize
      #
      # @overload initialize(xpos, ypos)
      #   @param xpos [Float]
      #   @param ypos [Float]
      #
      # @overload initialize(point)
      #   @param point [QPoint]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless [QtCore::QPoint, QtCore::QPointF].include?(other.class)
        self.class._operator_equal(self, other)
      end

      # @!visibility private
      def inspect
        T.inspect_struct(self, x:, y:)
      end
    end
  end
end
