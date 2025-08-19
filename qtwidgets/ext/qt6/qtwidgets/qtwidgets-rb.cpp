#include "qtwidgets-rb.hpp"

#include "qabstractbutton-rb.hpp"
#include "qapplication-rb.hpp"
#include "qlayout-rb.hpp"
#include "qboxlayout-rb.hpp"
#include "qpushbutton-rb.hpp"
#include "qwidget-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_QApplication(rb_mQt6QtWidgets);

        Init_QLayout(rb_mQt6QtWidgets);
        Init_QBoxLayout(rb_mQt6QtWidgets);

        Init_QWidget(rb_mQt6QtWidgets);
        Init_QAbstractButton(rb_mQt6QtWidgets);
        Init_QPushButton(rb_mQt6QtWidgets);
    });
}
