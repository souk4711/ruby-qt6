#include "bando-qtablewidget-rb.hpp"
#include <bando/qwidget.hpp>

#include <QTableWidget>

using namespace Rice;

using Bando_QTableWidget = BandoQWidget<QTableWidget, int, int, QWidget *>;

Rice::Class rb_mBando_cQTableWidget;

void Init_bando_qtablewidget(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQTableWidget =
        define_bando_qwidget_under<Bando_QTableWidget, QTableWidget>(rb_mQt6Bando, "QTableWidget")
            .define_constructor(Constructor<Bando_QTableWidget, int, int, QWidget *>(), Arg("rows"), Arg("columns"), Arg("parent"));
}
