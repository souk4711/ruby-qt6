#include "bando-qlistview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QListView>

using namespace Rice;

using Bando_QListView = BandoQWidget<QListView, QWidget *>;

Rice::Class rb_mBando_cQListView;

void Init_bando_qlistview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQListView =
        define_bando_qwidget_under<Bando_QListView, QListView>(rb_mQt6Bando, "QListView")
            .define_constructor(Constructor<Bando_QListView, QWidget *>(), Arg("parent"));
}
