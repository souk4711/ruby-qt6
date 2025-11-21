#include "qtnetworkversion-rb.hpp"
#include <qtnetworkversion.h>

using namespace Rice;

void Init_qtnetworkversion(Rice::Module rb_mQt6QtNetwork)
{
    rb_mQt6QtNetwork.define_constant("QTNETWORK_VERSION", QTNETWORK_VERSION_STR);
}
