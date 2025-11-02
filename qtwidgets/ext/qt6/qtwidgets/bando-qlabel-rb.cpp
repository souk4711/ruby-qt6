#include "bando-qlabel-rb.hpp"
#include <bando/qwidget.hpp>

#include <QLabel>

using namespace Rice;

using Bando_QLabel = BandoQWidget<QLabel, const QString &, QWidget *>;

Rice::Class rb_mBando_cQLabel;

void Init_bando_qlabel(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQLabel =
        define_bando_qwidget_under<Bando_QLabel, QLabel>(rb_mQt6Bando, "QLabel")
            .define_constructor(Constructor<Bando_QLabel, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
