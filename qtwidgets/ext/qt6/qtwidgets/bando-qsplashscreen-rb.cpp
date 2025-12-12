#include "bando-qsplashscreen-rb.hpp"
#include <bando/qwidget.hpp>

#include <QSplashScreen>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QSplashScreen = BandoQWidget<QSplashScreen, const QPixmap &>;

Class rb_mBando_cQSplashScreen;

void Init_bando_qsplashscreen(Module rb_mQt6Bando)
{
    rb_mBando_cQSplashScreen =
        define_bando_qwidget_under<Bando_QSplashScreen, QSplashScreen>(rb_mQt6Bando, "QSplashScreen")
            .define_constructor(Constructor<Bando_QSplashScreen, const QPixmap &>(), Arg("pixmap"));
}
