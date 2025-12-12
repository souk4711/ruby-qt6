#include "bando-qcolumnview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QColumnView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QColumnView = BandoQWidget<QColumnView, QWidget *>;

Class rb_mBando_cQColumnView;

void Init_bando_qcolumnview(Module rb_mQt6Bando)
{
    rb_mBando_cQColumnView =
        define_bando_qwidget_under<Bando_QColumnView, QColumnView>(rb_mQt6Bando, "QColumnView")
            .define_constructor(Constructor<Bando_QColumnView, QWidget *>(), Arg("parent"));
}
