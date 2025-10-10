#include "bando-qtoolbutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QToolButton>

using namespace Rice;

using Bando_QToolButton = BandoQWidget<QToolButton, QWidget *>;

Rice::Class rb_mBando_cQToolButton;

void Init_bando_qtoolbutton(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQToolButton =
        define_bando_qwidget_under<Bando_QToolButton, QToolButton>(rb_mQt6Bando, "QToolButton")
            .define_constructor(Constructor<Bando_QToolButton, QWidget *>(), Arg("parent"));
}
