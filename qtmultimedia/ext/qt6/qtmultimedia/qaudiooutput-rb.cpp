#include "qaudiooutput-rb.hpp"
#include <qaudiooutput.h>

#include <QAudioDevice>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAudioOutput;

void Init_qaudiooutput(Module rb_mQt6QtMultimedia)
{
    rb_cQAudioOutput =
        // RubyQt6::QtMultimedia::QAudioOutput
        define_class_under<QAudioOutput, QObject>(rb_mQt6QtMultimedia, "QAudioOutput")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAudioOutput::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAudioOutput, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("device", &QAudioOutput::device)
            .define_method("muted?", &QAudioOutput::isMuted)
            .define_method("volume", &QAudioOutput::volume)
            // Public Slots
            .define_method("set_device", &QAudioOutput::setDevice, Arg("device"))
            .define_method("set_muted", &QAudioOutput::setMuted, Arg("muted"))
            .define_method("set_volume", &QAudioOutput::setVolume, Arg("volume"));
            // Signals
            // .define_method("device_changed", &QAudioOutput::deviceChanged)
            // .define_method("muted_changed", &QAudioOutput::mutedChanged, Arg("muted"))
            // .define_method("volume_changed", &QAudioOutput::volumeChanged, Arg("volume"));
}
