#include "qtwebenginewidgetsversion-rb.hpp"
#include <qtwebenginewidgetsversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtwebenginewidgetsversion(Module rb_mQt6QtWebEngineWidgets)
{
    rb_mQt6QtWebEngineWidgets.define_constant("QTWEBENGINEWIDGETS_VERSION", QTWEBENGINEWIDGETS_VERSION_STR);
}
