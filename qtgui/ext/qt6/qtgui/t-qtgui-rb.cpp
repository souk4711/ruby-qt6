#include "t-qtgui-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QPoint>
#include <QPointF>
#include <QTextLength>
#include <QScreen>

using namespace Rice;

void Init_t_qtgui(Rice::Module rb_mQt6T)
{
    // QList<QPoint> -> QPolygon
    define_qlist_under<QPoint>(rb_mQt6T);

    // QList<QPointF> -> QPolygonF
    define_qlist_under<QPointF>(rb_mQt6T);

    // QList<QTextLength>
    define_qlist_under<QTextLength>(rb_mQt6T);

    // QList<QScreen *>
    define_qlist_under<QScreen *>(rb_mQt6T);
}
