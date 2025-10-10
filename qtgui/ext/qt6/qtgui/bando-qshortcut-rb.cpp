#include "bando-qshortcut-rb.hpp"
#include <bando/qobject.hpp>

#include <QShortcut>

using namespace Rice;

using Bando_QShortcut = BandoQObject<QShortcut, const QKeySequence &, QObject *>;

Rice::Class rb_mBando_cQShortcut;

void Init_bando_qshortcut(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQShortcut =
        define_bando_qobject_under<Bando_QShortcut, QShortcut>(rb_mQt6Bando, "QShortcut")
            .define_constructor(Constructor<Bando_QShortcut, const QKeySequence &, QObject *>(), Arg("key"), Arg("parent"));
}
