#include "qaudiosink-rb.hpp"
#include <qaudiosink.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAudioSink;

void Init_qaudiosink(Module rb_mQt6QtMultimedia)
{
    rb_cQAudioSink =
        // RubyQt6::QtMultimedia::QAudioSink
        define_qlass_under<QAudioSink, QObject>(rb_mQt6QtMultimedia, "QAudioSink")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAudioSink::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAudioSink, const QAudioDevice &, const QAudioFormat &, QObject *>(), Arg("device"), Arg("format"), Arg("parent"))
            // Public Functions
            .define_method("buffer_frame_count", &QAudioSink::bufferFrameCount)
            .define_method("buffer_size", &QAudioSink::bufferSize)
            .define_method("bytes_free", &QAudioSink::bytesFree)
            .define_method("elapsed_u_secs", &QAudioSink::elapsedUSecs)
            .define_method("error", &QAudioSink::error)
            .define_method("format", &QAudioSink::format)
            .define_method("frames_free", &QAudioSink::framesFree)
            .define_method("null?", &QAudioSink::isNull)
            .define_method("processed_u_secs", &QAudioSink::processedUSecs)
            .define_method("reset", &QAudioSink::reset)
            .define_method("resume", &QAudioSink::resume)
            .define_method("set_buffer_frame_count", &QAudioSink::setBufferFrameCount, Arg("frames_count"))
            .define_method("set_buffer_size", &QAudioSink::setBufferSize, Arg("bytes"))
            .define_method("set_volume", &QAudioSink::setVolume, Arg("volume"))
            .define_method<QIODevice *(QAudioSink::*)()>("start", &QAudioSink::start)
            .define_method<void (QAudioSink::*)(QIODevice *)>("start", &QAudioSink::start, Arg("device"))
            .define_method("state", &QAudioSink::state)
            .define_method("stop", &QAudioSink::stop)
            .define_method("suspend", &QAudioSink::suspend)
            .define_method("volume", &QAudioSink::volume);
            // Signals
            // .define_method("state_changed", &QAudioSink::stateChanged, Arg("state"));
}
