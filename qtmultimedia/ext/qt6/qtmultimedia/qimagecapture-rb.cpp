#include "qimagecapture-rb.hpp"
#include <qimagecapture.h>
#include <rice/qt6/qenum.hpp>

#include <QMediaCaptureSession>
#include <QMediaMetaData>

using namespace Rice;

Rice::Class rb_cQImageCapture;

void Init_qimagecapture(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQImageCapture =
        // RubyQt6::QtMultimedia::QImageCapture
        define_class_under<QImageCapture, QObject>(rb_mQt6QtMultimedia, "QImageCapture")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QImageCapture::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QImageCapture, QObject *>(), Arg("parent"))
            // Public Functions
            .define_method("add_meta_data", &QImageCapture::addMetaData, Arg("meta_data"))
            .define_method("capture_session", &QImageCapture::captureSession)
            .define_method("error", &QImageCapture::error)
            .define_method("error_string", &QImageCapture::errorString)
            .define_method("file_format", &QImageCapture::fileFormat)
            .define_method("available?", &QImageCapture::isAvailable)
            .define_method("ready_for_capture?", &QImageCapture::isReadyForCapture)
            .define_method("meta_data", &QImageCapture::metaData)
            .define_method("quality", &QImageCapture::quality)
            .define_method("resolution", &QImageCapture::resolution)
            .define_method("set_file_format", &QImageCapture::setFileFormat, Arg("format"))
            .define_method("set_meta_data", &QImageCapture::setMetaData, Arg("meta_data"))
            .define_method("set_quality", &QImageCapture::setQuality, Arg("quality"))
            .define_method<void (QImageCapture::*)(const QSize &)>("set_resolution", &QImageCapture::setResolution, Arg("size"))
            .define_method<void (QImageCapture::*)(int, int)>("set_resolution", &QImageCapture::setResolution, Arg("width"), Arg("height"))
            // Public Slots
            .define_method("capture", &QImageCapture::capture)
            .define_method("capture_to_file", &QImageCapture::captureToFile, Arg("location") = static_cast<const QString &>(QString()))
            // Signals
            // .define_method("error_changed", &QImageCapture::errorChanged)
            // .define_method("error_occurred", &QImageCapture::errorOccurred, Arg("id"), Arg("error"), Arg("error_string"))
            // .define_method("file_format_changed", &QImageCapture::fileFormatChanged)
            // .define_method("image_available", &QImageCapture::imageAvailable, Arg("id"), Arg("frame"))
            // .define_method("image_captured", &QImageCapture::imageCaptured, Arg("id"), Arg("preview"))
            // .define_method("image_exposed", &QImageCapture::imageExposed, Arg("id"))
            // .define_method("image_metadata_available", &QImageCapture::imageMetadataAvailable, Arg("id"), Arg("meta_data"))
            // .define_method("image_saved", &QImageCapture::imageSaved, Arg("id"), Arg("file_name"))
            // .define_method("meta_data_changed", &QImageCapture::metaDataChanged)
            // .define_method("quality_changed", &QImageCapture::qualityChanged)
            // .define_method("ready_for_capture_changed", &QImageCapture::readyForCaptureChanged, Arg("ready"))
            // .define_method("resolution_changed", &QImageCapture::resolutionChanged)
            // Static Public Members
            .define_singleton_function("file_format_description", &QImageCapture::fileFormatDescription, Arg("c"))
            .define_singleton_function("file_format_name", &QImageCapture::fileFormatName, Arg("c"))
            .define_singleton_function("supported_formats", &QImageCapture::supportedFormats);

    Data_Type<QImageCapture::Error> rb_cQImageCaptureError =
        // RubyQt6::QtMultimedia::QImageCapture::Error
        define_qenum_under<QImageCapture::Error>(rb_cQImageCapture, "Error");
        define_qenum_value_under(rb_cQImageCaptureError, "NoError", QImageCapture::Error::NoError);
        define_qenum_value_under(rb_cQImageCaptureError, "NotReadyError", QImageCapture::Error::NotReadyError);
        define_qenum_value_under(rb_cQImageCaptureError, "ResourceError", QImageCapture::Error::ResourceError);
        define_qenum_value_under(rb_cQImageCaptureError, "OutOfSpaceError", QImageCapture::Error::OutOfSpaceError);
        define_qenum_value_under(rb_cQImageCaptureError, "NotSupportedFeatureError", QImageCapture::Error::NotSupportedFeatureError);
        define_qenum_value_under(rb_cQImageCaptureError, "FormatError", QImageCapture::Error::FormatError);

    Data_Type<QImageCapture::FileFormat> rb_cQImageCaptureFileFormat =
        // RubyQt6::QtMultimedia::QImageCapture::FileFormat
        define_qenum_under<QImageCapture::FileFormat>(rb_cQImageCapture, "FileFormat");
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "UnspecifiedFormat", QImageCapture::FileFormat::UnspecifiedFormat);
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "JPEG", QImageCapture::FileFormat::JPEG);
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "PNG", QImageCapture::FileFormat::PNG);
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "WebP", QImageCapture::FileFormat::WebP);
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "Tiff", QImageCapture::FileFormat::Tiff);
        define_qenum_value_under(rb_cQImageCaptureFileFormat, "LastFileFormat", QImageCapture::FileFormat::LastFileFormat);

    Data_Type<QImageCapture::Quality> rb_cQImageCaptureQuality =
        // RubyQt6::QtMultimedia::QImageCapture::Quality
        define_qenum_under<QImageCapture::Quality>(rb_cQImageCapture, "Quality");
        define_qenum_value_under(rb_cQImageCaptureQuality, "VeryLowQuality", QImageCapture::Quality::VeryLowQuality);
        define_qenum_value_under(rb_cQImageCaptureQuality, "LowQuality", QImageCapture::Quality::LowQuality);
        define_qenum_value_under(rb_cQImageCaptureQuality, "NormalQuality", QImageCapture::Quality::NormalQuality);
        define_qenum_value_under(rb_cQImageCaptureQuality, "HighQuality", QImageCapture::Quality::HighQuality);
        define_qenum_value_under(rb_cQImageCaptureQuality, "VeryHighQuality", QImageCapture::Quality::VeryHighQuality);
}
