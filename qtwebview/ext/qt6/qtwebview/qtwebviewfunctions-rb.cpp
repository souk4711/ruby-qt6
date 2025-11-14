#include "qtwebviewfunctions-rb.hpp"
#include <qtwebviewfunctions.h>

using namespace Rice;

void Init_qtwebviewfunctions(Rice::Module rb_mQt6QtWebView)
{
    Module rb_mQtWebView =
        // RubyQt6::QtWebView::QtWebView
        define_module_under(rb_mQt6QtWebView, "QtWebView")
            // Static Public Members
            .define_singleton_function("initialize", &QtWebView::initialize);
}
