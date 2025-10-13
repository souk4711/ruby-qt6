#include "bando-qprintdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QPrintDialog>
#include <QPrinter>

using namespace Rice;

using Bando_QPrintDialog = BandoQWidget<QPrintDialog, QPrinter *, QWidget *>;

Rice::Class rb_mBando_cQPrintDialog;

void Init_bando_qprintdialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQPrintDialog =
        define_bando_qwidget_under<Bando_QPrintDialog, QPrintDialog>(rb_mQt6Bando, "QPrintDialog")
            .define_constructor(Constructor<Bando_QPrintDialog, QPrinter *, QWidget *>(), Arg("printer"), Arg("parent"));
}
