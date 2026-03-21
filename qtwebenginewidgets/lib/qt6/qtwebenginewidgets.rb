# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/qtwebenginecore"

require "qt6/qtwebenginewidgets/version"
require "qt6/qtwebenginewidgets/qtwebenginewidgets"
require_relative "qtwebenginewidgets/qtwebenginewidgetsversion"

require_relative "qtwebenginewidgets/qwebengineview"

RubyQt6.initialize!(RubyQt6::QtWebEngineWidgets)
