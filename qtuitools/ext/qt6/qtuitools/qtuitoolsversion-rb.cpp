#include "qtuitoolsversion-rb.hpp"
#include <qtuitoolsversion.h>

using namespace Rice;

void Init_qtuitoolsversion(Rice::Module rb_mQt6QtUiTools)
{
    rb_mQt6QtUiTools.define_constant("QTUITOOLS_VERSION", QTUITOOLS_VERSION_STR);
}
