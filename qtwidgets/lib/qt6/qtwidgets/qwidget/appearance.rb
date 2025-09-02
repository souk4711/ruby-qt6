# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    class QWidget < RubyQt6::QtCore::QObject
      # @return [QCursor]
      #
      # This property holds the cursor shape for this widget
      #
      # The mouse cursor will assume this shape when it's over this widget.
      # See the list of predefined cursor objects for a range of useful
      # shapes.
      #
      # An editor widget might use an I-beam cursor:
      #
      #   setCursor(Qt::IBeamCursor);
      #
      # If no cursor has been set, or after a call to unsetCursor(), the
      # parent's cursor is used.
      #
      # By default, this property contains a cursor with the Qt::ArrowCursor
      # shape.
      #
      # Some underlying window implementations will reset the cursor if it
      # leaves a widget even if the mouse is grabbed. If you want to have a
      # cursor set for all widgets, even when outside the window, consider
      # QGuiApplication::setOverrideCursor().
      def cursor
        _cursor
      end

      # @return [QFont]
      #
      # This property holds the font currently set for the widget
      #
      # This property describes the widget's requested font. The font is used
      # by the widget's style when rendering standard components, and is
      # available as a means to ensure that custom widgets can maintain
      # consistency with the native platform's look and feel. It's common
      # that different platforms, or different styles, define different fonts
      # for an application.
      #
      # When you assign a new font to a widget, the properties from this font
      # are combined with the widget's default font to form the widget's final
      # font. You can call fontInfo() to get a copy of the widget's final
      # font. The final font is also used to initialize QPainter's font.
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

      # @return [QFontInfo]
      #
      # Returns the font info for the widget's current font. Equivalent to
      # QFontInfo(widget->font()).
      def font_info
        _font_info
      end

      # @return [QFontMetrics]
      #
      # Returns the font metrics for the widget's current font. Equivalent to
      # QFontMetrics(widget->font()).
      def font_metrics
        _font_metrics
      end

      # @return [QPalette]
      #
      # This property holds the widget's palette
      #
      # This property describes the widget's palette. The palette is used by
      # the widget's style when rendering standard components, and is
      # available as a means to ensure that custom widgets can maintain
      # consistency with the native platform's look and feel. It's common that
      # different platforms, or different styles, have different palettes.
      #
      # When you assign a new palette to a widget, the color roles from this
      # palette are combined with the widget's default palette to form the
      # widget's final palette. The palette entry for the widget's background
      # role is used to fill the widget's background (see
      # QWidget::autoFillBackground), and the foreground role initializes
      # QPainter's pen.
      #
      # The default depends on the system environment. QApplication maintains
      # a system/theme palette which serves as a default for all widgets.
      # There may also be special palette defaults for certain types of
      # widgets (e.g., on Windows Vista, all classes that derive from QMenuBar
      # have a special default palette). You can also define default palettes
      # for widgets yourself by passing a custom palette and the name of a
      # widget to QApplication::setPalette(). Finally, the style always has
      # the option of polishing the palette as it's assigned (see
      # QStyle::polish()).
      #
      # QWidget propagates explicit palette roles from parent to child. If you
      # assign a brush or color to a specific role on a palette and assign
      # that palette to a widget, that role will propagate to all the widget's
      # children, overriding any system defaults for that role. Note that
      # palettes by default don't propagate to windows (see isWindow()) unless
      # the Qt::WA_WindowPropagation attribute is enabled.
      #
      # QWidget's palette propagation is similar to its font propagation.
      #
      # The current style, which is used to render the content of all standard
      # Qt widgets, is free to choose colors and brushes from the widget
      # palette, or, in some cases, to ignore the palette (partially, or
      # completely). In particular, certain styles like GTK style, Mac style,
      # and Windows Vista style, depend on third party APIs to render the
      # content of widgets, and these styles typically do not follow the
      # palette. Because of this, assigning roles to a widget's palette is not
      # guaranteed to change the appearance of the widget. Instead, you may
      # choose to apply a styleSheet.
      def palette
        _palette
      end

      # @return [QPalette::ColorRole]
      #
      # Returns the background role of the widget.
      #
      # The background role defines the brush from the widget's palette that
      # is used to render the background.
      #
      # If no explicit background role is set, the widget inherits its parent
      # widget's background role.
      def background_role
        _background_role
      end

      # @return [QPalette::ColorRole]
      #
      # Returns the foreground role.
      #
      # The foreground role defines the color from the widget's palette that
      # is used to draw the foreground.
      #
      # If no explicit foreground role is set, the function returns a role
      # that contrasts with the background role.
      def foreground_role
        _foreground_role
      end

      # @return [QStyle]
      #
      # Returns the widget's style object.
      def style
        _style
      end

      # @return [QString]
      #
      # This property holds the widget's style sheet
      #
      # The style sheet contains a textual description of customizations to
      # the widget's style, as described in the Qt Style Sheets document.
      def style_sheet
        _style_sheet
      end

      # @param cursor [QCursor]
      # @return [nil]
      #
      # Sets the widget's cursor property.
      def set_cursor(cursor)
        _set_cursor(cursor)
      end

      # @return [nil]
      #
      # Unsets the widget's cursor property.
      def unset_cursor
        _unset_cursor
      end

      # @param font [QFont]
      # @return [nil]
      #
      # Sets the widget's font property.
      def set_font(font)
        _set_font(font)
      end

      # @param palette [QPalette]
      # @return [nil]
      #
      # Sets the widget's palette property.
      def set_palette(palette)
        _set_palette(palette)
      end

      # @param color_role [QPalette::ColorRole]
      # @return [nil]
      #
      # Sets the background role of the widget to role.
      #
      # The background role defines the brush from the widget's palette that
      # is used to render the background.
      #
      # If role is QPalette::NoRole, then the widget inherits its parent's
      # background role.
      #
      # Note that styles are free to choose any color from the palette. You
      # can modify the palette or set a style sheet if you don't achieve the
      # result you want with setBackgroundRole().
      def set_background_role(color_role)
        _set_background_role(color_role)
      end

      # @param color_role [QPalette::ColorRole]
      # @return [nil]
      #
      # Sets the foreground role of the widget to role.
      #
      # The foreground role defines the color from the widget's palette that
      # is used to draw the foreground.
      #
      # If role is QPalette::NoRole, the widget uses a foreground role that
      # contrasts with the background role.
      #
      # Note that styles are free to choose any color from the palette. You
      # can modify the palette or set a style sheet if you don't achieve the
      # result you want with setForegroundRole().
      def set_foreground_role(color_role)
        _set_foreground_role(color_role)
      end

      # @param style [QStyle]
      # @return [nil]
      #
      # Sets the widget's GUI style to style. The ownership of the style
      # object is not transferred.
      #
      # If no style is set, the widget uses the application's style,
      # QApplication::style() instead.
      #
      # Setting a widget's style has no effect on existing or future child
      # widgets.
      def set_style(style)
        _set_style(style)
      end

      # @param style_sheet [QString]
      # @return [nil]
      #
      # Sets the widget's styleSheet property.
      def set_style_sheet(style_sheet)
        _set_style_sheet(QtCore::QString.new(style_sheet))
      end
    end
  end
end
