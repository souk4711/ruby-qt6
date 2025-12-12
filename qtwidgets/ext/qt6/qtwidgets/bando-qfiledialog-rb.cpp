#include "bando-qfiledialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFileDialog>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QFileDialog = BandoQWidget<QFileDialog, QWidget *>;

Class rb_mBando_cQFileDialog;

void Init_bando_qfiledialog(Module rb_mQt6Bando)
{
    rb_mBando_cQFileDialog =
        define_bando_qwidget_under<Bando_QFileDialog, QFileDialog>(rb_mQt6Bando, "QFileDialog")
            .define_constructor(Constructor<Bando_QFileDialog, QWidget *>(), Arg("parent"));
}
