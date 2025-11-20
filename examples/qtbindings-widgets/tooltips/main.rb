# frozen_string_literal: true

require 'qt6/all'
require_relative 'sortingbox'

app = QApplication.new
sortingbox = SortingBox.new
sortingbox.show
app.exec
