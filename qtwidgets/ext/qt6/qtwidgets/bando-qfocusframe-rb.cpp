#include "bando-qfocusframe-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFocusFrame>

using namespace Rice;

using Bando_QFocusFrame = BandoQWidget<QFocusFrame, QWidget *>;

Rice::Class rb_mBando_cQFocusFrame;

void Init_bando_qfocusframe(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQFocusFrame =
        define_bando_qwidget_under<Bando_QFocusFrame, QFocusFrame>(rb_mQt6Bando, "QFocusFrame")
            .define_constructor(Constructor<Bando_QFocusFrame, QWidget *>(), Arg("parent"));
}
