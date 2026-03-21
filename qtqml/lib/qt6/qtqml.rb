# frozen_string_literal: true

require "qt6/qtcore"

require "qt6/qtqml/version"
require "qt6/qtqml/qtqml"
require_relative "qtqml/qtqmlversion"

require_relative "qtqml/qjsengine"
require_relative "qtqml/qqmlengine"
require_relative "qtqml/qqmlapplicationengine"
require_relative "qtqml/qqmlcontext"

RubyQt6.initialize!(RubyQt6::QtQml)
