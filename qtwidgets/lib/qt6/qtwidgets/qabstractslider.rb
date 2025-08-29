# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractslider.html
    class QAbstractSlider < RubyQt6::QtWidgets::QWidget
      # @return [Boolean]
      #
      # This property holds whether or not a slider shows its values inverted.
      #
      # If this property is false (the default), the minimum and maximum will
      # be shown in its classic position for the inherited widget. If the
      # value is true, the minimum and maximum appear at their opposite
      # location.
      #
      # Note: This property makes most sense for sliders and dials. For scroll
      # bars, the visual effect of the scroll bar subcontrols depends on
      # whether or not the styles understand inverted appearance; most styles
      # ignore this property for scroll bars.
      def inverted_appearance?
        _inverted_appearance?
      end

      # @return [Boolean]
      #
      # This property holds whether or not the slider inverts its wheel and
      # key events.
      #
      # If this property is false, scrolling the mouse wheel "up" and using
      # keys like page up will increase the slider's value towards its
      # maximum. Otherwise pressing page up will move value towards the
      # slider's minimum.
      def inverted_controls?
        _inverted_controls?
      end

      # @return [Integer]
      #
      # This property holds the slider's maximum value
      #
      # When setting this property, the minimum is adjusted if necessary to
      # ensure that the range remains valid. Also the slider's current value
      # is adjusted to be within the new range
      def maximum
        _maximum
      end

      # @return [Integer]
      #
      # This property holds the sliders's minimum value
      #
      # When setting this property, the maximum is adjusted if necessary to
      # ensure that the range remains valid. Also the slider's current value
      # is adjusted to be within the new range.
      def minimum
        _minimum
      end

      # @return [Qt::Orientation]
      #
      # This property holds the orientation of the slider
      #
      # The orientation must be Qt::Vertical (the default) or Qt::Horizontal.
      def orientation
        _orientation
      end

      # @return [Integer]
      #
      # This property holds the page step.
      #
      # The larger of two natural steps that an abstract slider provides and
      # typically corresponds to the user pressing PageUp or PageDown.
      def page_step
        _page_step
      end

      # @return [Integer]
      #
      # This property holds the single step.
      #
      # The smaller of two natural steps that an abstract sliders provides and
      # typically corresponds to the user pressing an arrow key.
      #
      # If the property is modified during an auto repeating key event,
      # behavior is undefined.
      def single_step
        _single_step
      end

      # @return [Boolean]
      #
      # This property holds whether the slider is pressed down.
      #
      # The property is set by subclasses in order to let the abstract slider
      # know whether or not tracking has any effect.
      #
      # Changing the slider down property emits the sliderPressed() and
      # sliderReleased() signals.
      def slider_down?
        _slider_down?
      end

      # @return [Integer]
      #
      # This property holds the current slider position
      #
      # If tracking is enabled (the default), this is identical to value.
      def slider_position
        _slider_position
      end

      # @return [Boolean]
      #
      # This property holds whether slider tracking is enabled
      #
      # If tracking is enabled (the default), the slider emits the
      # valueChanged() signal while the slider is being dragged. If tracking
      # is disabled, the slider emits the valueChanged() signal only when the
      # user releases the slider.
      def tracking?
        _has_tracking?
      end

      # @return [Integer]
      #
      # This property holds the slider's current value
      #
      # The slider forces the value to be within the legal range: minimum <=
      # value <= maximum.
      #
      # Changing the value also changes the sliderPosition.
      def value
        _value
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the slider's invertedAppearance property.
      def set_inverted_appearance(enabled)
        _set_inverted_appearance(enabled)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the slider's invertedControls property.
      def set_inverted_controls(enabled)
        _set_inverted_controls(enabled)
      end

      # @param max [Integer]
      # @return [nil]
      #
      # Sets the slider's maximum property.
      def set_maximum(max)
        _set_maximum(max)
      end

      # @param min [Integer]
      # @return [nil]
      #
      # Sets the slider's minimum property.
      def set_minimum(min)
        _set_minimum(min)
      end

      # @param orientation [Qt::Orientation]
      # @return [nil]
      #
      # Sets the slider's orientation property.
      def set_orientation(orientation)
        _set_orientation(orientation)
      end

      # @param step [Integer]
      # @return [nil]
      #
      # Sets the slider's pageStep property.
      def set_page_step(step)
        _set_page_step(step)
      end

      # @param step [Integer]
      # @return [nil]
      #
      # Sets the slider's singleStep property.
      def set_single_step(step)
        _set_single_step(step)
      end

      # @param down [Boolean]
      # @return [nil]
      #
      # Sets the slider's sliderDown property.
      def set_slider_down(down)
        _set_slider_down(down)
      end

      # @param position [Integer]
      # @return [nil]
      #
      # Sets the slider's sliderPosition property.
      def set_slider_position(position)
        _set_slider_position(position)
      end

      # @param enabled [Boolean]
      # @return [nil]
      #
      # Sets the slider's tracking property.
      def set_tracking(enabled)
        _set_tracking(enabled)
      end

      # @param value [Integer]
      # @return [nil]
      #
      # Sets the slider's value property.
      def set_value(value)
        _set_value(value)
      end

      # @param min [Integer]
      # @param max [Integer]
      # @return [nil]
      #
      # Sets the slider's minimum to min and its maximum to max.
      #
      # If max is smaller than min, min becomes the only legal value.
      def set_range(min, max)
        _set_range(min, max)
      end

      # @param action [QAbstractSlider::SliderAction]
      # @return [nil]
      #
      # Triggers a slider action. Possible actions are SliderSingleStepAdd,
      # SliderSingleStepSub, SliderPageStepAdd, SliderPageStepSub,
      # SliderToMinimum, SliderToMaximum, and SliderMove.
      def trigger_action(action)
        _trigger_action(action)
      end
    end
  end
end
