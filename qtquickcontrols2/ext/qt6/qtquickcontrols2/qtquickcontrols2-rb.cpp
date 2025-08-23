#include "qtquickcontrols2-rb.hpp"

// clang-format off
#include "qtquickcontrols2version-rb.hpp"
// clang-format on

extern "C" void Init_qtquickcontrols2()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtQuickControls2 = define_module_under(rb_mQt6, "QtQuickControls2");

        Init_qtquickcontrols2version(rb_mQt6QtQuickControls2);
    });
}
