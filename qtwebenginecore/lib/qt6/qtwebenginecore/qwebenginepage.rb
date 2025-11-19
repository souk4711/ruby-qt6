# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginepage.html
    class QWebEnginePage < RubyQt6::QtCore::QObject
      # @!parse class FileSelectionMode             ; end
      # @!parse class FindFlag                      ; end
      # @!parse class JavaScriptConsoleMessageLevel ; end
      # @!parse class LifecycleState                ; end
      # @!parse class NavigationType                ; end
      # @!parse class RenderProcessTerminationStatus; end
      # @!parse class WebAction                     ; end
      # @!parse class WebWindowType                 ; end
      # @!parse class FindFlags                     ; end
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::FileSelectionMode
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::FindFlag
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::JavaScriptConsoleMessageLevel
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::LifecycleState
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::NavigationType
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::RenderProcessTerminationStatus
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::WebAction
      rubyqt6_declare_enum_under QWebEnginePage, QWebEnginePage::WebWindowType
      rubyqt6_declare_qflags QWebEnginePage::FindFlags, QWebEnginePage::FindFlag

      # @!parse
      q_object do
        signal "audioMutedChanged(bool)"
        signal "certificateError(QWebEngineCertificateError)"
        signal "contentsSizeChanged(QSizeF)"
        signal "desktopMediaRequested(QWebEngineDesktopMediaRequest)"
        signal "fileSystemAccessRequested(QWebEngineFileSystemAccessRequest)"
        signal "findTextFinished(QWebEngineFindTextResult)"
        signal "fullScreenRequested(QWebEngineFullScreenRequest)"
        signal "geometryChangeRequested(QRect)"
        signal "iconChanged(QIcon)"
        signal "iconUrlChanged(QUrl)"
        signal "lifecycleStateChanged(LifecycleState)"
        signal "linkHovered(QString)"
        signal "loadFinished(bool)"
        signal "loadProgress(int)"
        signal "loadStarted()"
        signal "loadingChanged(QWebEngineLoadingInfo)"
        signal "navigationRequested(QWebEngineNavigationRequest&)"
        signal "newWindowRequested(QWebEngineNewWindowRequest&)"
        signal "pdfPrintingFinished(QString,bool)"
        signal "permissionRequested(QWebEnginePermission)"
        signal "printRequested()"
        signal "printRequestedByFrame(QWebEngineFrame)"
        signal "recentlyAudibleChanged(bool)"
        signal "recommendedStateChanged(LifecycleState)"
        signal "registerProtocolHandlerRequested(QWebEngineRegisterProtocolHandlerRequest)"
        signal "renderProcessPidChanged(qlonglong)"
        signal "renderProcessTerminated(RenderProcessTerminationStatus,int)"
        signal "scrollPositionChanged(QPointF)"
        signal "selectClientCertificate(QWebEngineClientCertificateSelection)"
        signal "selectionChanged()"
        signal "titleChanged(QString)"
        signal "urlChanged(QUrl)"
        signal "visibleChanged(bool)"
        signal "webAuthUxRequested(QWebEngineWebAuthUxRequest*)"
        signal "windowCloseRequested()"
        signal "zoomFactorChanged(double)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QWebEnginePage]
      def initialize(parent)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
