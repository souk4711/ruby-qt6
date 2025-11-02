#include "bando-qdatetimeedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDateTimeEdit>

using namespace Rice;

using Bando_QDateTimeEdit = BandoQWidget<QDateTimeEdit, const QDateTime &, QWidget *>;

Rice::Class rb_mBando_cQDateTimeEdit;

void Init_bando_qdatetimeedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDateTimeEdit =
        define_bando_qwidget_under<Bando_QDateTimeEdit, QDateTimeEdit>(rb_mQt6Bando, "QDateTimeEdit")
            .define_constructor(Constructor<Bando_QDateTimeEdit, const QDateTime &, QWidget *>(), Arg("datetime"), Arg("parent"));
}
