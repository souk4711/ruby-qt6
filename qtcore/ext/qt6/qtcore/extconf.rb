# frozen_string_literal: true

require "mkmf-rice"
require_relative "../../../lib/mkmf-rubyqt6"

includedir = qt_install_headers
includedir_private = Dir["#{includedir}/QtCore/*.*.*"][0]
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir_private}")
append_cppflags("-I#{includedir_private}/QtCore")
abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")

create_makefile("qt6/qtcore/qtcore")
