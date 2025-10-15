# frozen_string_literal: true

require 'qt6/all'
require_relative 'movieplayer'

app = QApplication.new(ARGV)
player = MoviePlayer.new
player.show
app.exec
