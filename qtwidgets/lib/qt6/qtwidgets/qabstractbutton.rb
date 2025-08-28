# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractbutton.html
    class QAbstractButton < RubyQt6::QtWidgets::QWidget
      # @return [QButtonGroup]
      #
      # Returns the group that this button belongs to.
      #
      # If the button is not a member of any QButtonGroup, this function
      # returns nullptr.
      def group
        _group
      end

      # @return [Boolean]
      #
      # This property holds whether auto-exclusivity is enabled.
      #
      # If auto-exclusivity is enabled, checkable buttons that belong to the
      # same parent widget behave as if they were part of the same exclusive
      # button group. In an exclusive button group, only one button can be
      # checked at any time; checking another button  automatically unchecks
      # the previously checked one.
      #
      # The property has no effect on buttons that belong to a button group.
      #
      # autoExclusive is off by default, except for radio buttons.
      def auto_exclusive?
        _auto_exclusive?
      end

      # @return [Boolean]
      #
      # This property holds whether autoRepeat is enabled.
      #
      # If autoRepeat is enabled, then the pressed(), released(), and clicked()
      # signals are emitted at regular intervals when the button is down.
      #
      # autoRepeat is off by default. The initial delay and the repetition
      # interval are defined in milliseconds by autoRepeatDelay and
      # autoRepeatInterval.
      def auto_repeat?
        _auto_repeat?
      end

      # @return [Integer]
      #
      # This property holds the initial delay of auto-repetition.
      #
      # If autoRepeat is enabled, then autoRepeatDelay defines the initial
      # delay in milliseconds before auto-repetition kicks in.
      def auto_repeat_delay
        _auto_repeat_delay
      end

      # @return [Integer]
      #
      # This property holds the interval of auto-repetition.
      #
      # If autoRepeat is enabled, then autoRepeatInterval defines the length
      # of the auto-repetition interval in millisecons.
      def auto_repeat_interval
        _auto_repeat_interval
      end

      # @return [Boolean]
      #
      # This property holds whether the button is checkable.
      #
      # By default, the button is not checkable.
      def checkable?
        _checkable?
      end

      # @return [Boolean]
      #
      # This property holds whether the button is checked.
      #
      # Only checkable buttons can be checked. By default, the button is
      # unchecked.
      def checked?
        _checked?
      end

      # @return [Boolean]
      #
      # This property holds whether the button is pressed down.
      #
      # If this property is true, the button is pressed down. The signals
      # pressed() and clicked() are not emitted if you set this property to
      # true. The default is false.
      def down?
        _down?
      end

      # @return [QIcon]
      #
      # This property holds the icon shown on the button.
      #
      # The icon's default size is defined by the GUI style, but can be
      # adjusted by setting the iconSize property.
      def icon
        _icon
      end

      # @return [QSize]
      #
      # This property holds the icon size used for this button.
      #
      # The default size is defined by the GUI style. This is a maximum size
      # for the icons. Smaller icons will not be scaled up.
      def icon_size
        _icon_size
      end

      # @return [QKeySequence]
      #
      # This property holds the mnemonic associated with the button.
      def shortcut
        _shortcut
      end

      # @return [QString]
      #
      # This property holds the text shown on the button.
      #
      # If the button has no text, the text() function will return an empty
      # string.
      #
      # If the text contains an ampersand character ('&'), a shortcut is
      # automatically created for it. The character that follows the '&' will
      # be used as the shortcut key. Any previous shortcut will be overwritten
      # or cleared if no shortcut is defined by the text. See the QShortcut
      # documentation for details. To display an actual ampersand, use '&&'.
      #
      # There is no default text.
      def text
        _text
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the button's autoExclusive property.
      def set_auto_exclusive(b)
        _set_auto_exclusive(b)
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the button's autoRepeat property.
      def set_auto_repeat(b)
        _set_auto_repeat(b)
      end

      # @param i [Integer]
      # @return [nil]
      #
      # Sets the button's autoRepeatDelay property.
      def set_auto_repeat_delay(i)
        _set_auto_repeat_delay(i)
      end

      # @param i [Integer]
      # @return [nil]
      #
      # Sets the button's autoRepeatInterval property.
      def set_auto_repeat_interval(i)
        _set_auto_repeat_interval(i)
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the button's checkable property.
      def set_checkable(b)
        _set_checkable(b)
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the button's checked property.
      def set_checked(b)
        _set_checked(b)
      end

      # @param b [Boolean]
      # @return [nil]
      #
      # Sets the button's down property.
      def set_down(b)
        _set_down(b)
      end

      # @param icon [QIcon]
      # @return [nil]
      #
      # Sets the button's icon property.
      def set_icon(icon)
        _set_icon(icon)
      end

      # @param size [QSize]
      # @return [nil]
      #
      # Sets the button's iconSize property.
      def set_icon_size(size)
        _set_icon_size(size)
      end

      # @param key [QKeySequence]
      # @return [nil]
      #
      # Sets the button's shortcut property.
      def set_shortcut(key)
        _set_shortcut(key)
      end

      # @param text [QString]
      # @return [nil]
      #
      # Sets the button's text property.
      def set_text(text)
        _set_text(text)
      end

      # @return [nil]
      #
      # Performs an animated click: the button is pressed immediately, and
      # released 100ms later.
      #
      # Calling this function again before the button is released resets the
      # release timer.
      #
      # All signals associated with a click are emitted as appropriate.
      #
      # This function does nothing if the button is disabled.
      def animate_click
        _animate_click
      end

      # @return [nil]
      #
      # Performs a click.
      #
      # All the usual signals associated with a click are emitted as
      # appropriate. If the button is checkable, the state of the button is
      # toggled.
      #
      # This function does nothing if the button is disabled.
      def click
        _click
      end

      # @return [nil]
      #
      # Toggles the state of a checkable button.
      def toggle
        _toggle
      end
    end
  end
end
