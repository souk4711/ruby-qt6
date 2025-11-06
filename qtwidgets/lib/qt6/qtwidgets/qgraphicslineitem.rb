# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgraphicslineitem.html
    class QGraphicsLineItem < RubyQt6::QtWidgets::QGraphicsItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QGraphicsItem]
      # @return [QGraphicsLineItem]
      def initialize(parent = nil)
        _initialize(parent)
      end
    end
  end
end
