#include "bando-qcombobox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QComboBox>

using namespace Rice;

using Bando_QComboBox = BandoQWidget<QComboBox, QWidget *>;

Rice::Class rb_mBando_cQComboBox;

void Init_bando_qcombobox(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQComboBox =
        define_bando_qwidget_under<Bando_QComboBox, QComboBox>(rb_mQt6Bando, "QComboBox")
            .define_constructor(Constructor<Bando_QComboBox, QWidget *>(), Arg("parent"));
}
