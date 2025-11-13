# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtabwidget.html
    class QTabWidget < RubyQt6::QtWidgets::QWidget
      # @!parse class TabPosition; end
      # @!parse class TabShape   ; end
      rubyqt6_declare_enum_under QTabWidget, QTabWidget::TabPosition
      rubyqt6_declare_enum_under QTabWidget, QTabWidget::TabShape

      # @!parse
      q_object do
        signal "currentChanged(int)"
        signal "tabBarClicked(int)"
        signal "tabBarDoubleClicked(int)"
        signal "tabCloseRequested(int)"
        slot "setCurrentIndex(int)"
        slot "setCurrentWidget(QWidget*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTabWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_tab(*args)
        T.args_nth_to_qstr(args, -1)
        _add_tab(*args)
      end
    end
  end
end
