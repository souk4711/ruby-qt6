#include "bando-qsystemtrayicon-rb.hpp"
#include <bando/qobject.hpp>

#include <QSystemTrayIcon>

using namespace Rice;

using Bando_QSystemTrayIcon = BandoQObject<QSystemTrayIcon, const QIcon &, QObject *>;

Rice::Class rb_mBando_cQSystemTrayIcon;

void Init_bando_qsystemtrayicon(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSystemTrayIcon =
        define_bando_qobject_under<Bando_QSystemTrayIcon, QSystemTrayIcon>(rb_mQt6Bando, "QSystemTrayIcon")
            .define_constructor(Constructor<Bando_QSystemTrayIcon, const QIcon &, QObject *>(), Arg("icon"), Arg("parent"));
}
