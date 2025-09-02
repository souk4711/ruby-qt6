# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qvboxlayout.html
    class QVBoxLayout < RubyQt6::QtWidgets::QBoxLayout
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QVBoxLayout]
      #
      # Constructs a new top-level vertical box with parent parent.
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
