# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginedownloadrequest.html
    class QWebEngineDownloadRequest < RubyQt6::QtCore::QObject
      # @!parse class DownloadInterruptReason; end
      # @!parse class DownloadState          ; end
      # @!parse class SavePageFormat         ; end
      rubyqt6_declare_enum_under QWebEngineDownloadRequest, QWebEngineDownloadRequest::DownloadInterruptReason
      rubyqt6_declare_enum_under QWebEngineDownloadRequest, QWebEngineDownloadRequest::DownloadState
      rubyqt6_declare_enum_under QWebEngineDownloadRequest, QWebEngineDownloadRequest::SavePageFormat

      # @!parse
      q_object do
        signal "downloadDirectoryChanged()"
        signal "downloadFileNameChanged()"
        signal "interruptReasonChanged()"
        signal "isFinishedChanged()"
        signal "isPausedChanged()"
        signal "receivedBytesChanged()"
        signal "savePageFormatChanged()"
        signal "stateChanged(QWebEngineDownloadRequest::DownloadState)"
        signal "totalBytesChanged()"
        slot "accept()"
        slot "cancel()"
        slot "pause()"
        slot "resume()"
      end
    end
  end
end
