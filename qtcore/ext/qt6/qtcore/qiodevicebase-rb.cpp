#include "qiodevicebase-rb.hpp"
#include <qiodevicebase.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQIODeviceBase;

void Init_qiodevicebase(Module rb_mQt6QtCore)
{
    rb_cQIODeviceBase =
        // RubyQt6::QtCore::QIODeviceBase
        define_qlass_under<QIODeviceBase>(rb_mQt6QtCore, "QIODeviceBase");

    Data_Type<QIODeviceBase::OpenModeFlag> rb_cQIODeviceBaseOpenModeFlag =
        // RubyQt6::QtCore::QIODeviceBase::OpenModeFlag
        define_qenum_under<QIODeviceBase::OpenModeFlag>(rb_cQIODeviceBase, "OpenModeFlag");
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "NotOpen", QIODeviceBase::OpenModeFlag::NotOpen);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "ReadOnly", QIODeviceBase::OpenModeFlag::ReadOnly);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "WriteOnly", QIODeviceBase::OpenModeFlag::WriteOnly);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "ReadWrite", QIODeviceBase::OpenModeFlag::ReadWrite);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "Append", QIODeviceBase::OpenModeFlag::Append);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "Truncate", QIODeviceBase::OpenModeFlag::Truncate);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "Text", QIODeviceBase::OpenModeFlag::Text);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "Unbuffered", QIODeviceBase::OpenModeFlag::Unbuffered);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "NewOnly", QIODeviceBase::OpenModeFlag::NewOnly);
        define_qenum_value_under(rb_cQIODeviceBaseOpenModeFlag, "ExistingOnly", QIODeviceBase::OpenModeFlag::ExistingOnly);

    Data_Type<QFlags<QIODeviceBase::OpenModeFlag>> rb_cQIODeviceBaseOpenMode =
        // RubyQt6::QtCore::QIODeviceBase::OpenMode
        define_qflags_under<QIODeviceBase::OpenModeFlag>(rb_cQIODeviceBase, "OpenMode");
}
