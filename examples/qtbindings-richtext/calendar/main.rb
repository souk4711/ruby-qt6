# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new
window = MainWindow.new
window.resize(640, 256)
window.show
app.exec
