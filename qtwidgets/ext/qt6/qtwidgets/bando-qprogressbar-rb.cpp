#include "bando-qprogressbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QProgressBar>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QProgressBar = BandoQWidget<QProgressBar, QWidget *>;

Class rb_mBando_cQProgressBar;

void Init_bando_qprogressbar(Module rb_mQt6Bando)
{
    rb_mBando_cQProgressBar =
        define_bando_qwidget_under<Bando_QProgressBar, QProgressBar>(rb_mQt6Bando, "QProgressBar")
            .define_constructor(Constructor<Bando_QProgressBar, QWidget *>(), Arg("parent"));
}
