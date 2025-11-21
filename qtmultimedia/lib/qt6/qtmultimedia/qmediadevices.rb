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

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QMediaDevices]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
