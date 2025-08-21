#include "qtwidgets-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");
    });
}
