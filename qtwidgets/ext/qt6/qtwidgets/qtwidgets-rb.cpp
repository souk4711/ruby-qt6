#include "qtwidgets-rb.hpp"

// clang-format off
#include "qtwidgetsversion-rb.hpp"

#include "qwidget-rb.hpp"
#include "qframe-rb.hpp"
#include "qlabel-rb.hpp"
#include "qabstractbutton-rb.hpp"
#include "qpushbutton-rb.hpp"
#include "qapplication-rb.hpp"
// clang-format on

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_qtwidgetsversion(rb_mQt6QtWidgets);

        Init_qwidget(rb_mQt6QtWidgets);
        Init_qframe(rb_mQt6QtWidgets);
        Init_qlabel(rb_mQt6QtWidgets);
        Init_qabstractbutton(rb_mQt6QtWidgets);
        Init_qpushbutton(rb_mQt6QtWidgets);
        Init_qapplication(rb_mQt6QtWidgets);
    });
}
