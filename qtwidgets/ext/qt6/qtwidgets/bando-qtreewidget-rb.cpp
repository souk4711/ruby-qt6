#include "bando-qtreewidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTreeWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTreeWidget = BandoQWidget<QTreeWidget, QWidget *>;

Class rb_mBando_cQTreeWidget;

void Init_bando_qtreewidget(Module rb_mQt6Bando)
{
    rb_mBando_cQTreeWidget =
        define_bando_qwidget_under<Bando_QTreeWidget, QTreeWidget>(rb_mQt6Bando, "QTreeWidget")
            .define_constructor(Constructor<Bando_QTreeWidget, QWidget *>(), Arg("parent"));
}
