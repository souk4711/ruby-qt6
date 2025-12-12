#include "bando-qdockwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDockWidget>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDockWidget = BandoQWidget<QDockWidget, const QString &, QWidget *>;

Class rb_mBando_cQDockWidget;

void Init_bando_qdockwidget(Module rb_mQt6Bando)
{
    rb_mBando_cQDockWidget =
        define_bando_qwidget_under<Bando_QDockWidget, QDockWidget>(rb_mQt6Bando, "QDockWidget")
            .define_constructor(Constructor<Bando_QDockWidget, const QString &, QWidget *>(), Arg("title"), Arg("parent"));
}
