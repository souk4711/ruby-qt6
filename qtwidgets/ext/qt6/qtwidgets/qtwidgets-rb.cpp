#include "qtwidgets-rb.hpp"
#include "qtwidgetsversion-rb.hpp"

#include "qlayoutitem-rb.hpp"
#include "qsizepolicy-rb.hpp"
#include "qtooltip-rb.hpp"

#include "qapplication-rb.hpp"
#include "qstyle-rb.hpp"
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

#include "bando-qlayout-rb.hpp"
#include "bando-qwidget-rb.hpp"
#include "bando-qcheckbox-rb.hpp"
#include "bando-qpushbutton-rb.hpp"
#include "bando-qcommandlinkbutton-rb.hpp"
#include "bando-qradiobutton-rb.hpp"
#include "bando-qtoolbutton-rb.hpp"
#include "bando-qdial-rb.hpp"
#include "bando-qscrollbar-rb.hpp"
#include "bando-qslider-rb.hpp"
#include "bando-qdatetimeedit-rb.hpp"
#include "bando-qspinbox-rb.hpp"
#include "bando-qcalendarwidget-rb.hpp"
#include "bando-qcombobox-rb.hpp"
#include "bando-qfontcombobox-rb.hpp"
#include "bando-qdialog-rb.hpp"
#include "bando-qcolordialog-rb.hpp"
#include "bando-qerrormessage-rb.hpp"
#include "bando-qfiledialog-rb.hpp"
#include "bando-qfontdialog-rb.hpp"
#include "bando-qinputdialog-rb.hpp"
#include "bando-qmessagebox-rb.hpp"
#include "bando-qprogressdialog-rb.hpp"
#include "bando-qwizard-rb.hpp"
#include "bando-qframe-rb.hpp"
#include "bando-qabstractscrollarea-rb.hpp"
#include "bando-qcolumnview-rb.hpp"
#include "bando-qheaderview-rb.hpp"
#include "bando-qlistview-rb.hpp"
#include "bando-qlistwidget-rb.hpp"
#include "bando-qtableview-rb.hpp"
#include "bando-qtablewidget-rb.hpp"
#include "bando-qtreeview-rb.hpp"
#include "bando-qtreewidget-rb.hpp"
#include "bando-qundoview-rb.hpp"
#include "bando-qgraphicsview-rb.hpp"
#include "bando-qmdiarea-rb.hpp"
#include "bando-qplaintextedit-rb.hpp"
#include "bando-qscrollarea-rb.hpp"
#include "bando-qtextedit-rb.hpp"
#include "bando-qtextbrowser-rb.hpp"
#include "bando-qlabel-rb.hpp"
#include "bando-qlcdnumber-rb.hpp"
#include "bando-qsplitter-rb.hpp"
#include "bando-qstackedwidget-rb.hpp"
#include "bando-qtoolbox-rb.hpp"
#include "bando-qdialogbuttonbox-rb.hpp"
#include "bando-qdockwidget-rb.hpp"
#include "bando-qfocusframe-rb.hpp"
#include "bando-qgroupbox-rb.hpp"
#include "bando-qkeysequenceedit-rb.hpp"
#include "bando-qlineedit-rb.hpp"
#include "bando-qmainwindow-rb.hpp"
#include "bando-qmdisubwindow-rb.hpp"
#include "bando-qmenu-rb.hpp"
#include "bando-qmenubar-rb.hpp"
#include "bando-qprogressbar-rb.hpp"
#include "bando-qrubberband-rb.hpp"
#include "bando-qsizegrip-rb.hpp"
#include "bando-qsplashscreen-rb.hpp"
#include "bando-qstatusbar-rb.hpp"
#include "bando-qsystemtrayicon-rb.hpp"
#include "bando-qtabbar-rb.hpp"
#include "bando-qtabwidget-rb.hpp"
#include "bando-qtoolbar-rb.hpp"

