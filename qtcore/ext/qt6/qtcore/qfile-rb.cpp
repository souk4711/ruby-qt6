#include "qfile-rb.hpp"
#include <qfile.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFile;

void Init_qfile(Module rb_mQt6QtCore)
{
    rb_cQFile =
        // RubyQt6::QtCore::QFile
        define_qlass_under<QFile, QFileDevice>(rb_mQt6QtCore, "QFile")
            // RubyQt6-Defined Functions
            .define_singleton_function("_qobject_cast", [](QObject *object) -> const QFile * { return qobject_cast<QFile *>(object); })
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFile::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QFile, const QString &>(), Arg("name"))
            // Public Functions
            .define_method<bool (QFile::*)(const QString &)>("copy", &QFile::copy, Arg("new_name"))
            .define_method<bool (QFile::*)() const>("exists", &QFile::exists)
            .define_method("file_name", &QFile::fileName)
            .define_method("filesystem_file_name", &QFile::filesystemFileName)
            // .define_method("filesystem_sym_link_target", &QFile::filesystemSymLinkTarget)
            .define_method<bool (QFile::*)(const QString &)>("link", &QFile::link, Arg("new_name"))
            .define_method<bool (QFile::*)()>("move_to_trash", &QFile::moveToTrash)
            .define_method<bool (QFile::*)(FILE *, QIODeviceBase::OpenMode, QFileDevice::FileHandleFlags)>("open", &QFile::open, Arg("f"), Arg("io_flags"), Arg("handle_flags") = static_cast<QFileDevice::FileHandleFlags>(QFileDevice::FileHandleFlag::DontCloseHandle))
            .define_method<bool (QFile::*)(QIODeviceBase::OpenMode)>("open", &QFile::open, Arg("flags"))
            .define_method<bool (QFile::*)(QIODeviceBase::OpenMode, QFileDevice::Permissions)>("open", &QFile::open, Arg("flags"), Arg("permissions"))
            .define_method<bool (QFile::*)(int, QIODeviceBase::OpenMode, QFileDevice::FileHandleFlags)>("open", &QFile::open, Arg("fd"), Arg("io_flags"), Arg("handle_flags") = static_cast<QFileDevice::FileHandleFlags>(QFileDevice::FileHandleFlag::DontCloseHandle))
            .define_method<QFileDevice::Permissions (QFile::*)() const>("permissions", &QFile::permissions)
            .define_method<bool (QFile::*)()>("remove", &QFile::remove)
            .define_method<bool (QFile::*)(const QString &)>("rename", &QFile::rename, Arg("new_name"))
            .define_method<bool (QFile::*)(qint64)>("resize", &QFile::resize, Arg("sz"))
            .define_method<void (QFile::*)(const QString &)>("set_file_name", &QFile::setFileName, Arg("name"))
            .define_method<bool (QFile::*)(QFileDevice::Permissions)>("set_permissions", &QFile::setPermissions, Arg("permission_spec"))
            .define_method("size", &QFile::size)
            .define_method<QString (QFile::*)() const>("sym_link_target", &QFile::symLinkTarget)
            // Static Public Members
            .define_singleton_function<bool (*)(const QString &, const QString &)>("copy", &QFile::copy, Arg("file_name"), Arg("new_name"))
            .define_singleton_function<QString (*)(const QByteArray &)>("decode_name", &QFile::decodeName, Arg("local_file_name"))
            .define_singleton_function<QString (*)(const char *)>("decode_name", &QFile::decodeName, Arg("local_file_name"))
            .define_singleton_function("encode_name", &QFile::encodeName, Arg("file_name"))
            .define_singleton_function<bool (*)(const QString &)>("exists", &QFile::exists, Arg("file_name"))
            .define_singleton_function<bool (*)(const QString &, const QString &)>("link", &QFile::link, Arg("file_name"), Arg("new_name"))
            .define_singleton_function<bool (*)(const QString &, QString *)>("move_to_trash", &QFile::moveToTrash, Arg("file_name"), Arg("path_in_trash") = static_cast<QString *>(nullptr))
            .define_singleton_function<QFileDevice::Permissions (*)(const QString &)>("permissions", &QFile::permissions, Arg("filename"))
            .define_singleton_function<bool (*)(const QString &)>("remove", &QFile::remove, Arg("file_name"))
            .define_singleton_function<bool (*)(const QString &, const QString &)>("rename", &QFile::rename, Arg("old_name"), Arg("new_name"))
            .define_singleton_function<bool (*)(const QString &, qint64)>("resize", &QFile::resize, Arg("filename"), Arg("sz"))
            .define_singleton_function<bool (*)(const QString &, QFileDevice::Permissions)>("set_permissions", &QFile::setPermissions, Arg("filename"), Arg("permission_spec"))
            .define_singleton_function("supports_move_to_trash", &QFile::supportsMoveToTrash)
            .define_singleton_function<QString (*)(const QString &)>("sym_link_target", &QFile::symLinkTarget, Arg("file_name"));
}
