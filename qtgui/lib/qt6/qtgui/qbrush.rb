# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qbrush.html
    class QBrush
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QBrush]
      #
      # @overload initialize(bs)
      #   @param bs [Qt::BrushStyle]
      #
      # @overload initialize(color, bs = Qt::SolidPattern)
      #   @param color [Qt::GlobalColor, QColor]
      #   @param bs [Qt::BrushStyle]
      #
      # @overload initialize(color, pixmap)
      #   @param color [Qt::GlobalColor, QColor]
      #   @param pixmap [QPixmap]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
