#include "qtwebenginecore-rb.hpp"
#include "qtwebenginecoreversion-rb.hpp"

#include "qwebenginenotification-rb.hpp"
#include "qwebenginepage-rb.hpp"
#include "qwebengineprofile-rb.hpp"

extern "C" void Init_qtwebenginecore()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWebEngineCore = define_module_under(rb_mQt6, "QtWebEngineCore");

        Init_qtwebenginecoreversion(rb_mQt6QtWebEngineCore);

        Init_qwebenginenotification(rb_mQt6QtWebEngineCore);
        Init_qwebenginepage(rb_mQt6QtWebEngineCore);
        Init_qwebengineprofile(rb_mQt6QtWebEngineCore);
    });
}
