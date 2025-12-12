#include "bando-qcheckbox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QCheckBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QCheckBox = BandoQWidget<QCheckBox, const QString &, QWidget *>;

Class rb_mBando_cQCheckBox;

void Init_bando_qcheckbox(Module rb_mQt6Bando)
{
    rb_mBando_cQCheckBox =
        define_bando_qwidget_under<Bando_QCheckBox, QCheckBox>(rb_mQt6Bando, "QCheckBox")
            .define_constructor(Constructor<Bando_QCheckBox, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
