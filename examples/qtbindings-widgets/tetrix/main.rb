# frozen_string_literal: true

require 'qt6/all'
require_relative 'tetrixwindow'

Kernel.srand
app = QApplication.new
window = TetrixWindow.new
window.show
app.exec
