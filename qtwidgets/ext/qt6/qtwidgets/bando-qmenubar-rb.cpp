#include "bando-qmenubar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMenuBar>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QMenuBar = BandoQWidget<QMenuBar, QWidget *>;

Class rb_mBando_cQMenuBar;

void Init_bando_qmenubar(Module rb_mQt6Bando)
{
    rb_mBando_cQMenuBar =
        define_bando_qwidget_under<Bando_QMenuBar, QMenuBar>(rb_mQt6Bando, "QMenuBar")
            .define_constructor(Constructor<Bando_QMenuBar, QWidget *>(), Arg("parent"));
}
