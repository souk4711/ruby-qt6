# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/qtqml"
require "qt6/qtquick"

require "qt6/qtquickwidgets/version"
require "qt6/qtquickwidgets/qtquickwidgets"
require_relative "qtquickwidgets/qtquickwidgetsversion"

require_relative "qtquickwidgets/qquickwidget"

RubyQt6.initialize!(RubyQt6::QtQuickWidgets)
