#include "bando-qlineedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QLineEdit>

using namespace Rice;

using Bando_QLineEdit = BandoQWidget<QLineEdit, const QString &, QWidget *>;

Rice::Class rb_mBando_cQLineEdit;

void Init_bando_qlineedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQLineEdit =
        define_bando_qwidget_under<Bando_QLineEdit, QLineEdit>(rb_mQt6Bando, "QLineEdit")
            .define_constructor(Constructor<Bando_QLineEdit, const QString &, QWidget *>(), Arg("contents"), Arg("parent"));
}
