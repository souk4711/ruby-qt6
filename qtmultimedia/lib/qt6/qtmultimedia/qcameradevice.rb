# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qcameradevice.html
    class QCameraDevice
      # @!parse class Position; end
      rubyqt6_declare_enum_under QCameraDevice, QCameraDevice::Position

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QCameraDevice]
      def initialize
        _initialize
      end
    end
  end
end
