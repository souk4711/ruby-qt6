#include "bando-qjsengine-rb.hpp"
#include <bando/qobject.hpp>

#include <QJSEngine>

using namespace Rice;

using Bando_QJSEngine = BandoQObject<QJSEngine, QObject *>;

Rice::Class rb_mBando_cQJSEngine;

void Init_bando_qjsengine(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQJSEngine =
        define_bando_qobject_under<Bando_QJSEngine, QJSEngine>(rb_mQt6Bando, "QJSEngine")
            .define_constructor(Constructor<Bando_QJSEngine, QObject *>(), Arg("parent"));
}
