#include "qtquickwidgetsversion-rb.hpp"
#include <qtquickwidgetsversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtquickwidgetsversion(Module rb_mQt6QtQuickWidgets)
{
    rb_mQt6QtQuickWidgets.define_constant("QTQUICKWIDGETS_VERSION", QTQUICKWIDGETS_VERSION_STR);
}
