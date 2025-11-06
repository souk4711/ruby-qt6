# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qdockwidget.html
    class QDockWidget < RubyQt6::QtWidgets::QWidget
      # @!parse class DockWidgetFeature ; end
      # @!parse class DockWidgetFeatures; end
      rubyqt6_declare_enum_under QDockWidget, QDockWidget::DockWidgetFeature
      rubyqt6_declare_qflags QDockWidget::DockWidgetFeatures, QDockWidget::DockWidgetFeature

      # @!parse
      q_object do
        signal "allowedAreasChanged(Qt::DockWidgetAreas)"
        signal "dockLocationChanged(Qt::DockWidgetArea)"
        signal "featuresChanged(QDockWidget::DockWidgetFeatures)"
        signal "topLevelChanged(bool)"
        signal "visibilityChanged(bool)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param title [String, QString]
      # @param parent [QWidget]
      # @return [QDockWidget]
      def initialize(title, parent = nil)
        _initialize(T.to_qstr(title), parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
