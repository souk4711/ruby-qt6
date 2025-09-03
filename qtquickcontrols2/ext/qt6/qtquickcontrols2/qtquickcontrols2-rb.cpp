#include "qtquickcontrols2-rb.hpp"
#include "qtquickcontrols2version-rb.hpp"

#include "qquickstyle-rb.hpp"

extern "C" void Init_qtquickcontrols2()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtQuickControls2 = define_module_under(rb_mQt6, "QtQuickControls2");

        Init_qtquickcontrols2version(rb_mQt6QtQuickControls2);

        Init_qquickstyle(rb_mQt6QtQuickControls2);
    });
}
