#include "qtguiversion-rb.hpp"
#include <qtguiversion.h>

using namespace Rice;

void Init_qtguiversion(Rice::Module rb_mQt6QtGui)
{
    rb_mQt6QtGui.define_constant("QTGUI_VERSION", QTGUI_VERSION_STR);
}
