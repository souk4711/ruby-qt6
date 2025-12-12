#include "bando-qstackedwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QStackedWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QStackedWidget = BandoQWidget<QStackedWidget, QWidget *>;

Class rb_mBando_cQStackedWidget;

void Init_bando_qstackedwidget(Module rb_mQt6Bando)
{
    rb_mBando_cQStackedWidget =
        define_bando_qwidget_under<Bando_QStackedWidget, QStackedWidget>(rb_mQt6Bando, "QStackedWidget")
            .define_constructor(Constructor<Bando_QStackedWidget, QWidget *>(), Arg("parent"));
}
