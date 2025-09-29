# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qcolordialog.html
    class QColorDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class ColorDialogOption; end
      rubyqt6_include_constants QColorDialog, QColorDialog::ColorDialogOption

      # @!parse
      q_object do
        signal "colorSelected(QColor)"
        signal "currentColorChanged(QColor)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param initial [QColor]
      # @param parent [QWidget]
      # @return [QColorDialog]
      def initialize(initial, parent = nil)
        _initialize(initial, parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
