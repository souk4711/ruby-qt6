# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qslider.html
    class QSlider < RubyQt6::QtWidgets::QAbstractSlider
      # @!visibility private
      alias_method :_initialize, :initialize

      # @!parse class TickPosition; end
      rubyqt6_include_constants QSlider, QSlider::TickPosition

      # @param orientation [Qt::Orientation]
      # @param parent [QWidget]
      # @return [QLabel]
      #
      # Constructs a slider with the given parent. The orientation parameter
      # determines whether the slider is horizontal or vertical; the valid
      # values are Qt::Vertical and Qt::Horizontal.
      def initialize(orientation, parent = nil)
        _initialize(orientation, parent)
        _take_ownership_from_rubyrice(self) if parent
      end

      # @return [Integer]
      #
      # This property holds the interval between tickmarks
      #
      # This is a value interval, not a pixel interval. If it is 0, the slider
      # will choose between singleStep and pageStep.
      #
      # The default value is 0.
      def tick_interval
        _tick_interval
      end

      # @return [QSlider::TickPosition]
      #
      # This property holds the tickmark position for this slider
      #
      # The valid values are described by the QSlider::TickPosition enum.
      #
      # The default value is QSlider::NoTicks.
      def tick_position
        _tick_position
      end

      # @param interval [Integer]
      # @return [nil]
      #
      # Sets the slider's tickInterval property.
      def set_tick_interval(interval)
        _set_tick_interval(interval)
      end

      # @param position [QSlider::TickPosition]
      # @return [nil]
      #
      # Sets the slider's tickInterval property.
      def set_tick_position(position)
        _set_tick_position(position)
      end
    end
  end
end
