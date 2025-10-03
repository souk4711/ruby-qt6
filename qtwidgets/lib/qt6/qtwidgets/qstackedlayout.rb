# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstackedlayout.html
    class QStackedLayout < RubyQt6::QtWidgets::QLayout
      # @!parse class StackingMode; end
      rubyqt6_declare_enum_under QStackedLayout, QStackedLayout::StackingMode

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
      # @return [QStackedLayout]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
