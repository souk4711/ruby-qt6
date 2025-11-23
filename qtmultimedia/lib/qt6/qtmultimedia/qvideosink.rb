# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qvideosink.html
    class QVideoSink < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "subtitleTextChanged(QString)"
        signal "videoFrameChanged(QVideoFrame)"
        signal "videoSizeChanged()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QVideoSink]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
