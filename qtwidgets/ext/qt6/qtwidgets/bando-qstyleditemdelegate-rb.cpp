#include "bando-qstyleditemdelegate-rb.hpp"
#include <bando/qitemdelegate.hpp>

#include <QStyledItemDelegate>

using namespace Rice;

using Bando_QStyledItemDelegate = BandoQItemDelegate<QStyledItemDelegate, QObject *>;

Rice::Class rb_mBando_cQStyledItemDelegate;

void Init_bando_qstyleditemdelegate(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQStyledItemDelegate =
        define_bando_qitemdelegate_under<Bando_QStyledItemDelegate, QStyledItemDelegate>(rb_mQt6Bando, "QStyledItemDelegate")
            .define_constructor(Constructor<Bando_QStyledItemDelegate, QObject *>(), Arg("parent"));
}
