# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qformlayout.html
    class QFormLayout < RubyQt6::QtWidgets::QLayout
      # @!parse class FieldGrowthPolicy; end
      # @!parse class ItemRole         ; end
      # @!parse class RowWrapPolicy    ; end
      # @!parse class TakeRowResult    ; end
      rubyqt6_include_constants QFormLayout, QFormLayout::FieldGrowthPolicy
      rubyqt6_include_constants QFormLayout, QFormLayout::ItemRole
      rubyqt6_include_constants QFormLayout, QFormLayout::RowWrapPolicy
      rubyqt6_include_constants QFormLayout, QFormLayout::TakeRowResult

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QFormLayout]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
