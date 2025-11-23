# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediarecorder.html
    class QMediaRecorder < RubyQt6::QtCore::QObject
      # @!parse class EncodingMode ; end
      # @!parse class Error        ; end
      # @!parse class Quality      ; end
      # @!parse class RecorderState; end
      rubyqt6_declare_enum_under QMediaRecorder, QMediaRecorder::EncodingMode
      rubyqt6_declare_enum_under QMediaRecorder, QMediaRecorder::Error
      rubyqt6_declare_enum_under QMediaRecorder, QMediaRecorder::Quality
      rubyqt6_declare_enum_under QMediaRecorder, QMediaRecorder::RecorderState

      # @!parse
      q_object do
        signal "actualLocationChanged(QUrl)"
        signal "audioBitRateChanged()"
        signal "audioChannelCountChanged()"
        signal "audioSampleRateChanged()"
        signal "autoStopChanged()"
        signal "durationChanged(qlonglong)"
        signal "encodingModeChanged()"
        signal "errorChanged()"
        signal "errorOccurred(Error,QString)"
        signal "mediaFormatChanged()"
        signal "metaDataChanged()"
        signal "qualityChanged()"
        signal "recorderStateChanged(RecorderState)"
        signal "videoBitRateChanged()"
        signal "videoFrameRateChanged()"
        signal "videoResolutionChanged()"
        slot "pause()"
        slot "record()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QMediaRecorder]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
