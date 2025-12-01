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

def rubyqt6_config_depend_rubygems(*mods)
  append_cppflags("-I#{qt_install_headers}")
  mods.each { |mod| rubyqt6_config_depend_rubygem(mod) }
end

def rubyqt6_config_depend_rubygem(mod)
  includedir = File.join(qt_install_headers, mod)
  append_cppflags("-I#{includedir}")
end

def rubyqt6_config(mod, pkg:)
  includedir = File.join(qt_install_headers, mod)
  append_cppflags("-I#{includedir}")

  library = mod.sub("Qt", "Qt6")
  message = "Could not find lib#{library}, please install #{pkg}"
  raise message unless find_library(library, nil, qt_install_libs)

  r = (ENV["RUBYQT6_CXXFLAGS"] || "").strip
  append_cppflags(r) if r != ""
end
