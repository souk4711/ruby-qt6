# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qwidget.html
    class QWidget < RubyQt6::QtCore::QObject
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QWidget]
      # @return [QWidget]
      #
      # Constructs a widget which is a child of parent, with widget flags set
      # to f.
      #
      # If parent is nullptr, the new widget becomes a window. If parent is
      # another widget, this widget becomes a child window inside parent. The
      # new widget is deleted when its parent is deleted.
      #
      # The widget flags argument, f, is normally 0, but it can be set to
      # customize the frame of a window (i.e. parent must be nullptr). To
      # customize the frame, use a value composed from the bitwise OR of any
      # of the window flags.
      #
      # If you add a child widget to an already visible widget you must
      # explicitly show the child to make it visible.
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_rice(self) if parent
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

      # return [QRect]
      #
      # This property holds the geometry of the widget relative to its parent
      # and excluding the window frame
      #
      # When changing the geometry, the widget, if visible, receives a move
      # event (moveEvent()) and/or a resize event (resizeEvent()) immediately.
      # If the widget is not currently visible, it is guaranteed to receive
      # appropriate events before it is shown.
      #
      # The size component is adjusted if it lies outside the range defined
      # by minimumSize() and maximumSize().
      def geometry
        _geometry
      end

      # @param geometry [QRect]
      # @return [nil]
      #
      # Sets the widget geometry.
      def geometry=(geometry)
        _set_geometry(geometry)
      end

      # @return [QSize]
      #
      # This property holds the size of the widget excluding any window frame
      #
      # If the widget is visible when it is being resized, it receives a resize
      # event (resizeEvent()) immediately. If the widget is not currently
      # visible, it is guaranteed to receive an event before it is shown.
      #
      # The size is adjusted if it lies outside the range defined by
      # minimumSize() and maximumSize().
      #
      # By default, this property contains a value that depends on the user's
      # platform and screen geomet
      def size
        _size
      end

      # @return [nil]
      # @overload rezie(size)
      #   @param size [QSize]
      # @overload rezie(width, height)
      #   @param width [Integer]
      #   @param height [Integer]
      #
      # Sets the widget size.
      def resize(*args)
        _resize(*args)
      end

      # @return [QFont]
      #
      # This property holds the font currently set for the widget
      #
      # This property describes the widget's requested font. The font is used
      # by the widget's style when rendering standard components, and is
      # available as a means to ensure that custom widgets can maintain
      # consistency with the native platform's look and feel. It's common
      # that different platforms, or different styles, define different
      # fonts for an application.
      #
      # When you assign a new font to a widget, the properties from this font
      # are combined with the widget's default font to form the widget's final
      # font. You can call fontInfo() to get a copy of the widget's final font.
      # The final font is also used to initialize QPainter's font.
      #
      # The default depends on the system environment. QApplication maintains
      # a system/theme font which serves as a default for all widgets. There
      # may also be special font defaults for certain types of widgets. You
      # can also define default fonts for widgets yourself by passing a custom
      # font and the name of a widget to QApplication::setFont(). Finally, the
      # font is matched against Qt's font database to find the best match.
      #
      # QWidget propagates explicit font properties from parent to child. If
      # you change a specific property on a font and assign that font to a
      # widget, that property will propagate to all the widget's children,
      # overriding any system defaults for that property. Note that fonts by
      # default don't propagate to windows (see isWindow()) unless the
      # Qt::WA_WindowPropagation attribute is enabled.
      #
      # QWidget's font propagation is similar to its palette propagation.
      #
      # The current style, which is used to render the content of all standard
      # Qt widgets, is free to choose to use the widget font, or in some cases,
      # to ignore it (partially, or completely). In particular, certain styles
      # like GTK style, Mac style, and Windows Vista style, apply special
      # modifications to the widget font to match the platform's native look
      # and feel. Because of this, assigning properties to a widget's font is
      # not guaranteed to change the appearance of the widget. Instead, you
      # may choose to apply a styleSheet.
      def font
        _font
      end

      # @param font [QFont]
      # @return [nil]
      #
      # Sets the widget font.
      def font=(font)
        _set_font(font)
      end
    end
  end
end
