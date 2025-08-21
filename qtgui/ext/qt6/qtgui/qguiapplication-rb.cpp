#include "qguiapplication-rb.hpp"
#include <qguiapplication.h>

using namespace Rice;

Rice::Class rb_cQGuiApplication;

void Init_qguiapplication(Rice::Module rb_mQt6QtGui)
{
    rb_cQGuiApplication =
        // Qt6::QtGui::QGuiApplication
        define_class_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication");
}
