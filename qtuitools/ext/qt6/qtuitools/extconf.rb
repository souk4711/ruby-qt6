# frozen_string_literal: true

RUBYQT6_RICE_GEM_PATH = Gem::Specification.find_by_name("ruby-qt6-rice").full_gem_path
require File.join(RUBYQT6_RICE_GEM_PATH, "lib/mkmf-rubyqt6.rb")

rubyqt6_config_depend_rubygems("QtCore", "QtGui", "QtWidgets")
rubyqt6_config("QtUiTools", pkg: "qt6-tools")

create_makefile("qt6/qtuitools/qtuitools")
