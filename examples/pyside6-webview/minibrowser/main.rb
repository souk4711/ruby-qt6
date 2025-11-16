# frozen_string_literal: true

require 'qt6/all'
require_relative 'rc_qml'

class Utils < RubyQt6::Bando::QObject
  q_object do
    slot 'QUrl from_user_input(QString)'
  end

  def from_user_input(str)
    QUrl.from_user_input(str)
  end
end

QtWebView.initialize

app = QGuiApplication.new(ARGV.empty? ? ['minibrowser'] : ARGV)
QGuiApplication.set_application_display_name(QGuiApplication.translate('main', 'QtWebView Example'))

engine = QQmlApplicationEngine.new
context = engine.root_context
context.set_context_property('utils', Utils.new)
context.set_context_property('initialUrl', QVariant.new(QUrl.new('https://www.qt.io')))

geometry = QGuiApplication.primary_screen.available_geometry
unless QGuiApplication.style_hints.show_is_full_screen
  size = geometry.size * 4 / 5
  offset = (geometry.size - size) / 2
  pos = geometry.top_left + QPoint.new(offset.width, offset.height)
  geometry = QRect.new(pos, size)
end

engine.set_initial_properties(x: geometry.x, y: geometry.y, width: geometry.width, height: geometry.height)
engine.load(QUrl.from_local_file('main.qml'))
app.exec
