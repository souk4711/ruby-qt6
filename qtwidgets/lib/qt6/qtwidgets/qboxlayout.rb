# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qboxlayout.html
    class QBoxLayout < RubyQt6::QtWidgets::QLayout
      # @!parse class Direction; end
      rubyqt6_include_constants QBoxLayout, QBoxLayout::Direction

      # @!visibility private
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param direction [QBoxLayout::Direction]
      # @param parent [QWidget]
      # @return [QBoxLayout]
      def initialize(direction, parent = nil)
        _initialize(direction, parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
