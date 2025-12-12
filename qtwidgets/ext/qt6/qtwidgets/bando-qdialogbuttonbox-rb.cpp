#include "bando-qdialogbuttonbox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QDialogButtonBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QDialogButtonBox = BandoQWidget<QDialogButtonBox, QDialogButtonBox::StandardButtons, Qt::Orientation, QWidget *>;

Class rb_mBando_cQDialogButtonBox;

void Init_bando_qdialogbuttonbox(Module rb_mQt6Bando)
{
    rb_mBando_cQDialogButtonBox =
        define_bando_qwidget_under<Bando_QDialogButtonBox, QDialogButtonBox>(rb_mQt6Bando, "QDialogButtonBox")
            .define_constructor(Constructor<Bando_QDialogButtonBox, QDialogButtonBox::StandardButtons, Qt::Orientation, QWidget *>(), Arg("buttons"), Arg("orientation"), Arg("parent"));
}
