# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!method show
      #   @return [nil]
      #
      #   Shows the widget and its child widgets.
      #
      #   For child windows, this is equivalent to calling setVisible(true).
      #   Otherwise, it is equivalent to calling showFullScreen(),
      #   showMaximized(), or setVisible(true), depending on the platform's
      #   default behavior for the window flags.

      # @!method show_full_screen
      #   @return [nil]
      #
      #   Shows the widget in full-screen mode.
      #
      #   Calling this function only affects windows.
      #
      #   To return from full-screen mode, call showNormal() or close().

      # @!method show_maximized
      #   @return [nil]
      #
      #   Shows the widget maximized.
      #
      #   Calling this function only affects windows.

      # @!method show_minimized
      #   @return [nil]
      #
      #   Shows the widget minimized, as an icon.
      #
      #   Calling this function only affects windows.

      # @!method show_normal
      #   @return [nil]
      #
      #   Restores the widget after it has been maximized or minimized.
      #
      #   Calling this function only affects windows.

      # @!method hide
      #   @return [nil]
      #
      #   Hides the widget. This function is equivalent to setVisible(false).

      # @!method size
      #   @return [QSize]
      #
      #   This property holds the size of the widget excluding any window frame
      #
      #   If the widget is visible when it is being resized, it receives a resize
      #   event (resizeEvent()) immediately. If the widget is not currently
      #   visible, it is guaranteed to receive an event before it is shown.
      #
      #   The size is adjusted if it lies outside the range defined by
      #   minimumSize() and maximumSize().
      #
      #   By default, this property contains a value that depends on the user's
      #   platform and screen geomet

      # @!method resize(..)
      #   @return [nil]
      #   @overload rezie(width, height)
      #     @param width [Integer]
      #     @param height [Integer]
      #   @overload rezie(size)
      #     @param size [QSize]
      #
      #   Sets the widget size.

      # @!method font
      #   @return [QFont]
      #
      #   This property holds the font currently set for the widget
      #
      #   This property describes the widget's requested font. The font is used
      #   by the widget's style when rendering standard components, and is
      #   available as a means to ensure that custom widgets can maintain
      #   consistency with the native platform's look and feel. It's common
      #   that different platforms, or different styles, define different
      #   fonts for an application.
      #
      #   When you assign a new font to a widget, the properties from this font
      #   are combined with the widget's default font to form the widget's final
      #   font. You can call fontInfo() to get a copy of the widget's final font.
      #   The final font is also used to initialize QPainter's font.
      #
      #   The default depends on the system environment. QApplication maintains
      #   a system/theme font which serves as a default for all widgets. There
      #   may also be special font defaults for certain types of widgets. You
      #   can also define default fonts for widgets yourself by passing a custom
      #   font and the name of a widget to QApplication::setFont(). Finally, the
      #   font is matched against Qt's font database to find the best match.
      #
      #   QWidget propagates explicit font properties from parent to child. If
      #   you change a specific property on a font and assign that font to a
      #   widget, that property will propagate to all the widget's children,
      #   overriding any system defaults for that property. Note that fonts by
      #   default don't propagate to windows (see isWindow()) unless the
      #   Qt::WA_WindowPropagation attribute is enabled.
      #
      #   QWidget's font propagation is similar to its palette propagation.
      #
      #   The current style, which is used to render the content of all standard
      #   Qt widgets, is free to choose to use the widget font, or in some cases,
      #   to ignore it (partially, or completely). In particular, certain styles
      #   like GTK style, Mac style, and Windows Vista style, apply special
      #   modifications to the widget font to match the platform's native look
      #   and feel. Because of this, assigning properties to a widget's font is
      #   not guaranteed to change the appearance of the widget. Instead, you
      #   may choose to apply a styleSheet.

      # @!method font=(font)
      #   @param font [QFont]
      #   @return [void]
      #
      #   Sets the widget font.

      # @!visibility private
      def _yardoc
      end
    end
  end
end
