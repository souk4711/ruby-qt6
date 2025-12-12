#include "qtnetworkversion-rb.hpp"
#include <qtnetworkversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtnetworkversion(Module rb_mQt6QtNetwork)
{
    rb_mQt6QtNetwork.define_constant("QTNETWORK_VERSION", QTNETWORK_VERSION_STR);
}
