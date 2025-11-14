#include "qtwebenginecoreversion-rb.hpp"
#include <qtwebenginecoreversion.h>

using namespace Rice;

void Init_qtwebenginecoreversion(Rice::Module rb_mQt6QtWebEngineCore)
{
    rb_mQt6QtWebEngineCore.define_constant("QTWEBENGINECORE_VERSION", QTWEBENGINECORE_VERSION_STR);
}
