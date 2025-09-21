# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpen.html
    class QPen
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPen]
      #
      # @overload initialize(style)
      #   @param style [Qt::PenStyle]
      #
      # @overload initialize(color)
      #   @param color [QColor]
      #
      # @overload initialize(brush, width, s = Qt::SolidLine, c = Qt::SquareCap, j = Qt::BevelJoin)
      #   @param brush [QBrush]
      #   @param width [Float]
      #   @param s [Qt::PenStyle]
      #   @param c [Qt::PenCapStyle]
      #   @param j [Qt::PenJoinStyle]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
