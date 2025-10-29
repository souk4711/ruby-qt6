#include "bando-qitemdelegate-rb.hpp"
#include <bando/qobject/qitemdelegate.hpp>

#include <QItemDelegate>

using namespace Rice;

using Bando_QItemDelegate = BandoQItemDelegate<QItemDelegate, QObject *>;

Rice::Class rb_mBando_cQItemDelegate;

void Init_bando_qitemdelegate(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQItemDelegate =
        define_bando_qitemdelegate_under<Bando_QItemDelegate, QItemDelegate>(rb_mQt6Bando, "QItemDelegate")
            .define_constructor(Constructor<Bando_QItemDelegate, QObject *>(), Arg("parent"));
}
