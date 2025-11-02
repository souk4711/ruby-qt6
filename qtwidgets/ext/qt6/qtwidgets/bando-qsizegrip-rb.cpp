#include "bando-qsizegrip-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSizeGrip>

using namespace Rice;

using Bando_QSizeGrip = BandoQWidget<QSizeGrip, QWidget *>;

Rice::Class rb_mBando_cQSizeGrip;

void Init_bando_qsizegrip(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSizeGrip =
        define_bando_qwidget_under<Bando_QSizeGrip, QSizeGrip>(rb_mQt6Bando, "QSizeGrip")
            .define_constructor(Constructor<Bando_QSizeGrip, QWidget *>(), Arg("parent"));
}
