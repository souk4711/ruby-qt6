# frozen_string_literal: true

module RubyQt6
  module QtCore
    # @see https://doc.qt.io/qt-6/qpointf.html
    class QPointF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPointF]
      #
      # @overload initialize(xpos, ypos)
      #   @param xpos [Float]
      #   @param ypos [Float]
      #
      # @overload initialize(point)
      #   @param point [QPoint]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
