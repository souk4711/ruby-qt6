# frozen_string_literal: true

require 'qt6/all'
require_relative 'dialog'

app = QApplication.new
dialog = Dialog.new
dialog.show
app.exec
