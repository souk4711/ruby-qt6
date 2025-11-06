# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qmenu.html
    class QMenu < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "aboutToHide()"
        signal "aboutToShow()"
        signal "hovered(QAction*)"
        signal "triggered(QAction*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param title [String, QString]
      # @param parent [QWidget]
      # @return [QMenu]
      def initialize(title, parent = nil)
        _initialize(T.to_qstr(title), parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
