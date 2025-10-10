#include "bando-qsettings-rb.hpp"
#include <bando/qobject.hpp>

#include <QSettings>

using namespace Rice;

using Bando_QSettings = BandoQObject<QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>;

Rice::Class rb_mBando_cQSettings;

void Init_bando_qsettings(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSettings =
        define_bando_qobject_under<Bando_QSettings, QSettings>(rb_mQt6Bando, "QSettings")
            .define_constructor(Constructor<Bando_QSettings, QSettings::Format, QSettings::Scope, const QString &, const QString &, QObject *>(), Arg("format"), Arg("scope"), Arg("organization"), Arg("application"), Arg("parent"));
}
