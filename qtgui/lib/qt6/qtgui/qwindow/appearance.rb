# frozen_string_literal: true

module RubyQt6
  module QtGui
    class QWindow < RubyQt6::QtCore::QObject
      # @return [QCursor]
      #
      # Returns the cursor shape for this window.
      def cursor
        _cursor
      end

      # @param cursor [QCursor]
      # @return [nil]
      #
      # Set the cursor shape for this window.
      #
      # The mouse cursor will assume this shape when it is over this window,
      # unless an override cursor is set. See the list of predefined cursor
      # objects for a range of useful shapes.
      #
      # If no cursor has been set, or after a call to unsetCursor(), the
      # parent window's cursor is used.
      #
      # By default, the cursor has the Qt::ArrowCursor shape.
      #
      # Some underlying window implementations will reset the cursor if it
      # leaves a window even if the mouse is grabbed. If you want to have a
      # cursor set for all windows, even when outside the window, consider
      # QGuiApplication::setOverrideCursor().
      def set_cursor(cursor)
        _set_cursor(cursor)
      end

      # @return [nil]
      #
      # Restores the default arrow cursor for this window.
      def unset_cursor
        _unset_cursor
      end
    end
  end
end
