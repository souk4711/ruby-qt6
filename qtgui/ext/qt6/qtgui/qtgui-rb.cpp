#include "qtgui-rb.hpp"

// clang-format off
#include "qguiapplication-rb.hpp"
#include "qwindow-rb.hpp"
// clang-format on

extern "C" void Init_qtgui()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");

        Init_qguiapplication(rb_mQt6QtGui);
        Init_qwindow(rb_mQt6QtGui);
    });
}
