# frozen_string_literal: true

require 'qt6/all'

TREE_DATA = {
  'Project A' => ['file_a.py', 'file_a.txt', 'something.xls'],
  'Project B' => ['file_b.csv', 'photo.jpg'],
  'Project C' => []
}.freeze

app = QApplication.new(ARGV)
tree = QTreeWidget.new
tree.set_column_count(2)
tree.set_header_labels(QStringList.new << 'Name' << 'Type')
TREE_DATA.reverse_each do |key, values|
  item = QTreeWidgetItem.new(QStringList.new << key)
  values.each do |value|
    ext = value.split('.')[-1].upcase
    child = QTreeWidgetItem.new(QStringList.new << value << ext)
    item.add_child(child)
  end
  tree.insert_top_level_item(0, item)
end
tree.show
app.exec
