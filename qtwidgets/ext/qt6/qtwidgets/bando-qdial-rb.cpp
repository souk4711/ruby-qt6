#include "bando-qdial-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDial>

using namespace Rice;

using Bando_QDial = BandoQWidget<QDial, QWidget *>;

Rice::Class rb_mBando_cQDial;

void Init_bando_qdial(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDial =
        define_bando_qwidget_under<Bando_QDial, QDial>(rb_mQt6Bando, "QDial")
            .define_constructor(Constructor<Bando_QDial, QWidget *>(), Arg("parent"));
}
