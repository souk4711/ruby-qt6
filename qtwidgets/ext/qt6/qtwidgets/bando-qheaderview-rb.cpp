#include "bando-qheaderview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QHeaderView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QHeaderView = BandoQWidget<QHeaderView, Qt::Orientation, QWidget *>;

Class rb_mBando_cQHeaderView;

void Init_bando_qheaderview(Module rb_mQt6Bando)
{
    rb_mBando_cQHeaderView =
        define_bando_qwidget_under<Bando_QHeaderView, QHeaderView>(rb_mQt6Bando, "QHeaderView")
            .define_constructor(Constructor<Bando_QHeaderView, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
