# frozen_string_literal: true

require "mkmf-rice"

append_cppflags("-I/usr/include/qt6")
append_cppflags("-I/usr/include/qt6/QtQuick")

abort "libQt6Quick is missing, please install qt6-declarative" unless have_library("Qt6Quick")

create_makefile("qt6/qtquick")
