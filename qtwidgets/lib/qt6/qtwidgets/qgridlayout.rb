# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qgridlayout.html
    class QGridLayout < RubyQt6::QtWidgets::QLayout
      # @!visibility private
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QGridLayout]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
