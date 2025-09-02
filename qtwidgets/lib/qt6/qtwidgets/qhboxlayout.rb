# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qhboxlayout.html
    class QHBoxLayout < RubyQt6::QtWidgets::QBoxLayout
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QHBoxLayout]
      #
      # Constructs a new top-level horizontal box with parent parent.
      #
      # The layout is set directly as the top-level layout for parent. There
      # can be only one top-level layout for a widget. It is returned
      # by QWidget::layout().
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rubyrice(self) if parent
      end
    end
  end
end
