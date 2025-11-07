# frozen_string_literal: true

require 'qt6/all'
require_relative 'tabdialog'

QApplication.new(ARGV)
tabdialog = TabDialog.new(ARGV.length >= 1 ? ARGV[0] : '.')
tabdialog.exec
