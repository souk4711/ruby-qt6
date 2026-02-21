#include "qtquickwidgets-rb.hpp"
#include "qtquickwidgetspreludes-rb.hpp"
#include "qtquickwidgetsversion-rb.hpp"

#include "qquickwidget-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtquickwidgets()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtQuickWidgets = define_module_under(rb_mQt6, "QtQuickWidgets");

        Init_qtquickwidgetspreludes(rb_mQt6);
        Init_qtquickwidgetsversion(rb_mQt6QtQuickWidgets);

        Init_qquickwidget(rb_mQt6QtQuickWidgets);
    });
}
