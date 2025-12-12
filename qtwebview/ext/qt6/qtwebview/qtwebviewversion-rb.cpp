#include "qtwebviewversion-rb.hpp"
#include <qtwebviewversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtwebviewversion(Module rb_mQt6QtWebView)
{
    rb_mQt6QtWebView.define_constant("QTWEBVIEW_VERSION", QTWEBVIEW_VERSION_STR);
}
