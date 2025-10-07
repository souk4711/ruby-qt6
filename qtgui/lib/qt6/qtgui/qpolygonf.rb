# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpolygonf.html
    class QPolygonF
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPolygonF]
      #
      # @overload initialize
      #
      # @overload initialize(polygon)
      #   @param polygon [QPolygon]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
