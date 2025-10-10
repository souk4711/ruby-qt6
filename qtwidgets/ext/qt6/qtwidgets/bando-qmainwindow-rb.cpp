#include "bando-qmainwindow-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMainWindow>

using namespace Rice;

using Bando_QMainWindow = BandoQWidget<QMainWindow, QWidget *>;

Rice::Class rb_mBando_cQMainWindow;

void Init_bando_qmainwindow(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQMainWindow =
        define_bando_qwidget_under<Bando_QMainWindow, QMainWindow>(rb_mQt6Bando, "QMainWindow")
            .define_constructor(Constructor<Bando_QMainWindow, QWidget *>(), Arg("parent"));
}
