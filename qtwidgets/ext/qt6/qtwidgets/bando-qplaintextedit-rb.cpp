#include "bando-qplaintextedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QPlainTextEdit>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QPlainTextEdit = BandoQWidget<QPlainTextEdit, const QString &, QWidget *>;

Class rb_mBando_cQPlainTextEdit;

void Init_bando_qplaintextedit(Module rb_mQt6Bando)
{
    rb_mBando_cQPlainTextEdit =
        define_bando_qwidget_under<Bando_QPlainTextEdit, QPlainTextEdit>(rb_mQt6Bando, "QPlainTextEdit")
            .define_constructor(Constructor<Bando_QPlainTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
