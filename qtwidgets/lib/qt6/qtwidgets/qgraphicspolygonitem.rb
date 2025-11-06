# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicspolygonitem.html
    class QGraphicsPolygonItem < RubyQt6::QtWidgets::QAbstractGraphicsShapeItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsPolygonItem]
      def initialize(parent = nil)
        _initialize(parent)
      end
    end
  end
end
