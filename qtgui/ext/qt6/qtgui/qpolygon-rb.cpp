#include "qpolygon-rb.hpp"
#include <qpolygon.h>

using namespace Rice;

Rice::Class rb_cQPolygon;
Rice::Class rb_cQPolygonF;

void Init_qpolygon(Rice::Module rb_mQt6QtGui)
{
    rb_cQPolygon =
        // RubyQt6::QtGui::QPolygon
        define_class_under<QPolygon, QList<QPoint>>(rb_mQt6QtGui, "QPolygon");

    rb_cQPolygonF =
        // RubyQt6::QtGui::QPolygonF
        define_class_under<QPolygonF, QList<QPointF>>(rb_mQt6QtGui, "QPolygonF");
}
