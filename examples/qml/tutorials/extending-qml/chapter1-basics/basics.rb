# frozen_string_literal: true

require 'qt6/qtquick'

include Qt6::QtCore
include Qt6::QtGui
include Qt6::QtQml
include Qt6::QtQuick

class PieChart < QQuickPaintedItem
  def initialize(parent=None)
    super
  end

  def paint(painter)
    pen = QPen.new(@color, 2)
    painter.pen = pen
    painter.set_render_hints(QPainter.RenderHint.Antialiasing, true)
    painter.draw_pie(self.bounding_rect.adjusted(1, 1, -1, -1), 90 * 16, 290 * 16)
  end
end

app = QGuiApplication.new
view = QQuickView.new
qml_file = QString.new(File.expand_path('app.qml', __dir__))
view.set_source(QUrl.from_local_file(qml_file))
view.show
app.exec
