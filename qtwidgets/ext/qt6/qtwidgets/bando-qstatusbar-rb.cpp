#include "bando-qstatusbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QStatusBar>

using namespace Rice;

using Bando_QStatusBar = BandoQWidget<QStatusBar, QWidget *>;

Rice::Class rb_mBando_cQStatusBar;

void Init_bando_qstatusbar(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQStatusBar =
        define_bando_qwidget_under<Bando_QStatusBar, QStatusBar>(rb_mQt6Bando, "QStatusBar")
            .define_constructor(Constructor<Bando_QStatusBar, QWidget *>(), Arg("parent"));
}
