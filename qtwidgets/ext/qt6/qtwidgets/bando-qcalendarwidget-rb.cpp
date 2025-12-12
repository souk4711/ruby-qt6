#include "bando-qcalendarwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QCalendarWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QCalendarWidget = BandoQWidget<QCalendarWidget, QWidget *>;

Class rb_mBando_cQCalendarWidget;

void Init_bando_qcalendarwidget(Module rb_mQt6Bando)
{
    rb_mBando_cQCalendarWidget =
        define_bando_qwidget_under<Bando_QCalendarWidget, QCalendarWidget>(rb_mQt6Bando, "QCalendarWidget")
            .define_constructor(Constructor<Bando_QCalendarWidget, QWidget *>(), Arg("parent"));
}
