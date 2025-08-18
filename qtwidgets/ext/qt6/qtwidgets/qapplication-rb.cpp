#include "qapplication-rb.hpp"

using namespace Rice;

Rice::Class rb_cQApplication;

void Init_QApplication(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQApplication = define_class_under<QApplication, QGuiApplication>(rb_mQt6QtWidgets, "QApplication")
                           .define_constructor(Constructor<QApplication, int &, char **>(), Arg("argc"), Arg("argv"))
                           .define_singleton_function("exec", &QApplication::exec);
}
