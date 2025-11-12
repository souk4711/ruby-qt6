# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qradialgradient.html
    class QRadialGradient < RubyQt6::QtGui::QGradient
      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QRadialGradient]
      #
      # @overload initialize
      #
      # @overload initialize(cx, cy, center_radius, fx, fy, focal_radius)
      #   @param cx [Float]
      #   @param cy [Float]
      #   @param center_radius [Float]
      #   @param fx [Float]
      #   @param fy [Float]
      #   @param focal_radius [Float]
      #
      # @overload initialize(cx, cy, center_radius, fx, fy)
      #   @param cx [Float]
      #   @param cy [Float]
      #   @param center_radius [Float]
      #   @param fx [Float]
      #   @param fy [Float]
      #
      # @overload initialize(cx, cy, center_radius)
      #   @param cx [Float]
      #   @param cy [Float]
      #   @param center_radius [Float]
      #
      # @overload initialize(center, center_radius, focal, focal_radius)
      #   @param center [QPointF]
      #   @param center_radius [Float]
      #   @param focal [QPointF]
      #   @param focal_radius [Float]
      #
      # @overload initialize(center, center_radius, focal)
      #   @param center [QPointF]
      #   @param center_radius [Float]
      #   @param focal [QPointF]
      #
      # @overload initialize(center, center_radius)
      #   @param center [QPointF]
      #   @param center_radius [Float]
      def initialize(*args)
        _initialize(*args)
      end
    end
  end
end
