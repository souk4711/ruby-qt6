#include "qtquick-rb.hpp"

// clang-format off
#include "qtquickversion-rb.hpp"

#include "qquickwindow-rb.hpp"
#include "qquickview-rb.hpp"
// clang-format on

extern "C" void Init_qtquick()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("Qt6");
        Rice::Module rb_mQt6QtQuick = define_module_under(rb_mQt6, "QtQuick");

        Init_qtquickversion(rb_mQt6QtQuick);

        Init_qquickwindow(rb_mQt6QtQuick);
        Init_qquickview(rb_mQt6QtQuick);
    });
}
