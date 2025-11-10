# frozen_string_literal: true

require_relative "mkmf-rice"

def qmake
  return @qmake if @qmake

  ["qmake6", "qmake"].each do |qmake|
    `#{qmake} -v`
    return @qmake = qmake if $?.success?
  end
  raise "Could not find qmake"
end

def qt_install_headers
  return @qt_install_headers if @qt_install_headers

  r = ENV["QT_INSTALL_HEADERS"] || ""
  return @qt_install_headers = r unless r == ""

  r = `#{qmake} -query QT_INSTALL_HEADERS`.strip
  return @qt_install_headers = r unless r == ""

  raise "Could not determine QT_INSTALL_HEADERS folder"
end

RUBYQT6_CXX_FLAGS = ENV["RUBYQT6_CXX_FLAGS"] || "-Os -fno-fast-math"
append_cppflags(RUBYQT6_CXX_FLAGS) unless RUBYQT6_CXX_FLAGS.strip == ""
