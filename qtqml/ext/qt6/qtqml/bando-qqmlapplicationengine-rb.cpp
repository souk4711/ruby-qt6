#include "bando-qqmlapplicationengine-rb.hpp"
#include <bando/qobject.hpp>

#include <QQmlApplicationEngine>

using namespace Rice;

using Bando_QQmlApplicationEngine = BandoQObject<QQmlApplicationEngine, QObject *>;

Rice::Class rb_mBando_cQQmlApplicationEngine;

void Init_bando_qqmlapplicationengine(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQmlApplicationEngine =
        define_bando_qobject_under<Bando_QQmlApplicationEngine, QQmlApplicationEngine>(rb_mQt6Bando, "QQmlApplicationEngine")
            .define_constructor(Constructor<Bando_QQmlApplicationEngine, QObject *>(), Arg("parent"));
}
