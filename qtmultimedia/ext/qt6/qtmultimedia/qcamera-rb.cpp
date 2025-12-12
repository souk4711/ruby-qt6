#include "qcamera-rb.hpp"
#include <qcamera.h>
#include <rice/qt6/qenum.hpp>

#include <QMediaCaptureSession>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCamera;

void Init_qcamera(Module rb_mQt6QtMultimedia)
{
    rb_cQCamera =
        // RubyQt6::QtMultimedia::QCamera
        define_class_under<QCamera, QObject>(rb_mQt6QtMultimedia, "QCamera")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QCamera::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QCamera, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("camera_device", &QCamera::cameraDevice)
            .define_method("camera_format", &QCamera::cameraFormat)
            .define_method("capture_session", &QCamera::captureSession)
            .define_method("color_temperature", &QCamera::colorTemperature)
            .define_method("custom_focus_point", &QCamera::customFocusPoint)
            .define_method("error", &QCamera::error)
            .define_method("error_string", &QCamera::errorString)
            .define_method("exposure_compensation", &QCamera::exposureCompensation)
            .define_method("exposure_mode", &QCamera::exposureMode)
            .define_method("exposure_time", &QCamera::exposureTime)
            .define_method("flash_mode", &QCamera::flashMode)
            .define_method("focus_distance", &QCamera::focusDistance)
            .define_method("focus_mode", &QCamera::focusMode)
            .define_method("focus_point", &QCamera::focusPoint)
            .define_method("active?", &QCamera::isActive)
            .define_method("available?", &QCamera::isAvailable)
            .define_method("exposure_mode_supported?", &QCamera::isExposureModeSupported, Arg("mode"))
            .define_method("flash_mode_supported?", &QCamera::isFlashModeSupported, Arg("mode"))
            .define_method("flash_ready?", &QCamera::isFlashReady)
            .define_method("focus_mode_supported?", &QCamera::isFocusModeSupported, Arg("mode"))
            .define_method("torch_mode_supported?", &QCamera::isTorchModeSupported, Arg("mode"))
            .define_method("white_balance_mode_supported?", &QCamera::isWhiteBalanceModeSupported, Arg("mode"))
            .define_method("iso_sensitivity", &QCamera::isoSensitivity)
            .define_method("manual_exposure_time", &QCamera::manualExposureTime)
            .define_method("manual_iso_sensitivity", &QCamera::manualIsoSensitivity)
            .define_method("maximum_exposure_time", &QCamera::maximumExposureTime)
            .define_method("maximum_iso_sensitivity", &QCamera::maximumIsoSensitivity)
            .define_method("maximum_zoom_factor", &QCamera::maximumZoomFactor)
            .define_method("minimum_exposure_time", &QCamera::minimumExposureTime)
            .define_method("minimum_iso_sensitivity", &QCamera::minimumIsoSensitivity)
            .define_method("minimum_zoom_factor", &QCamera::minimumZoomFactor)
            .define_method("set_camera_device", &QCamera::setCameraDevice, Arg("camera_device"))
            .define_method("set_camera_format", &QCamera::setCameraFormat, Arg("format"))
            .define_method("set_custom_focus_point", &QCamera::setCustomFocusPoint, Arg("point"))
            .define_method("set_focus_distance", &QCamera::setFocusDistance, Arg("d"))
            .define_method("set_focus_mode", &QCamera::setFocusMode, Arg("mode"))
            .define_method("set_zoom_factor", &QCamera::setZoomFactor, Arg("factor"))
            .define_method("supported_features", &QCamera::supportedFeatures)
            .define_method("torch_mode", &QCamera::torchMode)
            .define_method("white_balance_mode", &QCamera::whiteBalanceMode)
            .define_method("zoom_factor", &QCamera::zoomFactor)
            // Public Slots
            .define_method("set_active", &QCamera::setActive, Arg("active"))
            .define_method("set_auto_exposure_time", &QCamera::setAutoExposureTime)
            .define_method("set_auto_iso_sensitivity", &QCamera::setAutoIsoSensitivity)
            .define_method("set_color_temperature", &QCamera::setColorTemperature, Arg("color_temperature"))
            .define_method("set_exposure_compensation", &QCamera::setExposureCompensation, Arg("ev"))
            .define_method("set_exposure_mode", &QCamera::setExposureMode, Arg("mode"))
            .define_method("set_flash_mode", &QCamera::setFlashMode, Arg("mode"))
            .define_method("set_manual_exposure_time", &QCamera::setManualExposureTime, Arg("seconds"))
            .define_method("set_manual_iso_sensitivity", &QCamera::setManualIsoSensitivity, Arg("iso"))
            .define_method("set_torch_mode", &QCamera::setTorchMode, Arg("mode"))
            .define_method("set_white_balance_mode", &QCamera::setWhiteBalanceMode, Arg("mode"))
            .define_method("start", &QCamera::start)
            .define_method("stop", &QCamera::stop)
            .define_method("zoom_to", &QCamera::zoomTo, Arg("zoom"), Arg("rate"));
            // Signals
            // .define_method("active_changed", &QCamera::activeChanged, Arg("active"))
            // .define_method("brightness_changed", &QCamera::brightnessChanged)
            // .define_method("camera_device_changed", &QCamera::cameraDeviceChanged)
            // .define_method("camera_format_changed", &QCamera::cameraFormatChanged)
            // .define_method("color_temperature_changed", &QCamera::colorTemperatureChanged)
            // .define_method("contrast_changed", &QCamera::contrastChanged)
            // .define_method("custom_focus_point_changed", &QCamera::customFocusPointChanged)
            // .define_method("error_changed", &QCamera::errorChanged)
            // .define_method("error_occurred", &QCamera::errorOccurred, Arg("error"), Arg("error_string"))
            // .define_method("exposure_compensation_changed", &QCamera::exposureCompensationChanged, Arg("c"))
            // .define_method("exposure_mode_changed", &QCamera::exposureModeChanged)
            // .define_method("exposure_time_changed", &QCamera::exposureTimeChanged, Arg("speed"))
            // .define_method("flash_mode_changed", &QCamera::flashModeChanged)
            // .define_method("flash_ready", &QCamera::flashReady, Arg("ready"))
            // .define_method("focus_distance_changed", &QCamera::focusDistanceChanged, Arg("d"))
            // .define_method("focus_mode_changed", &QCamera::focusModeChanged)
            // .define_method("focus_point_changed", &QCamera::focusPointChanged)
            // .define_method("hue_changed", &QCamera::hueChanged)
            // .define_method("iso_sensitivity_changed", &QCamera::isoSensitivityChanged, Arg("iso"))
            // .define_method("manual_exposure_time_changed", &QCamera::manualExposureTimeChanged, Arg("speed"))
            // .define_method("manual_iso_sensitivity_changed", &QCamera::manualIsoSensitivityChanged, Arg("iso"))
            // .define_method("maximum_zoom_factor_changed", &QCamera::maximumZoomFactorChanged, Arg("factor"))
            // .define_method("minimum_zoom_factor_changed", &QCamera::minimumZoomFactorChanged, Arg("factor"))
            // .define_method("saturation_changed", &QCamera::saturationChanged)
            // .define_method("supported_features_changed", &QCamera::supportedFeaturesChanged)
            // .define_method("torch_mode_changed", &QCamera::torchModeChanged)
            // .define_method("white_balance_mode_changed", &QCamera::whiteBalanceModeChanged)
            // .define_method("zoom_factor_changed", &QCamera::zoomFactorChanged, Arg("factor"));

    Data_Type<QCamera::Error> rb_cQCameraError =
        // RubyQt6::QtMultimedia::QCamera::Error
        define_qenum_under<QCamera::Error>(rb_cQCamera, "Error");
        define_qenum_value_under(rb_cQCameraError, "NoError", QCamera::Error::NoError);
        define_qenum_value_under(rb_cQCameraError, "CameraError", QCamera::Error::CameraError);

    Data_Type<QCamera::ExposureMode> rb_cQCameraExposureMode =
        // RubyQt6::QtMultimedia::QCamera::ExposureMode
        define_qenum_under<QCamera::ExposureMode>(rb_cQCamera, "ExposureMode");
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureAuto", QCamera::ExposureMode::ExposureAuto);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureManual", QCamera::ExposureMode::ExposureManual);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposurePortrait", QCamera::ExposureMode::ExposurePortrait);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureNight", QCamera::ExposureMode::ExposureNight);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureSports", QCamera::ExposureMode::ExposureSports);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureSnow", QCamera::ExposureMode::ExposureSnow);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureBeach", QCamera::ExposureMode::ExposureBeach);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureAction", QCamera::ExposureMode::ExposureAction);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureLandscape", QCamera::ExposureMode::ExposureLandscape);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureNightPortrait", QCamera::ExposureMode::ExposureNightPortrait);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureTheatre", QCamera::ExposureMode::ExposureTheatre);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureSunset", QCamera::ExposureMode::ExposureSunset);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureSteadyPhoto", QCamera::ExposureMode::ExposureSteadyPhoto);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureFireworks", QCamera::ExposureMode::ExposureFireworks);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureParty", QCamera::ExposureMode::ExposureParty);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureCandlelight", QCamera::ExposureMode::ExposureCandlelight);
        define_qenum_value_under(rb_cQCameraExposureMode, "ExposureBarcode", QCamera::ExposureMode::ExposureBarcode);

    Data_Type<QCamera::Feature> rb_cQCameraFeature =
        // RubyQt6::QtMultimedia::QCamera::Feature
        define_qenum_under<QCamera::Feature>(rb_cQCamera, "Feature");
        define_qenum_value_under(rb_cQCameraFeature, "ColorTemperature", QCamera::Feature::ColorTemperature);
        define_qenum_value_under(rb_cQCameraFeature, "ExposureCompensation", QCamera::Feature::ExposureCompensation);
        define_qenum_value_under(rb_cQCameraFeature, "IsoSensitivity", QCamera::Feature::IsoSensitivity);
        define_qenum_value_under(rb_cQCameraFeature, "ManualExposureTime", QCamera::Feature::ManualExposureTime);
        define_qenum_value_under(rb_cQCameraFeature, "CustomFocusPoint", QCamera::Feature::CustomFocusPoint);
        define_qenum_value_under(rb_cQCameraFeature, "FocusDistance", QCamera::Feature::FocusDistance);


    Data_Type<QCamera::FlashMode> rb_cQCameraFlashMode =
        // RubyQt6::QtMultimedia::QCamera::FlashMode
        define_qenum_under<QCamera::FlashMode>(rb_cQCamera, "FlashMode");
        define_qenum_value_under(rb_cQCameraFlashMode, "FlashOff", QCamera::FlashMode::FlashOff);
        define_qenum_value_under(rb_cQCameraFlashMode, "FlashOn", QCamera::FlashMode::FlashOn);
        define_qenum_value_under(rb_cQCameraFlashMode, "FlashAuto", QCamera::FlashMode::FlashAuto);

    Data_Type<QCamera::FocusMode> rb_cQCameraFocusMode =
        // RubyQt6::QtMultimedia::QCamera::FocusMode
        define_qenum_under<QCamera::FocusMode>(rb_cQCamera, "FocusMode");
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeAuto", QCamera::FocusMode::FocusModeAuto);
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeAutoNear", QCamera::FocusMode::FocusModeAutoNear);
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeAutoFar", QCamera::FocusMode::FocusModeAutoFar);
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeHyperfocal", QCamera::FocusMode::FocusModeHyperfocal);
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeInfinity", QCamera::FocusMode::FocusModeInfinity);
        define_qenum_value_under(rb_cQCameraFocusMode, "FocusModeManual", QCamera::FocusMode::FocusModeManual);

    Data_Type<QCamera::TorchMode> rb_cQCameraTorchMode =
        // RubyQt6::QtMultimedia::QCamera::TorchMode
        define_qenum_under<QCamera::TorchMode>(rb_cQCamera, "TorchMode");
        define_qenum_value_under(rb_cQCameraTorchMode, "TorchOff", QCamera::TorchMode::TorchOff);
        define_qenum_value_under(rb_cQCameraTorchMode, "TorchOn", QCamera::TorchMode::TorchOn);
        define_qenum_value_under(rb_cQCameraTorchMode, "TorchAuto", QCamera::TorchMode::TorchAuto);

    Data_Type<QCamera::WhiteBalanceMode> rb_cQCameraWhiteBalanceMode =
        // RubyQt6::QtMultimedia::QCamera::WhiteBalanceMode
        define_qenum_under<QCamera::WhiteBalanceMode>(rb_cQCamera, "WhiteBalanceMode");
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceAuto", QCamera::WhiteBalanceMode::WhiteBalanceAuto);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceManual", QCamera::WhiteBalanceMode::WhiteBalanceManual);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceSunlight", QCamera::WhiteBalanceMode::WhiteBalanceSunlight);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceCloudy", QCamera::WhiteBalanceMode::WhiteBalanceCloudy);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceShade", QCamera::WhiteBalanceMode::WhiteBalanceShade);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceTungsten", QCamera::WhiteBalanceMode::WhiteBalanceTungsten);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceFluorescent", QCamera::WhiteBalanceMode::WhiteBalanceFluorescent);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceFlash", QCamera::WhiteBalanceMode::WhiteBalanceFlash);
        define_qenum_value_under(rb_cQCameraWhiteBalanceMode, "WhiteBalanceSunset", QCamera::WhiteBalanceMode::WhiteBalanceSunset);
}
