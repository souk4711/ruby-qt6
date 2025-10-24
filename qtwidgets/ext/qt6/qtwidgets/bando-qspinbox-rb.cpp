#include "bando-qspinbox-rb.hpp"
#include <bando/qwidget/qspinbox.hpp>

#include <QSpinBox>

using namespace Rice;

using Bando_QSpinBox = BandoQSpinBox<QSpinBox, QWidget *>;

Rice::Class rb_mBando_cQSpinBox;

void Init_bando_qspinbox(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSpinBox =
        define_bando_qspinbox_under<Bando_QSpinBox, QSpinBox>(rb_mQt6Bando, "QSpinBox")
            .define_constructor(Constructor<Bando_QSpinBox, QWidget *>(), Arg("parent"));
}
