# frozen_string_literal: true

require 'qt6/all'

COLORS = [
  ['Red', '#FF0000'],
  ['Green', '#00FF00'],
  ['Blue', '#0000FF'],
  ['Black', '#000000'],
  ['White', '#FFFFFF'],
  ['Electric Green', '#41CD52'],
  ['Dark Blue', '#222840'],
  ['Yellow', '#F9E56d']
].freeze

app = QApplication.new(ARGV)
table = QTableWidget.new(COLORS.length, COLORS[0].length + 1)
table.set_horizontal_header_labels(QStringList.new << 'Name' << 'Hex Code' << 'Color')
COLORS.each_with_index do |(name, code), i|
  item_name = QTableWidgetItem.new(name)
  item_code = QTableWidgetItem.new(code)
  item_color = QTableWidgetItem.new
  item_color.set_background(QBrush.new(QColor.new(code)))
  table.set_item(i, 0, item_name)
  table.set_item(i, 1, item_code)
  table.set_item(i, 2, item_color)
end
table.show
app.exec
