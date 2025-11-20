# frozen_string_literal: true

require 'qt6/all'
require_relative 'dialog'

QApplication.new
dialog = Dialog.new
dialog.exec
