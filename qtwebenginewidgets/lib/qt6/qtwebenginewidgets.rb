# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/qtwebenginecore"

require_relative "qtwebenginewidgets/version"
require_relative "qtwebenginewidgets/qtwebenginewidgets"
require_relative "qtwebenginewidgets/qtwebenginewidgetsversion"

require_relative "qtwebenginewidgets/qwebengineview"

RubyQt6.initialize!(RubyQt6::QtWebEngineWidgets)
