# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qvideoframeinput.html
    class QVideoFrameInput < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "readyToSendVideoFrame()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param format [QVideoFrameFormat]
      # @param parent [QObject]
      # @return [QVideoFrameInput]
      def initialize(format, parent = nil)
        _initialize(format, parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
