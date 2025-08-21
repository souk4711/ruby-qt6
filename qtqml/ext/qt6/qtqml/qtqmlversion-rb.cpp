#include "qtqmlversion-rb.hpp"
#include <qtqmlversion.h>

using namespace Rice;

void Init_qtqmlversion(Rice::Module rb_mQt6QtQml)
{
    rb_mQt6QtQml.define_constant("QTQML_VERSION", QTQML_VERSION_STR);
}
