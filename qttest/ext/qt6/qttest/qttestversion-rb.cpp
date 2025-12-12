#include "qttestversion-rb.hpp"
#include <qttestversion.h>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qttestversion(Module rb_mQt6QtTest)
{
    rb_mQt6QtTest.define_constant("QTTEST_VERSION", QTTEST_VERSION_STR);
}
