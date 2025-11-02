#include "bando-qdoublespinbox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDoubleSpinBox>

using namespace Rice;

using Bando_QDoubleSpinBox = BandoQWidget<QDoubleSpinBox, QWidget *>;

Rice::Class rb_mBando_cQDoubleSpinBox;

void Init_bando_qdoublespinbox(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDoubleSpinBox =
        define_bando_qwidget_under<Bando_QDoubleSpinBox, QDoubleSpinBox>(rb_mQt6Bando, "QDoubleSpinBox")
            .define_constructor(Constructor<Bando_QDoubleSpinBox, QWidget *>(), Arg("parent"));
}
