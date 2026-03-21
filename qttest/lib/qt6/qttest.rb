# frozen_string_literal: true

require "qt6/qtcore"

require "qt6/qttest/version"
require "qt6/qttest/qttest"
require_relative "qttest/qttestversion"

require_relative "qttest/qsignalspy"

RubyQt6.initialize!(RubyQt6::QtTest)
