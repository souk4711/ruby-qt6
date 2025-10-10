#include "bando-qqmlengine-rb.hpp"
#include <bando/qobject.hpp>

#include <QQmlEngine>

using namespace Rice;

using Bando_QQmlEngine = BandoQObject<QQmlEngine, QObject *>;

Rice::Class rb_mBando_cQQmlEngine;

void Init_bando_qqmlengine(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQmlEngine =
        define_bando_qobject_under<Bando_QQmlEngine, QQmlEngine>(rb_mQt6Bando, "QQmlEngine")
            .define_constructor(Constructor<Bando_QQmlEngine, QObject *>(), Arg("parent"));
}
