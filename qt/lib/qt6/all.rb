# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtqml"
require "qt6/qtquick"
require "qt6/qtquickcontrols2"
require "qt6/qtwidgets"

rubyqt6_include_constants ::Object, RubyQt6::QtCore
rubyqt6_include_constants ::Object, RubyQt6::QtGui
rubyqt6_include_constants ::Object, RubyQt6::QtQml
rubyqt6_include_constants ::Object, RubyQt6::QtQuick
rubyqt6_include_constants ::Object, RubyQt6::QtQuickControls2
rubyqt6_include_constants ::Object, RubyQt6::QtWidgets

::Object.define_method("SIGNAL", RubyQt6::QtCore::QtMetaMacro.instance_method("SIGNAL"))
::Object.define_method("SLOT", RubyQt6::QtCore::QtMetaMacro.instance_method("SLOT"))
