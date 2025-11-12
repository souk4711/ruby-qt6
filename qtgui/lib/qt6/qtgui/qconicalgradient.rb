# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qconicalgradient.html
    class QConicalGradient < RubyQt6::QtGui::QGradient
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QConicalGradient]
      #
      # @overload initialize
      #
      # @overload initialize(center_x, center_y, start_angle)
      #   @param center_x [Float]
      #   @param center_y [Float]
      #   @param start_angle [Float]
      #
      # @overload initialize(center, start_angle)
      #   @param center [QPointF]
      #   @param start_angle [Float]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
