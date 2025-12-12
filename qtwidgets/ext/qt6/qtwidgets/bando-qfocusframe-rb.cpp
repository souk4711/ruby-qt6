#include "bando-qfocusframe-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFocusFrame>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QFocusFrame = BandoQWidget<QFocusFrame, QWidget *>;

Class rb_mBando_cQFocusFrame;

void Init_bando_qfocusframe(Module rb_mQt6Bando)
{
    rb_mBando_cQFocusFrame =
        define_bando_qwidget_under<Bando_QFocusFrame, QFocusFrame>(rb_mQt6Bando, "QFocusFrame")
            .define_constructor(Constructor<Bando_QFocusFrame, QWidget *>(), Arg("parent"));
}
