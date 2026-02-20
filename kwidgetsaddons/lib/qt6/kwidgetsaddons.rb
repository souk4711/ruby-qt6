# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/kcoreaddons"
require "qt6/kguiaddons"

require_relative "kwidgetsaddons/version"
require_relative "kwidgetsaddons/kwidgetsaddons"
require_relative "kwidgetsaddons/kwidgetsaddonsversion"

require_relative "kwidgetsaddons/kguiitem"
require_relative "kwidgetsaddons/kmessagebox"
require_relative "kwidgetsaddons/kseparator"

require_relative "bando/kseparator"

RubyQt6.initialize!(RubyQt6::KWidgetsAddons)
