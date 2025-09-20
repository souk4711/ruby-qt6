# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickitem.html
    class QQuickItem < RubyQt6::QtCore::QObject
      # @!visibility private
      q_object do
        signal "activeFocusChanged(bool)"
        signal "activeFocusOnTabChanged(bool)"
        signal "antialiasingChanged(bool)"
        signal "baselineOffsetChanged(double)"
        signal "childrenChanged()"
        signal "childrenRectChanged(QRectF)"
        signal "clipChanged(bool)"
        signal "containmentMaskChanged()"
        signal "enabledChanged()"
        signal "focusChanged(bool)"
        signal "focusPolicyChanged(Qt::FocusPolicy)"
        signal "heightChanged()"
        signal "implicitHeightChanged()"
        signal "implicitWidthChanged()"
        signal "opacityChanged()"
        signal "parentChanged(QQuickItem*)"
        signal "rotationChanged()"
        signal "scaleChanged()"
        signal "smoothChanged(bool)"
        signal "stateChanged(QString)"
        signal "transformOriginChanged(TransformOrigin)"
        signal "visibleChanged()"
        signal "visibleChildrenChanged()"
        signal "widthChanged()"
        signal "windowChanged(QQuickWindow*)"
        signal "xChanged()"
        signal "yChanged()"
        signal "zChanged()"
        slot "update()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QQuickItem]
      # @return [QQuickItem]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end

      # @!visibility private
      def set_parent_item(parent)
        _set_parent_item(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
