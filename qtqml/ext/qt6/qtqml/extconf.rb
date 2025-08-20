# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtQml")

abort "libQt6Qml is missing, please install qt6-declarative" unless have_library("Qt6Qml")

create_makefile("qt6/qtqml")
