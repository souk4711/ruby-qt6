# frozen_string_literal: true

class SlidersGroup < RubyQt6::Bando::QGroupBox
  q_object do
    signal 'value_changed(int)'
    slot 'set_value(int)'
    slot 'set_minimum(int)'
    slot 'set_maximum(int)'
    slot 'invert_appearance(bool)'
    slot 'invert_key_bindings(bool)'
  end

  def initialize(orientation, title, parent = nil)
    super(title, parent)

    @slider = QSlider.new(orientation)
    @slider.set_focus_policy Qt::StrongFocus
    @slider.set_tick_position QSlider::TicksBothSides
    @slider.set_tick_interval 10
    @slider.set_single_step 1

    @scroll_bar = QScrollBar.new(orientation)
    @scroll_bar.set_focus_policy Qt::StrongFocus

    @dial = QDial.new
    @dial.set_focus_policy Qt::StrongFocus

    @slider.value_changed.connect(@scroll_bar, :set_value)
    @scroll_bar.value_changed.connect(@dial, :set_value)
    @dial.value_changed.connect(@slider, :set_value)
    @dial.value_changed.connect(self, :value_changed)

    direction = (orientation == Qt::Horizontal ? QBoxLayout::TopToBottom : QBoxLayout::LeftToRight)

    @sliders_layout = QBoxLayout.new(direction).tap do |l|
      l.add_widget(@slider)
      l.add_widget(@scroll_bar)
      l.add_widget(@dial)
    end
    set_layout(@sliders_layout)
  end

  def set_value(value)
    @slider.set_value value
  end

  def set_minimum(value)
    @slider.set_minimum value
    @scroll_bar.set_minimum value
    @dial.set_minimum value
  end

  def set_maximum(value)
    @slider.set_maximum value
    @scroll_bar.set_maximum value
    @dial.set_maximum value
  end

  def invert_appearance(invert)
    @slider.set_inverted_appearance invert
    @scroll_bar.set_inverted_appearance invert
    @dial.set_inverted_appearance invert
  end

  def invert_key_bindings(invert)
    @slider.set_inverted_controls invert
    @scroll_bar.set_inverted_controls invert
    @dial.set_inverted_controls invert
  end
end
