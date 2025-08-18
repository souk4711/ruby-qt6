#include "qguiapplication-rb.hpp"

using namespace Rice;

Rice::Class rb_cQGuiApplication;

void Init_QGuiApplication(Rice::Module rb_mQt6QtGui)
{
    rb_cQGuiApplication =
        define_class_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication")
            .define_constructor(Constructor<QGuiApplication, int &, char **>(), Arg("argc"), Arg("argv"));
}
