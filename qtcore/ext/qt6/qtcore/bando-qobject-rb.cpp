#include "bando-qobject-rb.hpp"
#include <bando/qobject.hpp>

#include <QObject>

using namespace Rice;

using Bando_QObject = BandoQObject<QObject, QObject *>;

Rice::Class rb_mBando_cQObject;

void Init_bando_qobject(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQObject =
        define_bando_qobject_under<Bando_QObject, QObject>(rb_mQt6Bando, "QObject")
            .define_constructor(Constructor<Bando_QObject, QObject *>(), Arg("parent"));
}
