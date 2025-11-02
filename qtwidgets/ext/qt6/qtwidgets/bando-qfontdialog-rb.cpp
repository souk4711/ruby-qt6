#include "bando-qfontdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFontDialog>

using namespace Rice;

using Bando_QFontDialog = BandoQWidget<QFontDialog, const QFont &, QWidget *>;

Rice::Class rb_mBando_cQFontDialog;

void Init_bando_qfontdialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQFontDialog =
        define_bando_qwidget_under<Bando_QFontDialog, QFontDialog>(rb_mQt6Bando, "QFontDialog")
            .define_constructor(Constructor<Bando_QFontDialog, const QFont &, QWidget *>(), Arg("initial"), Arg("parent"));
}
