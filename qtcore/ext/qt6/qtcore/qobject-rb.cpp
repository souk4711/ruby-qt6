#include "qobject-rb.hpp"
#include <qobject.h>

using namespace Rice;

Rice::Class rb_cQObject;

void Init_qobject(Rice::Module rb_mQt6QtCore)
{
    rb_cQObject =
        // Qt6::QtCore::QObject
        define_class_under<QObject>(rb_mQt6QtCore, "QObject");
}
