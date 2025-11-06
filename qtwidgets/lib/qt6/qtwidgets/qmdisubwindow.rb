# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmdisubwindow.html
    class QMdiSubWindow < RubyQt6::QtWidgets::QWidget
      # @!parse class SubWindowOption ; end
      # @!parse class SubWindowOptions; end
      rubyqt6_declare_enum_under QMdiSubWindow, QMdiSubWindow::SubWindowOption
      rubyqt6_declare_qflags QMdiSubWindow::SubWindowOptions, QMdiSubWindow::SubWindowOption

      # @!parse
      q_object do
        signal "aboutToActivate()"
        signal "windowStateChanged(Qt::WindowStates,Qt::WindowStates)"
        slot "showShaded()"
        slot "showSystemMenu()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QMdiSubWindow]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end

      # @!visibility private
      def widget
        T.bando_qobject_cast(_widget)
      end
    end
  end
end
