#include "qtwidgetssetup-rb.hpp"

#include <rice/qt6/dllimport/qtcore.hpp>
#include <rice/qt6/dllimport/qtgui.hpp>

void Init_qtwidgetssetup(Rice::Module rb_mQt6)
{
    Rice::Module rb_mQt6QtCore = Rice::define_module_under(rb_mQt6, "QtCore");
    Rice::Module rb_mQt6QtGui = Rice::define_module_under(rb_mQt6, "QtGui");

    Init_rice_dllimport_qtcore(rb_mQt6QtCore);
    Init_rice_dllimport_qtgui(rb_mQt6QtGui);
}
