#include "qmetaobject-rb.hpp"
#include <qobjectdefs.h>

using namespace Rice;

Rice::Class rb_cQMetaObject;
Rice::Class rb_cQMetaObjectConnection;

void Init_qmetaobject(Rice::Module rb_mQt6QtCore)
{
    rb_cQMetaObject =
        // RubyQt6::QtCore::QMetaObject
        define_class_under<QMetaObject>(rb_mQt6QtCore, "QMetaObject");

    rb_cQMetaObjectConnection =
        // RubyQt6::QtCore::QMetaObject::Connection
        define_class_under<QMetaObject::Connection>(rb_cQMetaObject, "Connection");
}
