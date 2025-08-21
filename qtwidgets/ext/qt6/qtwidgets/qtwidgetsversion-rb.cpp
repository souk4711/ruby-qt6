#include "qtwidgetsversion-rb.hpp"
#include <qtwidgetsversion.h>

using namespace Rice;

void Init_qtwidgetsversion(Rice::Module rb_mQt6QtWidgets)
{
    rb_mQt6QtWidgets.define_constant("QTWIDGETS_VERSION", QTWIDGETS_VERSION_STR);
}
