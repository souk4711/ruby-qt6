#include "bando-qwebenginepage-rb.hpp"
#include <bando/qobject/qwebenginepage.hpp>

#include <QWebEnginePage>
#include <QWebEngineProfile>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QWebEnginePage = BandoQWebEnginePage<QWebEnginePage, QObject *>;

Class rb_mBando_cQWebEnginePage;

void Init_bando_qwebenginepage(Module rb_mQt6Bando)
{
    rb_mBando_cQWebEnginePage =
        define_bando_qwebenginepage_under<Bando_QWebEnginePage, QWebEnginePage>(rb_mQt6Bando, "QWebEnginePage")
            .define_constructor(Constructor<Bando_QWebEnginePage, QObject *>(), Arg("parent"));
}
