# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtqml"
require "qt6/qtquick"
require "qt6/qtquickcontrols2"
require "qt6/qtwidgets"

module RubyQt6
  def self.qt_modules
    constants.grep(/Qt[A-Z]/).map(&->(m) { const_get(m) })
  end
end
