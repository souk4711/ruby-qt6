# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtabbar.html
    class QTabBar < RubyQt6::QtWidgets::QWidget
      # @!parse class ButtonPosition   ; end
      # @!parse class SelectionBehavior; end
      # @!parse class Shape            ; end
      rubyqt6_declare_enum_under QTabBar, QTabBar::ButtonPosition
      rubyqt6_declare_enum_under QTabBar, QTabBar::SelectionBehavior
      rubyqt6_declare_enum_under QTabBar, QTabBar::Shape

      # @!parse
      q_object do
        signal "currentChanged(int)"
        signal "tabBarClicked(int)"
        signal "tabBarDoubleClicked(int)"
        signal "tabCloseRequested(int)"
        signal "tabMoved(int,int)"
        slot "setCurrentIndex(int)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QTabBar]
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
