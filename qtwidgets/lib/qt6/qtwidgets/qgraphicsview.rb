# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsview.html
    class QGraphicsView < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class CacheModeFlag     ; end
      # @!parse class DragMode          ; end
      # @!parse class OptimizationFlag  ; end
      # @!parse class ViewportAnchor    ; end
      # @!parse class ViewportUpdateMode; end
      rubyqt6_include_constants QGraphicsView, QGraphicsView::CacheModeFlag
      rubyqt6_include_constants QGraphicsView, QGraphicsView::DragMode
      rubyqt6_include_constants QGraphicsView, QGraphicsView::OptimizationFlag
      rubyqt6_include_constants QGraphicsView, QGraphicsView::ViewportAnchor
      rubyqt6_include_constants QGraphicsView, QGraphicsView::ViewportUpdateMode

      # @!parse
      q_object do
        signal "rubberBandChanged(QRect,QPointF,QPointF)"
        slot "invalidateScene(QRectF,QGraphicsScene::SceneLayers)"
        slot "invalidateScene(QRectF)"
        slot "invalidateScene()"
        slot "updateScene(QList<QRectF>)"
        slot "updateSceneRect(QRectF)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QGraphicsView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
