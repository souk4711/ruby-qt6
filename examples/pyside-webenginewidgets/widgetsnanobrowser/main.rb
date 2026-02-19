# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new
mainwin = MainWindow.new
available_geometry = mainwin.screen.available_geometry
mainwin.resize(available_geometry.width * 2 / 3, available_geometry.height * 2 / 3)
mainwin.show
app.exec
