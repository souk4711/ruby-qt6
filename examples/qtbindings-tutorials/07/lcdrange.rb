# frozen_string_literal: true

require 'qt6/all'

class LCDRange < RubyQt6::Bando::QWidget
  q_object do
    signal 'value_changed(int)'
    slot 'set_value(int)'
  end

  def initialize(parent = nil)
    super

    lcd = QLCDNumber.new(2)
    @slider = QSlider.new(Qt::Horizontal)
    @slider.set_range(0, 99)
    @slider.set_value(0)
    @slider.value_changed.connect(lcd, :display)
    @slider.value_changed.connect(self, :value_changed)

    layout = QVBoxLayout.new
    layout.add_widget(lcd)
    layout.add_widget(@slider)
    set_layout(layout)
  end

  def set_value(value)
    @slider.set_value(value)
  end
end
