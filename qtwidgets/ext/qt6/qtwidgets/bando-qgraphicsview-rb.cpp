#include "bando-qgraphicsview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QGraphicsView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QGraphicsView = BandoQWidget<QGraphicsView, QWidget *>;

Class rb_mBando_cQGraphicsView;

void Init_bando_qgraphicsview(Module rb_mQt6Bando)
{
    rb_mBando_cQGraphicsView =
        define_bando_qwidget_under<Bando_QGraphicsView, QGraphicsView>(rb_mQt6Bando, "QGraphicsView")
            .define_constructor(Constructor<Bando_QGraphicsView, QWidget *>(), Arg("parent"));
}
