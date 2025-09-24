#include "t-qtgui-rb.hpp"

#include <rice/qlist.hpp>
#include <QPoint>
#include <QPointF>

using namespace Rice;

void Init_t_qtgui(Rice::Module rb_mQt6T)
{
    define_qlist_under<QPoint>(rb_mQt6T);
    define_qlist_under<QPointF>(rb_mQt6T);
}
