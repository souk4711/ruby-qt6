#include "bando-qdbusabstractadaptor-rb.hpp"
#include <bando/qobject.hpp>

#include <QDBusAbstractAdaptor>

using namespace Rice;

using Bando_QDBusAbstractAdaptor = BandoQObject<QDBusAbstractAdaptor, QObject *>;

Rice::Class rb_mBando_cQDBusAbstractAdaptor;

void Init_bando_qdbusabstractadaptor(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQDBusAbstractAdaptor =
        define_bando_qobject_under<Bando_QDBusAbstractAdaptor, QDBusAbstractAdaptor>(rb_mQt6Bando, "QDBusAbstractAdaptor")
            .define_constructor(Constructor<Bando_QDBusAbstractAdaptor, QObject *>(), Arg("parent"));
}
