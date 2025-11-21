# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qmediadevices.html
    class QMediaDevices < RubyQt6::QtCore::QObject
      # @!parse
      q_object do
        signal "audioInputsChanged()"
        signal "audioOutputsChanged()"
        signal "videoInputsChanged()"
      end
    end
  end
end
