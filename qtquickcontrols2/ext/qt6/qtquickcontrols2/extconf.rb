# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtQuickControls2")
abort "libQt6QuickControls2 is missing, please install qt6-declarative" unless have_library("Qt6QuickControls2")

create_makefile("qt6/qtquickcontrols2")
