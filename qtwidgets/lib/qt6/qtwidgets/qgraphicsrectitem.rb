# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsrectitem.html
    class QGraphicsRectItem < RubyQt6::QtWidgets::QAbstractGraphicsShapeItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsRectItem]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
