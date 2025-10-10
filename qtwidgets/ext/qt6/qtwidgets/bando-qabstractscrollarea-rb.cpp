#include "bando-qabstractscrollarea-rb.hpp"
#include <bando/qwidget.hpp>

#include <QAbstractScrollArea>

using namespace Rice;

using Bando_QAbstractScrollArea = BandoQWidget<QAbstractScrollArea, QWidget *>;

Rice::Class rb_mBando_cQAbstractScrollArea;

void Init_bando_qabstractscrollarea(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQAbstractScrollArea =
        define_bando_qwidget_under<Bando_QAbstractScrollArea, QAbstractScrollArea>(rb_mQt6Bando, "QAbstractScrollArea")
            .define_constructor(Constructor<Bando_QAbstractScrollArea, QWidget *>(), Arg("parent"));
}
