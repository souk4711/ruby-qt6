# frozen_string_literal: true

RUBYQT6_RICE_GEM_PATH = Gem::Specification.find_by_name("ruby-qt6-rice").full_gem_path
require File.join(RUBYQT6_RICE_GEM_PATH, "lib/mkmf-rubyqt6.rb")

includedir_private = Dir["#{qt_install_headers}/QtCore/*.*.*"][0]
append_cppflags("-I#{includedir_private}")
append_cppflags("-I#{includedir_private}/QtCore")

rubyqt6_extconf("QtCore", depends: [])
