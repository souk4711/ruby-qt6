#include "qmediarecorder-rb.hpp"
#include <qmediarecorder.h>
#include <rice/qt6/qenum.hpp>

#include <QIODevice>
#include <QMediaCaptureSession>
#include <QMediaFormat>
#include <QUrl>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMediaRecorder;

void Init_qmediarecorder(Module rb_mQt6QtMultimedia)
{
    rb_cQMediaRecorder =
        // RubyQt6::QtMultimedia::QMediaRecorder
        define_qlass_under<QMediaRecorder, QObject>(rb_mQt6QtMultimedia, "QMediaRecorder")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMediaRecorder::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMediaRecorder, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("actual_location", &QMediaRecorder::actualLocation)
            .define_method("add_meta_data", &QMediaRecorder::addMetaData, Arg("meta_data"))
            .define_method("audio_bit_rate", &QMediaRecorder::audioBitRate)
            .define_method("audio_channel_count", &QMediaRecorder::audioChannelCount)
            .define_method("audio_sample_rate", &QMediaRecorder::audioSampleRate)
            .define_method("auto_stop", &QMediaRecorder::autoStop)
            .define_method("capture_session", &QMediaRecorder::captureSession)
            .define_method("duration", &QMediaRecorder::duration)
            .define_method("encoding_mode", &QMediaRecorder::encodingMode)
            .define_method("error", &QMediaRecorder::error)
            .define_method("error_string", &QMediaRecorder::errorString)
            .define_method("available?", &QMediaRecorder::isAvailable)
            .define_method("media_format", &QMediaRecorder::mediaFormat)
            .define_method("meta_data", &QMediaRecorder::metaData)
            .define_method("output_device", &QMediaRecorder::outputDevice)
            .define_method("output_location", &QMediaRecorder::outputLocation)
            .define_method("quality", &QMediaRecorder::quality)
            .define_method("recorder_state", &QMediaRecorder::recorderState)
            .define_method("set_audio_bit_rate", &QMediaRecorder::setAudioBitRate, Arg("bit_rate"))
            .define_method("set_audio_channel_count", &QMediaRecorder::setAudioChannelCount, Arg("channels"))
            .define_method("set_audio_sample_rate", &QMediaRecorder::setAudioSampleRate, Arg("sample_rate"))
            .define_method("set_auto_stop", &QMediaRecorder::setAutoStop, Arg("auto_stop"))
            .define_method("set_encoding_mode", &QMediaRecorder::setEncodingMode, Arg("mode"))
            .define_method("set_media_format", &QMediaRecorder::setMediaFormat, Arg("format"))
            .define_method("set_meta_data", &QMediaRecorder::setMetaData, Arg("meta_data"))
            .define_method("set_output_device", &QMediaRecorder::setOutputDevice, Arg("device"))
            .define_method("set_output_location", &QMediaRecorder::setOutputLocation, Arg("location"))
            .define_method("set_quality", &QMediaRecorder::setQuality, Arg("quality"))
            .define_method("set_video_bit_rate", &QMediaRecorder::setVideoBitRate, Arg("bit_rate"))
            .define_method("set_video_frame_rate", &QMediaRecorder::setVideoFrameRate, Arg("frame_rate"))
            .define_method<void (QMediaRecorder::*)(const QSize &)>("set_video_resolution", &QMediaRecorder::setVideoResolution, Arg("size"))
            .define_method<void (QMediaRecorder::*)(int, int)>("set_video_resolution", &QMediaRecorder::setVideoResolution, Arg("width"), Arg("height"))
            .define_method("video_bit_rate", &QMediaRecorder::videoBitRate)
            .define_method("video_frame_rate", &QMediaRecorder::videoFrameRate)
            .define_method("video_resolution", &QMediaRecorder::videoResolution)
            // Public Slots
            .define_method("pause", &QMediaRecorder::pause)
            .define_method("record", &QMediaRecorder::record)
            .define_method("stop", &QMediaRecorder::stop);
            // Signals
            // .define_method("actual_location_changed", &QMediaRecorder::actualLocationChanged, Arg("location"))
            // .define_method("audio_bit_rate_changed", &QMediaRecorder::audioBitRateChanged)
            // .define_method("audio_channel_count_changed", &QMediaRecorder::audioChannelCountChanged)
            // .define_method("audio_sample_rate_changed", &QMediaRecorder::audioSampleRateChanged)
            // .define_method("auto_stop_changed", &QMediaRecorder::autoStopChanged)
            // .define_method("duration_changed", &QMediaRecorder::durationChanged, Arg("duration"))
            // .define_method("encoding_mode_changed", &QMediaRecorder::encodingModeChanged)
            // .define_method("error_changed", &QMediaRecorder::errorChanged)
            // .define_method("error_occurred", &QMediaRecorder::errorOccurred, Arg("error"), Arg("error_string"))
            // .define_method("media_format_changed", &QMediaRecorder::mediaFormatChanged)
            // .define_method("meta_data_changed", &QMediaRecorder::metaDataChanged)
            // .define_method("quality_changed", &QMediaRecorder::qualityChanged)
            // .define_method("recorder_state_changed", &QMediaRecorder::recorderStateChanged, Arg("state"))
            // .define_method("video_bit_rate_changed", &QMediaRecorder::videoBitRateChanged)
            // .define_method("video_frame_rate_changed", &QMediaRecorder::videoFrameRateChanged)
            // .define_method("video_resolution_changed", &QMediaRecorder::videoResolutionChanged);

    Data_Type<QMediaRecorder::EncodingMode> rb_cQMediaRecorderEncodingMode =
        // RubyQt6::QtMultimedia::QMediaRecorder::EncodingMode
        define_qenum_under<QMediaRecorder::EncodingMode>(rb_cQMediaRecorder, "EncodingMode");
        define_qenum_value_under(rb_cQMediaRecorderEncodingMode, "ConstantQualityEncoding", QMediaRecorder::EncodingMode::ConstantQualityEncoding);
        define_qenum_value_under(rb_cQMediaRecorderEncodingMode, "ConstantBitRateEncoding", QMediaRecorder::EncodingMode::ConstantBitRateEncoding);
        define_qenum_value_under(rb_cQMediaRecorderEncodingMode, "AverageBitRateEncoding", QMediaRecorder::EncodingMode::AverageBitRateEncoding);
        define_qenum_value_under(rb_cQMediaRecorderEncodingMode, "TwoPassEncoding", QMediaRecorder::EncodingMode::TwoPassEncoding);

    Data_Type<QMediaRecorder::Error> rb_cQMediaRecorderError =
        // RubyQt6::QtMultimedia::QMediaRecorder::Error
        define_qenum_under<QMediaRecorder::Error>(rb_cQMediaRecorder, "Error");
        define_qenum_value_under(rb_cQMediaRecorderError, "NoError", QMediaRecorder::Error::NoError);
        define_qenum_value_under(rb_cQMediaRecorderError, "ResourceError", QMediaRecorder::Error::ResourceError);
        define_qenum_value_under(rb_cQMediaRecorderError, "FormatError", QMediaRecorder::Error::FormatError);
        define_qenum_value_under(rb_cQMediaRecorderError, "OutOfSpaceError", QMediaRecorder::Error::OutOfSpaceError);
        define_qenum_value_under(rb_cQMediaRecorderError, "LocationNotWritable", QMediaRecorder::Error::LocationNotWritable);

    Data_Type<QMediaRecorder::Quality> rb_cQMediaRecorderQuality =
        // RubyQt6::QtMultimedia::QMediaRecorder::Quality
        define_qenum_under<QMediaRecorder::Quality>(rb_cQMediaRecorder, "Quality");
        define_qenum_value_under(rb_cQMediaRecorderQuality, "VeryLowQuality", QMediaRecorder::Quality::VeryLowQuality);
        define_qenum_value_under(rb_cQMediaRecorderQuality, "LowQuality", QMediaRecorder::Quality::LowQuality);
        define_qenum_value_under(rb_cQMediaRecorderQuality, "NormalQuality", QMediaRecorder::Quality::NormalQuality);
        define_qenum_value_under(rb_cQMediaRecorderQuality, "HighQuality", QMediaRecorder::Quality::HighQuality);
        define_qenum_value_under(rb_cQMediaRecorderQuality, "VeryHighQuality", QMediaRecorder::Quality::VeryHighQuality);

    Data_Type<QMediaRecorder::RecorderState> rb_cQMediaRecorderRecorderState =
        // RubyQt6::QtMultimedia::QMediaRecorder::RecorderState
        define_qenum_under<QMediaRecorder::RecorderState>(rb_cQMediaRecorder, "RecorderState");
        define_qenum_value_under(rb_cQMediaRecorderRecorderState, "StoppedState", QMediaRecorder::RecorderState::StoppedState);
        define_qenum_value_under(rb_cQMediaRecorderRecorderState, "RecordingState", QMediaRecorder::RecorderState::RecordingState);
        define_qenum_value_under(rb_cQMediaRecorderRecorderState, "PausedState", QMediaRecorder::RecorderState::PausedState);
}
