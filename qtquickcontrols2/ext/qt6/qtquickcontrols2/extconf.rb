# frozen_string_literal: true

require "mkmf-rice"

QTCORE_LIB_PATH = File.join(__dir__, "../../../../qtcore/lib")
if File.exist?(QTCORE_LIB_PATH)
  require File.join(QTCORE_LIB_PATH, "mkmf-rubyqt6.rb")
else
  require "mkmf-rubyqt6"
end

includedir = qt_install_headers
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir}/QtGui")
append_cppflags("-I#{includedir}/QtQml")
append_cppflags("-I#{includedir}/QtQuick")
append_cppflags("-I#{includedir}/QtQuickControls2")
abort "libQt6QuickControls2 is missing, please install qt6-declarative" unless have_library("Qt6QuickControls2")

create_makefile("qt6/qtquickcontrols2/qtquickcontrols2")
