#include "qtwebenginewidgetsversion-rb.hpp"
#include <qtwebenginewidgetsversion.h>

using namespace Rice;

void Init_qtwebenginewidgetsversion(Rice::Module rb_mQt6QtWebEngineWidgets)
{
    rb_mQt6QtWebEngineWidgets.define_constant("QTWEBENGINEWIDGETS_VERSION", QTWEBENGINEWIDGETS_VERSION_STR);
}
