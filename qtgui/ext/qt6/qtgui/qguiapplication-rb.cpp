#include "qguiapplication-rb.hpp"
#include <QGuiApplication>

using namespace Rice;

Rice::Class rb_cQGuiApplication;

void Init_QGuiApplication(Rice::Module rb_mQt6QtGui)
{
    rb_cQGuiApplication = // Qt6::QtGui::QGuiApplication
        define_class_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication")
            .define_constructor(Constructor<QGuiApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_singleton_function("exec", &QGuiApplication::exec);
}
