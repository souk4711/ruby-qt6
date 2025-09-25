# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")

create_makefile("qt6/qtgui")
