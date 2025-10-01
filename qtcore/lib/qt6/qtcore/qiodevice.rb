# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qiodevice.html
    class QIODevice < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "aboutToClose()"
        signal "bytesWritten(qlonglong)"
        signal "channelBytesWritten(int,qlonglong)"
        signal "channelReadyRead(int)"
        signal "readChannelFinished()"
        signal "readyRead()"
      end
    end
  end
end
