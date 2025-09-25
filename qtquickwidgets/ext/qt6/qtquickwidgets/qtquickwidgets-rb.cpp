#include "qtquickwidgets-rb.hpp"
#include "qtquickwidgetsversion-rb.hpp"

#include "qquickwidget-rb.hpp"

extern "C" void Init_qtquickwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtQuickWidgets = define_module_under(rb_mQt6, "QtQuickWidgets");

        Init_qtquickwidgetsversion(rb_mQt6QtQuickWidgets);

        Init_qquickwidget(rb_mQt6QtQuickWidgets);
    });
}
