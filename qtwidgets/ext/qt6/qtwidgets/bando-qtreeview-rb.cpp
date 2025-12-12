#include "bando-qtreeview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTreeView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTreeView = BandoQWidget<QTreeView, QWidget *>;

Class rb_mBando_cQTreeView;

void Init_bando_qtreeview(Module rb_mQt6Bando)
{
    rb_mBando_cQTreeView =
        define_bando_qwidget_under<Bando_QTreeView, QTreeView>(rb_mQt6Bando, "QTreeView")
            .define_constructor(Constructor<Bando_QTreeView, QWidget *>(), Arg("parent"));
}
