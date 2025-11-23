# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qwindowcapture.html
    class QWindowCapture < RubyQt6::QtCore::QObject
      # @!parse class Error; end
      rubyqt6_declare_enum_under QWindowCapture, QWindowCapture::Error

      # @!parse
      q_object do
        signal "activeChanged(bool)"
        signal "errorChanged()"
        signal "errorOccurred(QWindowCapture::Error,QString)"
        signal "windowChanged(QCapturableWindow)"
        slot "setActive(bool)"
        slot "start()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QWindowCapture]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
