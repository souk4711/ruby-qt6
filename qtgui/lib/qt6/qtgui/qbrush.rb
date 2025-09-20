# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qbrush.html
    class QBrush
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param color [Qt::BrushStyle, Qt::GlobalColor, QImage, QPixmap, QColor]
      # @return [QBrush]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
