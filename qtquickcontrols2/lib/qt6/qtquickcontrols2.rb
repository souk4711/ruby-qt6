# frozen_string_literal: true

require "qt6/qtcore"

require_relative "qtquickcontrols2/version"
require_relative "qtquickcontrols2/qtquickcontrols2"
require_relative "qtquickcontrols2/qtquickcontrols2version"

require_relative "qtquickcontrols2/qquickstyle"

RubyQt6.initialize!(RubyQt6::QtQuickControls2)
