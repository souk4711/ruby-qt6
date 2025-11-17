# frozen_string_literal: true

module RubyQt6
  module QtWebEngineCore
    # @see https://doc.qt.io/qt-6/qwebenginepage.html
    class QWebEnginePage < RubyQt6::QtCore::QObject
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QObject)\n" \
        "    initialize(QWebEngineProfile, QObject)\n"

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

      # @return [QWebEnginePage]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QObject]
      #
      # @overload initialize(profile, parent = nil)
      #   @param profile [QWebEngineProfile]
      #   @param parent [QObject]
      def initialize(*args)
        parent = T.args_nth_delete_qobject(args, -1)
        case args.size
        when 0 then _initialize(QtWebEngineCore::QWebEngineProfile.default_profile, parent)
        when 1 then _initialize(args[-1], parent)
        else raise ArgumentError, INITIALIZE_ARG_ERROR_MESSAGE
        end
        _take_ownership_from_ruby(self)
      end
    end
  end
end
