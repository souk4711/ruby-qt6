#include "bando-qdateedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDateEdit>

using namespace Rice;

using Bando_QDateEdit = BandoQWidget<QDateEdit, QDate, QWidget *>;

Rice::Class rb_mBando_cQDateEdit;

void Init_bando_qdateedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDateEdit =
        define_bando_qwidget_under<Bando_QDateEdit, QDateEdit>(rb_mQt6Bando, "QDateEdit")
            .define_constructor(Constructor<Bando_QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"));
}
