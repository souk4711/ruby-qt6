# frozen_string_literal: true

require 'qt6/all'
require_relative './window'

app = QApplication.new(ARGV)
window = Window.new
window.show
app.exec
