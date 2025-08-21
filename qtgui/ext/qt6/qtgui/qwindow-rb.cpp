#include "qwindow-rb.hpp"
#include <qwindow.h>

using namespace Rice;

Rice::Class rb_cQWindow;

void Init_qwindow(Rice::Module rb_mQt6QtGui)
{
    rb_cQWindow =
        // Qt6::QtGui::QWindow
        define_class_under<QWindow, QObject>(rb_mQt6QtGui, "QWindow")
            .define_method("show", &QWindow::show)
            .define_method("show_normal", &QWindow::showNormal)
            .define_method("show_maximized", &QWindow::showMaximized)
            .define_method("show_minimized", &QWindow::showMinimized)
            .define_method("show_full_screen", &QWindow::showFullScreen)
            .define_method("hide", &QWindow::hide)
            .define_method("close", &QWindow::close);
}
