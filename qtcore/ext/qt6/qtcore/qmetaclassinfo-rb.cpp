#include "qmetaclassinfo-rb.hpp"
#include <qmetaobject.h>

using namespace Rice;

Rice::Class rb_cQMetaClassInfo;

void Init_qmetaclassinfo(Rice::Module rb_mQt6QtCore)
{
    rb_cQMetaClassInfo =
        // RubyQt6::QtCore::QMetaClassInfo
        define_class_under<QMetaClassInfo>(rb_mQt6QtCore, "QMetaClassInfo")
            // Public Functions
            .define_method("name", &QMetaClassInfo::name)
            .define_method("value", &QMetaClassInfo::value);
}
