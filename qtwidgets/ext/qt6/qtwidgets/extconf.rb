# frozen_string_literal: true

RUBYQT6_RICE_GEM_PATH = Gem::Specification.find_by_name("ruby-qt6-rice").full_gem_path
require File.join(RUBYQT6_RICE_GEM_PATH, "lib/mkmf-rubyqt6.rb")

rubyqt6_config_depend_rubygems("QtCore", "QtGui")
rubyqt6_config("QtWidgets", pkg: "qt6-base")

create_makefile("qt6/qtwidgets/qtwidgets")
