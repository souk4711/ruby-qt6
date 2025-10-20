# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qimagewriter.html
    class QImageWriter
      # @!parse class ImageWriterError; end
      rubyqt6_declare_enum_under QImageWriter, QImageWriter::ImageWriterError

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QImageWriter]
      #
      # @overload initialize
      #
      # @overload initialize(device, format)
      #   @param device [QIODevice]
      #   @param format [QByteArray]
      #
      # @overload initialize(file_name, format)
      #   @param file_name [String, QString]
      #   @param format [QByteArray]
      def initialize(*args)
        T.args_nth_to_qstr(args, 0)
        _initialize(*args)
      end
    end
  end
end
