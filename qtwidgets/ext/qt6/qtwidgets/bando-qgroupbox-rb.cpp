#include "bando-qgroupbox-rb.hpp"
#include <bando/qwidget.hpp>

#include <QGroupBox>

using namespace Rice;

using Bando_QGroupBox = BandoQWidget<QGroupBox, const QString &, QWidget *>;

Rice::Class rb_mBando_cQGroupBox;

void Init_bando_qgroupbox(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQGroupBox =
        define_bando_qwidget_under<Bando_QGroupBox, QGroupBox>(rb_mQt6Bando, "QGroupBox")
            .define_constructor(Constructor<Bando_QGroupBox, const QString &, QWidget *>(), Arg("title"), Arg("parent"));
}
