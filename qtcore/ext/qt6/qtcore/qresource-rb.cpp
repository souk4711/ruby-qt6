#include "qresource-rb.hpp"
#include <qresource.h>
#include <rice/qenum.hpp>

#include <QDateTime>

using namespace Rice;

Rice::Class rb_cQResource;

void Init_qresource(Rice::Module rb_mQt6QtCore)
{
    rb_cQResource =
        // RubyQt6::QtCore::QResource
        define_class_under<QResource>(rb_mQt6QtCore, "QResource")
            // RubyQt6-Defined Functions
            .define_singleton_function("register_resource", [](const char *rcc_filename, const char *resource_root) -> bool { return QResource::registerResource(QString(rcc_filename), QString(resource_root)); }, Arg("rcc_filename"), Arg("resource_root") = static_cast<const char *>(nullptr))
            .define_singleton_function("unregister_resource", [](const char *rcc_filename, const char *resource_root) -> bool { return QResource::unregisterResource(QString(rcc_filename), QString(resource_root)); }, Arg("rcc_filename"), Arg("resource_root") = static_cast<const char *>(nullptr))
            // Constructor
            .define_constructor(Constructor<QResource>())
            .define_constructor(Constructor<QResource, const QString &>(), Arg("file"))
            .define_constructor(Constructor<QResource, const QString &, const QLocale &>(), Arg("file"), Arg("locale"))
            // Public Functions
            .define_method("absolute_file_path", &QResource::absoluteFilePath)
            .define_method("compression_algorithm", &QResource::compressionAlgorithm)
            .define_method("data", &QResource::data)
            .define_method("file_name", &QResource::fileName)
            .define_method("valid?", &QResource::isValid)
            .define_method("last_modified", &QResource::lastModified)
            .define_method("locale", &QResource::locale)
            .define_method("set_file_name", &QResource::setFileName, Arg("file"))
            .define_method("set_locale", &QResource::setLocale, Arg("locale"))
            .define_method("size", &QResource::size)
            .define_method("uncompressed_data", &QResource::uncompressedData)
            .define_method("uncompressed_size", &QResource::uncompressedSize)
            // Static Public Members
            .define_singleton_function<bool (*)(const QString &, const QString &)>("register_resource", &QResource::registerResource, Arg("rcc_filename"), Arg("resource_root") = static_cast<const QString &>(QString()))
            .define_singleton_function<bool (*)(const uchar *, const QString &)>("register_resource", &QResource::registerResource, Arg("rcc_data"), Arg("resource_root") = static_cast<const QString &>(QString()))
            .define_singleton_function<bool (*)(const QString &, const QString &)>("unregister_resource", &QResource::unregisterResource, Arg("rcc_filename"), Arg("resource_root") = static_cast<const QString &>(QString()))
            .define_singleton_function<bool (*)(const uchar *, const QString &)>("unregister_resource", &QResource::unregisterResource, Arg("rcc_data"), Arg("resource_root") = static_cast<const QString &>(QString()));

    Enum<QResource::Compression> rb_cQResourceCompression =
        // RubyQt6::QtCore::QResource::Compression
        define_qenum_under<QResource::Compression>("Compression", rb_cQResource)
            .define_value("NoCompression", QResource::Compression::NoCompression)
            .define_value("ZlibCompression", QResource::Compression::ZlibCompression)
            .define_value("ZstdCompression", QResource::Compression::ZstdCompression);
}
