#include "qwindow-rb.hpp"
#include <qwindow.h>

using namespace Rice;

Rice::Class rb_cQWindow;

void Init_qwindow(Rice::Module rb_mQt6QtGui)
{
    rb_cQWindow =
        // Qt6::QtGui::QWindow
        define_class_under<QWindow, QObject>(rb_mQt6QtGui, "QWindow");
}
