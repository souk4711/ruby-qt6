#include "bando-qinputdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QInputDialog>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QInputDialog = BandoQWidget<QInputDialog, QWidget *>;

Class rb_mBando_cQInputDialog;

void Init_bando_qinputdialog(Module rb_mQt6Bando)
{
    rb_mBando_cQInputDialog =
        define_bando_qwidget_under<Bando_QInputDialog, QInputDialog>(rb_mQt6Bando, "QInputDialog")
            .define_constructor(Constructor<Bando_QInputDialog, QWidget *>(), Arg("parent"));
}
