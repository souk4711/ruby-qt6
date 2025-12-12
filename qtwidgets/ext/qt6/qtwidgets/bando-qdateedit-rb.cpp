#include "bando-qdateedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDateEdit>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDateEdit = BandoQWidget<QDateEdit, QDate, QWidget *>;

Class rb_mBando_cQDateEdit;

void Init_bando_qdateedit(Module rb_mQt6Bando)
{
    rb_mBando_cQDateEdit =
        define_bando_qwidget_under<Bando_QDateEdit, QDateEdit>(rb_mQt6Bando, "QDateEdit")
            .define_constructor(Constructor<Bando_QDateEdit, QDate, QWidget *>(), Arg("date"), Arg("parent"));
}
