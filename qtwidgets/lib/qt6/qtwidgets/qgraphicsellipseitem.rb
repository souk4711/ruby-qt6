# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsellipseitem.html
    class QGraphicsEllipseItem < RubyQt6::QtWidgets::QAbstractGraphicsShapeItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsEllipseItem]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
