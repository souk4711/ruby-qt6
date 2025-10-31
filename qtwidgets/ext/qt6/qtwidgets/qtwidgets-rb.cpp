#include "qtwidgets-rb.hpp"
#include "qtwidgetsversion-rb.hpp"

#include "qgraphicsitem-rb.hpp"
#include "qlayoutitem-rb.hpp"
#include "qsizepolicy-rb.hpp"
#include "qstylefactory-rb.hpp"
#include "qstyleoption-rb.hpp"
#include "qtooltip-rb.hpp"

#include "qabstractitemdelegate-rb.hpp"
#include "qitemdelegate-rb.hpp"
#include "qstyleditemdelegate-rb.hpp"
#include "qapplication-rb.hpp"
#include "qgraphicsobject-rb.hpp"
#include "qgraphicstextitem-rb.hpp"
#include "qgraphicswidget-rb.hpp"
#include "qgraphicsscene-rb.hpp"
#include "qlayout-rb.hpp"
#include "qboxlayout-rb.hpp"
#include "qformlayout-rb.hpp"
#include "qgridlayout-rb.hpp"
#include "qstackedlayout-rb.hpp"
#include "qstyle-rb.hpp"

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
#include "qabstractitemview-rb.hpp"
#include "qcolumnview-rb.hpp"
#include "qheaderview-rb.hpp"
#include "qlistview-rb.hpp"
#include "qlistwidget-rb.hpp"
#include "qtableview-rb.hpp"
#include "qtablewidget-rb.hpp"
#include "qtreeview-rb.hpp"
#include "qtreewidget-rb.hpp"
#include "qundoview-rb.hpp"
#include "qgraphicsview-rb.hpp"
#include "qmdiarea-rb.hpp"
#include "qplaintextedit-rb.hpp"
#include "qscrollarea-rb.hpp"
#include "qtextedit-rb.hpp"
#include "qtextbrowser-rb.hpp"
#include "qlabel-rb.hpp"
#include "qlcdnumber-rb.hpp"
#include "qsplitter-rb.hpp"
#include "qstackedwidget-rb.hpp"
#include "qtoolbox-rb.hpp"
#include "qdialogbuttonbox-rb.hpp"
#include "qdockwidget-rb.hpp"
#include "qfocusframe-rb.hpp"
#include "qgroupbox-rb.hpp"
#include "qkeysequenceedit-rb.hpp"
#include "qlineedit-rb.hpp"
#include "qmainwindow-rb.hpp"
#include "qmdisubwindow-rb.hpp"
#include "qmenu-rb.hpp"
#include "qmenubar-rb.hpp"
#include "qprogressbar-rb.hpp"
#include "qrubberband-rb.hpp"
#include "qsizegrip-rb.hpp"
#include "qsplashscreen-rb.hpp"
#include "qstatusbar-rb.hpp"
#include "qsystemtrayicon-rb.hpp"
#include "qtabbar-rb.hpp"
#include "qtabwidget-rb.hpp"
#include "qtoolbar-rb.hpp"

#include "t-qtwidgets-rb.hpp"

#include "bando-qitemdelegate-rb.hpp"
#include "bando-qstyleditemdelegate-rb.hpp"
#include "bando-qlayout-rb.hpp"
#include "bando-qwidget-rb.hpp"
#include "bando-qspinbox-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_qtwidgetsversion(rb_mQt6QtWidgets);

        Init_qgraphicsitem(rb_mQt6QtWidgets);
        Init_qlayoutitem(rb_mQt6QtWidgets);
        Init_qsizepolicy(rb_mQt6QtWidgets);
        Init_qstylefactory(rb_mQt6QtWidgets);
        Init_qstyleoption(rb_mQt6QtWidgets);
        Init_qtooltip(rb_mQt6QtWidgets);

        Init_qabstractitemdelegate(rb_mQt6QtWidgets);
        Init_qitemdelegate(rb_mQt6QtWidgets);
        Init_qstyleditemdelegate(rb_mQt6QtWidgets);
        Init_qapplication(rb_mQt6QtWidgets);
        Init_qgraphicsobject(rb_mQt6QtWidgets);
        Init_qgraphicstextitem(rb_mQt6QtWidgets);
        Init_qgraphicswidget(rb_mQt6QtWidgets);
        Init_qgraphicsscene(rb_mQt6QtWidgets);
        Init_qlayout(rb_mQt6QtWidgets);
        Init_qboxlayout(rb_mQt6QtWidgets);
        Init_qformlayout(rb_mQt6QtWidgets);
        Init_qgridlayout(rb_mQt6QtWidgets);
        Init_qstackedlayout(rb_mQt6QtWidgets);
        Init_qstyle(rb_mQt6QtWidgets);

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
        Init_qabstractitemview(rb_mQt6QtWidgets);
        Init_qcolumnview(rb_mQt6QtWidgets);
        Init_qheaderview(rb_mQt6QtWidgets);
        Init_qlistview(rb_mQt6QtWidgets);
        Init_qlistwidget(rb_mQt6QtWidgets);
        Init_qtableview(rb_mQt6QtWidgets);
        Init_qtablewidget(rb_mQt6QtWidgets);
        Init_qtreeview(rb_mQt6QtWidgets);
        Init_qtreewidget(rb_mQt6QtWidgets);
        Init_qundoview(rb_mQt6QtWidgets);
        Init_qgraphicsview(rb_mQt6QtWidgets);
        Init_qmdiarea(rb_mQt6QtWidgets);
        Init_qplaintextedit(rb_mQt6QtWidgets);
        Init_qscrollarea(rb_mQt6QtWidgets);
        Init_qtextedit(rb_mQt6QtWidgets);
        Init_qtextbrowser(rb_mQt6QtWidgets);
        Init_qlabel(rb_mQt6QtWidgets);
        Init_qlcdnumber(rb_mQt6QtWidgets);
        Init_qsplitter(rb_mQt6QtWidgets);
        Init_qstackedwidget(rb_mQt6QtWidgets);
        Init_qtoolbox(rb_mQt6QtWidgets);
        Init_qdialogbuttonbox(rb_mQt6QtWidgets);
        Init_qdockwidget(rb_mQt6QtWidgets);
        Init_qfocusframe(rb_mQt6QtWidgets);
        Init_qgroupbox(rb_mQt6QtWidgets);
        Init_qkeysequenceedit(rb_mQt6QtWidgets);
        Init_qlineedit(rb_mQt6QtWidgets);
        Init_qmainwindow(rb_mQt6QtWidgets);
        Init_qmdisubwindow(rb_mQt6QtWidgets);
        Init_qmenu(rb_mQt6QtWidgets);
        Init_qmenubar(rb_mQt6QtWidgets);
        Init_qprogressbar(rb_mQt6QtWidgets);
        Init_qrubberband(rb_mQt6QtWidgets);
        Init_qsizegrip(rb_mQt6QtWidgets);
        Init_qsplashscreen(rb_mQt6QtWidgets);
        Init_qstatusbar(rb_mQt6QtWidgets);
        Init_qsystemtrayicon(rb_mQt6QtWidgets);
        Init_qtabbar(rb_mQt6QtWidgets);
        Init_qtabwidget(rb_mQt6QtWidgets);
        Init_qtoolbar(rb_mQt6QtWidgets);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtwidgets(rb_mQt6T);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qitemdelegate(rb_mQt6Bando);
        Init_bando_qstyleditemdelegate(rb_mQt6Bando);
        Init_bando_qlayout(rb_mQt6Bando);
        Init_bando_qwidget(rb_mQt6Bando);
        Init_bando_qspinbox(rb_mQt6Bando);
    });
}
