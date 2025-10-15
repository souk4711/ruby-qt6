# frozen_string_literal: true

module RubyQt6
  module QtGui
    # @see https://doc.qt.io/qt-6/qscreen.html
    class QScreen < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "availableGeometryChanged(QRect)"
        signal "geometryChanged(QRect)"
        signal "logicalDotsPerInchChanged(double)"
        signal "orientationChanged(Qt::ScreenOrientation)"
        signal "physicalDotsPerInchChanged(double)"
        signal "physicalSizeChanged(QSizeF)"
        signal "primaryOrientationChanged(Qt::ScreenOrientation)"
        signal "refreshRateChanged(double)"
        signal "virtualGeometryChanged(QRect)"
      end
    end
  end
end
