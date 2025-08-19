#include "qtwidgets-rb.hpp"

#include "qapplication-rb.hpp"

#include "qwidget-rb.hpp"
#include "qabstractbutton-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_QApplication(rb_mQt6QtWidgets);

        Init_QWidget(rb_mQt6QtWidgets);
        Init_QAbstractButton(rb_mQt6QtWidgets);
    });
}
