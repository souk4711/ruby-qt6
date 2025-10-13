#include "qtprintsupportversion-rb.hpp"
#include <qtprintsupportversion.h>

using namespace Rice;

void Init_qtprintsupportversion(Rice::Module rb_mQt6QtPrintSupport)
{
    rb_mQt6QtPrintSupport.define_constant("QTPRINTSUPPORT_VERSION", QTPRINTSUPPORT_VERSION_STR);
}
