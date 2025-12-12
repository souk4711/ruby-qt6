#include "bando-qsplitter-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSplitter>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QSplitter = BandoQWidget<QSplitter, Qt::Orientation, QWidget *>;

Class rb_mBando_cQSplitter;

void Init_bando_qsplitter(Module rb_mQt6Bando)
{
    rb_mBando_cQSplitter =
        define_bando_qwidget_under<Bando_QSplitter, QSplitter>(rb_mQt6Bando, "QSplitter")
            .define_constructor(Constructor<Bando_QSplitter, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
