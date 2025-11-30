# frozen_string_literal: true

require_relative "mkmf-rice"

def qmake
  return @qmake if @qmake

  ["qmake6", "qmake"].each do |qmake|
    `#{qmake} -v`
    return @qmake = qmake if $?.success?
  end
  raise "Could not find qmake, please add qmake to your PATH environment variable"
end

qmake_persistent_props = {}
%w[QT_INSTALL_HEADERS QT_INSTALL_LIBS].each do |name|
  define_method(name.downcase) do
    return qmake_persistent_props[name] if qmake_persistent_props[name]

    r = (ENV[name] || "").strip
    return qmake_persistent_props[name] = r if r != ""

    r = `#{qmake} -query #{name}`.strip
    return qmake_persistent_props[name] = r if r != ""

    raise "Could not determine #{env} folder"
  end
end

def rubyqt6_cxx_flags
  (ENV["RUBYQT6_CXX_FLAGS"] || "").strip
end

abort "Could not find Qt6Core library" unless find_library("Qt6Core", nil, qt_install_libs)
abort "Could not find QtCore/QtCoreVersion header" unless find_header("QtCore/QtCoreVersion", qt_install_headers)
append_cppflags(rubyqt6_cxx_flags) unless rubyqt6_cxx_flags == ""
