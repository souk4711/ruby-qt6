#include "bando-qundoview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QUndoView>

using namespace Rice;

using Bando_QUndoView = BandoQWidget<QUndoView, QWidget *>;

Rice::Class rb_mBando_cQUndoView;

void Init_bando_qundoview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQUndoView =
        define_bando_qwidget_under<Bando_QUndoView, QUndoView>(rb_mQt6Bando, "QUndoView")
            .define_constructor(Constructor<Bando_QUndoView, QWidget *>(), Arg("parent"));
}
