#include "qtqml-rb.hpp"

// clang-format off
// clang-format on

extern "C" void Init_qtqml()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQml = define_module_under(rb_mQt6, "QtQml");
    });
}
