# frozen_string_literal: true

require 'qt6/all'
require_relative 'classwizard'

QApplication.new(ARGV)
wizard = ClassWizard.new
wizard.exec
