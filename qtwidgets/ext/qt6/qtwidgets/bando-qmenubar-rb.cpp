#include "bando-qmenubar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMenuBar>

using namespace Rice;

using Bando_QMenuBar = BandoQWidget<QMenuBar, QWidget *>;

Rice::Class rb_mBando_cQMenuBar;

void Init_bando_qmenubar(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQMenuBar =
        define_bando_qwidget_under<Bando_QMenuBar, QMenuBar>(rb_mQt6Bando, "QMenuBar")
            .define_constructor(Constructor<Bando_QMenuBar, QWidget *>(), Arg("parent"));
}
