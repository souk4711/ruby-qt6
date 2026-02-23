#include "qmediametadata-rb.hpp"
#include <qmediametadata.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMediaMetaData;

void Init_qmediametadata(Module rb_mQt6QtMultimedia)
{
    rb_cQMediaMetaData =
        // RubyQt6::QtMultimedia::QMediaMetaData
        define_qlass_under<QMediaMetaData>(rb_mQt6QtMultimedia, "QMediaMetaData")
            // Constructor
            .define_constructor(Constructor<QMediaMetaData>())
            // Public Functions
            .define_method("clear", &QMediaMetaData::clear)
            .define_method("insert", &QMediaMetaData::insert, Arg("k"), Arg("value"))
            .define_method("empty?", &QMediaMetaData::isEmpty)
            .define_method("keys", &QMediaMetaData::keys)
            .define_method("remove", &QMediaMetaData::remove, Arg("k"))
            .define_method("string_value", &QMediaMetaData::stringValue, Arg("k"))
            .define_method("value", &QMediaMetaData::value, Arg("k"));

    Data_Type<QMediaMetaData::Key> rb_cQMediaMetaDataKey =
        // RubyQt6::QtMultimedia::QMediaMetaData::Key
        define_qenum_under<QMediaMetaData::Key>(rb_cQMediaMetaData, "Key");
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Title", QMediaMetaData::Key::Title);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Author", QMediaMetaData::Key::Author);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Comment", QMediaMetaData::Key::Comment);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Description", QMediaMetaData::Key::Description);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Genre", QMediaMetaData::Key::Genre);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Date", QMediaMetaData::Key::Date);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Language", QMediaMetaData::Key::Language);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Publisher", QMediaMetaData::Key::Publisher);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Copyright", QMediaMetaData::Key::Copyright);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Url", QMediaMetaData::Key::Url);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Duration", QMediaMetaData::Key::Duration);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "MediaType", QMediaMetaData::Key::MediaType);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "FileFormat", QMediaMetaData::Key::FileFormat);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "AudioBitRate", QMediaMetaData::Key::AudioBitRate);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "AudioCodec", QMediaMetaData::Key::AudioCodec);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "VideoBitRate", QMediaMetaData::Key::VideoBitRate);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "VideoCodec", QMediaMetaData::Key::VideoCodec);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "VideoFrameRate", QMediaMetaData::Key::VideoFrameRate);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "AlbumTitle", QMediaMetaData::Key::AlbumTitle);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "AlbumArtist", QMediaMetaData::Key::AlbumArtist);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "ContributingArtist", QMediaMetaData::Key::ContributingArtist);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "TrackNumber", QMediaMetaData::Key::TrackNumber);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Composer", QMediaMetaData::Key::Composer);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "LeadPerformer", QMediaMetaData::Key::LeadPerformer);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "ThumbnailImage", QMediaMetaData::Key::ThumbnailImage);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "CoverArtImage", QMediaMetaData::Key::CoverArtImage);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Orientation", QMediaMetaData::Key::Orientation);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "Resolution", QMediaMetaData::Key::Resolution);
        define_qenum_value_under(rb_cQMediaMetaDataKey, "HasHdrContent", QMediaMetaData::Key::HasHdrContent);
}
