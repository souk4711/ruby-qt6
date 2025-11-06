# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicsitemgroup.html
    class QGraphicsItemGroup < RubyQt6::QtWidgets::QGraphicsItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsItemGroup]
      def initialize(parent = nil)
        _initialize(parent)
      end
    end
  end
end
