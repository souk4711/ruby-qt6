# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtqml"
require "qt6/qtquick"
require "qt6/qtquickcontrols2"
require "qt6/qtwidgets"

[
  RubyQt6::Bando,
  RubyQt6::QtCore,
  RubyQt6::QtGui,
  RubyQt6::QtQml,
  RubyQt6::QtQuick,
  RubyQt6::QtQuickControls2,
  RubyQt6::QtWidgets
].each do |mod|
  mod.constants.each do |const|
    next if ::Object.const_defined?(const)
    ::Object.const_set(const, mod.const_get(const)) if const.start_with?("Q")
  end
end
