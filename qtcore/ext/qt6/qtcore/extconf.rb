# frozen_string_literal: true

RUBYQT6_RICE_LIB_PATH = File.join(__dir__, "../../../../rice/lib")
if File.exist?(RUBYQT6_RICE_LIB_PATH)
  require File.join(RUBYQT6_RICE_LIB_PATH, "mkmf-rubyqt6.rb")
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
