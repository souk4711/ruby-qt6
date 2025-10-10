#include "bando-qtreewidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTreeWidget>

using namespace Rice;

using Bando_QTreeWidget = BandoQWidget<QTreeWidget, QWidget *>;

Rice::Class rb_mBando_cQTreeWidget;

void Init_bando_qtreewidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTreeWidget =
        define_bando_qwidget_under<Bando_QTreeWidget, QTreeWidget>(rb_mQt6Bando, "QTreeWidget")
            .define_constructor(Constructor<Bando_QTreeWidget, QWidget *>(), Arg("parent"));
}
