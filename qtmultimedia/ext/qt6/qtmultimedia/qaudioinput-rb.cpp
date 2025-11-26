#include "qaudioinput-rb.hpp"
#include <qaudioinput.h>

#include <QAudioDevice>

using namespace Rice;

Rice::Class rb_cQAudioInput;

void Init_qaudioinput(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQAudioInput =
        // RubyQt6::QtMultimedia::QAudioInput
        define_class_under<QAudioInput, QObject>(rb_mQt6QtMultimedia, "QAudioInput")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAudioInput::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QAudioInput, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("device", &QAudioInput::device)
            .define_method("muted?", &QAudioInput::isMuted)
            .define_method("volume", &QAudioInput::volume)
            // Public Slots
            .define_method("set_device", &QAudioInput::setDevice, Arg("device"))
            .define_method("set_muted", &QAudioInput::setMuted, Arg("muted"))
            .define_method("set_volume", &QAudioInput::setVolume, Arg("volume"));
            // Signals
            // .define_method("device_changed", &QAudioInput::deviceChanged)
            // .define_method("muted_changed", &QAudioInput::mutedChanged, Arg("muted"))
            // .define_method("volume_changed", &QAudioInput::volumeChanged, Arg("volume"));
}
