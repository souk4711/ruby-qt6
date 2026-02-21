#include "qtwebenginewidgets-rb.hpp"
#include "qtwebenginewidgetspreludes-rb.hpp"
#include "qtwebenginewidgetsversion-rb.hpp"

#include "qwebengineview-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtwebenginewidgets()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtWebEngineWidgets = define_module_under(rb_mQt6, "QtWebEngineWidgets");

        Init_qtwebenginewidgetspreludes(rb_mQt6);
        Init_qtwebenginewidgetsversion(rb_mQt6QtWebEngineWidgets);

        Init_qwebengineview(rb_mQt6QtWebEngineWidgets);
    });
}
