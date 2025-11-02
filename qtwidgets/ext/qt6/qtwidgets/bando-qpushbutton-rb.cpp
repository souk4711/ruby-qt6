#include "bando-qpushbutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QPushButton>

using namespace Rice;

using Bando_QPushButton = BandoQWidget<QPushButton, const QString &, QWidget *>;

Rice::Class rb_mBando_cQPushButton;

void Init_bando_qpushbutton(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQPushButton =
        define_bando_qwidget_under<Bando_QPushButton, QPushButton>(rb_mQt6Bando, "QPushButton")
            .define_constructor(Constructor<Bando_QPushButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
