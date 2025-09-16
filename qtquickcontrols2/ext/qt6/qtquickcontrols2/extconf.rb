# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtQml")
append_cppflags("-I#{includedir}/QtQuick")
append_cppflags("-I#{includedir}/QtQuickControls2")

abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")
abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")
abort "libQt6Qml is missing, please install qt6-declarative" unless have_library("Qt6Qml")
abort "libQt6Quick is missing, please install qt6-declarative" unless have_library("Qt6Quick")
abort "libQt6QuickControls2 is missing, please install qt6-declarative" unless have_library("Qt6QuickControls2")

create_makefile("qt6/qtquickcontrols2")
