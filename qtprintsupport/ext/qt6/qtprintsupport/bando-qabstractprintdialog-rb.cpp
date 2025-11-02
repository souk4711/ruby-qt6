#include "bando-qabstractprintdialog-rb.hpp"
#include <bando/qwidget.hpp>

#include <QAbstractPrintDialog>
#include <QPrinter>

using namespace Rice;

using Bando_QAbstractPrintDialog = BandoQWidget<QAbstractPrintDialog, QPrinter *, QWidget *>;

Rice::Class rb_mBando_cQAbstractPrintDialog;

void Init_bando_qabstractprintdialog(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQAbstractPrintDialog =
        define_bando_qwidget_under<Bando_QAbstractPrintDialog, QAbstractPrintDialog>(rb_mQt6Bando, "QAbstractPrintDialog")
            .define_constructor(Constructor<Bando_QAbstractPrintDialog, QPrinter *, QWidget *>(), Arg("printer"), Arg("parent"));
}
