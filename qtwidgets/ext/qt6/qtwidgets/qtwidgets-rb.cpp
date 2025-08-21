#include "qtwidgets-rb.hpp"

// clang-format off
#include "qapplication-rb.hpp"

#include "qlayout-rb.hpp"
#include "qboxlayout-rb.hpp"

#include "qwidget-rb.hpp"
#include "qabstractbutton-rb.hpp"
#include "qpushbutton-rb.hpp"
#include "qframe-rb.hpp"
#include "qlabel-rb.hpp"

#include <QApplication>
QApplication *app;
void _newQApplication()
{
    int argc = 0;
    app = new QApplication(argc, 0);
}
void _execQApplication()
{
    QApplication::exec();
}
// clang-format on

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        rb_mQt6QtWidgets.define_singleton_function("_qapp_new", &_newQApplication);
        rb_mQt6QtWidgets.define_singleton_function("_qapp_exec", &_execQApplication);

        Init_qapplication(rb_mQt6QtWidgets);

        Init_qlayout(rb_mQt6QtWidgets);
        Init_qboxlayout(rb_mQt6QtWidgets);

        Init_qwidget(rb_mQt6QtWidgets);
        Init_qabstractbutton(rb_mQt6QtWidgets);
        Init_qpushbutton(rb_mQt6QtWidgets);
        Init_qframe(rb_mQt6QtWidgets);
        Init_qlabel(rb_mQt6QtWidgets);
    });
}
