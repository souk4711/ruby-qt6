# frozen_string_literal: true

require 'qt6/all'

class LCDRange < RubyQt6::Bando::QWidget
  def initialize
    super

    lcd = QLCDNumber.new(2)
    slider = QSlider.new(Qt::Horizontal)
    slider.set_range(0, 99)
    slider.set_value(0)
    slider.value_changed.connect(lcd, :display)

    layout = QVBoxLayout.new
    layout.add_widget(lcd)
    layout.add_widget(slider)
    set_layout(layout)
  end
end

class MyWidget < RubyQt6::Bando::QWidget
  def initialize
    super

    quit = QPushButton.new('Quit')
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.clicked.connect($qApp, :quit)

    grid = QGridLayout.new
    (0..3).each do |row|
      (0..3).each do |column|
        grid.add_widget(LCDRange.new, row, column)
      end
    end

    layout = QVBoxLayout.new
    layout.add_widget(quit)
    layout.add_layout(grid)
    set_layout(layout)
  end
end

app = QApplication.new
widget = MyWidget.new
widget.show
app.exec
