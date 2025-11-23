# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qvideoframe.html
    class QVideoFrame
      # @!parse class HandleType; end
      # @!parse class MapMode   ; end
      rubyqt6_declare_enum_under QVideoFrame, QVideoFrame::HandleType
      rubyqt6_declare_enum_under QVideoFrame, QVideoFrame::MapMode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QVideoFrame]
      #
      # @overload initialize
      #
      # @overload initialize(image)
      #   @param image [QImage]
      #
      # @overload initialize(format)
      #   @param format [QVideoFrameFormat]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
