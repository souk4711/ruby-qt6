# frozen_string_literal: true

module RubyQt6
  module QtQuickControls2
    # @see https://doc.qt.io/qt-6/qquickstyle.html
    class QQuickStyle
      class << self
        # @!method name
        #   @return [QString]
        #
        #   Returns the name of the application style.

        # @param style [QString]
        # @return [nil]
        #
        # Sets the application style.
        def style=(style)
          self._style = QtCore::QString.new(style)
        end

        # @param style [QString]
        # @return [nil]
        #
        # Sets the application fallback style.
        def fallback_style=(style)
          self._fallback_style = QtCore::QString.new(style)
        end
      end
    end
  end
end
