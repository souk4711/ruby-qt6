#include "qaudiosource-rb.hpp"
#include <qaudiosource.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAudioSource;

void Init_qaudiosource(Module rb_mQt6QtMultimedia)
{
    rb_cQAudioSource =
        // RubyQt6::QtMultimedia::QAudioSource
        define_qlass_under<QAudioSource, QObject>(rb_mQt6QtMultimedia, "QAudioSource")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QAudioSource * { return qobject_cast<QAudioSource *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAudioSource::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAudioSource, const QAudioDevice &, const QAudioFormat &, QObject *>(), Arg("device"), Arg("format"), Arg("parent"))
            // Public Functions
            .define_method("buffer_frame_count", &QAudioSource::bufferFrameCount)
            .define_method("buffer_size", &QAudioSource::bufferSize)
            .define_method("bytes_available", &QAudioSource::bytesAvailable)
            .define_method("elapsed_u_secs", &QAudioSource::elapsedUSecs)
            .define_method("error", &QAudioSource::error)
            .define_method("format", &QAudioSource::format)
            .define_method("frames_available", &QAudioSource::framesAvailable)
            .define_method("null?", &QAudioSource::isNull)
            .define_method("processed_u_secs", &QAudioSource::processedUSecs)
            .define_method("reset", &QAudioSource::reset)
            .define_method("resume", &QAudioSource::resume)
            .define_method("set_buffer_frame_count", &QAudioSource::setBufferFrameCount, Arg("frames"))
            .define_method("set_buffer_size", &QAudioSource::setBufferSize, Arg("bytes"))
            .define_method("set_volume", &QAudioSource::setVolume, Arg("volume"))
            .define_method<QIODevice *(QAudioSource::*)()>("start", &QAudioSource::start)
            .define_method<void (QAudioSource::*)(QIODevice *)>("start", &QAudioSource::start, Arg("device"))
            .define_method("state", &QAudioSource::state)
            .define_method("stop", &QAudioSource::stop)
            .define_method("suspend", &QAudioSource::suspend)
            .define_method("volume", &QAudioSource::volume);
            // Signals
            // .define_method("state_changed", &QAudioSource::stateChanged, Arg("state"));
}
