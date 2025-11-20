# frozen_string_literal: true

require 'qt6/all'
require_relative 'movieplayer'

app = QApplication.new
player = MoviePlayer.new
player.show
app.exec
