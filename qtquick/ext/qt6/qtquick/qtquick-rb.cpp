#include "qtquick-rb.hpp"
#include "qtquickversion-rb.hpp"

#include "qquickwindow-rb.hpp"
#include "qquickview-rb.hpp"
#include "qquickitem-rb.hpp"

#include "bando-rb.hpp"

extern "C" void Init_qtquick()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtQuick = define_module_under(rb_mQt6, "QtQuick");

        Init_qtquickversion(rb_mQt6QtQuick);

        Init_qquickwindow(rb_mQt6QtQuick);
        Init_qquickview(rb_mQt6QtQuick);
        Init_qquickitem(rb_mQt6QtQuick);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando(rb_mQt6Bando);
    });
}
