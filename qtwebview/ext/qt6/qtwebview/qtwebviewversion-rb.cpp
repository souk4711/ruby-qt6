#include "qtwebviewversion-rb.hpp"
#include <qtwebviewversion.h>

using namespace Rice;

void Init_qtwebviewversion(Rice::Module rb_mQt6QtWebView)
{
    rb_mQt6QtWebView.define_constant("QTWEBVIEW_VERSION", QTWEBVIEW_VERSION_STR);
}
