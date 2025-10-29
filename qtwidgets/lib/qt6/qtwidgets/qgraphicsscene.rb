# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsscene.html
    class QGraphicsScene < RubyQt6::QtCore::QObject
      # @!parse class ItemIndexMethod; end
      # @!parse class SceneLayer     ; end
      # @!parse class SceneLayers    ; end
      rubyqt6_declare_enum_under QGraphicsScene, QGraphicsScene::ItemIndexMethod
      rubyqt6_declare_enum_under QGraphicsScene, QGraphicsScene::SceneLayer
      rubyqt6_declare_qflags QGraphicsScene::SceneLayers, QGraphicsScene::SceneLayer

      # @!parse
      q_object do
        signal "changed(QList<QRectF>)"
        signal "focusItemChanged(QGraphicsItem*,QGraphicsItem*,Qt::FocusReason)"
        signal "sceneRectChanged(QRectF)"
        signal "selectionChanged()"
        slot "advance()"
        slot "clear()"
        slot "clearSelection()"
        slot "invalidate(QRectF,SceneLayers)"
        slot "invalidate(QRectF)"
        slot "invalidate()"
        slot "update(QRectF)"
        slot "update()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QGraphicsScene]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
