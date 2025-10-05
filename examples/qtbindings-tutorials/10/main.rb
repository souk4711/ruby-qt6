# frozen_string_literal: true

require 'qt6/all'
require_relative 'lcdrange'
require_relative 'cannon'

class MyWidget < RubyQt6::Bando::QWidget
  def initialize
    super

    quit = QPushButton.new('Quit')
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.clicked.connect($qApp, :quit)

    angle = LCDRange.new(self)
    force = LCDRange.new(self)
    cannon_field = CannonField.new(self)
    angle.set_range(5, 70)
    force.set_range(10, 50)
    angle.value_changed.connect(cannon_field, :set_angle)
    force.value_changed.connect(cannon_field, :set_force)
    cannon_field.angle_changed.connect(angle, :set_value)
    cannon_field.force_changed.connect(force, :set_value)

    left_layout = QVBoxLayout.new
    left_layout.add_widget(angle)
    left_layout.add_widget(force)

    grid_layout = QGridLayout.new
    grid_layout.add_widget(quit, 0, 0)
    grid_layout.add_layout(left_layout, 1, 0)
    grid_layout.add_widget(cannon_field, 1, 1, 2, 1)
    grid_layout.set_column_stretch(1, 10)
    set_layout(grid_layout)

    angle.set_value(60)
    force.set_value(25)
    angle.set_focus
  end
end

app = QApplication.new(ARGV)
widget = MyWidget.new
widget.set_geometry(100, 100, 500, 355)
widget.show
app.exec
