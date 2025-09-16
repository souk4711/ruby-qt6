#include "bando-rb.hpp"
#include <bando/qobject.hpp>
#include <bando/qwindow.hpp>

#include <QGuiApplication>
#include <QWindow>

using namespace Rice;

using Bando_QGuiApplication = BandoQObject<QGuiApplication, int &, char **>;
using Bando_QWindow = BandoQWindow<QWindow, QWindow *>;

Rice::Class rb_mBando_cQGuiApplication;
Rice::Class rb_mBando_cQWindow;

void Init_bando(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQGuiApplication =
        define_class_under<Bando_QGuiApplication, QGuiApplication>(rb_mQt6Bando, "QGuiApplication")
            .define_constructor(Constructor<Bando_QGuiApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_method("_initialize_value", &Bando_QGuiApplication::initializeValue, Arg("mo"), Arg("value"));

    rb_mBando_cQWindow =
        define_class_under<Bando_QWindow, QWindow>(rb_mQt6Bando, "QWindow")
            .define_constructor(Constructor<Bando_QWindow, QWindow *>(), Arg("parent"))
            .define_method("_initialize_value", &Bando_QWindow::initializeValue, Arg("mo"), Arg("value"));
}
