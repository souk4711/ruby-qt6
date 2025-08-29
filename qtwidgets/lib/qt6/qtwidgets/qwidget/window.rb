# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    class QWidget < RubyQt6::QtCore::QObject
      # @return [Boolean]
      #
      # This property holds whether the widget is shown in full screen mode.
      #
      # A widget in full screen mode occupies the whole screen area and does
      # not display window decorations, such as a title bar.
      def full_screen?
        _full_screen?
      end

      # @return [Boolean]
      #
      # This property holds whether this widget is maximized.
      #
      # This property is only relevant for windows.
      def maximized?
        _maximized?
      end

      # @return [Boolean]
      #
      # This property holds whether this widget is minimized (iconified).
      #
      # This property is only relevant for windows.
      def minimized?
        _minimized?
      end

      # @return [Boolean]
      #
      # This property holds whether the document shown in the window has
      # unsaved changes
      #
      # A modified window is a window whose content has changed but has not
      # been saved to disk. This flag will have different effects varied by
      # the platform. On macOS the close button will have a modified look;
      # on other platforms, the window title will have an '*' (asterisk).
      #
      # The window title must contain a "[*]" placeholder, which indicates
      # where the '*' should appear. Normally, it should appear right after
      # the file name (e.g., "document1.txt[*] - Text Editor"). If the
      # window isn't modified, the placeholder is simply removed.
      #
      # Note that if a widget is set as modified, all its ancestors will also
      # be set as modified. However, if you call setWindowModified(false) on
      # a widget, this will not propagate to its parent because other children
      # of the parent might have been modified.
      def window_modified?
        _window_modified?
      end

      # @return [QString]
      #
      # This property holds the window title (caption)
      #
      # This property only makes sense for top-level widgets, such as windows
      # and dialogs. If no caption has been set, the title is based of the
      # windowFilePath. If neither of these is set, then the title is an empty
      # string.
      #
      # If you use the windowModified mechanism, the window title must contain
      # a "[*]" placeholder, which indicates where the '*' should appear.
      # Normally, it should appear right after the file name (e.g.,
      # "document1.txt[*] - Text Editor"). If the windowModified property is
      # false (the default), the placeholder is simply removed.
      #
      # On some desktop platforms (including Windows and Unix), the application
      # name (from QGuiApplication::applicationDisplayName) is added at the end
      # of the window title, if set. This is done by the QPA plugin, so it is
      # shown to the user, but isn't part of the windowTitle string.
      def window_title
        _window_title
      end

      # @return [QIcon]
      #
      # This property holds the widget's icon.
      #
      # This property only makes sense for windows. If no icon has been set,
      # windowIcon() returns the application icon (QApplication::windowIcon()).
      def window_icon
        _window_icon
      end

      # @return [Boolean]
      #
      # This property holds whether this widget's window is the active window
      #
      # The active window is the window that contains the widget that has
      # keyboard focus (The window may still have focus if it has no widgets
      # or none of its widgets accepts keyboard focus).
      #
      # When popup windows are visible, this property is true for both the
      # active window and for the popup.
      def active_window?
        _active_window?
      end

      # @return [nil]
      #
      # Shows the widget and its child widgets.
      #
      # For child windows, this is equivalent to calling setVisible(true).
      # Otherwise, it is equivalent to calling showFullScreen(),
      # showMaximized(), or setVisible(true), depending on the platform's
      # default behavior for the window flags.
      def show
        _show
      end

      # @return [nil]
      #
      # Shows the widget in full-screen mode.
      #
      # Calling this function only affects windows.
      #
      # To return from full-screen mode, call showNormal() or close().
      def show_full_screen
        _show_full_screen
      end

      # @return [nil]
      #
      # Shows the widget maximized.
      #
      # Calling this function only affects windows.
      def show_maximized
        _show_maximized
      end

      # @return [nil]
      #
      # Shows the widget minimized, as an icon.
      #
      # Calling this function only affects windows.
      def show_minimized
        _show_minimized
      end

      # @return [nil]
      #
      # Restores the widget after it has been maximized or minimized.
      #
      # Calling this function only affects windows.
      def show_normal
        _show_normal
      end

      # @return [nil]
      #
      # Hides the widget. This function is equivalent to setVisible(false).
      def hide
        _hide
      end

      # @return [nil]
      #
      # Raises this widget to the top of the parent widget's stack.
      #
      # After this call the widget will be visually in front of any overlapping
      # sibling widgets.
      def raise
        _raise
      end

      # @return [nil]
      #
      # Lowers the widget to the bottom of the parent widget's stack.
      #
      # After this call the widget will be visually behind (and therefore
      # obscured by) any overlapping sibling widgets.
      def lower
        _lower
      end

      # @return [Boolean]
      #
      # Closes this widget. Returns true if the widget was closed; otherwise
      # returns false.
      #
      # First it sends the widget a QCloseEvent. The widget is hidden if it
      # accepts the close event. If it ignores the event, nothing happens.
      # The default implementation of QWidget::closeEvent() accepts the
      # close event.
      #
      # If the widget has the Qt::WA_DeleteOnClose flag, the widget is also
      # deleted. A close events is delivered to the widget no matter if the
      # widget is visible or not.
      #
      # The QGuiApplication::lastWindowClosed() signal is emitted when the
      # last visible primary window (i.e. window with no parent) with the
      # Qt::WA_QuitOnClose attribute set is closed. By default this attribute
      # is set for all widgets except transient windows such as splash screens,
      # tool windows, and popup menus.
      def close
        _close
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the widget's windowModified property.
      def set_window_modified(b)
        _set_window_modified(b)
      end

      # @param title [QString]
      # @return [nil]
      #
      # Sets the widget's windowTitle property.
      def set_window_title(title)
        _set_window_title(QtCore::QString.new(title))
      end

      # @param icon [QIcon]
      # @return [nil]
      #
      # Sets the widget's windowIcon property.
      def set_window_icon(icon)
        _set_window_icon(icon)
      end

      # @return [nil]
      #
      # Sets the top-level widget containing this widget to be the active
      # window.
      #
      # An active window is a visible top-level window that has the keyboard
      # input focus.
      #
      # This function performs the same operation as clicking the mouse on the
      # title bar of a top-level window. On X11, the result depends on the
      # Window Manager. If you want to ensure that the window is stacked on
      # top as well you should also call raise(). Note that the window must
      # be visible, otherwise activateWindow() has no effect.
      #
      # On Windows, if you are calling this when the application is not
      # currently the active one then it will not make it the active window.
      # It will change the color of the taskbar entry to indicate that the
      # window has changed in some way. This is because Microsoft does not
      # allow an application to interrupt what the user is currently doing in
      # another application.
      def activate_window
        _activate_window
      end

      # @return [nil]
      # @overload update()
      # @overload update(r)
      #   @param r [QRect, QRegion]
      # @overload update(x, y, w, h)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Updates the widget unless updates are disabled or the widget is hidden.
      #
      # This function does not cause an immediate repaint; instead it schedules
      # a paint event for processing when Qt returns to the main event loop.
      # This permits Qt to optimize for more speed and less flicker than a call
      # to repaint() does.
      #
      # Calling update() several times normally results in just one
      # paintEvent() call.
      #
      # Qt normally erases the widget's area before the paintEvent() call. If
      # the Qt::WA_OpaquePaintEvent widget attribute is set, the widget is
      # responsible for painting all its pixels with an opaque color.
      def update(*args)
        _update(*args)
      end

      # @return [nil]
      # @overload repaint()
      # @overload repaint(r)
      #   @param r [QRect, QRegion]
      # @overload repaint(x, y, w, h)
      #   @param x [Integer]
      #   @param y [Integer]
      #   @param w [Integer]
      #   @param h [Integer]
      #
      # Repaints the widget directly by calling paintEvent() immediately,
      # unless updates are disabled or the widget is hidden.
      #
      # We suggest only using repaint() if you need an immediate repaint, for
      # example during animation. In most circumstances update() is better, as
      # it permits Qt to optimize for speed and minimize flicker.
      def repaint(*args)
        _repaint(*args)
      end

      # @return [nil]
      # @overload scroll(dx, dy)
      #   @param dx [Integer]
      #   @param dy [Integer]
      # @overload scroll(dx, dy, r)
      #   @param dx [Integer]
      #   @param dy [Integer]
      #   @param r [QRect]
      #
      # Scrolls the widget including its children dx pixels to the right and dy
      # downward. Both dx and dy may be negative.
      #
      # After scrolling, the widgets will receive paint events for the areas
      # that need to be repainted. For widgets that Qt knows to be opaque, this
      # is only the newly exposed parts. For example, if an opaque widget is
      # scrolled 8 pixels to the left, only an 8-pixel wide stripe at the right
      # edge needs updating.
      #
      # Since widgets propagate the contents of their parents by default, you
      # need to set the autoFillBackground property, or use setAttribute() to
      # set the Qt::WA_OpaquePaintEvent attribute, to make a widget opaque.
      #
      # For widgets that use contents propagation, a scroll will cause an
      # update of the entire scroll area.
      def scroll(*args)
        _scroll(*args)
      end
    end
  end
end
