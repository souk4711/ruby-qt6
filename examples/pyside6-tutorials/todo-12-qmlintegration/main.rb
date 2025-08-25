# frozen_string_literal: true

require "qt6"

include(*RubyQt6.qt_modules)

QML_IMPORT_NAME = "io.qt.textproperties"
QML_IMPORT_MAJOR_VERSION = 1

class Bridge < QObject
  def getColor(s)
    case s.lower
    when "red"
      "#ef9a9a"
    when "green"
      "#a5d6a7"
    when "blue"
      "#90caf9"
    else
      "white"
    end
  end

  def getSize(s)
    size = int(s * 34)
    max(1, size)
  end

  def getItalic(s)
    s.lower == "italic"
  end

  def getBold(s)
    s.lower == "bold"
  end

  def getUnderline(s)
    s.lower == "underline"
  end
end

app = QGuiApplication.new
QQuickStyle.style = "Material"
engine = QQmlApplicationEngine.new
engine.add_import_path(".")
engine.load_from_module("QmlIntegration", "Main")
app.exec
