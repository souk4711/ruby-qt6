#include "bando-qwebenginepage-rb.hpp"
#include <bando/qobject/qwebenginepage.hpp>

#include <QWebEnginePage>
#include <QWebEngineProfile>

using namespace Rice;

using Bando_QWebEnginePage = BandoQWebEnginePage<QWebEnginePage, QWebEngineProfile *, QObject *>;

Rice::Class rb_mBando_cQWebEnginePage;

void Init_bando_qwebenginepage(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQWebEnginePage =
        define_bando_qwebenginepage_under<Bando_QWebEnginePage, QWebEnginePage>(rb_mQt6Bando, "QWebEnginePage")
            .define_constructor(Constructor<Bando_QWebEnginePage, QWebEngineProfile *, QObject *>(), Arg("profile"), Arg("parent"));
}
