# frozen_string_literal: true

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

BANDO_INCLUDEDIR = File.expand_path(File.join(__dir__, "../include"))
raise "Could not find bando/_.hpp header" unless find_header("bando/_.hpp", BANDO_INCLUDEDIR)
