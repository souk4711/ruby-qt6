#include "bando-qpushbutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QPushButton>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;

Class rb_mBando_cQPushButton;

void Init_bando_qpushbutton(Module rb_mQt6Bando)
{
    rb_mBando_cQPushButton =
        define_bando_qwidget_under<Bando_QPushButton, QPushButton>(rb_mQt6Bando, "QPushButton")
            .define_constructor(Constructor<Bando_QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
