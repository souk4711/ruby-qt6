# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtWidgets")

abort "libQt6Widgets is missing, please install qt6-base" unless have_library("Qt6Widgets")

create_makefile("qt6/qtwidgets")
