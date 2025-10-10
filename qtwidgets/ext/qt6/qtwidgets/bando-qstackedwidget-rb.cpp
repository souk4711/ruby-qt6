#include "bando-qstackedwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QStackedWidget>

using namespace Rice;

using Bando_QStackedWidget = BandoQWidget<QStackedWidget, QWidget *>;

Rice::Class rb_mBando_cQStackedWidget;

void Init_bando_qstackedwidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQStackedWidget =
        define_bando_qwidget_under<Bando_QStackedWidget, QStackedWidget>(rb_mQt6Bando, "QStackedWidget")
            .define_constructor(Constructor<Bando_QStackedWidget, QWidget *>(), Arg("parent"));
}
