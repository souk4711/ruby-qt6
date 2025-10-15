# frozen_string_literal: true

require 'qt6/all'
require_relative 'screenshot'

app = QApplication.new(ARGV)
screenshot = Screenshot.new
screenshot.show
app.exec
