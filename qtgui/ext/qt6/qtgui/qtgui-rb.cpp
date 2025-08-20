#include "qtgui-rb.hpp"
#include "qguiapplication-rb.hpp"

extern "C" void Init_qtgui()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");

        Init_QGuiApplication(rb_mQt6QtGui);
    });
}
