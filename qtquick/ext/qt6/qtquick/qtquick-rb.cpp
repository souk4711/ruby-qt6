#include "qtquick-rb.hpp"

// clang-format off
#include "qquickview-rb.hpp"
// clang-format on

extern "C" void Init_qtquick()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQucik = define_module_under(rb_mQt6, "QtQucik");

        Init_QQuickView(rb_mQt6QtQucik);
    });
}
