#include "bando-qtoolbutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QToolButton>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QToolButton = BandoQWidget<QToolButton, QWidget *>;

Class rb_mBando_cQToolButton;

void Init_bando_qtoolbutton(Module rb_mQt6Bando)
{
    rb_mBando_cQToolButton =
        define_bando_qwidget_under<Bando_QToolButton, QToolButton>(rb_mQt6Bando, "QToolButton")
            .define_constructor(Constructor<Bando_QToolButton, QWidget *>(), Arg("parent"));
}
