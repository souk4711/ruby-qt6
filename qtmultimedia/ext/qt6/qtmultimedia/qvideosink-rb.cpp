#include "qvideosink-rb.hpp"
#include <qvideosink.h>

#include <QVideoFrame>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQVideoSink;

void Init_qvideosink(Module rb_mQt6QtMultimedia)
{
    rb_cQVideoSink =
        // RubyQt6::QtMultimedia::QVideoSink
        define_qlass_under<QVideoSink, QObject>(rb_mQt6QtMultimedia, "QVideoSink")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QVideoSink::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QVideoSink, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("set_subtitle_text", &QVideoSink::setSubtitleText, Arg("subtitle"))
            .define_method("set_video_frame", &QVideoSink::setVideoFrame, Arg("frame"))
            .define_method("subtitle_text", &QVideoSink::subtitleText)
            .define_method("video_frame", &QVideoSink::videoFrame)
            .define_method("video_size", &QVideoSink::videoSize);
            // Signals
            // .define_method("subtitle_text_changed", &QVideoSink::subtitleTextChanged, Arg("subtitle_text"))
            // .define_method("video_frame_changed", &QVideoSink::videoFrameChanged, Arg("frame"))
            // .define_method("video_size_changed", &QVideoSink::videoSizeChanged);
}
