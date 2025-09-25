# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtWidgets")
abort "libQt6Widgets is missing, please install qt6-base" unless have_library("Qt6Widgets")

create_makefile("qt6/qtwidgets")
