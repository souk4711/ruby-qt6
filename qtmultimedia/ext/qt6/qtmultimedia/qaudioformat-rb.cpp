#include "qaudioformat-rb.hpp"
#include <qaudioformat.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQAudioFormat;

void Init_qaudioformat(Module rb_mQt6QtMultimedia)
{
    rb_cQAudioFormat =
        // RubyQt6::QtMultimedia::QAudioFormat
        define_qlass_under<QAudioFormat>(rb_mQt6QtMultimedia, "QAudioFormat")
            // Constructor
            .define_constructor(Constructor<QAudioFormat>())
            // Public Functions
            .define_method("bytes_for_duration", &QAudioFormat::bytesForDuration, Arg("microseconds"))
            .define_method("bytes_for_frames", &QAudioFormat::bytesForFrames, Arg("frame_count"))
            .define_method("bytes_per_frame", &QAudioFormat::bytesPerFrame)
            .define_method("bytes_per_sample", &QAudioFormat::bytesPerSample)
            .define_method<QAudioFormat::ChannelConfig (QAudioFormat::*)() const>("channel_config", &QAudioFormat::channelConfig)
            .define_method("channel_count", &QAudioFormat::channelCount)
            .define_method("channel_offset", &QAudioFormat::channelOffset, Arg("channel"))
            .define_method("duration_for_bytes", &QAudioFormat::durationForBytes, Arg("byte_count"))
            .define_method("duration_for_frames", &QAudioFormat::durationForFrames, Arg("frame_count"))
            .define_method("frames_for_bytes", &QAudioFormat::framesForBytes, Arg("byte_count"))
            .define_method("frames_for_duration", &QAudioFormat::framesForDuration, Arg("microseconds"))
            .define_method("valid?", &QAudioFormat::isValid)
            .define_method("normalized_sample_value", &QAudioFormat::normalizedSampleValue, Arg("sample"))
            .define_method("sample_format", &QAudioFormat::sampleFormat)
            .define_method("sample_rate", &QAudioFormat::sampleRate)
            .define_method("set_channel_config", &QAudioFormat::setChannelConfig, Arg("config"))
            .define_method("set_channel_count", &QAudioFormat::setChannelCount, Arg("channel_count"))
            .define_method("set_sample_format", &QAudioFormat::setSampleFormat, Arg("f"))
            .define_method("set_sample_rate", &QAudioFormat::setSampleRate, Arg("sample_rate"))
            // Static Public Members
            .define_singleton_function("default_channel_config_for_channel_count", &QAudioFormat::defaultChannelConfigForChannelCount, Arg("channel_count"));

    Data_Type<QAudioFormat::AudioChannelPosition> rb_cQAudioFormatAudioChannelPosition =
        // RubyQt6::QtMultimedia::QAudioFormat::AudioChannelPosition
        define_qenum_under<QAudioFormat::AudioChannelPosition>(rb_cQAudioFormat, "AudioChannelPosition");
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "UnknownPosition", QAudioFormat::AudioChannelPosition::UnknownPosition);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "FrontLeft", QAudioFormat::AudioChannelPosition::FrontLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "FrontRight", QAudioFormat::AudioChannelPosition::FrontRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "FrontCenter", QAudioFormat::AudioChannelPosition::FrontCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "LFE", QAudioFormat::AudioChannelPosition::LFE);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BackLeft", QAudioFormat::AudioChannelPosition::BackLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BackRight", QAudioFormat::AudioChannelPosition::BackRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "FrontLeftOfCenter", QAudioFormat::AudioChannelPosition::FrontLeftOfCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "FrontRightOfCenter", QAudioFormat::AudioChannelPosition::FrontRightOfCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BackCenter", QAudioFormat::AudioChannelPosition::BackCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "SideLeft", QAudioFormat::AudioChannelPosition::SideLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "SideRight", QAudioFormat::AudioChannelPosition::SideRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopCenter", QAudioFormat::AudioChannelPosition::TopCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopFrontLeft", QAudioFormat::AudioChannelPosition::TopFrontLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopFrontCenter", QAudioFormat::AudioChannelPosition::TopFrontCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopFrontRight", QAudioFormat::AudioChannelPosition::TopFrontRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopBackLeft", QAudioFormat::AudioChannelPosition::TopBackLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopBackCenter", QAudioFormat::AudioChannelPosition::TopBackCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopBackRight", QAudioFormat::AudioChannelPosition::TopBackRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "LFE2", QAudioFormat::AudioChannelPosition::LFE2);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopSideLeft", QAudioFormat::AudioChannelPosition::TopSideLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "TopSideRight", QAudioFormat::AudioChannelPosition::TopSideRight);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BottomFrontCenter", QAudioFormat::AudioChannelPosition::BottomFrontCenter);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BottomFrontLeft", QAudioFormat::AudioChannelPosition::BottomFrontLeft);
        define_qenum_value_under(rb_cQAudioFormatAudioChannelPosition, "BottomFrontRight", QAudioFormat::AudioChannelPosition::BottomFrontRight);

    Data_Type<QAudioFormat::ChannelConfig> rb_cQAudioFormatChannelConfig =
        // RubyQt6::QtMultimedia::QAudioFormat::ChannelConfig
        define_qenum_under<QAudioFormat::ChannelConfig>(rb_cQAudioFormat, "ChannelConfig");
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigUnknown", QAudioFormat::ChannelConfig::ChannelConfigUnknown);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigMono", QAudioFormat::ChannelConfig::ChannelConfigMono);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigStereo", QAudioFormat::ChannelConfig::ChannelConfigStereo);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfig2Dot1", QAudioFormat::ChannelConfig::ChannelConfig2Dot1);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfig3Dot0", QAudioFormat::ChannelConfig::ChannelConfig3Dot0);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfig3Dot1", QAudioFormat::ChannelConfig::ChannelConfig3Dot1);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigSurround5Dot0", QAudioFormat::ChannelConfig::ChannelConfigSurround5Dot0);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigSurround5Dot1", QAudioFormat::ChannelConfig::ChannelConfigSurround5Dot1);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigSurround7Dot0", QAudioFormat::ChannelConfig::ChannelConfigSurround7Dot0);
        define_qenum_value_under(rb_cQAudioFormatChannelConfig, "ChannelConfigSurround7Dot1", QAudioFormat::ChannelConfig::ChannelConfigSurround7Dot1);

    Data_Type<QAudioFormat::SampleFormat> rb_cQAudioFormatSampleFormat =
        // RubyQt6::QtMultimedia::QAudioFormat::SampleFormat
        define_qenum_under<QAudioFormat::SampleFormat>(rb_cQAudioFormat, "SampleFormat");
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "Unknown", QAudioFormat::SampleFormat::Unknown);
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "UInt8", QAudioFormat::SampleFormat::UInt8);
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "Int16", QAudioFormat::SampleFormat::Int16);
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "Int32", QAudioFormat::SampleFormat::Int32);
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "Float", QAudioFormat::SampleFormat::Float);
        define_qenum_value_under(rb_cQAudioFormatSampleFormat, "NSampleFormats", QAudioFormat::SampleFormat::NSampleFormats);
}
