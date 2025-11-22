#include "qaudiodevice-rb.hpp"
#include <qaudiodevice.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQAudioDevice;

void Init_qaudiodevice(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQAudioDevice =
        // RubyQt6::QtMultimedia::QAudioDevice
        define_class_under<QAudioDevice>(rb_mQt6QtMultimedia, "QAudioDevice")
            // RubyQt6-Defined Functions
            .define_singleton_function("_operator_equal", [](QAudioDevice *lhs, QAudioDevice *rhs) -> bool { return *lhs == *rhs; }, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("_qvariant_register_metatype", []() -> int { return qRegisterMetaType<QAudioDevice>(); })
            .define_singleton_function("_qvariant_from_value", [](const QAudioDevice &value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("_qvariant_to_value", [](const QVariant &qvariant) -> QAudioDevice { return qvariant.value<QAudioDevice>(); })
            // Constructor
            .define_constructor(Constructor<QAudioDevice>())
            // Public Functions
            .define_method("channel_configuration", &QAudioDevice::channelConfiguration)
            .define_method("description", &QAudioDevice::description)
            .define_method("id", &QAudioDevice::id)
            .define_method("default?", &QAudioDevice::isDefault)
            .define_method("format_supported?", &QAudioDevice::isFormatSupported, Arg("format"))
            .define_method("null?", &QAudioDevice::isNull)
            .define_method("maximum_channel_count", &QAudioDevice::maximumChannelCount)
            .define_method("maximum_sample_rate", &QAudioDevice::maximumSampleRate)
            .define_method("minimum_channel_count", &QAudioDevice::minimumChannelCount)
            .define_method("minimum_sample_rate", &QAudioDevice::minimumSampleRate)
            .define_method("mode", &QAudioDevice::mode)
            .define_method("preferred_format", &QAudioDevice::preferredFormat)
            .define_method("supported_sample_formats", &QAudioDevice::supportedSampleFormats);

    Data_Type<QAudioDevice::Mode> rb_cQAudioDeviceMode =
        // RubyQt6::QtMultimedia::QAudioDevice::Mode
        define_qenum_under<QAudioDevice::Mode>(rb_cQAudioDevice, "Mode");
        define_qenum_value_under(rb_cQAudioDeviceMode, "Null", QAudioDevice::Mode::Null);
        define_qenum_value_under(rb_cQAudioDeviceMode, "Input", QAudioDevice::Mode::Input);
        define_qenum_value_under(rb_cQAudioDeviceMode, "Output", QAudioDevice::Mode::Output);
}
