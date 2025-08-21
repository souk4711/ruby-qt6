# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtCore")
append_cppflags("-I/usr/include/qt6/QtGui")
append_cppflags("-I/usr/include/qt6/QtWidgets")

abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")
abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")
abort "libQt6Widgets is missing, please install qt6-base" unless have_library("Qt6Widgets")

create_makefile("qt6/qtwidgets")
