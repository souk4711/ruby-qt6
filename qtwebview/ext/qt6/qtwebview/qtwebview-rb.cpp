#include "qtwebview-rb.hpp"
#include "qtwebviewpreludes-rb.hpp"
#include "qtwebviewversion-rb.hpp"
#include "qtwebviewfunctions-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtwebview()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtWebView = define_module_under(rb_mQt6, "QtWebView");

        Init_qtwebviewpreludes(rb_mQt6);
        Init_qtwebviewversion(rb_mQt6QtWebView);
        Init_qtwebviewfunctions(rb_mQt6QtWebView);
    });
}
