# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtQGui")
append_cppflags("-I#{includedir}/QtQml")
append_cppflags("-I#{includedir}/QtQuick")
append_cppflags("-I#{includedir}/QtQuickWidgets")
abort "libQt6QuickWidgets is missing, please install qt6-declarative" unless have_library("Qt6QuickWidgets")

create_makefile("qt6/qtquickwidgets")
