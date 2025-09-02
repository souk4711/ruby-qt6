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

      # @return [Float]
      #
      # This property holds the opacity of the window in the windowing system.
      #
      # If the windowing system supports window opacity, this can be used to
      # fade the window in and out, or to make it semitransparent.
      #
      # A value of 1.0 or above is treated as fully opaque, whereas a value
      # of 0.0 or below is treated as fully transparent. Values inbetween
      # represent varying levels of translucency between the two extremes.
      #
      # The default value is 1.0.
      def opacity
        _opacity
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

      # @param level [Float]
      # @return [nil]
      #
      # Sets the window's opacity property.
      def set_opacity(level)
        _set_opacity(level)
      end
    end
  end
end
