# frozen_string_literal: true

module RubyQt6
  module QtPrintSupport
    # @see https://doc.qt.io/qt-6/qabstractprintdialog.html
    class QAbstractPrintDialog < RubyQt6::QtWidgets::QDialog
      # @!parse class PrintDialogOption ; end
      # @!parse class PrintDialogOptions; end
      # @!parse class PrintRange        ; end
      rubyqt6_declare_enum_under QAbstractPrintDialog, QAbstractPrintDialog::PrintDialogOption
      rubyqt6_declare_enum_under QAbstractPrintDialog, QAbstractPrintDialog::PrintRange
      rubyqt6_declare_qflags QAbstractPrintDialog::PrintDialogOptions, QAbstractPrintDialog::PrintDialogOption

      # @!parse
      q_object do
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param printer [QPrinter]
      # @param parent [QWidget]
      # @return [QAbstractPrintDialog]
      def initialize(printer, parent = nil)
        _initialize(printer, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
