#include "bando-qprogressdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QProgressDialog>

using namespace Rice;

using Bando_QProgressDialog = BandoQWidget<QProgressDialog, const QString &, const QString &, int, int, QWidget *>;

Rice::Class rb_mBando_cQProgressDialog;

void Init_bando_qprogressdialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQProgressDialog =
        define_bando_qwidget_under<Bando_QProgressDialog, QProgressDialog>(rb_mQt6Bando, "QProgressDialog")
            .define_constructor(Constructor<Bando_QProgressDialog, const QString &, const QString &, int, int, QWidget *>(), Arg("label_text"), Arg("cancel_button_text"), Arg("minimum"), Arg("maximum"), Arg("parent"));
}
