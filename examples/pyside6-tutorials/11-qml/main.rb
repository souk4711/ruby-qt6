# frozen_string_literal: true

require 'qt6/all'

app = QGuiApplication.new
view = QQuickView.new
view.engine.add_import_path('.')
view.load_from_module('App', 'Main')
view.show
app.exec
