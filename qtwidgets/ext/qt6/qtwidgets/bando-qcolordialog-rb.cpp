#include "bando-qcolordialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QColorDialog>

using namespace Rice;

using Bando_QColorDialog = BandoQWidget<QColorDialog, const QColor &, QWidget *>;

Rice::Class rb_mBando_cQColorDialog;

void Init_bando_qcolordialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQColorDialog =
        define_bando_qwidget_under<Bando_QColorDialog, QColorDialog>(rb_mQt6Bando, "QColorDialog")
            .define_constructor(Constructor<Bando_QColorDialog, const QColor &, QWidget *>(), Arg("initial"), Arg("parent"));
}
