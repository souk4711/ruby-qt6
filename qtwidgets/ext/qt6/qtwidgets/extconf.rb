# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = find_qt6_includedir
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtWidgets")

abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")
abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")
abort "libQt6Widgets is missing, please install qt6-base" unless have_library("Qt6Widgets")

create_makefile("qt6/qtwidgets")
