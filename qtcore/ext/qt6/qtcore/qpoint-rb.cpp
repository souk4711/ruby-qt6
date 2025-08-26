#include "qpoint-rb.hpp"
#include <qpoint.h>

using namespace Rice;

Rice::Class rb_cQPoint;
Rice::Class rb_cQPointF;

void Init_qpoint(Rice::Module rb_mQt6QtCore)
{
    rb_cQPoint =
        // RubyQt6::QtCore::QPoint
        define_class_under<QPoint>(rb_mQt6QtCore, "QPoint");

    rb_cQPointF =
        // RubyQt6::QtCore::QPointF
        define_class_under<QPointF>(rb_mQt6QtCore, "QPointF");
}
