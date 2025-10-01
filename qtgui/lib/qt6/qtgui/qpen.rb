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
      # @overload initialize(brush, width)
      #   @param brush [QBrush]
      #   @param width [Float]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
