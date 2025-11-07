# frozen_string_literal: true

require 'qt6/all'
require_relative 'configdialog'

QApplication.new(ARGV)
dialog = ConfigDialog.new
dialog.exec
