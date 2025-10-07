# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qiodevice.html
    class QIODevice < RubyQt6::QtCore::QObject
      # Inherits QIODeviceBase
      OpenModeFlag = QtCore::QIODeviceBase::OpenModeFlag
      OpenMode = QtCore::QIODeviceBase::OpenMode

      # @!parse
      [
        OpenModeFlag
      ].each do |enum|
        enum.constants.each do |const|
          QIODevice.const_set(const, enum.const_get(const))
        end
      end

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
