#include "bando-qscrollbar-rb.hpp"
#include <bando/qwidget.hpp>

#include <QScrollBar>

using namespace Rice;

using Bando_QScrollBar = BandoQWidget<QScrollBar, Qt::Orientation, QWidget *>;

Rice::Class rb_mBando_cQScrollBar;

void Init_bando_qscrollbar(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQScrollBar =
        define_bando_qwidget_under<Bando_QScrollBar, QScrollBar>(rb_mQt6Bando, "QScrollBar")
            .define_constructor(Constructor<Bando_QScrollBar, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"));
}
