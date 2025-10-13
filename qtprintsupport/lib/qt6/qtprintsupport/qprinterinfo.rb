# frozen_string_literal: true

module RubyQt6
  module QtPrintSupport
    # @see https://doc.qt.io/qt-6/qprinterinfo.html
    class QPrinterInfo
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPrinterInfo]
      #
      # @overload initialize
      #
      # @overload initialize(printer)
      #   @param printer [QPrinter]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
