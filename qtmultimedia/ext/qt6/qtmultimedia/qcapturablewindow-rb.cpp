#include "qcapturablewindow-rb.hpp"
#include <qcapturablewindow.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQCapturableWindow;

void Init_qcapturablewindow(Module rb_mQt6QtMultimedia)
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
