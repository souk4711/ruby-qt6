# frozen_string_literal: true

require 'qt6/all'
require_relative 'finddialog'

QApplication.new(ARGV)
dialog = FindDialog.new
dialog.exec
