#include "qtquick-rb.hpp"

extern "C" void Init_qtquick()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQuick = define_module_under(rb_mQt6, "QtQuick");
    });
}
