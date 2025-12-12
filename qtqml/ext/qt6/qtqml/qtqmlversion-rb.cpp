#include "qtqmlversion-rb.hpp"
#include <qtqmlversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtqmlversion(Module rb_mQt6QtQml)
{
    rb_mQt6QtQml.define_constant("QTQML_VERSION", QTQML_VERSION_STR);
}
