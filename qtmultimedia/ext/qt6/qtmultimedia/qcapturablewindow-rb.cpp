#include "qcapturablewindow-rb.hpp"
#include <qcapturablewindow.h>

using namespace Rice;

Rice::Class rb_cQCapturableWindow;

void Init_qcapturablewindow(Rice::Module rb_mQt6QtMultimedia)
{
    rb_cQCapturableWindow =
        // RubyQt6::QtMultimedia::QCapturableWindow
        define_class_under<QCapturableWindow>(rb_mQt6QtMultimedia, "QCapturableWindow")
            // Constructor
            .define_constructor(Constructor<QCapturableWindow>())
            // Public Functions
            .define_method("description", &QCapturableWindow::description)
            .define_method("valid?", &QCapturableWindow::isValid);
}
