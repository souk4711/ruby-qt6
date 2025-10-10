#include "bando-qcoreapplication-rb.hpp"
#include <bando/qobject.hpp>

#include <QCoreApplication>

using namespace Rice;

using Bando_QCoreApplication = BandoQObject<QCoreApplication, int &, char **>;

Rice::Class rb_mBando_cQCoreApplication;

void Init_bando_qcoreapplication(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQCoreApplication =
        define_bando_qobject_under<Bando_QCoreApplication, QCoreApplication>(rb_mQt6Bando, "QCoreApplication")
            .define_constructor(Constructor<Bando_QCoreApplication, int &, char **>(), Arg("argc"), Arg("argv"));
}
