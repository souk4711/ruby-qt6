#include "bando-qlcdnumber-rb.hpp"
#include <bando/qwidget.hpp>

#include <QLCDNumber>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QLCDNumber = BandoQWidget<QLCDNumber, uint, QWidget *>;

Class rb_mBando_cQLCDNumber;

void Init_bando_qlcdnumber(Module rb_mQt6Bando)
{
    rb_mBando_cQLCDNumber =
        define_bando_qwidget_under<Bando_QLCDNumber, QLCDNumber>(rb_mQt6Bando, "QLCDNumber")
            .define_constructor(Constructor<Bando_QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"));
}
