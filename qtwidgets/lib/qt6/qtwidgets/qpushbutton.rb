# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qpushbutton.html
    class QPushButton < RubyQt6::QtWidgets::QAbstractButton
      # @!visibility private
      alias_method :_initialize, :initialize

      # @param text [QString]
      # @param parent [QWidget]
      # @return [QLabel]
      #
      # Constructs a label that displays the text.
      def initialize(text, parent = nil)
        _initialize(QtCore::QString.new(text), parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @return [Boolean]
      #
      # This property holds whether the push button is an auto default button
      #
      # If this property is set to true then the push button is an auto default
      # button.
      #
      # In some GUI styles a default button is drawn with an extra frame around
      # it, up to 3 pixels or more. Qt automatically keeps this space free
      # around auto-default buttons, i.e., auto-default buttons may have a
      # slightly larger size hint.
      #
      # This property's default is true for buttons that have a QDialog parent;
      # otherwise it defaults to false.
      #
      # See the default property for details of how default and auto-default
      # interact.
      def auto_default?
        _auto_default?
      end

      # @return [Boolean]
      #
      # This property holds whether the push button is the default button
      #
      # Default and autodefault buttons decide what happens when the user
      # presses enter in a dialog.
      #
      # A button with this property set to true (i.e., the dialog's default
      # button,) will automatically be pressed when the user presses enter,
      # with one exception: if an autoDefault button currently has focus, the
      # autoDefault button is pressed. When the dialog has autoDefault buttons
      # but no default button, pressing enter will press either the autoDefault
      # button that currently has focus, or if no button has focus, the next
      # autoDefault button in the focus chain.
      #
      # In a dialog, only one push button at a time can be the default button.
      # This button is then displayed with an additional frame (depending on
      # the GUI style).
      #
      # The default button behavior is provided only in dialogs. Buttons can
      # always be clicked from the keyboard by pressing Spacebar when the
      # button has focus.
      #
      # If the default property is set to false on the current default button
      # while the dialog is visible, a new default will automatically be
      # assigned the next time a push button in the dialog receives focus.
      #
      # This property's default is false.
      def default?
        _default?
      end

      # @return [Boolean]
      #
      # This property holds whether the button border is raised
      #
      # This property's default is false. If this property is set, most styles
      # will not paint the button background unless the button is being
      # pressed. setAutoFillBackground() can be used to ensure that the
      # background is filled using the QPalette::Button brush.
      def flat?
        _flat?
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the button's autoDefault property.
      def set_auto_default(enabled)
        _set_auto_default(enabled)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the button's default property.
      def set_default(enabled)
        _set_default(enabled)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the button's flat property.
      def set_flat(enabled)
        _set_flat(enabled)
      end

      # @return [QMenu]
      #
      # Returns the button's associated popup menu or nullptr if no popup menu
      # has been set.
      def menu
        _menu
      end

      # @param menu [QMenu]
      # @return [nil]
      #
      # Associates the popup menu menu with this push button. This turns the
      # button into a menu button, which in some styles will produce a small
      # triangle to the right of the button's text.
      #
      # Ownership of the menu is not transferred to the push button.
      def set_menu(menu)
        _set_menu(menu)
      end

      # @return [nil]
      #
      # Shows (pops up) the associated popup menu. If there is no such menu,
      # this function does nothing. This function does not return until the
      # popup menu has been closed by the user.
      def show_menu
        _show_menu
      end
    end
  end
end
