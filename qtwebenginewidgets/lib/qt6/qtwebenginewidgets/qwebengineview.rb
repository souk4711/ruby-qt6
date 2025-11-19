# frozen_string_literal: true

module RubyQt6
  module QtWebEngineWidgets
    # @see https://doc.qt.io/qt-6/qwebengineview.html
    class QWebEngineView < RubyQt6::QtWidgets::QWidget
      # @!parse
      q_object do
        signal "iconChanged(QIcon)"
        signal "iconUrlChanged(QUrl)"
        signal "loadFinished(bool)"
        signal "loadProgress(int)"
        signal "loadStarted()"
        signal "pdfPrintingFinished(QString,bool)"
        signal "printFinished(bool)"
        signal "printRequested()"
        signal "printRequestedByFrame(QWebEngineFrame)"
        signal "renderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus,int)"
        signal "selectionChanged()"
        signal "titleChanged(QString)"
        signal "urlChanged(QUrl)"
        slot "back()"
        slot "forward()"
        slot "reload()"
        slot "stop()"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWebEngineView]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
