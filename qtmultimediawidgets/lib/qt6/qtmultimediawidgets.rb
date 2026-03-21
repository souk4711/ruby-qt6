# frozen_string_literal: true

require "qt6/qtcore"
require "qt6/qtgui"
require "qt6/qtwidgets"
require "qt6/qtmultimedia"

require "qt6/qtmultimediawidgets/version"
require "qt6/qtmultimediawidgets/qtmultimediawidgets"
require_relative "qtmultimediawidgets/qtmultimediawidgetsversion"

require_relative "qtmultimediawidgets/qvideowidget"

RubyQt6.initialize!(RubyQt6::QtMultimediaWidgets)
