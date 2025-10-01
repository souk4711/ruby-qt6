# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtWidgets")
append_cppflags("-I#{includedir}/QtUiTools")
abort "libQt6UiTools is missing, please install qt6-tools" unless have_library("Qt6UiTools")

create_makefile("qt6/qtuitools")
