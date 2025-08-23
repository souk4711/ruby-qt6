require "qt6/qtquick"

include RubyQt6::QtCore
include RubyQt6::QtGui
include RubyQt6::QtQuick

app = QGuiApplication.new
view = QQuickView.new
view.engine.add_import_path(".")
view.load_from_module("App", "Main")
view.show
app.exec
