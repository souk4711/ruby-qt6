#include "bando-qtimeedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTimeEdit>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTimeEdit = BandoQWidget<QTimeEdit, QTime, QWidget *>;

Class rb_mBando_cQTimeEdit;

void Init_bando_qtimeedit(Module rb_mQt6Bando)
{
    rb_mBando_cQTimeEdit =
        define_bando_qwidget_under<Bando_QTimeEdit, QTimeEdit>(rb_mQt6Bando, "QTimeEdit")
            .define_constructor(Constructor<Bando_QTimeEdit, QTime, QWidget *>(), Arg("time"), Arg("parent"));
}
