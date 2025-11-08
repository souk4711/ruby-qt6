# frozen_string_literal: true

require 'qt6/all'
require_relative 'spinboxdelegate'

app = QApplication.new(ARGV)

delegate = SpinBoxDelegate.new
model = QStandardItemModel.new
model.set_row_count(4)
model.set_column_count(2)

view = QTableView.new
view.set_model(model)
view.set_item_delegate(delegate)
(0...4).each do |row|
  (0...2).each do |column|
    index = model.index(row, column, QModelIndex.new)
    model.set_data(index, QVariant.new((row + 1) * (column + 1)))
  end
end
view.set_window_title('Spin Box Delegate')
view.show

app.exec
