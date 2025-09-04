# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qstackedlayout.html
    class QStackedLayout < RubyQt6::QtWidgets::QLayout
      # @!parse class Direction; end
      rubyqt6_include_constants QStackedLayout, QStackedLayout::StackingMode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget, QLayout]
      # @return [QStackedLayout]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
