#include "qtquickpreludes-rb.hpp"
#include <rice/qt6/preludes/libqt6core.hpp>
#include <rice/qt6/preludes/libqt6gui.hpp>
#include <rice/qt6/preludes/libqt6qml.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtquickpreludes(Module rb_mQt6)
{
    declare_qlass_under_libqt6core(rb_mQt6);
    declare_qlass_under_libqt6gui(rb_mQt6);
    declare_qlass_under_libqt6qml(rb_mQt6);
}
