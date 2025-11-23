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

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QAudioInput]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
