#include "bando-qkeysequenceedit-rb.hpp"
#include <bando/qwidget.hpp>

#include <QKeySequenceEdit>

using namespace Rice;

using Bando_QKeySequenceEdit = BandoQWidget<QKeySequenceEdit, const QKeySequence &, QWidget *>;

Rice::Class rb_mBando_cQKeySequenceEdit;

void Init_bando_qkeysequenceedit(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQKeySequenceEdit =
        define_bando_qwidget_under<Bando_QKeySequenceEdit, QKeySequenceEdit>(rb_mQt6Bando, "QKeySequenceEdit")
            .define_constructor(Constructor<Bando_QKeySequenceEdit, const QKeySequence &, QWidget *>(), Arg("key_sequence"), Arg("parent"));
}
