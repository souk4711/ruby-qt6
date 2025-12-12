#include "bando-qmdiarea-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMdiArea>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QMdiArea = BandoQWidget<QMdiArea, QWidget *>;

Class rb_mBando_cQMdiArea;

void Init_bando_qmdiarea(Module rb_mQt6Bando)
{
    rb_mBando_cQMdiArea =
        define_bando_qwidget_under<Bando_QMdiArea, QMdiArea>(rb_mQt6Bando, "QMdiArea")
            .define_constructor(Constructor<Bando_QMdiArea, QWidget *>(), Arg("parent"));
}
