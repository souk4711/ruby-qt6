#include "qtmultimediapreludes-rb.hpp"
#include <rice/qt6/preludes/libqt6core.hpp>
#include <rice/qt6/preludes/libqt6gui.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtmultimediapreludes(Module rb_mQt6)
{
    declare_qlass_under_libqt6core(rb_mQt6);
    declare_qlass_under_libqt6gui(rb_mQt6);
}
