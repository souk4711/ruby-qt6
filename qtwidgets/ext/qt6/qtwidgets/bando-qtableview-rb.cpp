#include "bando-qtableview-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTableView>

using namespace Rice;

using Bando_QTableView = BandoQWidget<QTableView, QWidget *>;

Rice::Class rb_mBando_cQTableView;

void Init_bando_qtableview(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTableView =
        define_bando_qwidget_under<Bando_QTableView, QTableView>(rb_mQt6Bando, "QTableView")
            .define_constructor(Constructor<Bando_QTableView, QWidget *>(), Arg("parent"));
}