extern "C" void Init_qtwidgets()
{
    return Rice::detail::cpp_protect([] {
        Rice::Module rb_mQt6 = Rice::define_module("RubyQt6");
        Rice::Module rb_mQt6QtWidgets = define_module_under(rb_mQt6, "QtWidgets");

        Init_qtwidgetsversion(rb_mQt6QtWidgets);

        Init_qsizepolicy(rb_mQt6QtWidgets);
        Init_qlayoutitem(rb_mQt6QtWidgets);

        Init_qapplication(rb_mQt6QtWidgets);
        Init_qstyle(rb_mQt6QtWidgets);
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
        Init_qtooltip(rb_mQt6QtWidgets);
        Init_qsplashscreen(rb_mQt6QtWidgets);
        Init_qstatusbar(rb_mQt6QtWidgets);
        Init_qsystemtrayicon(rb_mQt6QtWidgets);
        Init_qtabbar(rb_mQt6QtWidgets);
        Init_qtabwidget(rb_mQt6QtWidgets);
        Init_qtoolbar(rb_mQt6QtWidgets);

        Rice::Module rb_mQt6T = define_module_under(rb_mQt6, "T");
        Init_t_qtwidgets(rb_mQt6T);

        Rice::Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
        Init_bando_qlayout(rb_mQt6Bando);
        Init_bando_qwidget(rb_mQt6Bando);
        Init_bando_qcheckbox(rb_mQt6Bando);
        Init_bando_qpushbutton(rb_mQt6Bando);
        Init_bando_qcommandlinkbutton(rb_mQt6Bando);
        Init_bando_qradiobutton(rb_mQt6Bando);
        Init_bando_qtoolbutton(rb_mQt6Bando);
        Init_bando_qdial(rb_mQt6Bando);
        Init_bando_qscrollbar(rb_mQt6Bando);
        Init_bando_qslider(rb_mQt6Bando);
        Init_bando_qdatetimeedit(rb_mQt6Bando);
        Init_bando_qspinbox(rb_mQt6Bando);
        Init_bando_qcalendarwidget(rb_mQt6Bando);
        Init_bando_qcombobox(rb_mQt6Bando);
        Init_bando_qfontcombobox(rb_mQt6Bando);
        Init_bando_qdialog(rb_mQt6Bando);
        Init_bando_qcolordialog(rb_mQt6Bando);
        Init_bando_qerrormessage(rb_mQt6Bando);
        Init_bando_qfiledialog(rb_mQt6Bando);
        Init_bando_qfontdialog(rb_mQt6Bando);
        Init_bando_qinputdialog(rb_mQt6Bando);
        Init_bando_qmessagebox(rb_mQt6Bando);
        Init_bando_qprogressdialog(rb_mQt6Bando);
        Init_bando_qwizard(rb_mQt6Bando);
        Init_bando_qframe(rb_mQt6Bando);
        Init_bando_qabstractscrollarea(rb_mQt6Bando);
        Init_bando_qcolumnview(rb_mQt6Bando);
        Init_bando_qheaderview(rb_mQt6Bando);
        Init_bando_qlistview(rb_mQt6Bando);
        Init_bando_qlistwidget(rb_mQt6Bando);
        Init_bando_qtableview(rb_mQt6Bando);
        Init_bando_qtablewidget(rb_mQt6Bando);
        Init_bando_qtreeview(rb_mQt6Bando);
        Init_bando_qtreewidget(rb_mQt6Bando);
        Init_bando_qundoview(rb_mQt6Bando);
        Init_bando_qgraphicsview(rb_mQt6Bando);
        Init_bando_qmdiarea(rb_mQt6Bando);
        Init_bando_qplaintextedit(rb_mQt6Bando);
        Init_bando_qscrollarea(rb_mQt6Bando);
        Init_bando_qtextedit(rb_mQt6Bando);
        Init_bando_qtextbrowser(rb_mQt6Bando);
        Init_bando_qlabel(rb_mQt6Bando);
        Init_bando_qlcdnumber(rb_mQt6Bando);
        Init_bando_qsplitter(rb_mQt6Bando);
        Init_bando_qstackedwidget(rb_mQt6Bando);
        Init_bando_qtoolbox(rb_mQt6Bando);
        Init_bando_qdialogbuttonbox(rb_mQt6Bando);
        Init_bando_qdockwidget(rb_mQt6Bando);
        Init_bando_qfocusframe(rb_mQt6Bando);
        Init_bando_qgroupbox(rb_mQt6Bando);
        Init_bando_qkeysequenceedit(rb_mQt6Bando);
        Init_bando_qlineedit(rb_mQt6Bando);
        Init_bando_qmainwindow(rb_mQt6Bando);
        Init_bando_qmdisubwindow(rb_mQt6Bando);
        Init_bando_qmenu(rb_mQt6Bando);
        Init_bando_qmenubar(rb_mQt6Bando);
        Init_bando_qprogressbar(rb_mQt6Bando);
        Init_bando_qrubberband(rb_mQt6Bando);
        Init_bando_qsizegrip(rb_mQt6Bando);
        Init_bando_qsplashscreen(rb_mQt6Bando);
        Init_bando_qstatusbar(rb_mQt6Bando);
        Init_bando_qsystemtrayicon(rb_mQt6Bando);
        Init_bando_qtabbar(rb_mQt6Bando);
        Init_bando_qtabwidget(rb_mQt6Bando);
        Init_bando_qtoolbar(rb_mQt6Bando);
    });
}
