# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new(ARGV)
window = MainWindow.new
window.resize(640, 512)
window.show
window.open_file('examples/example')
app.exec
