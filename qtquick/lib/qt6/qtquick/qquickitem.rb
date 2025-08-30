# frozen_string_literal: true

module RubyQt6
  module QtQuick
    # @see https://doc.qt.io/qt-6/qquickitem.html
    class QQuickItem < RubyQt6::QtCore::QObject
      include Mixins::QQmlParserStatus
    end
  end
end
