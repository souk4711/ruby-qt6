#include "bando-qplaintextedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QPlainTextEdit>

using namespace Rice;

using Bando_QPlainTextEdit = BandoQWidget<QPlainTextEdit, const QString &, QWidget *>;

Rice::Class rb_mBando_cQPlainTextEdit;

void Init_bando_qplaintextedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQPlainTextEdit =
        define_bando_qwidget_under<Bando_QPlainTextEdit, QPlainTextEdit>(rb_mQt6Bando, "QPlainTextEdit")
            .define_constructor(Constructor<Bando_QPlainTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
