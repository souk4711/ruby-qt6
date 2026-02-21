#include "qresource-rb.hpp"
#include <qresource.h>
#include <rice/qt6/qenum.hpp>

#include <QDateTime>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQResource;

void Init_qresource(Module rb_mQt6QtCore)
{
    rb_cQResource =
        // RubyQt6::QtCore::QResource
        define_qlass_under<QResource>(rb_mQt6QtCore, "QResource")
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

    Data_Type<QResource::Compression> rb_cQResourceCompression =
        // RubyQt6::QtCore::QResource::Compression
        define_qenum_under<QResource::Compression>(rb_cQResource, "Compression");
        define_qenum_value_under(rb_cQResourceCompression, "NoCompression", QResource::Compression::NoCompression);
        define_qenum_value_under(rb_cQResourceCompression, "ZlibCompression", QResource::Compression::ZlibCompression);
        define_qenum_value_under(rb_cQResourceCompression, "ZstdCompression", QResource::Compression::ZstdCompression);
}
