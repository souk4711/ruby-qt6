# frozen_string_literal: true

require 'qt6/all'
require_relative 'tetrixwindow'

Kernel.srand
app = QApplication.new(ARGV)
window = TetrixWindow.new
window.show
app.exec
