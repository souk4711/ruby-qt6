# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpen.html
    class QPen
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPen]
      #
      # @overload initialize
      #
      # @overload initialize(style)
      #   @param style [Qt::PenStyle]
      #
      # @overload initialize(color)
      #   @param color [QColor]
      #
      # @overload initialize(brush, width)
      #   @param brush [QBrush]
      #   @param width [Float]
      #
      # @overload initialize(brush, width, style)
      #   @param brush [QBrush]
      #   @param width [Float]
      #   @param style [Qt::PenStyle]
      #
      # @overload initialize(brush, width, style, cap)
      #   @param brush [QBrush]
      #   @param width [Float]
      #   @param style [Qt::PenStyle]
      #   @param cap [Qt::PenCapStyle]
      #
      # @overload initialize(brush, width, style, cap, join)
      #   @param brush [QBrush]
      #   @param width [Float]
      #   @param style [Qt::PenStyle]
      #   @param cap [Qt::PenCapStyle]
      #   @param join [Qt::PenJoinStyle]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(self.class)
        self.class._operator_equal(self, other)
      end
    end
  end
end
