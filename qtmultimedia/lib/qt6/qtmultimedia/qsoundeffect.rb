# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qsoundeffect.html
    class QSoundEffect < RubyQt6::QtCore::QObject
      # @!parse class Loop  ; end
      # @!parse class Status; end
      rubyqt6_declare_enum_under QSoundEffect, QSoundEffect::Loop
      rubyqt6_declare_enum_under QSoundEffect, QSoundEffect::Status

      # @!parse
      q_object do
        signal "audioDeviceChanged()"
        signal "loadedChanged()"
        signal "loopCountChanged()"
        signal "loopsRemainingChanged()"
        signal "mutedChanged()"
        signal "playingChanged()"
        signal "sourceChanged()"
        signal "statusChanged()"
        signal "volumeChanged()"
        slot "play()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QSoundEffect]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
