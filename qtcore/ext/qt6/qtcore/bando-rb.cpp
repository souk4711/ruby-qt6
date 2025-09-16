#include "bando-rb.hpp"
#include <bando/qobject.hpp>

#include <QObject>
#include <QCoreApplication>

using namespace Rice;

using Bando_QObject = BandoQObject<QObject, QObject *>;
using Bando_QCoreApplication = BandoQObject<QCoreApplication, int &, char **>;

Rice::Class rb_mBando_cQObject;
Rice::Class rb_mBando_cQCoreApplication;

void Init_bando(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQObject =
        define_class_under<Bando_QObject, QObject>(rb_mQt6Bando, "QObject")
            .define_constructor(Constructor<Bando_QObject, QObject *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QObject::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQCoreApplication =
        define_class_under<Bando_QCoreApplication, QCoreApplication>(rb_mQt6Bando, "QCoreApplication")
            .define_constructor(Constructor<Bando_QCoreApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QCoreApplication::initializeValue, Arg("mo"), Arg("value"));
}
