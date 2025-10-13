# frozen_string_literal: true

module RubyQt6
  module QtPrintSupport
    # @see https://doc.qt.io/qt-6/qprinter.html
    class QPrinter < RubyQt6::QtGui::QPagedPaintDevice
      # @!parse class ColorMode   ; end
      # @!parse class DuplexMode  ; end
      # @!parse class OutputFormat; end
      # @!parse class PageOrder   ; end
      # @!parse class PaperSource ; end
      # @!parse class PrintRange  ; end
      # @!parse class PrinterMode ; end
      # @!parse class PrinterState; end
      # @!parse class Unit        ; end
      rubyqt6_declare_enum_under QPrinter, QPrinter::ColorMode
      rubyqt6_declare_enum_under QPrinter, QPrinter::DuplexMode
      rubyqt6_declare_enum_under QPrinter, QPrinter::OutputFormat
      rubyqt6_declare_enum_under QPrinter, QPrinter::PageOrder
      rubyqt6_declare_enum_under QPrinter, QPrinter::PaperSource
      rubyqt6_declare_enum_under QPrinter, QPrinter::PrintRange
      rubyqt6_declare_enum_under QPrinter, QPrinter::PrinterMode
      rubyqt6_declare_enum_under QPrinter, QPrinter::PrinterState
      rubyqt6_declare_enum_under QPrinter, QPrinter::Unit

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPrinter]
      #
      # @overload initialize(mode)
      #   @param mode [QPrinter::PrinterMode]
      #
      # @overload initialize(printer, mode)
      #   @param printer [QPrinterInfo]
      #   @param mode [QPrinter::PrinterMode]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
