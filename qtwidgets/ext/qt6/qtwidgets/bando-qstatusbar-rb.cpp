#include "bando-qstatusbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QStatusBar>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QStatusBar = BandoQWidget<QStatusBar, QWidget *>;

Class rb_mBando_cQStatusBar;

void Init_bando_qstatusbar(Module rb_mQt6Bando)
{
    rb_mBando_cQStatusBar =
        define_bando_qwidget_under<Bando_QStatusBar, QStatusBar>(rb_mQt6Bando, "QStatusBar")
            .define_constructor(Constructor<Bando_QStatusBar, QWidget *>(), Arg("parent"));
}
