# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstackedwidget.html
    class QStackedWidget < RubyQt6::QtWidgets::QFrame
      # @!parse
      q_object do
        signal "currentChanged(int)"
        signal "widgetAdded(int)"
        signal "widgetRemoved(int)"
        slot "setCurrentIndex(int)"
        slot "setCurrentWidget(QWidget*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QStackedWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
