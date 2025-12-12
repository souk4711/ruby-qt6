#include "bando-qtoolbox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QToolBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QToolBox = BandoQWidget<QToolBox, QWidget *>;

Class rb_mBando_cQToolBox;

void Init_bando_qtoolbox(Module rb_mQt6Bando)
{
    rb_mBando_cQToolBox =
        define_bando_qwidget_under<Bando_QToolBox, QToolBox>(rb_mQt6Bando, "QToolBox")
            .define_constructor(Constructor<Bando_QToolBox, QWidget *>(), Arg("parent"));
}
