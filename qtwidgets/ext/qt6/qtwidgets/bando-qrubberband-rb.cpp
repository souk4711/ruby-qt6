#include "bando-qrubberband-rb.hpp"
#include <bando/qwidget.hpp>

#include <QRubberBand>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QRubberBand = BandoQWidget<QRubberBand, QRubberBand::Shape, QWidget *>;

Class rb_mBando_cQRubberBand;

void Init_bando_qrubberband(Module rb_mQt6Bando)
{
    rb_mBando_cQRubberBand =
        define_bando_qwidget_under<Bando_QRubberBand, QRubberBand>(rb_mQt6Bando, "QRubberBand")
            .define_constructor(Constructor<Bando_QRubberBand, QRubberBand::Shape, QWidget *>(), Arg("shape"), Arg("parent"));
}
