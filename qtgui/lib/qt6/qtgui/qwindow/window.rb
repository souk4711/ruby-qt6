# frozen_string_literal: true

module RubyQt6
  module QtGui
    class QWindow < RubyQt6::QtCore::QObject
      # @return [QString]
      #
      # This property holds the window's title in the windowing system.
      #
      # The window title might appear in the title area of the window
      # decorations, depending on the windowing system and the window
      # flags. It might also be used by the windowing system to identify
      # the window in other contexts, such as in the task switcher.
      def title
        _title
      end

      # @return [QIcon]
      #
      # Returns the window's icon in the windowing system.
      def icon
        _icon
      end

      # @return [nil]
      #
      # Shows the window.
      #
      # For child windows, this is equivalent to calling showNormal().
      # Otherwise, it is equivalent to calling showFullScreen(),
      # showMaximized(), or showNormal(), depending on the platform's default
      # behavior for the window type and flags.
      def show
        _show
      end

      # @return [nil]
      #
      # Shows the window as fullscreen.
      #
      # Equivalent to calling setWindowStates(Qt::WindowFullScreen) and then
      # setVisible(true).
      def show_full_screen
        _show_full_screen
      end

      # @return [nil]
      #
      # Shows the window as maximized.
      #
      # Equivalent to calling setWindowStates(Qt::WindowMaximized) and then
      # setVisible(true).
      def show_maximized
        _show_maximized
      end

      # @return [nil]
      #
      # Shows the window as minimized.
      #
      # Equivalent to calling setWindowStates(Qt::WindowMinimized) and then
      # setVisible(true).
      def show_minimized
        _show_minimized
      end

      # @return [nil]
      #
      # Shows the window as normal, i.e. neither maximized, minimized, nor
      # fullscreen.
      #
      # Equivalent to calling setWindowStates(Qt::WindowNoState) and then
      # setVisible(true).
      def show_normal
        _show_normal
      end

      # @return [nil]
      #
      # Hides the window.
      #
      # Equivalent to calling setVisible(false).
      def hide
        _hide
      end

      # @return [nil]
      #
      # Raise the window in the windowing system.
      #
      # Requests that the window be raised to appear above other windows.
      def raise
        _raise
      end

      # @return [nil]
      #
      # Lower the window in the windowing system.
      #
      # Requests that the window be lowered to appear below other windows.
      def lower
        _lower
      end

      # @return [Boolean]
      #
      # Close the window.
      #
      # This closes the window, effectively calling destroy(), and potentially
      # quitting the application. Returns true on success, false if it has a
      # parent window (in which case the top level window should be closed
      # instead).
      def close
        _close
      end

      # @param msec [Integer]
      # @return [nil]
      #
      # Causes an alert to be shown for msec milliseconds. If msec is 0
      # (the default), then the alert is shown indefinitely until the window
      # becomes active again. This function has no effect on an active window.
      #
      # In alert state, the window indicates that it demands attention, for
      # example by flashing or bouncing the taskbar entry.
      def alert(msec)
        _alert(msec)
      end

      # @param title [QString]
      # @return [nil]
      #
      # Sets the window's title in the windowing system.
      def set_title(title)
        _set_title(QtCore::QString.new(title))
      end

      # @param icon [QIcon[
      # @return [nil]
      #
      # Sets the window's icon in the windowing system.
      #
      # The window icon might be used by the windowing system for example to
      # decorate the window, and/or in the task switcher.
      def set_icon(icon)
        _set_icon(icon)
      end

      # @return [Boolean]
      #
      # Returns true if the window is active.
      #
      # This is the case for the window that has input focus as well as
      # windows that are in the same parent / transient parent chain as
      # the focus window.
      #
      # Typically active windows should appear active from a style
      # perspective.
      #
      # To get the window that currently has focus, use
      # QGuiApplication::focusWindow().
      def active?
        _active?
      end
    end
  end
end
