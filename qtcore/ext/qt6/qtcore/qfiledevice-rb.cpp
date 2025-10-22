#include "qfiledevice-rb.hpp"
#include <qfiledevice.h>
#include <rice/qenum.hpp>
#include <rice/qflags.hpp>

#include <QDateTime>

using namespace Rice;

Rice::Class rb_cQFileDevice;

void Init_qfiledevice(Rice::Module rb_mQt6QtCore)
{
    rb_cQFileDevice =
        // RubyQt6::QtCore::QFileDevice
        define_class_under<QFileDevice, QIODevice>(rb_mQt6QtCore, "QFileDevice")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QFileDevice::staticMetaObject; })
            // Public Functions
            .define_method("at_end", &QFileDevice::atEnd)
            .define_method("close", &QFileDevice::close)
            .define_method("error", &QFileDevice::error)
            .define_method("file_name", &QFileDevice::fileName)
            .define_method("file_time", &QFileDevice::fileTime, Arg("time"))
            .define_method("flush", &QFileDevice::flush)
            .define_method("handle", &QFileDevice::handle)
            .define_method("sequential?", &QFileDevice::isSequential)
            .define_method("map", &QFileDevice::map, Arg("offset"), Arg("size"), Arg("flags") = static_cast<QFileDevice::MemoryMapFlags>(QFileDevice::MemoryMapFlag::NoOptions))
            .define_method("permissions", &QFileDevice::permissions)
            .define_method("pos", &QFileDevice::pos)
            .define_method("resize", &QFileDevice::resize, Arg("sz"))
            .define_method("seek", &QFileDevice::seek, Arg("offset"))
            .define_method("set_file_time", &QFileDevice::setFileTime, Arg("new_date"), Arg("file_time"))
            .define_method("set_permissions", &QFileDevice::setPermissions, Arg("permission_spec"))
            .define_method("size", &QFileDevice::size)
            .define_method("unmap", &QFileDevice::unmap, Arg("address"))
            .define_method("unset_error", &QFileDevice::unsetError);

    Enum<QFileDevice::FileError> rb_cQFileDeviceFileError =
        // RubyQt6::QtCore::QFileDevice::FileError
        define_qenum_under<QFileDevice::FileError>("FileError", rb_cQFileDevice)
            .define_value("NoError", QFileDevice::FileError::NoError)
            .define_value("ReadError", QFileDevice::FileError::ReadError)
            .define_value("WriteError", QFileDevice::FileError::WriteError)
            .define_value("FatalError", QFileDevice::FileError::FatalError)
            .define_value("ResourceError", QFileDevice::FileError::ResourceError)
            .define_value("OpenError", QFileDevice::FileError::OpenError)
            .define_value("AbortError", QFileDevice::FileError::AbortError)
            .define_value("TimeOutError", QFileDevice::FileError::TimeOutError)
            .define_value("UnspecifiedError", QFileDevice::FileError::UnspecifiedError)
            .define_value("RemoveError", QFileDevice::FileError::RemoveError)
            .define_value("RenameError", QFileDevice::FileError::RenameError)
            .define_value("PositionError", QFileDevice::FileError::PositionError)
            .define_value("ResizeError", QFileDevice::FileError::ResizeError)
            .define_value("PermissionsError", QFileDevice::FileError::PermissionsError)
            .define_value("CopyError", QFileDevice::FileError::CopyError);

    Enum<QFileDevice::FileHandleFlag> rb_cQFileDeviceFileHandleFlag =
        // RubyQt6::QtCore::QFileDevice::FileHandleFlag
        define_qenum_under<QFileDevice::FileHandleFlag>("FileHandleFlag", rb_cQFileDevice)
            .define_value("AutoCloseHandle", QFileDevice::FileHandleFlag::AutoCloseHandle)
            .define_value("DontCloseHandle", QFileDevice::FileHandleFlag::DontCloseHandle);

    Enum<QFileDevice::FileTime> rb_cQFileDeviceFileTime =
        // RubyQt6::QtCore::QFileDevice::FileTime
        define_qenum_under<QFileDevice::FileTime>("FileTime", rb_cQFileDevice)
            .define_value("FileAccessTime", QFileDevice::FileTime::FileAccessTime)
            .define_value("FileBirthTime", QFileDevice::FileTime::FileBirthTime)
            .define_value("FileMetadataChangeTime", QFileDevice::FileTime::FileMetadataChangeTime)
            .define_value("FileModificationTime", QFileDevice::FileTime::FileModificationTime);

    Enum<QFileDevice::MemoryMapFlag> rb_cQFileDeviceMemoryMapFlag =
        // RubyQt6::QtCore::QFileDevice::MemoryMapFlag
        define_qenum_under<QFileDevice::MemoryMapFlag>("MemoryMapFlag", rb_cQFileDevice)
            .define_value("NoOptions", QFileDevice::MemoryMapFlag::NoOptions)
            .define_value("MapPrivateOption", QFileDevice::MemoryMapFlag::MapPrivateOption);

    Enum<QFileDevice::Permission> rb_cQFileDevicePermission =
        // RubyQt6::QtCore::QFileDevice::Permission
        define_qenum_under<QFileDevice::Permission>("Permission", rb_cQFileDevice)
            .define_value("ReadOwner", QFileDevice::Permission::ReadOwner)
            .define_value("WriteOwner", QFileDevice::Permission::WriteOwner)
            .define_value("ExeOwner", QFileDevice::Permission::ExeOwner)
            .define_value("ReadUser", QFileDevice::Permission::ReadUser)
            .define_value("WriteUser", QFileDevice::Permission::WriteUser)
            .define_value("ExeUser", QFileDevice::Permission::ExeUser)
            .define_value("ReadGroup", QFileDevice::Permission::ReadGroup)
            .define_value("WriteGroup", QFileDevice::Permission::WriteGroup)
            .define_value("ExeGroup", QFileDevice::Permission::ExeGroup)
            .define_value("ReadOther", QFileDevice::Permission::ReadOther)
            .define_value("WriteOther", QFileDevice::Permission::WriteOther)
            .define_value("ExeOther", QFileDevice::Permission::ExeOther);

    Data_Type<QFlags<QFileDevice::FileHandleFlag>> rb_cQFileDeviceFileHandleFlags =
        // RubyQt6::QtCore::QFileDevice::FileHandleFlags
        define_qflags_under<QFileDevice::FileHandleFlag>(rb_cQFileDevice, "FileHandleFlags");

    Data_Type<QFlags<QFileDevice::MemoryMapFlag>> rb_cQFileDeviceMemoryMapFlags =
        // RubyQt6::QtCore::QFileDevice::MemoryMapFlags
        define_qflags_under<QFileDevice::MemoryMapFlag>(rb_cQFileDevice, "MemoryMapFlags");

    Data_Type<QFlags<QFileDevice::Permission>> rb_cQFileDevicePermissions =
        // RubyQt6::QtCore::QFileDevice::Permissions
        define_qflags_under<QFileDevice::Permission>(rb_cQFileDevice, "Permissions");
}
