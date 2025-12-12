#include "bando-qstyleditemdelegate-rb.hpp"
#include <bando/qobject/qitemdelegate.hpp>

#include <QStyledItemDelegate>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QStyledItemDelegate = BandoQItemDelegate<QStyledItemDelegate, QObject *>;

Class rb_mBando_cQStyledItemDelegate;

void Init_bando_qstyleditemdelegate(Module rb_mQt6Bando)
{
    rb_mBando_cQStyledItemDelegate =
        define_bando_qitemdelegate_under<Bando_QStyledItemDelegate, QStyledItemDelegate>(rb_mQt6Bando, "QStyledItemDelegate")
            .define_constructor(Constructor<Bando_QStyledItemDelegate, QObject *>(), Arg("parent"));
}
