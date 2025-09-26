# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qimage.html
    class QImage < RubyQt6::QtGui::QPaintDevice
      # @!parse class Format    ; end
      # @!parse class InvertMode; end
      rubyqt6_include_constants QImage, QImage::Format
      rubyqt6_include_constants QImage, QImage::InvertMode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QImage]
      #
      # @overload initialize(file_name, format = "")
      #   @param file_name [String, QString]
      #   @param format [String]
      def initialize(*args)
        args[0] = T.to_qstr(args[0]) if args[0].is_a?(::String)
        _initialize(*args)
      end
    end
  end
end
