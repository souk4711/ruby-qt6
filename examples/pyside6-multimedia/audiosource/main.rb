# frozen_string_literal: true

require 'qt6/all'
require_relative 'inputtest'

QApplication.set_application_name('Audio Sources Example')
app = QApplication.new
input = InputTest.new
input.show
app.exec
