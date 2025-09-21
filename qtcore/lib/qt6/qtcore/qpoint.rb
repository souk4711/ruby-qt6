# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qpoint.html
    class QPoint
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPoint]
      #
      # @overload initialize(xpos, ypos)
      #   @param xpos [Integer]
      #   @param ypos [Integer]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
