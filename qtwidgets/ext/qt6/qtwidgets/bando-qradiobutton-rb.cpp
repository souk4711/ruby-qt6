#include "bando-qradiobutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QRadioButton>

using namespace Rice;

using Bando_QRadioButton = BandoQWidget<QRadioButton, const QString &, QWidget *>;

Rice::Class rb_mBando_cQRadioButton;

void Init_bando_qradiobutton(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQRadioButton =
        define_bando_qwidget_under<Bando_QRadioButton, QRadioButton>(rb_mQt6Bando, "QRadioButton")
            .define_constructor(Constructor<Bando_QRadioButton, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
