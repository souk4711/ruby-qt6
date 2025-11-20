# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new
window = MainWindow.new
window.resize(640, 480)
window.show
window.create_sample
app.exec
