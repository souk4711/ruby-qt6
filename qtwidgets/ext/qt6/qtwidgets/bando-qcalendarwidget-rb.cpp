#include "bando-qcalendarwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QCalendarWidget>

using namespace Rice;

using Bando_QCalendarWidget = BandoQWidget<QCalendarWidget, QWidget *>;

Rice::Class rb_mBando_cQCalendarWidget;

void Init_bando_qcalendarwidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQCalendarWidget =
        define_bando_qwidget_under<Bando_QCalendarWidget, QCalendarWidget>(rb_mQt6Bando, "QCalendarWidget")
            .define_constructor(Constructor<Bando_QCalendarWidget, QWidget *>(), Arg("parent"));
}
