#include "t-qtgui-rb.hpp"
#include <rice/qlist.hpp>

#include <QPoint>
#include <QPointF>
#include <QScreen>

using namespace Rice;

void Init_t_qtgui(Rice::Module rb_mQt6T)
{
    // QList<QPoint> -> QPolygon
    define_qlist_under<QPoint>(rb_mQt6T);

    // QList<QPointF> -> QPolygonF
    define_qlist_under<QPointF>(rb_mQt6T);

    // QList<QScreen *>
    define_qlist_under<QScreen *>(rb_mQt6T);
}
