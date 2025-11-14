#include "qtwebenginecore-rb.hpp"
#include "qtwebenginecoreversion-rb.hpp"

extern "C" void Init_qtwebenginecore()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWebEngineCore = define_module_under(rb_mQt6, "QtWebEngineCore");

        Init_qtwebenginecoreversion(rb_mQt6QtWebEngineCore);
    });
}
