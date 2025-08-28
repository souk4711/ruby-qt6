# frozen_string_literal: true

module RubyQt6
  module QtQuickControls2
    # @see https://doc.qt.io/qt-6/qquickstyle.html
    class QQuickStyle
      class << self
        # @return [QString]
        #
        # Returns the name of the application style.
        def name
          _name
        end

        # @param style [QString]
        # @return [nil]
        #
        # Sets the application style.
        def set_style(style)
          _set_style(QtCore::QString.new(style))
        end

        # @param style [QString]
        # @return [nil]
        #
        # Sets the application fallback style.
        def set_fallback_style(style)
          _set_fallback_style(QtCore::QString.new(style))
        end
      end
    end
  end
end
