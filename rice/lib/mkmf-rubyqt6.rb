# frozen_string_literal: true

require_relative "qt6/mkmf-rice"

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
  # Add custom cxxflags
  r = (ENV["RUBYQT6_CXXFLAGS"] || "").strip
  append_cppflags(r) if r != ""

  # Add rubyqt6 cxxflag
  r = "RUBYQT6_BUILD_#{mod.upcase}_LIB"
  append_cppflags("-D#{r}")

  # Add included directories
  append_cppflags("-I#{qt_install_headers}")
  (Array(depends) + Array(mod)).each do |name|
    if name.start_with?("Qt")
      includedir = File.join(qt_install_headers, name)
      append_cppflags("-I#{includedir}")
    elsif name.start_with?("K")
      includedir = File.join("/usr/include/KF6", name)
      append_cppflags("-I#{includedir}")
    end
  end

  # Add libraries
  (Array(depends) + Array(mod)).each do |name|
    if name.start_with?("Qt")
      library = name.sub("Qt", "Qt6")
      message = "Could not find lib#{library}, please install qt6 package"
      raise message unless find_library(library, nil, qt_install_libs)
    elsif name.start_with?("K")
      library = name.sub("K", "KF6")
      message = "Could not find lib#{library}, please install kf6 package"
      raise message unless find_library(library, nil, "/usr/lib")
    end
  end

  # Create Makefile
  name = mod.downcase
  create_makefile("qt6/#{name}/#{name}")
end
