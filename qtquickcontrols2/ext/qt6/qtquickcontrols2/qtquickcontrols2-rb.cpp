#include "qtquickcontrols2-rb.hpp"
#include "qtquickcontrols2preludes-rb.hpp"
#include "qtquickcontrols2version-rb.hpp"

#include "qquickstyle-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtquickcontrols2()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtQuickControls2 = define_module_under(rb_mQt6, "QtQuickControls2");

        Init_qtquickcontrols2preludes(rb_mQt6);
        Init_qtquickcontrols2version(rb_mQt6QtQuickControls2);

        Init_qquickstyle(rb_mQt6QtQuickControls2);
    });
}
