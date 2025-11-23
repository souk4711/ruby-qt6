# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qscreencapture.html
    class QScreenCapture < RubyQt6::QtCore::QObject
      # @!parse class Error; end
      rubyqt6_declare_enum_under QScreenCapture, QScreenCapture::Error

      # @!parse
      q_object do
        signal "activeChanged(bool)"
        signal "errorChanged()"
        signal "errorOccurred(QScreenCapture::Error,QString)"
        signal "screenChanged(QScreen*)"
        slot "setActive(bool)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QScreenCapture]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
