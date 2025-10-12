# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmainwindow.html
    class QMainWindow < RubyQt6::QtWidgets::QWidget
      # @!parse class DockOption; end
      rubyqt6_declare_enum_under QMainWindow, QMainWindow::DockOption

      # @!parse class DockOptions; end
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
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
