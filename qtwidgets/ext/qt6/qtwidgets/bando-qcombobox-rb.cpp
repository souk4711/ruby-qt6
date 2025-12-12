#include "bando-qcombobox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QComboBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QComboBox = BandoQWidget<QComboBox, QWidget *>;

Class rb_mBando_cQComboBox;

void Init_bando_qcombobox(Module rb_mQt6Bando)
{
    rb_mBando_cQComboBox =
        define_bando_qwidget_under<Bando_QComboBox, QComboBox>(rb_mQt6Bando, "QComboBox")
            .define_constructor(Constructor<Bando_QComboBox, QWidget *>(), Arg("parent"));
}
