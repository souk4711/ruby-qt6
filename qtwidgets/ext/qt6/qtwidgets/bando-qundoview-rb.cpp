#include "bando-qundoview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QUndoView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QUndoView = BandoQWidget<QUndoView, QWidget *>;

Class rb_mBando_cQUndoView;

void Init_bando_qundoview(Module rb_mQt6Bando)
{
    rb_mBando_cQUndoView =
        define_bando_qwidget_under<Bando_QUndoView, QUndoView>(rb_mQt6Bando, "QUndoView")
            .define_constructor(Constructor<Bando_QUndoView, QWidget *>(), Arg("parent"));
}
