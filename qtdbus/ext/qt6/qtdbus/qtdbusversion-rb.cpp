#include "qtdbusversion-rb.hpp"
#include <qtdbusversion.h>

using namespace Rice;

void Init_qtdbusversion(Rice::Module rb_mQt6QtDBus)
{
    rb_mQt6QtDBus.define_constant("QTDBUS_VERSION", QTDBUS_VERSION_STR);
}
