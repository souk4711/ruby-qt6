#include "bando-qtabwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTabWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTabWidget = BandoQWidget<QTabWidget, QWidget *>;

Class rb_mBando_cQTabWidget;

void Init_bando_qtabwidget(Module rb_mQt6Bando)
{
    rb_mBando_cQTabWidget =
        define_bando_qwidget_under<Bando_QTabWidget, QTabWidget>(rb_mQt6Bando, "QTabWidget")
            .define_constructor(Constructor<Bando_QTabWidget, QWidget *>(), Arg("parent"));
}
