# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/kcoreaddons"

require_relative "kguiaddons/version"
require_relative "kguiaddons/kguiaddons"
require_relative "kguiaddons/kguiaddonsversion"

require_relative "kguiaddons/kdatevalidator"

RubyQt6.initialize!(RubyQt6::KGuiAddons)
