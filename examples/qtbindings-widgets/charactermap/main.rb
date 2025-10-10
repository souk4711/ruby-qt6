# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new(ARGV)
window = MainWindow.new
window.show
app.exec
