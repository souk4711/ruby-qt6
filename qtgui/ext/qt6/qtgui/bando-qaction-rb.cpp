#include "bando-qaction-rb.hpp"
#include <bando/qobject.hpp>

#include <QAction>

using namespace Rice;

using Bando_QAction = BandoQObject<QAction, const QIcon &, const QString &, QObject *>;

Rice::Class rb_mBando_cQAction;

void Init_bando_qaction(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQAction =
        define_bando_qobject_under<Bando_QAction, QAction>(rb_mQt6Bando, "QAction")
            .define_constructor(Constructor<Bando_QAction, const QIcon &, const QString &, QObject *>(), Arg("icon"), Arg("text"), Arg("parent"));
}
