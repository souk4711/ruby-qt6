#include "bando-qtabbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTabBar>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTabBar = BandoQWidget<QTabBar, QWidget *>;

Class rb_mBando_cQTabBar;

void Init_bando_qtabbar(Module rb_mQt6Bando)
{
    rb_mBando_cQTabBar =
        define_bando_qwidget_under<Bando_QTabBar, QTabBar>(rb_mQt6Bando, "QTabBar")
            .define_constructor(Constructor<Bando_QTabBar, QWidget *>(), Arg("parent"));
}
