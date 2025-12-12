#include "qmediaformat-rb.hpp"
#include <qmediaformat.h>
#include <rice/qt6/qenum.hpp>

#include <QMimeType>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMediaFormat;

void Init_qmediaformat(Module rb_mQt6QtMultimedia)
{
    rb_cQMediaFormat =
        // RubyQt6::QtMultimedia::QMediaFormat
        define_class_under<QMediaFormat>(rb_mQt6QtMultimedia, "QMediaFormat")
            // Constructor
            .define_constructor(Constructor<QMediaFormat, QMediaFormat::FileFormat>(), Arg("format"))
            // Public Functions
            .define_method("audio_codec", &QMediaFormat::audioCodec)
            .define_method("file_format", &QMediaFormat::fileFormat)
            .define_method("supported?", &QMediaFormat::isSupported, Arg("mode"))
            .define_method("mime_type", &QMediaFormat::mimeType)
            .define_method("resolve_for_encoding", &QMediaFormat::resolveForEncoding, Arg("flags"))
            .define_method("set_audio_codec", &QMediaFormat::setAudioCodec, Arg("codec"))
            .define_method("set_file_format", &QMediaFormat::setFileFormat, Arg("f"))
            .define_method("set_video_codec", &QMediaFormat::setVideoCodec, Arg("codec"))
            .define_method("supported_audio_codecs", &QMediaFormat::supportedAudioCodecs, Arg("m"))
            .define_method("supported_file_formats", &QMediaFormat::supportedFileFormats, Arg("m"))
            .define_method("supported_video_codecs", &QMediaFormat::supportedVideoCodecs, Arg("m"))
            .define_method("video_codec", &QMediaFormat::videoCodec)
            // Static Public Members
            .define_singleton_function("audio_codec_description", &QMediaFormat::audioCodecDescription, Arg("codec"))
            .define_singleton_function("audio_codec_name", &QMediaFormat::audioCodecName, Arg("codec"))
            .define_singleton_function("file_format_description", &QMediaFormat::fileFormatDescription, Arg("file_format"))
            .define_singleton_function("file_format_name", &QMediaFormat::fileFormatName, Arg("file_format"))
            .define_singleton_function("video_codec_description", &QMediaFormat::videoCodecDescription, Arg("codec"))
            .define_singleton_function("video_codec_name", &QMediaFormat::videoCodecName, Arg("codec"));

    Data_Type<QMediaFormat::ConversionMode> rb_cQMediaFormatConversionMode =
        // RubyQt6::QtMultimedia::QMediaFormat::ConversionMode
        define_qenum_under<QMediaFormat::ConversionMode>(rb_cQMediaFormat, "ConversionMode");
        define_qenum_value_under(rb_cQMediaFormatConversionMode, "Encode", QMediaFormat::ConversionMode::Encode);
        define_qenum_value_under(rb_cQMediaFormatConversionMode, "Decode", QMediaFormat::ConversionMode::Decode);

    Data_Type<QMediaFormat::FileFormat> rb_cQMediaFormatFileFormat =
        // RubyQt6::QtMultimedia::QMediaFormat::FileFormat
        define_qenum_under<QMediaFormat::FileFormat>(rb_cQMediaFormat, "FileFormat");
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "UnspecifiedFormat", QMediaFormat::FileFormat::UnspecifiedFormat);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "WMV", QMediaFormat::FileFormat::WMV);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "AVI", QMediaFormat::FileFormat::AVI);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "Matroska", QMediaFormat::FileFormat::Matroska);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "MPEG4", QMediaFormat::FileFormat::MPEG4);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "Ogg", QMediaFormat::FileFormat::Ogg);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "QuickTime", QMediaFormat::FileFormat::QuickTime);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "WebM", QMediaFormat::FileFormat::WebM);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "Mpeg4Audio", QMediaFormat::FileFormat::Mpeg4Audio);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "AAC", QMediaFormat::FileFormat::AAC);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "WMA", QMediaFormat::FileFormat::WMA);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "MP3", QMediaFormat::FileFormat::MP3);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "FLAC", QMediaFormat::FileFormat::FLAC);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "Wave", QMediaFormat::FileFormat::Wave);
        define_qenum_value_under(rb_cQMediaFormatFileFormat, "LastFileFormat", QMediaFormat::FileFormat::LastFileFormat);

    Data_Type<QMediaFormat::ResolveFlags> rb_cQMediaFormatResolveFlags =
        // RubyQt6::QtMultimedia::QMediaFormat::ResolveFlags
        define_qenum_under<QMediaFormat::ResolveFlags>(rb_cQMediaFormat, "ResolveFlags");
        define_qenum_value_under(rb_cQMediaFormatResolveFlags, "NoFlags", QMediaFormat::ResolveFlags::NoFlags);
        define_qenum_value_under(rb_cQMediaFormatResolveFlags, "RequiresVideo", QMediaFormat::ResolveFlags::RequiresVideo);

    Data_Type<QMediaFormat::AudioCodec> rb_cQMediaFormatAudioCodec =
        // RubyQt6::QtMultimedia::QMediaFormat::AudioCodec
        define_qenum_under<QMediaFormat::AudioCodec>(rb_cQMediaFormat, "AudioCodec");
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "Unspecified", QMediaFormat::AudioCodec::Unspecified);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "MP3", QMediaFormat::AudioCodec::MP3);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "AAC", QMediaFormat::AudioCodec::AAC);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "AC3", QMediaFormat::AudioCodec::AC3);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "EAC3", QMediaFormat::AudioCodec::EAC3);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "FLAC", QMediaFormat::AudioCodec::FLAC);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "DolbyTrueHD", QMediaFormat::AudioCodec::DolbyTrueHD);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "Opus", QMediaFormat::AudioCodec::Opus);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "Vorbis", QMediaFormat::AudioCodec::Vorbis);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "Wave", QMediaFormat::AudioCodec::Wave);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "WMA", QMediaFormat::AudioCodec::WMA);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "ALAC", QMediaFormat::AudioCodec::ALAC);
        define_qenum_value_under(rb_cQMediaFormatAudioCodec, "LastAudioCodec", QMediaFormat::AudioCodec::LastAudioCodec);

    Data_Type<QMediaFormat::VideoCodec> rb_cQMediaFormatVideoCodec =
        // RubyQt6::QtMultimedia::QMediaFormat::VideoCodec
        define_qenum_under<QMediaFormat::VideoCodec>(rb_cQMediaFormat, "VideoCodec");
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "Unspecified", QMediaFormat::VideoCodec::Unspecified);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "MPEG1", QMediaFormat::VideoCodec::MPEG1);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "MPEG2", QMediaFormat::VideoCodec::MPEG2);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "MPEG4", QMediaFormat::VideoCodec::MPEG4);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "H264", QMediaFormat::VideoCodec::H264);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "H265", QMediaFormat::VideoCodec::H265);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "VP8", QMediaFormat::VideoCodec::VP8);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "VP9", QMediaFormat::VideoCodec::VP9);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "AV1", QMediaFormat::VideoCodec::AV1);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "Theora", QMediaFormat::VideoCodec::Theora);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "WMV", QMediaFormat::VideoCodec::WMV);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "MotionJPEG", QMediaFormat::VideoCodec::MotionJPEG);
        define_qenum_value_under(rb_cQMediaFormatVideoCodec, "LastVideoCodec", QMediaFormat::VideoCodec::LastVideoCodec);
}
