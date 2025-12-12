#include "bando-qmenu-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMenu>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QMenu = BandoQWidget<QMenu, const QString &, QWidget *>;

Class rb_mBando_cQMenu;

void Init_bando_qmenu(Module rb_mQt6Bando)
{
    rb_mBando_cQMenu =
        define_bando_qwidget_under<Bando_QMenu, QMenu>(rb_mQt6Bando, "QMenu")
            .define_constructor(Constructor<Bando_QMenu, const QString &, QWidget *>(), Arg("title"), Arg("parent"));
}
