# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicswidget.html
    class QGraphicsWidget < RubyQt6::QtWidgets::QGraphicsObject
      # @!parse
      q_object do
        signal "geometryChanged()"
        signal "layoutChanged()"
        slot "close()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsWidget]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
