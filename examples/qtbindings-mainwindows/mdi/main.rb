# frozen_string_literal: true

require 'qt6/all'
require_relative 'mainwindow'

app = QApplication.new
mainwin = MainWindow.new
mainwin.show
app.exec
