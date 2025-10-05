# frozen_string_literal: true

require 'qt6/all'

# $ rcc icons.qrc -binary -o icons.qrc.rcc
QResource.register_resource(File.join(__dir__, 'icons.qrc.rcc'))
