#include "bando-qmessagebox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMessageBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QMessageBox = BandoQWidget<QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>;

Class rb_mBando_cQMessageBox;

void Init_bando_qmessagebox(Module rb_mQt6Bando)
{
    rb_mBando_cQMessageBox =
        define_bando_qwidget_under<Bando_QMessageBox, QMessageBox>(rb_mQt6Bando, "QMessageBox")
            .define_constructor(Constructor<Bando_QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>(), Arg("icon"), Arg("title"), Arg("text"), Arg("buttons"), Arg("parent"));
}
