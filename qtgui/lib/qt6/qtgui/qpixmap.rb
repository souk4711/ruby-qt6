# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpixmap.html
    class QPixmap < RubyQt6::QtGui::QPaintDevice
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPixmap]
      #
      # @overload initialize
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
        T.args_nth_to_qstr(args, 0)
        _initialize(*args)
      end

      # @!visibility private
      def load(file_name, format = "", flags = nil)
        flags ||= Qt::AutoColor
        _load(T.to_qstr(file_name), format, T.to_qflags(flags))
      end
    end
  end
end
