# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediacapturesession.html
    class QMediaCaptureSession < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "audioBufferInputChanged()"
        signal "audioInputChanged()"
        signal "audioOutputChanged()"
        signal "cameraChanged()"
        signal "imageCaptureChanged()"
        signal "recorderChanged()"
        signal "screenCaptureChanged()"
        signal "videoFrameInputChanged()"
        signal "videoOutputChanged()"
        signal "windowCaptureChanged()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QMediaCaptureSession]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
