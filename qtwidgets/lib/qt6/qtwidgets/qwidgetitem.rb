# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidgetitem.html
    class QWidgetItem < RubyQt6::QtWidgets::QLayoutItem
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param widget [QWidget]
      # @return [QWidgetItem]
      def initialize(widget)
        _initialize(widget)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
