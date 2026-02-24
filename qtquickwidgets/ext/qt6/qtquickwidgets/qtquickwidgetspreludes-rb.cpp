#include "qtquickwidgetspreludes-rb.hpp"
#include <rice/qt6/preludes/libqt6core.hpp>
#include <rice/qt6/preludes/libqt6gui.hpp>
#include <rice/qt6/preludes/libqt6widgets.hpp>
#include <rice/qt6/preludes/libqt6qml.hpp>
#include <rice/qt6/preludes/libqt6quick.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtquickwidgetspreludes(Module rb_mQt6)
{
    declare_qlass_under_libqt6core(rb_mQt6);
    declare_qlass_under_libqt6gui(rb_mQt6);
    declare_qlass_under_libqt6widgets(rb_mQt6);
    declare_qlass_under_libqt6qml(rb_mQt6);
    declare_qlass_under_libqt6quick(rb_mQt6);
}
