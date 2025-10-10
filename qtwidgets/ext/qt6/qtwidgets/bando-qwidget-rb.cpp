#include "bando-qwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QWidget>

using namespace Rice;

using Bando_QWidget = BandoQWidget<QWidget, QWidget *>;

Rice::Class rb_mBando_cQWidget;

void Init_bando_qwidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWidget =
        define_bando_qwidget_under<Bando_QWidget, QWidget>(rb_mQt6Bando, "QWidget")
            .define_constructor(Constructor<Bando_QWidget, QWidget *>(), Arg("parent"));
}
