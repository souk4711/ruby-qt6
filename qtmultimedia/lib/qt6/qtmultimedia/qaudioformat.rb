# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qaudioformat.html
    class QAudioFormat
      # @!parse class AudioChannelPosition; end
      # @!parse class ChannelConfig       ; end
      # @!parse class SampleFormat        ; end
      rubyqt6_declare_enum_under QAudioFormat, QAudioFormat::AudioChannelPosition
      rubyqt6_declare_enum_under QAudioFormat, QAudioFormat::ChannelConfig
      rubyqt6_declare_enum_under QAudioFormat, QAudioFormat::SampleFormat

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QAudioFormat]
      def initialize
        _initialize
      end
    end
  end
end
