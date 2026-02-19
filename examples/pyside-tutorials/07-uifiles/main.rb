# frozen_string_literal: true

require 'qt6/all'

app = QApplication.new
loader = QUiLoader.new
widget = loader.load(QFile.new('./mainwindow.ui'))
widget.show
app.exec
