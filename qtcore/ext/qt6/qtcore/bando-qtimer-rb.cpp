#include "bando-qtimer-rb.hpp"
#include <bando/qobject.hpp>

#include <QTimer>

using namespace Rice;

using Bando_QTimer = BandoQObject<QTimer, QObject *>;

Rice::Class rb_mBando_cQTimer;

void Init_bando_qtimer(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTimer =
        define_bando_qobject_under<Bando_QTimer, QTimer>(rb_mQt6Bando, "QTimer")
            .define_constructor(Constructor<Bando_QTimer, QObject *>(), Arg("parent"));
}
