# frozen_string_literal: true

require "mkmf-rice"
require "mkmf-rubyqt6"

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtQml")
append_cppflags("-I#{includedir}/QtQuick")
abort "libQt6Quick is missing, please install qt6-declarative" unless have_library("Qt6Quick")

create_makefile("qt6/qtquick/qtquick")
