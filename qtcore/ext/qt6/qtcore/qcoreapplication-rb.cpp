#include "qcoreapplication-rb.hpp"

using namespace Rice;

Rice::Class rb_cQCoreApplication;

void Init_QCoreApplication(Rice::Module rb_mQt6QtCore)
{
    rb_cQCoreApplication =
        define_class_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication")
            .define_constructor(Constructor<QCoreApplication, int &, char **, int>(), Arg("argc"), Arg("argv"));
}
