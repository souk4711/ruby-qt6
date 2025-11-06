# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicspixmapitem.html
    class QGraphicsPixmapItem < RubyQt6::QtWidgets::QGraphicsItem
      # @!parse class ShapeMode; end
      rubyqt6_declare_enum_under QGraphicsPixmapItem, QGraphicsPixmapItem::ShapeMode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsPixmapItem]
      def initialize(parent = nil)
        _initialize(parent)
      end
    end
  end
end
