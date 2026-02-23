#include "qtquick-rb.hpp"
#include "qtquickpreludes-rb.hpp"
#include "qtquickversion-rb.hpp"

#include "qquickitem-rb.hpp"
#include "qquickwindow-rb.hpp"
#include "qquickview-rb.hpp"

RICE4RUBYQT6_USE_NAMESPACE

extern "C" void Init_qtquick()
{
    return detail::cpp_protect([] {
        Module rb_mQt6 = define_module("RubyQt6");
        Module rb_mQt6QtQuick = define_module_under(rb_mQt6, "QtQuick");

        Init_qtquickpreludes(rb_mQt6);
        Init_qtquickversion(rb_mQt6QtQuick);

        Init_qquickitem(rb_mQt6QtQuick);
        Init_qquickwindow(rb_mQt6QtQuick);
        Init_qquickview(rb_mQt6QtQuick);
    });
}
