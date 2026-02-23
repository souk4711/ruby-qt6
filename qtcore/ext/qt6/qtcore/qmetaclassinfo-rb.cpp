#include "qmetaclassinfo-rb.hpp"
#include <qmetaobject.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMetaClassInfo;

void Init_qmetaclassinfo(Module rb_mQt6QtCore)
{
    rb_cQMetaClassInfo =
        // RubyQt6::QtCore::QMetaClassInfo
        define_qlass_under<QMetaClassInfo>(rb_mQt6QtCore, "QMetaClassInfo")
            // Public Functions
            .define_method("name", &QMetaClassInfo::name)
            .define_method("value", &QMetaClassInfo::value);
}
