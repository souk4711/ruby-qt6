#include "bando-qlcdnumber-rb.hpp"
#include <bando/qwidget.hpp>

#include <QLCDNumber>

using namespace Rice;

using Bando_QLCDNumber = BandoQWidget<QLCDNumber, uint, QWidget *>;

Rice::Class rb_mBando_cQLCDNumber;

void Init_bando_qlcdnumber(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQLCDNumber =
        define_bando_qwidget_under<Bando_QLCDNumber, QLCDNumber>(rb_mQt6Bando, "QLCDNumber")
            .define_constructor(Constructor<Bando_QLCDNumber, uint, QWidget *>(), Arg("num"), Arg("parent"));
}
