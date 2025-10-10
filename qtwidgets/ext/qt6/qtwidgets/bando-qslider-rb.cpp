#include "bando-qslider-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSlider>

using namespace Rice;

using Bando_QSlider = BandoQWidget<QSlider, Qt::Orientation, QWidget *>;

Rice::Class rb_mBando_cQSlider;

void Init_bando_qslider(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSlider =
        define_bando_qwidget_under<Bando_QSlider, QSlider>(rb_mQt6Bando, "QSlider")
            .define_constructor(Constructor<Bando_QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
