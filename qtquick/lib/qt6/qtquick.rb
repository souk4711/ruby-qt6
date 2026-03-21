# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtqml"

require "qt6/qtquick/version"
require "qt6/qtquick/qtquick"
require_relative "qtquick/qtquickversion"

require_relative "qtquick/qquickitem"
require_relative "qtquick/qquickwindow"
require_relative "qtquick/qquickview"

RubyQt6.initialize!(RubyQt6::QtQuick)
