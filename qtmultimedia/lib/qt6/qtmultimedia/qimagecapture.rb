# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qimagecapture.html
    class QImageCapture < RubyQt6::QtCore::QObject
      # @!parse class Error     ; end
      # @!parse class FileFormat; end
      # @!parse class Quality   ; end
      rubyqt6_declare_enum_under QImageCapture, QImageCapture::Error
      rubyqt6_declare_enum_under QImageCapture, QImageCapture::FileFormat
      rubyqt6_declare_enum_under QImageCapture, QImageCapture::Quality

      # @!parse
      q_object do
        signal "errorChanged()"
        signal "errorOccurred(int,QImageCapture::Error,QString)"
        signal "fileFormatChanged()"
        signal "imageAvailable(int,QVideoFrame)"
        signal "imageCaptured(int,QImage)"
        signal "imageExposed(int)"
        signal "imageMetadataAvailable(int,QMediaMetaData)"
        signal "imageSaved(int,QString)"
        signal "metaDataChanged()"
        signal "qualityChanged()"
        signal "readyForCaptureChanged(bool)"
        signal "resolutionChanged()"
        slot "capture()"
        slot "captureToFile()"
        slot "captureToFile(QString)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QImageCapture]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
