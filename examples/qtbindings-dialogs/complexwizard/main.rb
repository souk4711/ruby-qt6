# frozen_string_literal: true

require 'qt6/all'
require_relative 'licensewizard'

QApplication.new
wizard = LicenseWizard.new
wizard.exec
