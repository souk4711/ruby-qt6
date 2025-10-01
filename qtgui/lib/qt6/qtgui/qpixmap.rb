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
      # @overload initialize(file_name)
      #   @param file_name [String, QString]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(::String)
        _initialize(*args)
      end
    end
  end
end
