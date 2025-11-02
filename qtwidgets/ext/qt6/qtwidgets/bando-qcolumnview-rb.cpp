#include "bando-qcolumnview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QColumnView>

using namespace Rice;

using Bando_QColumnView = BandoQWidget<QColumnView, QWidget *>;

Rice::Class rb_mBando_cQColumnView;

void Init_bando_qcolumnview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQColumnView =
        define_bando_qwidget_under<Bando_QColumnView, QColumnView>(rb_mQt6Bando, "QColumnView")
            .define_constructor(Constructor<Bando_QColumnView, QWidget *>(), Arg("parent"));
}
