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

      # @return [Qt::ScreenOrientation]
      #
      # This property holds the orientation of the window's contents
      #
      # This is a hint to the window manager in case it needs to display
      # additional content like popups, dialogs, status bars, or similar in
      # relation to the window.
      #
      # The recommended orientation is QScreen::orientation() but an
      # application doesn't have to support all possible orientations, and
      # thus can opt to ignore the current screen orientation.
      #
      # The difference between the window and the content orientation
      # determines how much to rotate the content by. QScreen::angleBetween(),
      # QScreen::transformBetween(), and QScreen::mapBetween() can be used to
      # compute the necessary transform.
      #
      # The default value is Qt::PrimaryOrientation
      def content_orientation
        _content_orientation
      end

      # @return [Qt::WindowFlags]
      #
      # This property holds the window flags of the window
      #
      # The window flags control the window's appearance in the windowing
      # system, whether it's a dialog, popup, or a regular window, and
      # whether it should have a title bar, etc.
      #
      # The actual window flags might differ from the flags set with
      # setFlags() if the requested flags could not be fulfilled.
      def flags
        _flags
      end

      # @return [Qt::WindowType]
      #
      # Returns the type of the window.
      #
      # This returns the part of the window flags that represents whether the
      # window is a dialog, tooltip, popup, regular window, etc.
      def type
        _type
      end

      # @return [Qt::WindowModality]
      #
      # This property holds the modality of the window
      #
      # A modal window prevents other windows from receiving input events. Qt
      # supports two types of modality: Qt::WindowModal and
      # Qt::ApplicationModal.
      #
      # By default, this property is Qt::NonModal.
      def modality
        _modality
      end

      # @return [QWindow::Visibility]
      #
      # This property holds the screen-occupation state of the window.
      #
      # Visibility is whether the window should appear in the windowing
      # system as normal, minimized, maximized, fullscreen or hidden.
      #
      # To set the visibility to AutomaticVisibility means to give the window
      # a default visible state, which might be fullscreen or windowed
      # depending on the platform. When reading the visibility property
      # you will always get the actual state, never AutomaticVisibility.
      #
      # The default value is Hidden.
      def visibility
        _visibility
      end

      # @return [Boolean]
      #
      # This property holds whether the window is visible or not.
      #
      # This property controls the visibility of the window in the windowing
      # system.
      #
      # By default, the window is not visible, you must call setVisible(true),
      # or show() or similar to make it visible.
      def visible?
        _visible?
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

      # @param icon [QIcon]
      # @return [nil]
      #
      # Sets the window's icon in the windowing system.
      #
      # The window icon might be used by the windowing system for example to
      # decorate the window, and/or in the task switcher.
      def set_icon(icon)
        _set_icon(icon)
      end

      # @param orientation [Qt::ScreenOrientation]
      # @return [nil]
      #
      # Sets the window's contentOrientation property.
      def report_content_orientation_change(orientation)
        _report_content_orientation_change(orientation)
      end

      # @param flags [Qt::WindowFlags]
      # @return [nil]
      #
      # Sets the window's flags property.
      def set_flags(flags)
        _set_flags(flags)
      end

      # @param flag [Qt::WindowType]
      # @param on [Boolean]
      # @return [nil]
      #
      # Sets the window flag flag on this window if on is true; otherwise
      # clears the flag.
      def set_flag(flag, on)
        _set_flag(flag, on)
      end

      # @param modality [Boolean]
      # @return [nil]
      #
      # Sets the window's modality property.
      def set_modality(modality)
        _set_modality(modality)
      end

      # @param visibility [QWindow::Visibility]
      # @return [nil]
      #
      # Sets the window's visibility property.
      def set_visibility(visibility)
        _set_visibility(visibility)
      end

      # @param visible [Boolean]
      # @return [nil]
      #
      # Sets the window's visible property.
      def set_visible(visible)
        _set_visible(visible)
      end
    end
  end
end
