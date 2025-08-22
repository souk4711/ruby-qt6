#include "qquickpainteditem-rb.hpp"
#include <qquickpainteditem.h>

using namespace Rice;

Rice::Class rb_cQQuickPaintedItem;

void Init_qquickpainteditem(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickPaintedItem =
        // RubyQt6::QtQuick::QQuickPaintedItem
        define_class_under<QQuickPaintedItem, QQuickItem>(rb_mQt6QtQuick, "QQuickPaintedItem");
}
