#include "qtquick-rb.hpp"

// clang-format off
#include "qquickwindow-rb.hpp"
#include "qquickview-rb.hpp"
// clang-format on

extern "C" void Init_qtquick()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQuick = define_module_under(rb_mQt6, "QtQuick");

        Init_QQuickWindow(rb_mQt6QtQuick);
        Init_QQuickView(rb_mQt6QtQuick);
    });
}
