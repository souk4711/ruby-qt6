#include "qtprintsupportversion-rb.hpp"
#include <qtprintsupportversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtprintsupportversion(Module rb_mQt6QtPrintSupport)
{
    rb_mQt6QtPrintSupport.define_constant("QTPRINTSUPPORT_VERSION", QTPRINTSUPPORT_VERSION_STR);
}
