# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qinputdialog.html
    class QInputDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class InputDialogOption ; end
      # @!parse class InputDialogOptions; end
      # @!parse class InputMode         ; end
      rubyqt6_declare_enum_under QInputDialog, QInputDialog::InputDialogOption
      rubyqt6_declare_enum_under QInputDialog, QInputDialog::InputMode
      rubyqt6_declare_qflags QInputDialog::InputDialogOptions, QInputDialog::InputDialogOption

      # @!parse
      q_object do
        signal "doubleValueChanged(double)"
        signal "doubleValueSelected(double)"
        signal "intValueChanged(int)"
        signal "intValueSelected(int)"
        signal "textValueChanged(QString)"
        signal "textValueSelected(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QInputDialog]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self) if parent
      end
    end
  end
end
