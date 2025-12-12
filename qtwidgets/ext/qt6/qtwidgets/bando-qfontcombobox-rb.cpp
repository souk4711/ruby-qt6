#include "bando-qfontcombobox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QFontComboBox>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QFontComboBox = BandoQWidget<QFontComboBox, QWidget *>;

Class rb_mBando_cQFontComboBox;

void Init_bando_qfontcombobox(Module rb_mQt6Bando)
{
    rb_mBando_cQFontComboBox =
        define_bando_qwidget_under<Bando_QFontComboBox, QFontComboBox>(rb_mQt6Bando, "QFontComboBox")
            .define_constructor(Constructor<Bando_QFontComboBox, QWidget *>(), Arg("parent"));
}
