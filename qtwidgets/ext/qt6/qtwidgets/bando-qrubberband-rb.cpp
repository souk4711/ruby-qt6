#include "bando-qrubberband-rb.hpp"
#include <bando/qwidget.hpp>

#include <QRubberBand>

using namespace Rice;

using Bando_QRubberBand = BandoQWidget<QRubberBand, QRubberBand::Shape, QWidget *>;

Rice::Class rb_mBando_cQRubberBand;

void Init_bando_qrubberband(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQRubberBand =
        define_bando_qwidget_under<Bando_QRubberBand, QRubberBand>(rb_mQt6Bando, "QRubberBand")
            .define_constructor(Constructor<Bando_QRubberBand, QRubberBand::Shape, QWidget *>(), Arg("shape"), Arg("parent"));
}
