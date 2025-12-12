#include "qtquickcontrols2version-rb.hpp"
#include <qtquickcontrols2version.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtquickcontrols2version(Module rb_mQt6QtQuickControls2)
{
    rb_mQt6QtQuickControls2.define_constant("QTQUICKCONTROLS2_VERSION", QTQUICKCONTROLS2_VERSION_STR);
}
