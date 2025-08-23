# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qwindow.html
    class QWindow < RubyQt6::QtCore::QObject
      # @!method show
      #   @return [nil]
      #
      #   Shows the window.
      #
      #   For child windows, this is equivalent to calling showNormal(). Otherwise,
      #   it is equivalent to calling showFullScreen(), showMaximized(), or
      #   showNormal(), depending on the platform's default behavior for the window
      #   type and flags.

      # @!method show_full_screen
      #   @return [nil]
      #
      #   Shows the window as fullscreen.
      #
      #   Equivalent to calling setWindowStates(Qt::WindowFullScreen) and then setVisible(true).

      # @!method show_maximized
      #   @return [nil]
      #
      #   Shows the window as maximized.
      #
      #   Equivalent to calling setWindowStates(Qt::WindowMaximized) and then setVisible(true).

      # @!method show_minimized
      #   @return [nil]
      #
      #   Shows the window as minimized.
      #
      #   Equivalent to calling setWindowStates(Qt::WindowMinimized) and then setVisible(true).

      # @!method show_normal
      #   @return [nil]
      #
      #   Shows the window as normal, i.e. neither maximized, minimized, nor fullscreen.
      #
      #   Equivalent to calling setWindowStates(Qt::WindowNoState) and then setVisible(true).

      # @!method hide
      #   @return [nil]
      #
      #   Hides the window.
      #
      #   Equivalent to calling setVisible(false).

      _ = "yardoc"
    end
  end
end
