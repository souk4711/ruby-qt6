#include "qt-rb.hpp"

using namespace Rice;

void Init_Qt(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt = define_module_under(rb_mQt6QtCore, "Qt");
}
