# frozen_string_literal: true

require "qt6/qtcore"

require_relative "kcoreaddons/version"
require_relative "kcoreaddons/kcoreaddons"
require_relative "kcoreaddons/kcoreaddonsversion"

RubyQt6.initialize!(RubyQt6::KCoreAddons)
