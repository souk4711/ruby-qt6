# frozen_string_literal: true

require 'qt6/all'
require_relative 'tabdialog'

QApplication.new
tabdialog = TabDialog.new(ARGV[0] || '.')
tabdialog.exec
