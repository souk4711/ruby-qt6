#include "bando-qtextbrowser-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTextBrowser>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTextBrowser = BandoQWidget<QTextBrowser, QWidget *>;

Class rb_mBando_cQTextBrowser;

void Init_bando_qtextbrowser(Module rb_mQt6Bando)
{
    rb_mBando_cQTextBrowser =
        define_bando_qwidget_under<Bando_QTextBrowser, QTextBrowser>(rb_mQt6Bando, "QTextBrowser")
            .define_constructor(Constructor<Bando_QTextBrowser, QWidget *>(), Arg("parent"));
}
