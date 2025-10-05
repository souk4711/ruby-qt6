# frozen_string_literal: true

require 'qt6/all'
require_relative 'lcdrange'

class MyWidget < RubyQt6::Bando::QWidget
  def initialize
    super

    quit = QPushButton.new('Quit')
    quit.set_font(QFont.new('Times', 18, QFont::Bold))
    quit.clicked.connect($qApp, :quit)

    grid = QGridLayout.new
    previous_range = nil
    (0..3).each do |row|
      (0..3).each do |column|
        lcd_range = LCDRange.new(self)
        grid.add_widget(lcd_range, row, column)
        lcd_range.value_changed.connect(previous_range, :set_value) unless previous_range.nil?
        previous_range = lcd_range
      end
    end

    layout = QVBoxLayout.new
    layout.add_widget(quit)
    layout.add_layout(grid)
    set_layout(layout)
  end
end

app = QApplication.new(ARGV)
widget = MyWidget.new
widget.show
app.exec
