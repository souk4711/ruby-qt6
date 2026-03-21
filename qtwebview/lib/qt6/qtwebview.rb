# frozen_string_literal: true

require "qt6/qtcore"

require "qt6/qtwebview/version"
require "qt6/qtwebview/qtwebview"
require_relative "qtwebview/qtwebviewversion"
require_relative "qtwebview/qtwebviewfunctions"

RubyQt6.initialize!(RubyQt6::QtWebView)
