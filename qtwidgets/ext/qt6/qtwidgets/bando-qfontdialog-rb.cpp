#include "bando-qfontdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFontDialog>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QFontDialog = BandoQWidget<QFontDialog, const QFont &, QWidget *>;

Class rb_mBando_cQFontDialog;

void Init_bando_qfontdialog(Module rb_mQt6Bando)
{
    rb_mBando_cQFontDialog =
        define_bando_qwidget_under<Bando_QFontDialog, QFontDialog>(rb_mQt6Bando, "QFontDialog")
            .define_constructor(Constructor<Bando_QFontDialog, const QFont &, QWidget *>(), Arg("initial"), Arg("parent"));
}
