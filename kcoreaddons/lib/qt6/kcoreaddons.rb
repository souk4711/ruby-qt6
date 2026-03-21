# frozen_string_literal: true

require "qt6/qtcore"

require "qt6/kcoreaddons/version"
require "qt6/kcoreaddons/kcoreaddons"
require_relative "kcoreaddons/kcoreaddonsversion"

require_relative "kcoreaddons/kaboutdata"
require_relative "kcoreaddons/kaboutlicense"
require_relative "kcoreaddons/kaboutperson"
require_relative "kcoreaddons/kformat"

RubyQt6.initialize!(RubyQt6::KCoreAddons)
