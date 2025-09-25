#include "qtquickwidgetsversion-rb.hpp"
#include <qtquickwidgetsversion.h>

using namespace Rice;

void Init_qtquickwidgetsversion(Rice::Module rb_mQt6QtQuickWidgets)
{
    rb_mQt6QtQuickWidgets.define_constant("QTQUICKWIDGETS_VERSION", QTQUICKWIDGETS_VERSION_STR);
}
