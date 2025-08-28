# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qapplication.html
    class QApplication < RubyQt6::QtGui::QGuiApplication
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QApplication]
      #
      # Initializes the window system and constructs an application object with
      # argc command line arguments in argv.
      #
      # The global qApp pointer refers to this application object. Only one
      # application object should be created.
      #
      # This application object must be constructed before any paint devices
      # (including widgets, pixmaps, bitmaps etc.).
      def initialize
        _initialize
      end

      # @return [Boolean]
      #
      # toggles automatic SIP (software input panel) visibility
      #
      # Set this property to true to automatically display the SIP when
      # entering widgets that accept keyboard input. This property only
      # affects widgets with the WA_InputMethodEnabled attribute set, and
      # is typically used to launch a virtual keyboard on devices which
      # have very few or no keys.
      #
      # The property only has an effect on platforms that use software input
      # panels.
      #
      # The default is platform dependent.
      def auto_sip_enabled?
        _auto_sip_enabled?
      end

      # @return [Integer]
      #
      # This property holds the text cursor's flash (blink) time in
      # milliseconds.
      #
      # The flash time is the time required to display, invert and restore the
      # caret display. Usually the text cursor is displayed for half the cursor
      # flash time, then hidden for the same amount of time, but this may vary.
      #
      # The default value on X11 is 1000 milliseconds. On Windows, the Control
      # Panel value is used and setting this property sets the cursor flash
      # time for all applications.
      #
      # We recommend that widgets do not cache this value as it may change at
      # any time if the user changes the global desktop settings.
      def cursor_flash_time
        self.class._cursor_flash_time
      end

      # @return [Integer]
      #
      # This property holds the time limit in milliseconds that distinguishes
      # a double click from two consecutive mouse clicks
      #
      # The default value on X11 is 400 milliseconds. On Windows and Mac OS,
      # the operating system's value is used.
      def double_click_interval
        self.class._double_click_interval
      end

      # @return [Integer]
      #
      # This property holds the time limit in milliseconds that distinguishes
      # a key press from two consecutive key presses
      #
      # The default value on X11 is 400 milliseconds. On Windows and Mac OS,
      # the operating system's value is used.
      def keyboard_input_interval
        self.class._keyboard_input_interval
      end

      # @return [Integer]
      #
      # This property holds the minimum distance required for a drag and drop
      # operation to start.
      #
      # If you support drag and drop in your application, and want to start a
      # drag and drop operation after the user has moved the cursor a certain
      # distance with a button held down, you should use this property's value
      # as the minimum distance required.
      #
      # For example, if the mouse position of the click is stored in startPos
      # and the current position (e.g. in the mouse move event) is currentPos,
      # you can find out if a drag should be started with code like this:
      #
      #   if ((startPos - currentPos).manhattanLength() >= QApplication::startDragDistance())
      #     startTheDrag();
      #
      # Qt uses this value internally, e.g. in QFileDialog.
      #
      # The default value (if the platform doesn't provide a different default
      # ) is 10 pixels.
      def start_drag_distance
        self.class._start_drag_distance
      end

      # @return [Integer]
      #
      # This property holds the time in milliseconds that a mouse button must
      # be held down before a drag and drop operation will begin
      #
      # If you support drag and drop in your application, and want to start a
      # drag and drop operation after the user has held down a mouse button
      # for a certain amount of time, you should use this property's value as
      # the delay.
      #
      # Qt also uses this delay internally, e.g. in QTextEdit and QLineEdit,
      # for starting a drag.
      #
      # The default value is 500 ms.
      def start_drag_time
        self.class._start_drag_time
      end

      # @return [QString]
      #
      # This property holds the application style sheet
      #
      # By default, this property returns an empty string unless the user
      # specifies the -stylesheet option on the command line when running the
      # application.
      def style_sheet
        _style_sheet
      end

      # @return [Integer]
      #
      # This property holds the number of lines to scroll a widget, when the
      # mouse wheel is rotated.
      #
      # If the value exceeds the widget's number of visible lines, the widget
      # should interpret the scroll operation as a single page up or page
      # down. If the widget is an item view class, then the result of
      # scrolling one line depends on the setting of the widget's scroll mode.
      # Scroll one line can mean scroll one item or scroll one pixel.
      #
      # By default, this property has a value of 3.
      def wheel_scroll_lines
        self.class._wheel_scroll_lines
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the application's autoSipEnabled property.
      def set_auto_sip_enabled(b)
        _set_auto_sip_enabled(b)
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Sets the application's cursorFlashTime property.
      def set_cursor_flash_time(msec)
        self.class._set_cursor_flash_time(msec)
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Sets the application's doubleClickInterval property.
      def set_double_click_interval(msec)
        self.class._set_double_click_interval(msec)
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Sets the application's keyboardInputInterval property.
      def set_keyboard_input_interval(msec)
        self.class._set_keyboard_input_interval(msec)
      end

      # @param distance [Integer]
      # @return [nil]
      #
      # Sets the application's startDragDistance property.
      def set_start_drag_distance(distance)
        self.class._set_start_drag_distance(distance)
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Sets the application's startDragTime property.
      def set_start_drag_time(msec)
        self.class._set_start_drag_time(msec)
      end

      # @param sheet [QString]
      # @return [nil]
      #
      # Sets the application's styleSheet property.
      def set_style_sheet(sheet)
        _set_style_sheet(sheet)
      end

      # @param lines [Integer]
      # @return [nil]
      #
      # Sets the application's wheelScrollLines property.
      def set_wheel_scroll_lines(lines)
        self.class._set_wheel_scroll_lines(lines)
      end

      # @return [nil]
      #
      # Displays a simple message box about Qt. The message includes the
      # version number of Qt being used by the application.
      #
      # This is useful for inclusion in the Help menu of an application, as
      # shown in the Menus example.
      #
      # This function is a convenience slot for QMessageBox::aboutQt().
      def about_qt
        self.class._about_qt
      end

      # @return [nil]
      #
      # Closes all top-level windows.
      #
      # This function is particularly useful for applications with many
      # top-level windows.
      #
      # The windows are closed in random order, until one window does not
      # accept the close event. The application quits when the last window was
      # successfully closed, unless quitOnLastWindowClosed is set to false. To
      # trigger application termination from e.g. a menu, use
      # QCoreApplication::quit() instead of this function.
      def close_all_windows
        self.class._close_all_windows
      end

      # @return [Integer]
      #
      # Enters the main event loop and waits until exit() is called, then
      # returns the value that was set to exit() (which is 0 if exit() is
      # called via quit()).
      #
      # It is necessary to call this function to start event handling. The
      # main event loop receives events from the window system and dispatches
      # these to the application widgets.
      #
      # Generally, no user interaction can take place before calling exec().
      # As a special case, modal widgets like QMessageBox can be used before
      # calling exec(), because modal widgets call exec() to start a local
      # event loop.
      #
      # To make your application perform idle processing, i.e., executing a
      # special function whenever there are no pending events, use a
      # QChronoTimer with 0ns timeout. More advanced idle processing schemes
      # can be achieved using processEvents().
      #
      # We recommend that you connect clean-up code to the aboutToQuit()
      # signal, instead of putting it in your application's main() function.
      # This is because, on some platforms the QApplication::exec() call may
      # not return. For example, on the Windows platform, when the user logs
      # off, the system terminates the process after Qt closes all top-level
      # windows. Hence, there is no guarantee that the application will have
      # time to exit its event loop and execute code at the end of the main()
      # function, after the QApplication::exec() call.
      def exec
        self.class._exec
      end
    end
  end
end
