# frozen_string_literal: true

require 'qt6/all'
require_relative 'controllerwindow'

app = QApplication.new(ARGV)
controller = ControllerWindow.new
controller.show
app.exec
