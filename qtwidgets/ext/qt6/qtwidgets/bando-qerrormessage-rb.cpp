#include "bando-qerrormessage-rb.hpp"
#include <bando/qwidget.hpp>

#include <QErrorMessage>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QErrorMessage = BandoQWidget<QErrorMessage, QWidget *>;

Class rb_mBando_cQErrorMessage;

void Init_bando_qerrormessage(Module rb_mQt6Bando)
{
    rb_mBando_cQErrorMessage =
        define_bando_qwidget_under<Bando_QErrorMessage, QErrorMessage>(rb_mQt6Bando, "QErrorMessage")
            .define_constructor(Constructor<Bando_QErrorMessage, QWidget *>(), Arg("parent"));
}
