#include "qmetamethod-rb.hpp"
#include <qmetaobject.h>

using namespace Rice;

Rice::Class rb_cQMetaMethod;

void Init_qmetamethod(Rice::Module rb_mQt6QtCore)
{
    rb_cQMetaMethod =
        // RubyQt6::QtCore::QMetaMethod
        define_class_under<QMetaMethod>(rb_mQt6QtCore, "QMetaMethod");
}
