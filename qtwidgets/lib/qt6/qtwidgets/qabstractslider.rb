# frozen_string_literal: true

module RubyQt6
  module QtWidgets
    # @see https://doc.qt.io/qt-6/qabstractslider.html
    class QAbstractSlider < RubyQt6::QtWidgets::QWidget
      # @!parse class SliderAction; end
      rubyqt6_include_constants QAbstractSlider, QAbstractSlider::SliderAction

      # @!parse
      q_object do
        signal "actionTriggered(int)"
        signal "rangeChanged(int,int)"
        signal "sliderMoved(int)"
        signal "sliderPressed()"
        signal "sliderReleased()"
        signal "valueChanged(int)"
        slot "setOrientation(Qt::Orientation)"
        slot "setRange(int,int)"
        slot "setValue(int)"
      end
    end
  end
end
