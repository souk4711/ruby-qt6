#include "qwindow-rb.hpp"
#include <qwindow.h>

using namespace Rice;

Rice::Class rb_cQWindow;

void Init_qwindow(Rice::Module rb_mQt6QtGui)
{
    rb_cQWindow =
        // RubyQt6::QtGui::QWindow
        define_class_under<QWindow, QObject>(rb_mQt6QtGui, "QWindow")
            .define_method("_show", &QWindow::show)
            .define_method("_show_full_screen", &QWindow::showFullScreen)
            .define_method("_show_maximized", &QWindow::showMaximized)
            .define_method("_show_minimized", &QWindow::showMinimized)
            .define_method("_show_normal", &QWindow::showNormal)
            .define_method("_hide", &QWindow::hide);
}
