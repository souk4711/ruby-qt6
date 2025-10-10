#include "bando-qguiapplication-rb.hpp"
#include <bando/qobject.hpp>

#include <QGuiApplication>

using namespace Rice;

using Bando_QGuiApplication = BandoQObject<QGuiApplication, int &, char **>;

Rice::Class rb_mBando_cQGuiApplication;

void Init_bando_qguiapplication(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQGuiApplication =
        define_bando_qobject_under<Bando_QGuiApplication, QGuiApplication>(rb_mQt6Bando, "QGuiApplication")
            .define_constructor(Constructor<Bando_QGuiApplication, int &, char **>(), Arg("argc"), Arg("argv"));
}
