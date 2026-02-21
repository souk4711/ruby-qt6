#include "qfiledevice-rb.hpp"
#include <qfiledevice.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QDateTime>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQFileDevice;

void Init_qfiledevice(Module rb_mQt6QtCore)
{
    rb_cQFileDevice =
        // RubyQt6::QtCore::QFileDevice
        define_qlass_under<QFileDevice, QIODevice>(rb_mQt6QtCore, "QFileDevice")
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

    Data_Type<QFileDevice::FileError> rb_cQFileDeviceFileError =
        // RubyQt6::QtCore::QFileDevice::FileError
        define_qenum_under<QFileDevice::FileError>(rb_cQFileDevice, "FileError");
        define_qenum_value_under(rb_cQFileDeviceFileError, "NoError", QFileDevice::FileError::NoError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "ReadError", QFileDevice::FileError::ReadError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "WriteError", QFileDevice::FileError::WriteError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "FatalError", QFileDevice::FileError::FatalError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "ResourceError", QFileDevice::FileError::ResourceError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "OpenError", QFileDevice::FileError::OpenError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "AbortError", QFileDevice::FileError::AbortError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "TimeOutError", QFileDevice::FileError::TimeOutError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "UnspecifiedError", QFileDevice::FileError::UnspecifiedError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "RemoveError", QFileDevice::FileError::RemoveError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "RenameError", QFileDevice::FileError::RenameError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "PositionError", QFileDevice::FileError::PositionError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "ResizeError", QFileDevice::FileError::ResizeError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "PermissionsError", QFileDevice::FileError::PermissionsError);
        define_qenum_value_under(rb_cQFileDeviceFileError, "CopyError", QFileDevice::FileError::CopyError);

    Data_Type<QFileDevice::FileHandleFlag> rb_cQFileDeviceFileHandleFlag =
        // RubyQt6::QtCore::QFileDevice::FileHandleFlag
        define_qenum_under<QFileDevice::FileHandleFlag>(rb_cQFileDevice, "FileHandleFlag");
        define_qenum_value_under(rb_cQFileDeviceFileHandleFlag, "AutoCloseHandle", QFileDevice::FileHandleFlag::AutoCloseHandle);
        define_qenum_value_under(rb_cQFileDeviceFileHandleFlag, "DontCloseHandle", QFileDevice::FileHandleFlag::DontCloseHandle);

    Data_Type<QFileDevice::FileTime> rb_cQFileDeviceFileTime =
        // RubyQt6::QtCore::QFileDevice::FileTime
        define_qenum_under<QFileDevice::FileTime>(rb_cQFileDevice, "FileTime");
        define_qenum_value_under(rb_cQFileDeviceFileTime, "FileAccessTime", QFileDevice::FileTime::FileAccessTime);
        define_qenum_value_under(rb_cQFileDeviceFileTime, "FileBirthTime", QFileDevice::FileTime::FileBirthTime);
        define_qenum_value_under(rb_cQFileDeviceFileTime, "FileMetadataChangeTime", QFileDevice::FileTime::FileMetadataChangeTime);
        define_qenum_value_under(rb_cQFileDeviceFileTime, "FileModificationTime", QFileDevice::FileTime::FileModificationTime);

    Data_Type<QFileDevice::MemoryMapFlag> rb_cQFileDeviceMemoryMapFlag =
        // RubyQt6::QtCore::QFileDevice::MemoryMapFlag
        define_qenum_under<QFileDevice::MemoryMapFlag>(rb_cQFileDevice, "MemoryMapFlag");
        define_qenum_value_under(rb_cQFileDeviceMemoryMapFlag, "NoOptions", QFileDevice::MemoryMapFlag::NoOptions);
        define_qenum_value_under(rb_cQFileDeviceMemoryMapFlag, "MapPrivateOption", QFileDevice::MemoryMapFlag::MapPrivateOption);

    Data_Type<QFileDevice::Permission> rb_cQFileDevicePermission =
        // RubyQt6::QtCore::QFileDevice::Permission
        define_qenum_under<QFileDevice::Permission>(rb_cQFileDevice, "Permission");
        define_qenum_value_under(rb_cQFileDevicePermission, "ReadOwner", QFileDevice::Permission::ReadOwner);
        define_qenum_value_under(rb_cQFileDevicePermission, "WriteOwner", QFileDevice::Permission::WriteOwner);
        define_qenum_value_under(rb_cQFileDevicePermission, "ExeOwner", QFileDevice::Permission::ExeOwner);
        define_qenum_value_under(rb_cQFileDevicePermission, "ReadUser", QFileDevice::Permission::ReadUser);
        define_qenum_value_under(rb_cQFileDevicePermission, "WriteUser", QFileDevice::Permission::WriteUser);
        define_qenum_value_under(rb_cQFileDevicePermission, "ExeUser", QFileDevice::Permission::ExeUser);
        define_qenum_value_under(rb_cQFileDevicePermission, "ReadGroup", QFileDevice::Permission::ReadGroup);
        define_qenum_value_under(rb_cQFileDevicePermission, "WriteGroup", QFileDevice::Permission::WriteGroup);
        define_qenum_value_under(rb_cQFileDevicePermission, "ExeGroup", QFileDevice::Permission::ExeGroup);
        define_qenum_value_under(rb_cQFileDevicePermission, "ReadOther", QFileDevice::Permission::ReadOther);
        define_qenum_value_under(rb_cQFileDevicePermission, "WriteOther", QFileDevice::Permission::WriteOther);
        define_qenum_value_under(rb_cQFileDevicePermission, "ExeOther", QFileDevice::Permission::ExeOther);

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
