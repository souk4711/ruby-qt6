#include "bando-qmessagebox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QMessageBox>

using namespace Rice;

using Bando_QMessageBox = BandoQWidget<QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>;

Rice::Class rb_mBando_cQMessageBox;

void Init_bando_qmessagebox(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQMessageBox =
        define_bando_qwidget_under<Bando_QMessageBox, QMessageBox>(rb_mQt6Bando, "QMessageBox")
            .define_constructor(Constructor<Bando_QMessageBox, QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *>(), Arg("icon"), Arg("title"), Arg("text"), Arg("buttons"), Arg("parent"));
}
