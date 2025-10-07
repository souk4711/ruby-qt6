# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpolygon.html
    class QPolygon
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPolygon]
      #
      # @overload initialize
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
