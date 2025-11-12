# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qlineargradient.html
    class QLinearGradient < RubyQt6::QtGui::QGradient
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QLinearGradient]
      #
      # @overload initialize
      #
      # @overload initialize(start_x, start_y, final_stop_x, final_stop_y)
      #   @param start_x [Float]
      #   @param start_y [Float]
      #   @param final_stop_x [Float]
      #   @param final_stop_y [Float]
      #
      # @overload initialize(start, final_stop)
      #   @param start [QPointF]
      #   @param final_stop [QPointF]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
