# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpalette.html
    class QPalette
      # @!parse class ColorGroup; end
      # @!parse class ColorRole ; end
      rubyqt6_declare_enum_under QPalette, QPalette::ColorGroup
      rubyqt6_declare_enum_under QPalette, QPalette::ColorRole

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPalette]
      #
      # @overload initialize
      #
      # @overload initialize(button)
      #   @param button [QColor]
      #
      # @overload initialize(button, window)
      #   @param button [QColor]
      #   @param window [QColor]
      def initialize(*args)
        _initialize(*args)
      end

      # @!visibility private
      def ==(other)
        return false unless other.is_a?(self.class)
        self.class._operator_equal(self, other)
      end
    end
  end
end
