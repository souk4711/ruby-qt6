#include "qtwebview-rb.hpp"
#include "qtwebviewversion-rb.hpp"
#include "qtwebviewfunctions-rb.hpp"

extern "C" void Init_qtwebview()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWebView = define_module_under(rb_mQt6, "QtWebView");

        Init_qtwebviewversion(rb_mQt6QtWebView);
        Init_qtwebviewfunctions(rb_mQt6QtWebView);
    });
}
