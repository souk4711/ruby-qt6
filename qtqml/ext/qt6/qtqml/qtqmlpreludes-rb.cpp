#include "qtqmlpreludes-rb.hpp"
#include <rice/qt6/preludes/libqt6core.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtqmlpreludes(Module rb_mQt6)
{
    declare_qlass_under_libqt6core(rb_mQt6);
}
