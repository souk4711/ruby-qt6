# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = find_qt6_includedir
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtQml")

abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")
abort "libQt6Qml is missing, please install qt6-declarative" unless have_library("Qt6Qml")

create_makefile("qt6/qtqml")
