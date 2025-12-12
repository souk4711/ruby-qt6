#include "bando-qwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;

Class rb_mBando_cQWidget;

void Init_bando_qwidget(Module rb_mQt6Bando)
{
    rb_mBando_cQWidget =
        define_bando_qwidget_under<Bando_QWidget, QWidget>(rb_mQt6Bando, "QWidget")
            .define_constructor(Constructor<Bando_QWidget, QWidget *>(), Arg("parent"));
}
