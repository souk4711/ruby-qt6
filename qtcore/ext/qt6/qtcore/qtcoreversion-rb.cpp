#include "qtcoreversion-rb.hpp"
#include <qtcoreversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtcoreversion(Module rb_mQt6QtCore)
{
    rb_mQt6QtCore.define_constant("QTCORE_VERSION", QTCORE_VERSION_STR);
}
