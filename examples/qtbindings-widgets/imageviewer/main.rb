# frozen_string_literal: true

require 'qt6/all'
require_relative 'imageviewer'

app = QApplication.new(ARGV)
image_viewer = ImageViewer.new
image_viewer.show
app.exec
