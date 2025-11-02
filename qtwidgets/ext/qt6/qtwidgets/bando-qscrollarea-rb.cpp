#include "bando-qscrollarea-rb.hpp"
#include <bando/qwidget.hpp>

#include <QScrollArea>

using namespace Rice;

using Bando_QScrollArea = BandoQWidget<QScrollArea, QWidget *>;

Rice::Class rb_mBando_cQScrollArea;

void Init_bando_qscrollarea(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQScrollArea =
        define_bando_qwidget_under<Bando_QScrollArea, QScrollArea>(rb_mQt6Bando, "QScrollArea")
            .define_constructor(Constructor<Bando_QScrollArea, QWidget *>(), Arg("parent"));
}
