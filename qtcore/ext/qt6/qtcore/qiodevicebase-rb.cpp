#include "qiodevicebase-rb.hpp"
#include <qiodevicebase.h>
#include <rice/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQIODeviceBase;

void Init_qiodevicebase(Rice::Module rb_mQt6QtCore)
{
    rb_cQIODeviceBase =
        // RubyQt6::QtCore::QIODeviceBase
        define_class_under<QIODeviceBase>(rb_mQt6QtCore, "QIODeviceBase");

    Enum<QIODeviceBase::OpenModeFlag> rb_cQIODeviceBaseOpenModeFlag =
        // RubyQt6::QtCore::QIODeviceBase::OpenModeFlag
        define_enum_under<QIODeviceBase::OpenModeFlag>("OpenModeFlag", rb_cQIODeviceBase)
            .define_value("NotOpen", QIODeviceBase::OpenModeFlag::NotOpen)
            .define_value("ReadOnly", QIODeviceBase::OpenModeFlag::ReadOnly)
            .define_value("WriteOnly", QIODeviceBase::OpenModeFlag::WriteOnly)
            .define_value("ReadWrite", QIODeviceBase::OpenModeFlag::ReadWrite)
            .define_value("Append", QIODeviceBase::OpenModeFlag::Append)
            .define_value("Truncate", QIODeviceBase::OpenModeFlag::Truncate)
            .define_value("Text", QIODeviceBase::OpenModeFlag::Text)
            .define_value("Unbuffered", QIODeviceBase::OpenModeFlag::Unbuffered)
            .define_value("NewOnly", QIODeviceBase::OpenModeFlag::NewOnly)
            .define_value("ExistingOnly", QIODeviceBase::OpenModeFlag::ExistingOnly);

    Data_Type<QFlags<QIODeviceBase::OpenModeFlag>> rb_cQIODeviceBaseOpenMode =
        // RubyQt6::QtCore::QIODeviceBase::OpenMode
        define_qflags_under<QIODeviceBase::OpenModeFlag>(rb_cQIODeviceBase, "OpenMode");
}
