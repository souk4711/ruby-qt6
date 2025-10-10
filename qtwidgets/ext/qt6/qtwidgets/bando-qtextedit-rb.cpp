#include "bando-qtextedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTextEdit>

using namespace Rice;

using Bando_QTextEdit = BandoQWidget<QTextEdit, const QString &, QWidget *>;

Rice::Class rb_mBando_cQTextEdit;

void Init_bando_qtextedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTextEdit =
        define_bando_qwidget_under<Bando_QTextEdit, QTextEdit>(rb_mQt6Bando, "QTextEdit")
            .define_constructor(Constructor<Bando_QTextEdit, const QString &, QWidget *>(), Arg("text"), Arg("parent"));
}
