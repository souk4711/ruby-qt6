# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediaplayer.html
    class QMediaPlayer < RubyQt6::QtCore::QObject
      # @!parse class Error                        ; end
      # @!parse class Loops                        ; end
      # @!parse class MediaStatus                  ; end
      # @!parse class PitchCompensationAvailability; end
      # @!parse class PlaybackState                ; end
      rubyqt6_declare_enum_under QMediaPlayer, QMediaPlayer::Error
      rubyqt6_declare_enum_under QMediaPlayer, QMediaPlayer::Loops
      rubyqt6_declare_enum_under QMediaPlayer, QMediaPlayer::MediaStatus
      rubyqt6_declare_enum_under QMediaPlayer, QMediaPlayer::PitchCompensationAvailability
      rubyqt6_declare_enum_under QMediaPlayer, QMediaPlayer::PlaybackState

      # @!parse
      q_object do
        signal "activeTracksChanged()"
        signal "audioBufferOutputChanged()"
        signal "audioOutputChanged()"
        signal "bufferProgressChanged(float)"
        signal "durationChanged(qlonglong)"
        signal "errorChanged()"
        signal "errorOccurred(QMediaPlayer::Error,QString)"
        signal "hasAudioChanged(bool)"
        signal "hasVideoChanged(bool)"
        signal "loopsChanged()"
        signal "mediaStatusChanged(QMediaPlayer::MediaStatus)"
        signal "metaDataChanged()"
        signal "pitchCompensationChanged(bool)"
        signal "playbackOptionsChanged()"
        signal "playbackRateChanged(double)"
        signal "playbackStateChanged(QMediaPlayer::PlaybackState)"
        signal "playingChanged(bool)"
        signal "positionChanged(qlonglong)"
        signal "seekableChanged(bool)"
        signal "sourceChanged(QUrl)"
        signal "tracksChanged()"
        signal "videoOutputChanged()"
        slot "pause()"
        slot "play()"
        slot "resetPlaybackOptions()"
        slot "setPitchCompensation(bool)"
        slot "setPlaybackOptions(QPlaybackOptions)"
        slot "setPlaybackRate(double)"
        slot "setPosition(qlonglong)"
        slot "setSource(QUrl)"
        slot "setSourceDevice(QIODevice*)"
        slot "setSourceDevice(QIODevice*,QUrl)"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QMediaPlayer]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
