#include "qobject-rb.hpp"

using namespace Rice;

Rice::Class rb_cQObject;

void Init_QObject(Rice::Module rb_mQt6QtCore)
{
    rb_cQObject =
        define_class_under<QObject>(rb_mQt6QtCore, "QObject")
            .define_constructor(Constructor<QObject, QObject *>(), Arg("parent") = static_cast<QObject *>(nullptr));
}
