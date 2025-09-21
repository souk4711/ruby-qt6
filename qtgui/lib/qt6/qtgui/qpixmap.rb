# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpixmap.html
    class QPixmap < RubyQt6::QtGui::QPaintDevice
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPixmap]
      #
      # @overload initialize(w, h)
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # @overload initialize(size)
      #   @param size [QSize]
      #
      # @overload initialize(xpm)
      #   @param xpm [String]
      #
      # @overload initialize(file_name, format = "", flags = Qt::AutoColor)
      #   @param file_name [QString]
      #   @param format [String]
      #   @param flags [Qt::ImageConversionFlags]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
