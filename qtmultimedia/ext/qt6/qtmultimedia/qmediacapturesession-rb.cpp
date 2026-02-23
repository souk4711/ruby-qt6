#include "qmediacapturesession-rb.hpp"
#include <qmediacapturesession.h>

#include <QAudioBufferInput>
#include <QAudioInput>
#include <QAudioOutput>
#include <QCamera>
#include <QImageCapture>
#include <QMediaRecorder>
#include <QScreenCapture>
#include <QVideoFrameInput>
#include <QVideoSink>
#include <QWindowCapture>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMediaCaptureSession;

void Init_qmediacapturesession(Module rb_mQt6QtMultimedia)
{
    rb_cQMediaCaptureSession =
        // RubyQt6::QtMultimedia::QMediaCaptureSession
        define_qlass_under<QMediaCaptureSession, QObject>(rb_mQt6QtMultimedia, "QMediaCaptureSession")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMediaCaptureSession::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMediaCaptureSession, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("audio_buffer_input", &QMediaCaptureSession::audioBufferInput)
            .define_method("audio_input", &QMediaCaptureSession::audioInput)
            .define_method("audio_output", &QMediaCaptureSession::audioOutput)
            .define_method("camera", &QMediaCaptureSession::camera)
            .define_method("image_capture", &QMediaCaptureSession::imageCapture)
            .define_method("recorder", &QMediaCaptureSession::recorder)
            .define_method("screen_capture", &QMediaCaptureSession::screenCapture)
            .define_method("set_audio_buffer_input", &QMediaCaptureSession::setAudioBufferInput, Arg("input"))
            .define_method("set_audio_input", &QMediaCaptureSession::setAudioInput, Arg("input"))
            .define_method("set_audio_output", &QMediaCaptureSession::setAudioOutput, Arg("output"))
            .define_method("set_camera", &QMediaCaptureSession::setCamera, Arg("camera"))
            .define_method("set_image_capture", &QMediaCaptureSession::setImageCapture, Arg("image_capture"))
            .define_method("set_recorder", &QMediaCaptureSession::setRecorder, Arg("recorder"))
            .define_method("set_screen_capture", &QMediaCaptureSession::setScreenCapture, Arg("screen_capture"))
            .define_method("set_video_frame_input", &QMediaCaptureSession::setVideoFrameInput, Arg("input"))
            .define_method("set_video_output", &QMediaCaptureSession::setVideoOutput, Arg("output"))
            .define_method("set_video_sink", &QMediaCaptureSession::setVideoSink, Arg("sink"))
            .define_method("set_window_capture", &QMediaCaptureSession::setWindowCapture, Arg("window_capture"))
            .define_method("video_frame_input", &QMediaCaptureSession::videoFrameInput)
            .define_method("video_output", &QMediaCaptureSession::videoOutput)
            .define_method("video_sink", &QMediaCaptureSession::videoSink)
            .define_method("window_capture", &QMediaCaptureSession::windowCapture);
            // Signals
            // .define_method("audio_buffer_input_changed", &QMediaCaptureSession::audioBufferInputChanged)
            // .define_method("audio_input_changed", &QMediaCaptureSession::audioInputChanged)
            // .define_method("audio_output_changed", &QMediaCaptureSession::audioOutputChanged)
            // .define_method("camera_changed", &QMediaCaptureSession::cameraChanged)
            // .define_method("image_capture_changed", &QMediaCaptureSession::imageCaptureChanged)
            // .define_method("recorder_changed", &QMediaCaptureSession::recorderChanged)
            // .define_method("screen_capture_changed", &QMediaCaptureSession::screenCaptureChanged)
            // .define_method("video_frame_input_changed", &QMediaCaptureSession::videoFrameInputChanged)
            // .define_method("video_output_changed", &QMediaCaptureSession::videoOutputChanged)
            // .define_method("window_capture_changed", &QMediaCaptureSession::windowCaptureChanged);
}
