#include "bando-qmdisubwindow-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMdiSubWindow>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QMdiSubWindow = BandoQWidget<QMdiSubWindow, QWidget *>;

Class rb_mBando_cQMdiSubWindow;

void Init_bando_qmdisubwindow(Module rb_mQt6Bando)
{
    rb_mBando_cQMdiSubWindow =
        define_bando_qwidget_under<Bando_QMdiSubWindow, QMdiSubWindow>(rb_mQt6Bando, "QMdiSubWindow")
            .define_constructor(Constructor<Bando_QMdiSubWindow, QWidget *>(), Arg("parent"));
}
