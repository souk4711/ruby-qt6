# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qvideoframeformat.html
    class QVideoFrameFormat
      # @!parse class ColorRange   ; end
      # @!parse class ColorSpace   ; end
      # @!parse class ColorTransfer; end
      # @!parse class Direction    ; end
      # @!parse class PixelFormat  ; end
      rubyqt6_declare_enum_under QVideoFrameFormat, QVideoFrameFormat::ColorRange
      rubyqt6_declare_enum_under QVideoFrameFormat, QVideoFrameFormat::ColorSpace
      rubyqt6_declare_enum_under QVideoFrameFormat, QVideoFrameFormat::ColorTransfer
      rubyqt6_declare_enum_under QVideoFrameFormat, QVideoFrameFormat::Direction
      rubyqt6_declare_enum_under QVideoFrameFormat, QVideoFrameFormat::PixelFormat

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QVideoFrameFormat]
      #
      # @overload initialize
      #
      # @overload initialize(size, pixel_format)
      #   @param size [QSize]
      #   @param pixel_format [QVideoFrameFormat::PixelFormat]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
