#include "qmediadevices-rb.hpp"
#include <qmediadevices.h>

#include <QList>
#include <QAudioDevice>
#include <QCameraDevice>

using namespace Rice;

Rice::Class rb_cQMediaDevices;

void Init_qmediadevices(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQMediaDevices =
        // RubyQt6::QtMultimedia::QMediaDevices
        define_class_under<QMediaDevices, QObject>(rb_mQt6QtMultimedia, "QMediaDevices")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QMediaDevices::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QMediaDevices, QObject *>(), Arg("parent"))
            // Signals
            // .define_method("audio_inputs_changed", &QMediaDevices::audioInputsChanged)
            // .define_method("audio_outputs_changed", &QMediaDevices::audioOutputsChanged)
            // .define_method("video_inputs_changed", &QMediaDevices::videoInputsChanged)
            // Static Public Members
            .define_singleton_function("audio_inputs", &QMediaDevices::audioInputs)
            .define_singleton_function("audio_outputs", &QMediaDevices::audioOutputs)
            .define_singleton_function("default_audio_input", &QMediaDevices::defaultAudioInput)
            .define_singleton_function("default_audio_output", &QMediaDevices::defaultAudioOutput)
            .define_singleton_function("default_video_input", &QMediaDevices::defaultVideoInput)
            .define_singleton_function("video_inputs", &QMediaDevices::videoInputs);
}
