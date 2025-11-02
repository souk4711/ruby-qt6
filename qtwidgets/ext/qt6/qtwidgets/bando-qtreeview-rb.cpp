#include "bando-qtreeview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTreeView>

using namespace Rice;

using Bando_QTreeView = BandoQWidget<QTreeView, QWidget *>;

Rice::Class rb_mBando_cQTreeView;

void Init_bando_qtreeview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTreeView =
        define_bando_qwidget_under<Bando_QTreeView, QTreeView>(rb_mQt6Bando, "QTreeView")
            .define_constructor(Constructor<Bando_QTreeView, QWidget *>(), Arg("parent"));
}
