#include "bando-qitemdelegate-rb.hpp"
#include <bando/qobject/qitemdelegate.hpp>

#include <QItemDelegate>

RICE4RUBYQT6_USE_NAMESPACE

using Bando_QItemDelegate = BandoQItemDelegate<QItemDelegate, QObject *>;

Class rb_mBando_cQItemDelegate;

void Init_bando_qitemdelegate(Module rb_mQt6Bando)
{
    rb_mBando_cQItemDelegate =
        define_bando_qitemdelegate_under<Bando_QItemDelegate, QItemDelegate>(rb_mQt6Bando, "QItemDelegate")
            .define_constructor(Constructor<Bando_QItemDelegate, QObject *>(), Arg("parent"));
}
