#include "qtguiversion-rb.hpp"
#include <qtguiversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtguiversion(Module rb_mQt6QtGui)
{
    rb_mQt6QtGui.define_constant("QTGUI_VERSION", QTGUI_VERSION_STR);
}
