# frozen_string_literal: true

require 'qt6/all'

app = QApplication.new

model = QFileSystemModel.new
model.set_root_path(QDir.current_path)

tree = QTreeView.new
tree.set_model(model)
tree.set_root_index(model.index(QDir.current_path))
tree.set_window_title(QObject.tr('Dir View'))
tree.resize(640, 480)
tree.show

app.exec
