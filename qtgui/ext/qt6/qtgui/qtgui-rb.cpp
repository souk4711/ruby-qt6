#include "qtgui-rb.hpp"

// clang-format off
#include "qpaintdevice-rb.hpp"

#include "qguiapplication-rb.hpp"
#include "qwindow-rb.hpp"

#include <QGuiApplication>
QGuiApplication *app;
void _newQApplication()
{
    int argc = 0;
    app = new QGuiApplication(argc, 0);
}
void _execQApplication()
{
    QGuiApplication::exec();
}
// clang-format on

extern "C" void Init_qtgui()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");

        rb_mQt6QtGui.define_singleton_function("_qapp_new", &_newQApplication);
        rb_mQt6QtQml, rb_mQt6QtGui.define_singleton_function("_qapp_exec", &_execQApplication);

        Init_qpaintdevice(rb_mQt6QtGui);

        Init_qguiapplication(rb_mQt6QtGui);
        Init_qwindow(rb_mQt6QtGui);
    });
}
