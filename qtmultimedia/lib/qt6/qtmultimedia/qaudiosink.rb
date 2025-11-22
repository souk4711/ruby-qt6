# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qaudiosink.html
    class QAudioSink < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "stateChanged(QtAudio::State)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param device [QAudioDevice]
      # @param format [QAudioFormat]
      # @param parent [QObject]
      # @return [QAudioSink]
      def initialize(device, format, parent = nil)
        _initialize(device, format, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
