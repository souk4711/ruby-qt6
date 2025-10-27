#include "bando-qdbusinterface-rb.hpp"
#include <bando/qobject.hpp>

#include <QDBusInterface>

using namespace Rice;

using Bando_QDBusInterface = BandoQObject<QDBusInterface, const QString &, const QString &, const QString &, const QDBusConnection &, QObject *>;

Rice::Class rb_mBando_cQDBusInterface;

void Init_bando_qdbusinterface(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDBusInterface =
        define_bando_qobject_under<Bando_QDBusInterface, QDBusInterface>(rb_mQt6Bando, "QDBusInterface")
            .define_constructor(Constructor<Bando_QDBusInterface, const QString &, const QString &, const QString &, const QDBusConnection &, QObject *>(), Arg("service"), Arg("path"), Arg("interface"), Arg("connection"), Arg("parent"));
}
