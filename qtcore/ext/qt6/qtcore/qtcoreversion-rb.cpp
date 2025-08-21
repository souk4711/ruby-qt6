#include "qtcoreversion-rb.hpp"
#include <qtcoreversion.h>

using namespace Rice;

void Init_qtcoreversion(Rice::Module rb_mQt6QtCore)
{
    rb_mQt6QtCore.define_constant("QTCORE_VERSION", QTCORE_VERSION_STR);
}
