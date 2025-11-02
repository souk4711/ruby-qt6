#include "bando-qquickitem-rb.hpp"
#include <bando/qobject/qquickitem.hpp>

#include <QQuickItem>

using namespace Rice;

using Bando_QQuickItem = BandoQQuickItem<QQuickItem, QQuickItem *>;

Rice::Class rb_mBando_cQQuickItem;

void Init_bando_qquickitem(Rice::Module rb_mQt6Bando)
{
    rb_mBando_cQQuickItem =
        define_bando_qquickitem_under<Bando_QQuickItem, QQuickItem>(rb_mQt6Bando, "QQuickItem")
            .define_constructor(Constructor<Bando_QQuickItem, QQuickItem *>(), Arg("parent"));
}
