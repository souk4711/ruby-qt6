# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtCore")
append_cppflags("-I/usr/include/qt6/QtGui")
append_cppflags("-I/usr/include/qt6/QtQml")
append_cppflags("-I/usr/include/qt6/QtQuick")

abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")
abort "libQt6Gui is missing, please install qt6-base" unless have_library("Qt6Gui")
abort "libQt6Qml is missing, please install qt6-declarative" unless have_library("Qt6Qml")
abort "libQt6Quick is missing, please install qt6-declarative" unless have_library("Qt6Quick")

create_makefile("qt6/qtquick")
