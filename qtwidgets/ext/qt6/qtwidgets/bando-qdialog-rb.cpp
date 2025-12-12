#include "bando-qdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDialog>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDialog = BandoQWidget<QDialog, QWidget *>;

Class rb_mBando_cQDialog;

void Init_bando_qdialog(Module rb_mQt6Bando)
{
    rb_mBando_cQDialog =
        define_bando_qwidget_under<Bando_QDialog, QDialog>(rb_mQt6Bando, "QDialog")
            .define_constructor(Constructor<Bando_QDialog, QWidget *>(), Arg("parent"));
}
