#include "qsoundeffect-rb.hpp"
#include <qsoundeffect.h>
#include <rice/qt6/qenum.hpp>

#include <QAudioDevice>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSoundEffect;

void Init_qsoundeffect(Module rb_mQt6QtMultimedia)
{
    rb_cQSoundEffect =
        // RubyQt6::QtMultimedia::QSoundEffect
        define_qlass_under<QSoundEffect, QObject>(rb_mQt6QtMultimedia, "QSoundEffect")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QSoundEffect * { return qobject_cast<QSoundEffect *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSoundEffect::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSoundEffect, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("audio_device", &QSoundEffect::audioDevice)
            .define_method("loaded?", &QSoundEffect::isLoaded)
            .define_method("muted?", &QSoundEffect::isMuted)
            .define_method("playing?", &QSoundEffect::isPlaying)
            .define_method("loop_count", &QSoundEffect::loopCount)
            .define_method("loops_remaining", &QSoundEffect::loopsRemaining)
            .define_method("set_audio_device", &QSoundEffect::setAudioDevice, Arg("device"))
            .define_method("set_loop_count", &QSoundEffect::setLoopCount, Arg("loop_count"))
            .define_method("set_muted", &QSoundEffect::setMuted, Arg("muted"))
            .define_method("set_source", &QSoundEffect::setSource, Arg("url"))
            .define_method("set_volume", &QSoundEffect::setVolume, Arg("volume"))
            .define_method("source", &QSoundEffect::source)
            .define_method("status", &QSoundEffect::status)
            .define_method("volume", &QSoundEffect::volume)
            // Public Slots
            .define_method("play", &QSoundEffect::play)
            .define_method("stop", &QSoundEffect::stop)
            // Signals
            // .define_method("audio_device_changed", &QSoundEffect::audioDeviceChanged)
            // .define_method("loaded_changed", &QSoundEffect::loadedChanged)
            // .define_method("loop_count_changed", &QSoundEffect::loopCountChanged)
            // .define_method("loops_remaining_changed", &QSoundEffect::loopsRemainingChanged)
            // .define_method("muted_changed", &QSoundEffect::mutedChanged)
            // .define_method("playing_changed", &QSoundEffect::playingChanged)
            // .define_method("source_changed", &QSoundEffect::sourceChanged)
            // .define_method("status_changed", &QSoundEffect::statusChanged)
            // .define_method("volume_changed", &QSoundEffect::volumeChanged)
            // Static Public Members
            .define_singleton_function("supported_mime_types", &QSoundEffect::supportedMimeTypes);

    Data_Type<QSoundEffect::Loop> rb_cQSoundEffectLoop =
        // RubyQt6::QtMultimedia::QSoundEffect::Loop
        define_qenum_under<QSoundEffect::Loop>(rb_cQSoundEffect, "Loop");
        define_qenum_value_under(rb_cQSoundEffectLoop, "Infinite", QSoundEffect::Loop::Infinite);

    Data_Type<QSoundEffect::Status> rb_cQSoundEffectStatus =
        // RubyQt6::QtMultimedia::QSoundEffect::Status
        define_qenum_under<QSoundEffect::Status>(rb_cQSoundEffect, "Status");
        define_qenum_value_under(rb_cQSoundEffectStatus, "Null", QSoundEffect::Status::Null);
        define_qenum_value_under(rb_cQSoundEffectStatus, "Loading", QSoundEffect::Status::Loading);
        define_qenum_value_under(rb_cQSoundEffectStatus, "Ready", QSoundEffect::Status::Ready);
        define_qenum_value_under(rb_cQSoundEffectStatus, "Error", QSoundEffect::Status::Error);
}
