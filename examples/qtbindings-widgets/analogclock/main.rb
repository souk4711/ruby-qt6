# frozen_string_literal: true

require 'qt6/all'
require_relative 'analogclock'

app = QApplication.new
clock = AnalogClock.new
clock.show
app.exec
