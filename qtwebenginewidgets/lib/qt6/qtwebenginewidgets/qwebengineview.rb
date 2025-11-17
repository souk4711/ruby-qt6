# frozen_string_literal: true

module RubyQt6
  module QtWebEngineWidgets
    # @see https://doc.qt.io/qt-6/qwebengineview.html
    class QWebEngineView < RubyQt6::QtWidgets::QWidget
      INITIALIZE_ARG_ERROR_MESSAGE =
        "Could not resolve method call for #{name}#initialize\n" \
        "  2 overload(s) were evaluated based on the types of Ruby parameters provided:\n" \
        "    initialize(QWidget)\n" \
        "    initialize(QWebEngineProfile, QWidget)\n"

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

      # @return [QWebEngineView]
      #
      # @overload initialize(parent = nil)
      #   @param parent [QWidget]
      #
      # @overload initialize(profile, parent = nil)
      #   @param profile [QWebEngineProfile]
      #   @param parent [QWidget]
      def initialize(*args)
        parent = T.args_nth_delete_qwidget(args, -1)
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
