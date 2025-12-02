# frozen_string_literal: true

require_relative "mkmf-rice"

def qmake
  return @qmake if @qmake

  r = (ENV["QMAKE"] || "").strip
  return @qmake = r if r != ""

  ["qmake6", "qmake"].each do |qmake|
    `#{qmake} -v`
    return @qmake = qmake if $?.success?
  end

  raise "Could not find qmake, " \
    "please add qmake to your PATH environment variable"
end

qmake_persistent_props = {}
%w[QT_INSTALL_HEADERS QT_INSTALL_LIBS].each do |name|
  define_method(name.downcase) do
    return qmake_persistent_props[name] if qmake_persistent_props[name]

    r = (ENV[name] || "").strip
    return qmake_persistent_props[name] = r if r != ""

    r = `#{qmake} -query #{name}`.strip
    return qmake_persistent_props[name] = r if r != ""

    raise "Could not determine #{name} folder"
  end
end

def rubyqt6_extconf(mod, depends:)
  # Add optimize cxxflags
  r = (ENV["RUBYQT6_CXXFLAGS"] || "").strip
  append_cppflags(r) if r != ""

  # Add qt6 included directories
  append_cppflags("-I#{qt_install_headers}")
  (depends << mod).each do |name|
    includedir = File.join(qt_install_headers, name)
    append_cppflags("-I#{includedir}")
  end

  # Add qt6 libraries
  (depends << mod).each do |name|
    library = name.sub("Qt", "Qt6")
    message = "Could not find lib#{library}, please install qt6 package"
    raise message unless find_library(library, nil, qt_install_libs)
  end

  # Create Makefile
  gem_name = mod.downcase
  create_makefile("qt6/#{gem_name}/#{gem_name}")
end
