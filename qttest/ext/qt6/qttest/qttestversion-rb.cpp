#include "qttestversion-rb.hpp"
#include <qttestversion.h>

using namespace Rice;

void Init_qttestversion(Rice::Module rb_mQt6QtTest)
{
    rb_mQt6QtTest.define_constant("QTTEST_VERSION", QTTEST_VERSION_STR);
}
