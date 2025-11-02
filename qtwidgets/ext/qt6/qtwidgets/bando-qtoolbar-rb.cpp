#include "bando-qtoolbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QToolBar>

using namespace Rice;

using Bando_QToolBar = BandoQWidget<QToolBar, const QString &, QWidget *>;

Rice::Class rb_mBando_cQToolBar;

void Init_bando_qtoolbar(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQToolBar =
        define_bando_qwidget_under<Bando_QToolBar, QToolBar>(rb_mQt6Bando, "QToolBar")
            .define_constructor(Constructor<Bando_QToolBar, const QString &, QWidget *>(), Arg("title"), Arg("parent"));
}
