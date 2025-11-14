#include "qtwebenginewidgets-rb.hpp"
#include "qtwebenginewidgetsversion-rb.hpp"

extern "C" void Init_qtwebenginewidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWebEngineWidgets = define_module_under(rb_mQt6, "QtWebEngineWidgets");

        Init_qtwebenginewidgetsversion(rb_mQt6QtWebEngineWidgets);
    });
}
