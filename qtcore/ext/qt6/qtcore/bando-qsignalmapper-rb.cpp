#include "bando-qsignalmapper-rb.hpp"
#include <bando/qobject.hpp>

#include <QSignalMapper>

using namespace Rice;

using Bando_QSignalMapper = BandoQObject<QSignalMapper, QObject *>;

Rice::Class rb_mBando_cQSignalMapper;

void Init_bando_qsignalmapper(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQSignalMapper =
        define_bando_qobject_under<Bando_QSignalMapper, QSignalMapper>(rb_mQt6Bando, "QSignalMapper")
            .define_constructor(Constructor<Bando_QSignalMapper, QObject *>(), Arg("parent"));
}
