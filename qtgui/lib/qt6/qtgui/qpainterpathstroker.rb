# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qpainterpathstroker.html
    class QPainterPathStroker
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QPainterPathStroker]
      #
      # @overload initialize
      #
      # @overload initialize(pen)
      #   @param pen [QPen]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
