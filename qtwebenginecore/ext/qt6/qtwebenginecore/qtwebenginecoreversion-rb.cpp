#include "qtwebenginecoreversion-rb.hpp"
#include <qtwebenginecoreversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtwebenginecoreversion(Module rb_mQt6QtWebEngineCore)
{
    rb_mQt6QtWebEngineCore.define_constant("QTWEBENGINECORE_VERSION", QTWEBENGINECORE_VERSION_STR);
}
