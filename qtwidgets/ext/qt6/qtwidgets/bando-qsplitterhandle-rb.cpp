#include "bando-qsplitterhandle-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSplitterHandle>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QSplitterHandle = BandoQWidget<QSplitterHandle, Qt::Orientation, QSplitter *>;

Class rb_mBando_cQSplitterHandle;

void Init_bando_qsplitterhandle(Module rb_mQt6Bando)
{
    rb_mBando_cQSplitterHandle =
        define_bando_qwidget_under<Bando_QSplitterHandle, QSplitterHandle>(rb_mQt6Bando, "QSplitterHandle")
            .define_constructor(Constructor<Bando_QSplitterHandle, Qt::Orientation, QSplitter *>(), Arg("orientation"), Arg("parent"));
}
