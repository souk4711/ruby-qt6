#include "qtguisetup-rb.hpp"

#include <rice/qt6/dllimport/qtcore.hpp>

void Init_qtguisetup(Rice::Module rb_mQt6)
{
    Rice::Module rb_mQt6QtCore = Rice::define_module_under(rb_mQt6, "QtCore");

    Init_rice_dllimport_qtcore(rb_mQt6QtCore);
}
