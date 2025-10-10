#include "bando-qactiongroup-rb.hpp"
#include <bando/qobject.hpp>

#include <QActionGroup>

using namespace Rice;

using Bando_QActionGroup = BandoQObject<QActionGroup, QObject *>;

Rice::Class rb_mBando_cQActionGroup;

void Init_bando_qactiongroup(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQActionGroup =
        define_bando_qobject_under<Bando_QActionGroup, QActionGroup>(rb_mQt6Bando, "QActionGroup")
            .define_constructor(Constructor<Bando_QActionGroup, QObject *>(), Arg("parent"));
}
