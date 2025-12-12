#include "bando-qdatetimeedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDateTimeEdit>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDateTimeEdit = BandoQWidget<QDateTimeEdit, const QDateTime &, QWidget *>;

Class rb_mBando_cQDateTimeEdit;

void Init_bando_qdatetimeedit(Module rb_mQt6Bando)
{
    rb_mBando_cQDateTimeEdit =
        define_bando_qwidget_under<Bando_QDateTimeEdit, QDateTimeEdit>(rb_mQt6Bando, "QDateTimeEdit")
            .define_constructor(Constructor<Bando_QDateTimeEdit, const QDateTime &, QWidget *>(), Arg("datetime"), Arg("parent"));
}
