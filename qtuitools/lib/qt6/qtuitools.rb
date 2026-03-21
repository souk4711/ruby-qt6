# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"

require "qt6/qtuitools/version"
require "qt6/qtuitools/qtuitools"
require_relative "qtuitools/qtuitoolsversion"

require_relative "qtuitools/quiloader"

RubyQt6.initialize!(RubyQt6::QtUiTools)
