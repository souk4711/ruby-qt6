# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsobject.html
    class QGraphicsObject < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "childrenChanged()"
        signal "enabledChanged()"
        signal "heightChanged()"
        signal "opacityChanged()"
        signal "parentChanged()"
        signal "rotationChanged()"
        signal "scaleChanged()"
        signal "visibleChanged()"
        signal "widthChanged()"
        signal "xChanged()"
        signal "yChanged()"
        signal "zChanged()"
      end

      # @param parent [QGraphicsItem]
      # @return [QGraphicsObject]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
