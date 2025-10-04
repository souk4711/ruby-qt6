# frozen_string_literal: true

require "mkmf-rice"

QTCORE_LIB_PATH = File.join(__dir__, "../../../../qtcore/lib")
if File.exist?(QTCORE_LIB_PATH)
  require File.join(QTCORE_LIB_PATH, "mkmf-rubyqt6.rb")
else
  require "mkmf-rubyqt6"
end

includedir = qt_install_headers
includedir_private = Dir["#{includedir}/QtCore/*.*.*"][0]
append_cppflags("-I#{includedir}")
append_cppflags("-I#{includedir}/QtCore")
append_cppflags("-I#{includedir_private}")
append_cppflags("-I#{includedir_private}/QtCore")
abort "libQt6Core is missing, please install qt6-base" unless have_library("Qt6Core")

create_makefile("qt6/qtcore/qtcore")
