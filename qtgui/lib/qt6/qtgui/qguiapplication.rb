# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qguiapplication.html
    class QGuiApplication < RubyQt6::QtCore::QCoreApplication
      # @!parse
      q_object do
        signal "applicationDisplayNameChanged()"
        signal "applicationStateChanged(Qt::ApplicationState)"
        signal "commitDataRequest(QSessionManager&)"
        signal "focusObjectChanged(QObject*)"
        signal "focusWindowChanged(QWindow*)"
        signal "fontDatabaseChanged()"
        signal "lastWindowClosed()"
        signal "layoutDirectionChanged(Qt::LayoutDirection)"
        signal "primaryScreenChanged(QScreen*)"
        signal "saveStateRequest(QSessionManager&)"
        signal "screenAdded(QScreen*)"
        signal "screenRemoved(QScreen*)"
        slot "setBadgeNumber(qlonglong)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param argv [Array<String>]
      # @return [QGuiApplication]
      def initialize(argv)
        argv = _initialize_qApp_argv(argv)
        _initialize(argv.size, argv.data)
        _initialize_qApp
      end
    end
  end
end
