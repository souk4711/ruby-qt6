# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/qtqml"
require "qt6/qtquick"
require "qt6/qtquickcontrols2"
require "qt6/qtquickwidgets"
require "qt6/qtprintsupport"
require "qt6/qtuitools"
require "qt6/qtdbus" if RUBY_PLATFORM.downcase.include?("linux")

RubyQt6.load_defaults
