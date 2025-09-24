#include "qpolygon-rb.hpp"
#include <qpolygon.h>

#include <QList>

using namespace Rice;

Rice::Class rb_cQPointList;
Rice::Class rb_cQPointFList;
Rice::Class rb_cQPolygon;
Rice::Class rb_cQPolygonF;

void Init_qpolygon(Rice::Module rb_mQt6QtGui)
{
    rb_cQPointList =
        // RubyQt6::QtGui::QList<QPoint>
        define_class_under<QList<QPoint>>(rb_mQt6QtGui, "QPointList");

    rb_cQPointFList =
        // RubyQt6::QtGui::QList<QPointF>
        define_class_under<QList<QPointF>>(rb_mQt6QtGui, "QPointFList");

    rb_cQPolygon =
        // RubyQt6::QtGui::QPolygon
        define_class_under<QPolygon, QList<QPoint>>(rb_mQt6QtGui, "QPolygon");

    rb_cQPolygonF =
        // RubyQt6::QtGui::QPolygonF
        define_class_under<QPolygonF, QList<QPointF>>(rb_mQt6QtGui, "QPolygonF");
}
