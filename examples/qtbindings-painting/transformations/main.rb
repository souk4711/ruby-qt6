# frozen_string_literal: true

require 'qt6/all'
require_relative 'window'

app = QApplication.new
window = Window.new
window.show
app.exec
