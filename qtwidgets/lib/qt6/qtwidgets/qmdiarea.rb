# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmdiarea.html
    class QMdiArea < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class AreaOption ; end
      # @!parse class AreaOptions; end
      # @!parse class ViewMode   ; end
      # @!parse class WindowOrder; end
      rubyqt6_declare_enum_under QMdiArea, QMdiArea::AreaOption
      rubyqt6_declare_enum_under QMdiArea, QMdiArea::ViewMode
      rubyqt6_declare_enum_under QMdiArea, QMdiArea::WindowOrder
      rubyqt6_declare_qflags QMdiArea::AreaOptions, QMdiArea::AreaOption

      # @!parse
      q_object do
        signal "subWindowActivated(QMdiSubWindow*)"
        slot "activateNextSubWindow()"
        slot "activatePreviousSubWindow()"
        slot "cascadeSubWindows()"
        slot "closeActiveSubWindow()"
        slot "closeAllSubWindows()"
        slot "setActiveSubWindow(QMdiSubWindow*)"
        slot "tileSubWindows()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QMdiArea]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
