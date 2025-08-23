#include "qtquickcontrols2version-rb.hpp"
#include <qtquickcontrols2version.h>

using namespace Rice;

void Init_qtquickcontrols2version(Rice::Module rb_mQt6QtQuickControls2)
{
    rb_mQt6QtQuickControls2.define_constant("QTQUICKCONTROLS2_VERSION", QTQUICKCONTROLS2_VERSION_STR);
}
