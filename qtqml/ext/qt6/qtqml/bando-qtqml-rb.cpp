#include "bando-qtqml-rb.hpp"
#include <bando/qobject.hpp>

#include <QJSEngine>
#include <QQmlEngine>
#include <QQmlApplicationEngine>

using namespace Rice;

using Bando_QJSEngine = BandoQObject<QJSEngine, QObject *>;
using Bando_QQmlEngine = BandoQObject<QQmlEngine, QObject *>;
using Bando_QQmlApplicationEngine = BandoQObject<QQmlApplicationEngine, QObject *>;

Rice::Class rb_mBando_cQJSEngine;
Rice::Class rb_mBando_cQQmlEngine;
Rice::Class rb_mBando_cQQmlApplicationEngine;

void Init_bando_qtqml(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQJSEngine =
        define_bando_qobject_under<Bando_QJSEngine, QJSEngine>(rb_mQt6Bando, "QJSEngine")
            .define_constructor(Constructor<Bando_QJSEngine, QObject *>(), Arg("parent"));

    rb_mBando_cQQmlEngine =
        define_bando_qobject_under<Bando_QQmlEngine, QQmlEngine>(rb_mQt6Bando, "QQmlEngine")
            .define_constructor(Constructor<Bando_QQmlEngine, QObject *>(), Arg("parent"));

    rb_mBando_cQQmlApplicationEngine =
        define_bando_qobject_under<Bando_QQmlApplicationEngine, QQmlApplicationEngine>(rb_mQt6Bando, "QQmlApplicationEngine")
            .define_constructor(Constructor<Bando_QQmlApplicationEngine, QObject *>(), Arg("parent"));
}
