#include "bando-qdbusabstractinterface-rb.hpp"
#include <bando/qobject/qdbusabstractinterface.hpp>

#include <QDBusAbstractInterface>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDBusAbstractInterface = BandoQDBusAbstractInterface<QDBusAbstractInterface, const QString &, const QString &, const char *, const QDBusConnection &, QObject *>;

Class rb_mBando_cQDBusAbstractInterface;

void Init_bando_qdbusabstractinterface(Module rb_mQt6Bando)
{
    rb_mBando_cQDBusAbstractInterface =
        define_bando_qdbusabstractinterface_under<Bando_QDBusAbstractInterface, QDBusAbstractInterface>(rb_mQt6Bando, "QDBusAbstractInterface")
            .define_constructor(Constructor<Bando_QDBusAbstractInterface, const QString &, const QString &, const char *, const QDBusConnection &, QObject *>(), Arg("service"), Arg("path"), Arg("interface"), Arg("connection"), Arg("parent"));
}
