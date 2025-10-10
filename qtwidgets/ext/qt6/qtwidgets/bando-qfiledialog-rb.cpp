#include "bando-qfiledialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFileDialog>

using namespace Rice;

using Bando_QFileDialog = BandoQWidget<QFileDialog, QWidget *>;

Rice::Class rb_mBando_cQFileDialog;

void Init_bando_qfiledialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQFileDialog =
        define_bando_qwidget_under<Bando_QFileDialog, QFileDialog>(rb_mQt6Bando, "QFileDialog")
            .define_constructor(Constructor<Bando_QFileDialog, QWidget *>(), Arg("parent"));
}
