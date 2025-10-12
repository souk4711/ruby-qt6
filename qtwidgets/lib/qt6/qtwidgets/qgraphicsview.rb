# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsview.html
    class QGraphicsView < RubyQt6::QtWidgets::QAbstractScrollArea
      # @!parse class CacheModeFlag     ; end
      # @!parse class CacheMode         ; end
      # @!parse class DragMode          ; end
      # @!parse class OptimizationFlag  ; end
      # @!parse class OptimizationFlags ; end
      # @!parse class ViewportAnchor    ; end
      # @!parse class ViewportUpdateMode; end
      rubyqt6_declare_enum_under QGraphicsView, QGraphicsView::CacheModeFlag
      rubyqt6_declare_enum_under QGraphicsView, QGraphicsView::DragMode
      rubyqt6_declare_enum_under QGraphicsView, QGraphicsView::OptimizationFlag
      rubyqt6_declare_enum_under QGraphicsView, QGraphicsView::ViewportAnchor
      rubyqt6_declare_enum_under QGraphicsView, QGraphicsView::ViewportUpdateMode
      rubyqt6_declare_qflags QGraphicsView::CacheMode, QGraphicsView::CacheModeFlag
      rubyqt6_declare_qflags QGraphicsView::OptimizationFlags, QGraphicsView::OptimizationFlag

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
