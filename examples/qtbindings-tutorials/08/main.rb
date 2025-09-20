require 'qt6/all'
require_relative 'lcdrange.rb'
require_relative 'cannon.rb'

class MyWidget < QWidget
  def initialize
    super

    quit = QPushButton.new('Quit')
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.clicked.connect($qApp, :quit)

    angle = LCDRange.new(self)
    cannon_field = CannonField.new(self)
    angle.set_range(5, 70)
    angle.value_changed.connect(cannon_field, :set_angle)
    cannon_field.angle_changed.connect(angle, :set_value)

    grid_layout = QGridLayout.new
    grid_layout.add_widget(quit, 0, 0)
    grid_layout.add_widget(angle, 1, 0)
    grid_layout.add_widget(cannon_field, 1, 1, 2, 1)
    grid_layout.set_column_stretch(1, 10)
    set_layout(grid_layout)

    angle.set_value(60)
    angle.set_focus
  end
end

a = QApplication.new(ARGV)
w = MyWidget.new
w.set_geometry(100, 100, 500, 355)
w.show
a.exec
