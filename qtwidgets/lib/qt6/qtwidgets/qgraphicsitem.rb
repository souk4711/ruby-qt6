# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsitem.html
    class QGraphicsItem
      # @!parse class GraphicsItemFlag  ; end
      # @!parse class GraphicsItemChange; end
      # @!parse class CacheMode         ; end
      # @!parse class PanelModality     ; end
      rubyqt6_declare_enum_under QGraphicsItem, QGraphicsItem::GraphicsItemFlag
      rubyqt6_declare_enum_under QGraphicsItem, QGraphicsItem::GraphicsItemChange
      rubyqt6_declare_enum_under QGraphicsItem, QGraphicsItem::CacheMode
      rubyqt6_declare_enum_under QGraphicsItem, QGraphicsItem::PanelModality
    end
  end
end
