# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpalette.html
    class QPalette
      # @!parse class ColorGroup; end
      # @!parse class ColorRole; end
      rubyqt6_include_constants QPalette, QPalette::ColorGroup
      rubyqt6_include_constants QPalette, QPalette::ColorRole

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param button [QColor]
      # @return [QPalette]
      def initialize(button)
        _initialize(button)
      end
    end
  end
end
