#include "qtuitoolsversion-rb.hpp"
#include <qtuitoolsversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtuitoolsversion(Module rb_mQt6QtUiTools)
{
    rb_mQt6QtUiTools.define_constant("QTUITOOLS_VERSION", QTUITOOLS_VERSION_STR);
}
