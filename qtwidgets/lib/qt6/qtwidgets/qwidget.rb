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

      _ = "yardoc"
    end
  end
end
