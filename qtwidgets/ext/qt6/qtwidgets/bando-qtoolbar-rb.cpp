#include "bando-qtoolbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QToolBar>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QToolBar = BandoQWidget<QToolBar, QWidget *>;

Class rb_mBando_cQToolBar;

void Init_bando_qtoolbar(Module rb_mQt6Bando)
{
    rb_mBando_cQToolBar =
        define_bando_qwidget_under<Bando_QToolBar, QToolBar>(rb_mQt6Bando, "QToolBar")
            .define_constructor(Constructor<Bando_QToolBar, QWidget *>(), Arg("parent"));
}
