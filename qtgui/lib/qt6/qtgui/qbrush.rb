# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qbrush.html
    class QBrush
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param color [Qt::GlobalColor, QColor]
      # @return [QBrush]
      def initialize(color)
        _initialize(color)
      end
    end
  end
end
