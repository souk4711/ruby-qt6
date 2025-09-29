# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qtoolbar.html
    class QToolBar < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "actionTriggered(QAction*)"
        signal "allowedAreasChanged(Qt::ToolBarAreas)"
        signal "iconSizeChanged(QSize)"
        signal "movableChanged(bool)"
        signal "orientationChanged(Qt::Orientation)"
        signal "toolButtonStyleChanged(Qt::ToolButtonStyle)"
        signal "topLevelChanged(bool)"
        signal "visibilityChanged(bool)"
        slot "setIconSize(QSize)"
        slot "setToolButtonStyle(Qt::ToolButtonStyle)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param title [String, QString]
      # @param parent [QWidget]
      # @return [QToolBar]
      def initialize(title, parent = nil)
        _initialize(T.to_qstr(title), parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
