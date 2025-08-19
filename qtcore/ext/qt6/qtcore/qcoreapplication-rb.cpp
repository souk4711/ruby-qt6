// clang-format off

#include "qcoreapplication-rb.hpp"
#include <QCoreApplication>

using namespace Rice;

Rice::Class rb_cQCoreApplication;

void Init_QCoreApplication(Rice::Module rb_mQt6QtCore)
{
    rb_cQCoreApplication = // Qt6::QtCore::QCoreApplication
        define_class_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication")
            .define_constructor(Constructor<QCoreApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_singleton_function("exec", &QCoreApplication::exec);
}
