# frozen_string_literal: true

require 'qt6/all'
require_relative 'digitalclock'

app = QApplication.new(ARGV)
clock = DigitalClock.new
clock.show
app.exec
