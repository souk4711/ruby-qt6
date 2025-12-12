#include "qtdbusversion-rb.hpp"
#include <qtdbusversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtdbusversion(Module rb_mQt6QtDBus)
{
    rb_mQt6QtDBus.define_constant("QTDBUS_VERSION", QTDBUS_VERSION_STR);
}
