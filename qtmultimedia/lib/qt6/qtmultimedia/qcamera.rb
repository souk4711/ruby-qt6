# frozen_string_literal: true

module RubyQt6
  module QtMultimedia
    # @see https://doc.qt.io/qt-6/qcamera.html
    class QCamera < RubyQt6::QtCore::QObject
      # @!parse class Error           ; end
      # @!parse class ExposureMode    ; end
      # @!parse class Feature         ; end
      # @!parse class FlashMode       ; end
      # @!parse class FocusMode       ; end
      # @!parse class TorchMode       ; end
      # @!parse class WhiteBalanceMode; end
      rubyqt6_declare_enum_under QCamera, QCamera::Error
      rubyqt6_declare_enum_under QCamera, QCamera::ExposureMode
      rubyqt6_declare_enum_under QCamera, QCamera::Feature, alias: false
      rubyqt6_declare_enum_under QCamera, QCamera::FlashMode
      rubyqt6_declare_enum_under QCamera, QCamera::FocusMode
      rubyqt6_declare_enum_under QCamera, QCamera::TorchMode
      rubyqt6_declare_enum_under QCamera, QCamera::WhiteBalanceMode

      # @!parse
      q_object do
        signal "activeChanged(bool)"
        signal "brightnessChanged()"
        signal "cameraDeviceChanged()"
        signal "cameraFormatChanged()"
        signal "colorTemperatureChanged()"
        signal "contrastChanged()"
        signal "customFocusPointChanged()"
        signal "errorChanged()"
        signal "errorOccurred(QCamera::Error,QString)"
        signal "exposureCompensationChanged(float)"
        signal "exposureModeChanged()"
        signal "exposureTimeChanged(float)"
        signal "flashModeChanged()"
        signal "flashReady(bool)"
        signal "focusDistanceChanged(float)"
        signal "focusModeChanged()"
        signal "focusPointChanged()"
        signal "hueChanged()"
        signal "isoSensitivityChanged(int)"
        signal "manualExposureTimeChanged(float)"
        signal "manualIsoSensitivityChanged(int)"
        signal "maximumZoomFactorChanged(float)"
        signal "minimumZoomFactorChanged(float)"
        signal "saturationChanged()"
        signal "supportedFeaturesChanged()"
        signal "torchModeChanged()"
        signal "whiteBalanceModeChanged()"
        signal "zoomFactorChanged(float)"
        slot "setActive(bool)"
        slot "setAutoExposureTime()"
        slot "setAutoIsoSensitivity()"
        slot "setColorTemperature(int)"
        slot "setExposureCompensation(float)"
        slot "setExposureMode(ExposureMode)"
        slot "setFlashMode(FlashMode)"
        slot "setManualExposureTime(float)"
        slot "setManualIsoSensitivity(int)"
        slot "setTorchMode(TorchMode)"
        slot "setWhiteBalanceMode(WhiteBalanceMode)"
        slot "start()"
        slot "stop()"
        slot "zoomTo(float,float)"
      end

      # @!visibility private
      alias_method :_initialize, :initialize

      # @param parent [QObject]
      # @return [QCamera]
      def initialize(parent = nil)
        _initialize(parent)
        _take_ownership_from_ruby(self)
      end
    end
  end
end
