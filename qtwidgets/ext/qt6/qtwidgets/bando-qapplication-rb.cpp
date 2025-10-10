#include "bando-qapplication-rb.hpp"
#include <bando/qobject.hpp>

#include <QApplication>

using namespace Rice;

using Bando_QApplication = BandoQObject<QApplication, int &, char **>;

Rice::Class rb_mBando_cQApplication;

void Init_bando_qapplication(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQApplication =
        define_bando_qobject_under<Bando_QApplication, QApplication>(rb_mQt6Bando, "QApplication")
            .define_constructor(Constructor<Bando_QApplication, int &, char **>(), Arg("argc"), Arg("argv"));
}
