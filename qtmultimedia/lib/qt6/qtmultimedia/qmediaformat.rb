# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediaformat.html
    class QMediaFormat
      # @!parse class ConversionMode; end
      # @!parse class FileFormat    ; end
      # @!parse class ResolveFlags  ; end
      # @!parse class AudioCodec    ; end
      # @!parse class VideoCodec    ; end
      rubyqt6_declare_enum_under QMediaFormat, QMediaFormat::ConversionMode
      rubyqt6_declare_enum_under QMediaFormat, QMediaFormat::FileFormat
      rubyqt6_declare_enum_under QMediaFormat, QMediaFormat::ResolveFlags
      rubyqt6_declare_enum_under QMediaFormat, QMediaFormat::AudioCodec, alias: false
      rubyqt6_declare_enum_under QMediaFormat, QMediaFormat::VideoCodec, alias: false

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param format [QMediaFormat::FileFormat>]
      # @return [QMediaFormat]
      def initialize(format = nil)
        format ||= QtMultimedia::QMediaFormat::UnspecifiedFormat
        _initialize(format)
      end
    end
  end
end
