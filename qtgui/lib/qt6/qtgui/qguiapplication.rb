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

      # @return [QString]
      #
      # This property holds the user-visible name of this application.
      #
      # This name is shown to the user, for instance in window titles. It can
      # be translated, if necessary.
      #
      # If not set, the application display name defaults to the application
      # name.
      def application_display_name
        self.class._application_display_name
      end

      # @return [QString]
      #
      # This property holds the base name of the desktop entry for this
      # application.
      #
      # This is the file name, without the full path or the trailing
      # ".desktop" extension of the desktop entry that represents this
      # application according to the freedesktop desktop entry specification.
      #
      # This property gives a precise indication of what desktop entry
      # represents the application and it is needed by the windowing system to
      # retrieve such information without resorting to imprecise heuristics.
      def desktop_file_name
        self.class._desktop_file_name
      end

      # @return [Qt::LayoutDirection]
      #
      # This property holds the default layout direction for this application.
      #
      # On system start-up, or when the direction is explicitly set to
      # Qt::LayoutDirectionAuto, the default layout direction depends on the
      # application's language.
      def layout_direction
        self.class._layout_direction
      end

      # @return [QString]
      #
      # This property holds the name of the underlying platform plugin.
      def platform_name
        self.class._platform_name
      end

      # @return [QScreen]
      #
      # This property holds the primary (or default) screen of the application.
      #
      # This will be the screen where QWindows are initially shown, unless
      # otherwise specified.
      def primary_screen
        self.class._primary_screen
      end

      # @return [Boolean]
      #
      # This property holds whether the application implicitly quits when the
      # last window is closed.
      #
      # The default is true.
      #
      # If this property is true, the application will attempt to quit when
      # the last visible primary window (i.e. top level window with no
      # transient parent) is closed.
      #
      # Note that attempting a quit may not necessarily result in the
      # application quitting, for example if there still are active
      # QEventLoopLocker instances, or the QEvent::Quit event is ignored.
      def quit_on_last_window_closed?
        self.class._quit_on_last_window_closed?
      end

      # @return [QIcon]
      #
      # This property holds the default window icon.
      def window_icon
        self.class._window_icon
      end

      # @param name [QString]
      # @return [nil]
      #
      # Sets the application's display name.
      def set_application_display_name(name)
        self.class._set_application_display_name(name)
      end

      # @param name [QString]
      # @return [nil]
      #
      # Sets the application's desktopFileName property.
      def set_desktop_file_name(name)
        self.class._set_desktop_file_name(name)
      end

      # @param direction [Qt::LayoutDirection]
      # @return [nil]
      #
      # Sets the application's layoutDirection property.
      def set_layout_direction(direction)
        self.class._set_layout_direction(direction)
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the application's quitOnLastWindowClosed property.
      def set_quit_on_last_window_closed(b)
        self.class._set_quit_on_last_window_closed(b)
      end

      # @param icon [QIcon]
      # @return [nil]
      #
      # Sets the application's windowIcon property.
      def set_window_icon(icon)
        self.class._set_window_icon(icon)
      end

      # @return [Float]
      #
      # Returns the highest screen device pixel ratio found on the system.
      # This is the ratio between physical pixels and device-independent
      # pixels.
      #
      # Use this function only when you don't know which window you are
      # targeting. If you do know the target window, use
      # QWindow::devicePixelRatio() instead.
      def device_pixel_ratio
        _device_pixel_ratio
      end

      # @return [Boolean]
      #
      # Returns true if the application is currently saving the session;
      # otherwise returns false.
      #
      # This is true when commitDataRequest() and saveStateRequest() are
      # emitted, but also when the windows are closed afterwards by session
      # management.
      def saving_session?
        _saving_session?
      end

      # @return [Boolean]
      #
      # Returns true if the application has been restored from an earlier
      # session; otherwise returns false.
      def session_restored?
        _session_restored?
      end

      # @return [QString]
      #
      # Returns the current session's identifier.
      #
      # If the application has been restored from an earlier session, this
      # identifier is the same as it was in that previous session. The session
      # identifier is guaranteed to be unique both for different applications
      # and for different instances of the same application.
      def session_id
        _session_id
      end

      # @return [QString]
      #
      # Returns the session key in the current session.
      #
      # If the application has been restored from an earlier session, this key
      # is the same as it was when the previous session ended.
      #
      # The session key changes every time the session is saved. If the
      # shutdown process is cancelled, another session key will be used when
      # shutting down again.
      def session_key
        _session_key
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
      # To make your application perform idle processing, e.g., executing a
      # special function whenever there are no pending events, use a
      # QChronoTimer with 0ns timeout. More advanced idle processing schemes
      # can be achieved using processEvents().
      #
      # We recommend that you connect clean-up code to the aboutToQuit()
      # signal, instead of putting it in your application's main() function.
      # This is because, on some platforms, the QApplication::exec() call may
      # not return.
      def exec
        self.class._exec
      end
    end
  end
end
