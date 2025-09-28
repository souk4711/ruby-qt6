# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtoolbutton.html
    class QToolButton < RubyQt6::QtWidgets::QAbstractButton
      # @!parse class ToolButtonPopupMode; end
      rubyqt6_include_constants QToolButton, QToolButton::ToolButtonPopupMode

      # @!parse
      q_object do
        signal "triggered(QAction*)"
        slot "showMenu()"
        slot "setToolButtonStyle(Qt::ToolButtonStyle)"
        slot "setDefaultAction(QAction*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QToolButton]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
