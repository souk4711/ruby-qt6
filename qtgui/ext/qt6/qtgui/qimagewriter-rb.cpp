#include "qimagewriter-rb.hpp"
#include <qimagewriter.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQImageWriter;

void Init_qimagewriter(Module rb_mQt6QtGui)
{
    rb_cQImageWriter =
        // RubyQt6::QtGui::QImageWriter
        define_qlass_under<QImageWriter>(rb_mQt6QtGui, "QImageWriter")
            // Constructor
            .define_constructor(Constructor<QImageWriter>())
            .define_constructor(Constructor<QImageWriter, QIODevice *, const QByteArray &>(), Arg("device"), Arg("format"))
            .define_constructor(Constructor<QImageWriter, const QString &, const QByteArray &>(), Arg("file_name"), Arg("format"))
            // Public Functions
            .define_method("can_write", &QImageWriter::canWrite)
            .define_method("compression", &QImageWriter::compression)
            .define_method("device", &QImageWriter::device)
            .define_method("error", &QImageWriter::error)
            .define_method("error_string", &QImageWriter::errorString)
            .define_method("file_name", &QImageWriter::fileName)
            .define_method("format", &QImageWriter::format)
            .define_method("optimized_write", &QImageWriter::optimizedWrite)
            .define_method("progressive_scan_write", &QImageWriter::progressiveScanWrite)
            .define_method("quality", &QImageWriter::quality)
            .define_method("set_compression", &QImageWriter::setCompression, Arg("compression"))
            .define_method("set_device", &QImageWriter::setDevice, Arg("device"))
            .define_method("set_file_name", &QImageWriter::setFileName, Arg("file_name"))
            .define_method("set_format", &QImageWriter::setFormat, Arg("format"))
            .define_method("set_optimized_write", &QImageWriter::setOptimizedWrite, Arg("optimize"))
            .define_method("set_progressive_scan_write", &QImageWriter::setProgressiveScanWrite, Arg("progressive"))
            .define_method("set_quality", &QImageWriter::setQuality, Arg("quality"))
            .define_method("set_sub_type", &QImageWriter::setSubType, Arg("type"))
            .define_method("set_text", &QImageWriter::setText, Arg("key"), Arg("text"))
            .define_method("set_transformation", &QImageWriter::setTransformation, Arg("orientation"))
            .define_method("sub_type", &QImageWriter::subType)
            .define_method("supported_sub_types", &QImageWriter::supportedSubTypes)
            .define_method("supports_option", &QImageWriter::supportsOption, Arg("option"))
            .define_method("transformation", &QImageWriter::transformation)
            .define_method("write", &QImageWriter::write, Arg("image"))
            // Static Public Members
            .define_singleton_function("image_formats_for_mime_type", &QImageWriter::imageFormatsForMimeType, Arg("mime_type"))
            .define_singleton_function("supported_image_formats", &QImageWriter::supportedImageFormats)
            .define_singleton_function("supported_mime_types", &QImageWriter::supportedMimeTypes);

    Data_Type<QImageWriter::ImageWriterError> rb_cQImageWriterImageWriterError =
        // RubyQt6::QtGui::QImageWriter::ImageWriterError
        define_qenum_under<QImageWriter::ImageWriterError>(rb_cQImageWriter, "ImageWriterError");
        define_qenum_value_under(rb_cQImageWriterImageWriterError, "UnknownError", QImageWriter::ImageWriterError::UnknownError);
        define_qenum_value_under(rb_cQImageWriterImageWriterError, "DeviceError", QImageWriter::ImageWriterError::DeviceError);
        define_qenum_value_under(rb_cQImageWriterImageWriterError, "UnsupportedFormatError", QImageWriter::ImageWriterError::UnsupportedFormatError);
        define_qenum_value_under(rb_cQImageWriterImageWriterError, "InvalidImageError", QImageWriter::ImageWriterError::InvalidImageError);
}
