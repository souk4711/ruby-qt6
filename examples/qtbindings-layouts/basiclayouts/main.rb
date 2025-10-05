# frozen_string_literal: true

require 'qt6/all'
require_relative 'dialog'

app = QApplication.new(ARGV)
dialog = Dialog.new
dialog.show
app.exec
