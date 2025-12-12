#include "bando-qframe-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFrame>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QFrame = BandoQWidget<QFrame, QWidget *>;

Class rb_mBando_cQFrame;

void Init_bando_qframe(Module rb_mQt6Bando)
{
    rb_mBando_cQFrame =
        define_bando_qwidget_under<Bando_QFrame, QFrame>(rb_mQt6Bando, "QFrame")
            .define_constructor(Constructor<Bando_QFrame, QWidget *>(), Arg("parent"));
}
