# frozen_string_literal: true

module RubyQt6
  module QtPrintSupport
    # @see https://doc.qt.io/qt-6/qprintdialog.html
    class QPrintDialog < RubyQt6::QtPrintSupport::QAbstractPrintDialog
      # @!parse
      q_object do
        signal "accepted(QPrinter*)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param printer [QPrinter]
      # @param parent [QWidget]
      # @return [QPrintDialog]
      def initialize(printer, parent = nil)
        _initialize(printer, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
