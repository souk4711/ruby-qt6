#include "bando-qtableview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTableView>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QTableView = BandoQWidget<QTableView, QWidget *>;

Class rb_mBando_cQTableView;

void Init_bando_qtableview(Module rb_mQt6Bando)
{
    rb_mBando_cQTableView =
        define_bando_qwidget_under<Bando_QTableView, QTableView>(rb_mQt6Bando, "QTableView")
            .define_constructor(Constructor<Bando_QTableView, QWidget *>(), Arg("parent"));
}
