# frozen_string_literal: true

require_relative 'slidersgroup'

class Window < RubyQt6::Bando::QWidget
  def initialize
    super

    @horizontal_sliders = SlidersGroup.new(Qt::Horizontal, tr('Horizontal'))
    @vertical_sliders = SlidersGroup.new(Qt::Vertical, tr('Vertical'))

    @stacked_widget = QStackedWidget.new
    @stacked_widget.add_widget(@horizontal_sliders)
    @stacked_widget.add_widget(@vertical_sliders)

    create_controls(tr('Controls'))
    @horizontal_sliders.value_changed.connect(@vertical_sliders, :set_value)
    @vertical_sliders.value_changed.connect(@value_spinbox, :set_value)
    @value_spinbox.value_changed.connect(@horizontal_sliders, :set_value)

    layout = QHBoxLayout.new.tap do |l|
      l.add_widget(@controls_group)
      l.add_widget(@stacked_widget)
    end
    set_layout(layout)

    @minimum_spin_box.set_value 0
    @maximum_spin_box.set_value 20
    @value_spinbox.set_value 5
    set_window_title(tr('Sliders'))
  end

  def create_controls(title)
    @controls_group = QGroupBox.new(title)

    @minimum_label = QLabel.new(tr('Minimum value:'))
    @maximum_label = QLabel.new(tr('Maximum value:'))
    @value_label = QLabel.new(tr('Current value:'))

    @inverted_appearance = QCheckBox.new(tr('Inverted appearance'))
    @inverted_key_bindings = QCheckBox.new(tr('Inverted key bindings'))

    @minimum_spin_box = QSpinBox.new.tap do |s|
      s.set_range(-100, 100)
      s.set_single_step(1)
    end
    @maximum_spin_box = QSpinBox.new.tap do |s|
      s.set_range(-100, 100)
      s.set_single_step(1)
    end
    @value_spinbox = QSpinBox.new.tap do |s|
      s.set_range(-100, 100)
      s.set_single_step(1)
    end

    @orientation_combo = QComboBox.new
    @orientation_combo.add_item(tr('Horizontal slider-like widgets'))
    @orientation_combo.add_item(tr('Vertical slider-like widgets'))

    @orientation_combo.current_index_changed.connect(@stacked_widget, :set_current_index)
    @minimum_spin_box.value_changed.connect(@horizontal_sliders, :set_minimum)
    @minimum_spin_box.value_changed.connect(@vertical_sliders, :set_minimum)
    @maximum_spin_box.value_changed.connect(@horizontal_sliders, :set_maximum)
    @maximum_spin_box.value_changed.connect(@vertical_sliders, :set_maximum)
    @inverted_appearance.toggled.connect(@horizontal_sliders, :invert_appearance)
    @inverted_appearance.toggled.connect(@vertical_sliders, :invert_appearance)
    @inverted_key_bindings.toggled.connect(@horizontal_sliders, :invert_key_bindings)
    @inverted_key_bindings.toggled.connect(@vertical_sliders, :invert_key_bindings)

    controls_layout = QGridLayout.new.tap do |c|
      c.add_widget(@minimum_label, 0, 0)
      c.add_widget(@maximum_label, 1, 0)
      c.add_widget(@value_label, 2, 0)
      c.add_widget(@minimum_spin_box, 0, 1)
      c.add_widget(@maximum_spin_box, 1, 1)
      c.add_widget(@value_spinbox, 2, 1)
      c.add_widget(@inverted_appearance, 0, 2)
      c.add_widget(@inverted_key_bindings, 1, 2)
      c.add_widget(@orientation_combo, 3, 0, 1, 3)
    end
    @controls_group.set_layout(controls_layout)
  end
end
