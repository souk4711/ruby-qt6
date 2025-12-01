# frozen_string_literal: true

RUBYQT6_RICE_GEM_PATH = Gem::Specification.find_by_name("ruby-qt6-rice").full_gem_path
require File.join(RUBYQT6_RICE_GEM_PATH, "lib/mkmf-rubyqt6.rb")

rubyqt6_config_depend_rubygems("QtCore", "QtGui", "QtWidgets", "QtQml", "QtQuick")
rubyqt6_config("QtQuickWidgets", pkg: "qt6-declarative")

create_makefile("qt6/qtquickwidgets/qtquickwidgets")
