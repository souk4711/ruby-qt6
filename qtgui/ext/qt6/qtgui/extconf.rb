# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtGui")

abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")

create_makefile("qt6/qtgui")
