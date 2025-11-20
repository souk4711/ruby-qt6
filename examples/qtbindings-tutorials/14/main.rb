# frozen_string_literal: true

require 'qt6/all'
require_relative 'gamebrd'

app = QApplication.new
gb = GameBoard.new
gb.set_geometry(100, 100, 500, 355)
gb.show
app.exec
