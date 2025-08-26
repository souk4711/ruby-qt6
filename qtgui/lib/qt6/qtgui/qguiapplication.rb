# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qguiapplication.html
    class QGuiApplication < RubyQt6::QtCore::QCoreApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QGuiApplication]
      #
      # Initializes the window system and constructs an application object.
      #
      # The global qApp pointer refers to this application object. Only one
      # application object should be created.
      #
      # This application object must be constructed before any paint devices
      # (including pixmaps, bitmaps etc.).
      def initialize
        _initialize
      end

      # @return [Integer]
      #
      # Enters the main event loop and waits until exit() is called, and then
      # returns the value that was set to exit() (which is 0 if exit() is
      # called via quit()).
      #
      # It is necessary to call this function to start event handling. The main
      # event loop receives events from the window system and dispatches these
      # to the application widgets.
      #
      # Generally, no user interaction can take place before calling exec().
      #
      # To make your application perform idle processing, e.g., executing a special
      # function whenever there are no pending events, use a QChronoTimer with 0ns
      # timeout. More advanced idle processing schemes can be achieved using processEvents().
      #
      # We recommend that you connect clean-up code to the aboutToQuit() signal,
      # instead of putting it in your application's main() function. This is because, on
      # some platforms, the QApplication::exec() call may not return.
      def exec
        self.class._exec
      end
    end
  end
end
