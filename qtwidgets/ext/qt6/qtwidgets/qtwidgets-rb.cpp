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
// clang-format on

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
        Init_QFrame(rb_mQt6QtWidgets);
        Init_QLabel(rb_mQt6QtWidgets);
    });
}
