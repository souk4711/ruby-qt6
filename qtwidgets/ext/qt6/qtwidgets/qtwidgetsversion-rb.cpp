#include "qtwidgetsversion-rb.hpp"
#include <qtwidgetsversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtwidgetsversion(Module rb_mQt6QtWidgets)
{
    rb_mQt6QtWidgets.define_constant("QTWIDGETS_VERSION", QTWIDGETS_VERSION_STR);
}
