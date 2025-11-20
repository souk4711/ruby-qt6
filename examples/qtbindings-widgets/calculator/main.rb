# frozen_string_literal: true

require 'qt6/all'
require_relative 'calculator'

app = QApplication.new
calc = Calculator.new
calc.show
app.exec
