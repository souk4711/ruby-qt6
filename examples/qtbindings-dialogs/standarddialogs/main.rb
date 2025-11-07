# frozen_string_literal: true

require 'qt6/all'
require_relative 'dialog'

QApplication.new(ARGV)
dialog = Dialog.new
dialog.exec
