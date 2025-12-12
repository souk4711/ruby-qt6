#include "bando-qsizegrip-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSizeGrip>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QSizeGrip = BandoQWidget<QSizeGrip, QWidget *>;

Class rb_mBando_cQSizeGrip;

void Init_bando_qsizegrip(Module rb_mQt6Bando)
{
    rb_mBando_cQSizeGrip =
        define_bando_qwidget_under<Bando_QSizeGrip, QSizeGrip>(rb_mQt6Bando, "QSizeGrip")
            .define_constructor(Constructor<Bando_QSizeGrip, QWidget *>(), Arg("parent"));
}
