#include "qapplication-rb.hpp"
#include <qapplication.h>

using namespace Rice;

Rice::Class rb_cQApplication;

void Init_qapplication(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQApplication =
        // RubyQt6::QtWidgets::QApplication
        define_class_under<QApplication, QGuiApplication>(rb_mQt6QtWidgets, "QApplication")
            .define_constructor(Constructor<QApplication, int &, char **>(), Arg("argc") = static_cast<int>(0), Arg("argv") = static_cast<char **>(nullptr));
}
