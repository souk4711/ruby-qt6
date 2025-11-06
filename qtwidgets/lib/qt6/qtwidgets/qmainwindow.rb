# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmainwindow.html
    class QMainWindow < RubyQt6::QtWidgets::QWidget
      # @!parse class DockOption ; end
      # @!parse class DockOptions; end
      rubyqt6_declare_enum_under QMainWindow, QMainWindow::DockOption
      rubyqt6_declare_qflags QMainWindow::DockOptions, QMainWindow::DockOption

      # @!parse
      q_object do
        signal "iconSizeChanged(QSize)"
        signal "tabifiedDockWidgetActivated(QDockWidget*)"
        signal "toolButtonStyleChanged(Qt::ToolButtonStyle)"
        slot "setAnimated(bool)"
        slot "setDockNestingEnabled(bool)"
        slot "setUnifiedTitleAndToolBarOnMac(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QMainWindow]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def add_tool_bar(*args)
        T.args_nth_to_qstr(args, 0)
        _add_tool_bar(*args)
      end
    end
  end
end
