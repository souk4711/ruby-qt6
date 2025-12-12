#include "bando-qlabel-rb.hpp"
#include <bando/qwidget.hpp>

#include <QLabel>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QLabel = BandoQWidget<QLabel, const QString &, QWidget *>;

Class rb_mBando_cQLabel;

void Init_bando_qlabel(Module rb_mQt6Bando)
{
    rb_mBando_cQLabel =
        define_bando_qwidget_under<Bando_QLabel, QLabel>(rb_mQt6Bando, "QLabel")
            .define_constructor(Constructor<Bando_QLabel, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
