# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qaudiodevice.html
    class QAudioDevice
      # @!parse class Mode; end
      rubyqt6_declare_enum_under QAudioDevice, QAudioDevice::Mode

      # @!visibility private
      alias_method :_initialize, :initialize

      # @return [QAudioDevice]
      def initialize
        _initialize
      end
    end
  end
end
