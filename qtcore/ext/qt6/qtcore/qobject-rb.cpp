// clang-format off

#include "qobject-rb.hpp"
#include <QObject>

using namespace Rice;

Rice::Class rb_cQObject;

void Init_QObject(Rice::Module rb_mQt6QtCore)
{
    rb_cQObject =
        // Qt6::QtCore::QObject
        define_class_under<QObject>(rb_mQt6QtCore, "QObject")
            // Public Functions
            .define_constructor(Constructor<QObject, QObject*>(), Arg("parent") = static_cast<QObject *>(nullptr));
}
