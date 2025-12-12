#include "bando-qcommandlinkbutton-rb.hpp"
#include <bando/qwidget.hpp>

#include <QCommandLinkButton>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QCommandLinkButton = BandoQWidget<QCommandLinkButton, const QString &, const QString &, QWidget *>;

Class rb_mBando_cQCommandLinkButton;

void Init_bando_qcommandlinkbutton(Module rb_mQt6Bando)
{
    rb_mBando_cQCommandLinkButton =
        define_bando_qwidget_under<Bando_QCommandLinkButton, QCommandLinkButton>(rb_mQt6Bando, "QCommandLinkButton")
            .define_constructor(Constructor<Bando_QCommandLinkButton, const QString &, const QString &, QWidget *>(), Arg("text"), Arg("description"), Arg("parent"));
}
