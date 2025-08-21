# frozen_string_literal: true

require 'qt6/qtquick'

include Qt6::QtCore
include Qt6::QtGui
include Qt6::QtQml
include Qt6::QtQuick

app = QGuiApplication.new
view = QQuickView.new
qml_file = QString.new(File.expand_path('app.qml', __dir__))
view.set_source(QUrl.from_local_file(qml_file))
view.show
app.exec
