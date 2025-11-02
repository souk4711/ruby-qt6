#include "bando-qtextbrowser-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTextBrowser>

using namespace Rice;

using Bando_QTextBrowser = BandoQWidget<QTextBrowser, QWidget *>;

Rice::Class rb_mBando_cQTextBrowser;

void Init_bando_qtextbrowser(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTextBrowser =
        define_bando_qwidget_under<Bando_QTextBrowser, QTextBrowser>(rb_mQt6Bando, "QTextBrowser")
            .define_constructor(Constructor<Bando_QTextBrowser, QWidget *>(), Arg("parent"));
}
