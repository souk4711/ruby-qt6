#include "qtwidgets-rb.hpp"
#include "qtwidgetsversion-rb.hpp"

#include "qlayoutitem-rb.hpp"
#include "qsizepolicy-rb.hpp"

#include "qapplication-rb.hpp"
#include "qlayout-rb.hpp"
#include "qboxlayout-rb.hpp"
#include "qformlayout-rb.hpp"
#include "qgridlayout-rb.hpp"
#include "qstackedlayout-rb.hpp"

#include "qwidget-rb.hpp"
#include "qabstractbutton-rb.hpp"
#include "qcheckbox-rb.hpp"
#include "qpushbutton-rb.hpp"
#include "qcommandlinkbutton-rb.hpp"
#include "qradiobutton-rb.hpp"
#include "qtoolbutton-rb.hpp"
#include "qabstractslider-rb.hpp"
#include "qdial-rb.hpp"
#include "qscrollbar-rb.hpp"
#include "qslider-rb.hpp"
#include "qabstractspinbox-rb.hpp"
#include "qdatetimeedit-rb.hpp"
#include "qspinbox-rb.hpp"
#include "qcalendarwidget-rb.hpp"
#include "qcombobox-rb.hpp"
#include "qfontcombobox-rb.hpp"
#include "qdialog-rb.hpp"
#include "qcolordialog-rb.hpp"
#include "qerrormessage-rb.hpp"
#include "qfiledialog-rb.hpp"
#include "qfontdialog-rb.hpp"
#include "qinputdialog-rb.hpp"
#include "qmessagebox-rb.hpp"
#include "qprogressdialog-rb.hpp"
#include "qwizard-rb.hpp"
#include "qframe-rb.hpp"
#include "qabstractscrollarea-rb.hpp"
#include "qlabel-rb.hpp"
#include "qlcdnumber-rb.hpp"
#include "qlineedit-rb.hpp"

#include "bando-qtwidgets-layout-rb.hpp"
#include "bando-qtwidgets-widget-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_qtwidgetsversion(rb_mQt6QtWidgets);

        Init_qsizepolicy(rb_mQt6QtWidgets);
        Init_qlayoutitem(rb_mQt6QtWidgets);

        Init_qapplication(rb_mQt6QtWidgets);
        Init_qlayout(rb_mQt6QtWidgets);
        Init_qboxlayout(rb_mQt6QtWidgets);
        Init_qformlayout(rb_mQt6QtWidgets);
        Init_qgridlayout(rb_mQt6QtWidgets);
        Init_qstackedlayout(rb_mQt6QtWidgets);

        Init_qwidget(rb_mQt6QtWidgets);
        Init_qabstractbutton(rb_mQt6QtWidgets);
        Init_qcheckbox(rb_mQt6QtWidgets);
        Init_qpushbutton(rb_mQt6QtWidgets);
        Init_qcommandlinkbutton(rb_mQt6QtWidgets);
        Init_qradiobutton(rb_mQt6QtWidgets);
        Init_qtoolbutton(rb_mQt6QtWidgets);
        Init_qabstractslider(rb_mQt6QtWidgets);
        Init_qdial(rb_mQt6QtWidgets);
        Init_qscrollbar(rb_mQt6QtWidgets);
        Init_qslider(rb_mQt6QtWidgets);
        Init_qabstractspinbox(rb_mQt6QtWidgets);
        Init_qdatetimeedit(rb_mQt6QtWidgets);
        Init_qspinbox(rb_mQt6QtWidgets);
        Init_qcalendarwidget(rb_mQt6QtWidgets);
        Init_qcombobox(rb_mQt6QtWidgets);
        Init_qfontcombobox(rb_mQt6QtWidgets);
        Init_qdialog(rb_mQt6QtWidgets);
        Init_qcolordialog(rb_mQt6QtWidgets);
        Init_qerrormessage(rb_mQt6QtWidgets);
        Init_qfiledialog(rb_mQt6QtWidgets);
        Init_qfontdialog(rb_mQt6QtWidgets);
        Init_qinputdialog(rb_mQt6QtWidgets);
        Init_qmessagebox(rb_mQt6QtWidgets);
        Init_qprogressdialog(rb_mQt6QtWidgets);
        Init_qwizard(rb_mQt6QtWidgets);
        Init_qframe(rb_mQt6QtWidgets);
        Init_qabstractscrollarea(rb_mQt6QtWidgets);
        Init_qlabel(rb_mQt6QtWidgets);
        Init_qlcdnumber(rb_mQt6QtWidgets);
        Init_qlineedit(rb_mQt6QtWidgets);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qtwidgets_layout(rb_mQt6Bando);
        Init_bando_qtwidgets_widget(rb_mQt6Bando);
    });
}
