#include "qtwidgets-rb.hpp"
#include "qtwidgetsversion-rb.hpp"

#include "qwidget-rb.hpp"
#include "qlayoutitem-rb.hpp"
#include "qlayout-rb.hpp"
#include "qboxlayout-rb.hpp"
#include "qformlayout-rb.hpp"
#include "qgridlayout-rb.hpp"
#include "qstackedlayout-rb.hpp"

#include "qabstractbutton-rb.hpp"
#include "qpushbutton-rb.hpp"

#include "qabstractslider-rb.hpp"
#include "qslider-rb.hpp"

#include "qframe-rb.hpp"
#include "qlabel-rb.hpp"
#include "qlcdnumber-rb.hpp"

#include "qapplication-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_qtwidgetsversion(rb_mQt6QtWidgets);

        Init_qwidget(rb_mQt6QtWidgets);
        Init_qlayoutitem(rb_mQt6QtWidgets);
        Init_qlayout(rb_mQt6QtWidgets);
        Init_qboxlayout(rb_mQt6QtWidgets);
        Init_qformlayout(rb_mQt6QtWidgets);
        Init_qgridlayout(rb_mQt6QtWidgets);
        Init_qstackedlayout(rb_mQt6QtWidgets);

        Init_qabstractbutton(rb_mQt6QtWidgets);
        Init_qpushbutton(rb_mQt6QtWidgets);

        Init_qabstractslider(rb_mQt6QtWidgets);
        Init_qslider(rb_mQt6QtWidgets);

        Init_qframe(rb_mQt6QtWidgets);
        Init_qlabel(rb_mQt6QtWidgets);
        Init_qlcdnumber(rb_mQt6QtWidgets);

        Init_qapplication(rb_mQt6QtWidgets);
    });
}
