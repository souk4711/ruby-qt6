#include "bando-qlistwidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QListWidget>

using namespace Rice;

using Bando_QListWidget = BandoQWidget<QListWidget, QWidget *>;

Rice::Class rb_mBando_cQListWidget;

void Init_bando_qlistwidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQListWidget =
        define_bando_qwidget_under<Bando_QListWidget, QListWidget>(rb_mQt6Bando, "QListWidget")
            .define_constructor(Constructor<Bando_QListWidget, QWidget *>(), Arg("parent"));
}
