# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qaudioinput.html
    class QAudioInput < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "deviceChanged()"
        signal "mutedChanged(bool)"
        signal "volumeChanged(float)"
        slot "setDevice(QAudioDevice)"
        slot "setMuted(bool)"
        slot "setVolume(float)"
      end
    end
  end
end
