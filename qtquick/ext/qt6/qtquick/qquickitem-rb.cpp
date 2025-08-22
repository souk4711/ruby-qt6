#include "qquickitem-rb.hpp"
#include <qquickitem.h>

using namespace Rice;

Rice::Class rb_cQQuickItem;

void Init_qquickitem(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickItem =
        // RubyQt6::QtQuick::QQuickItem
        define_class_under<QQuickItem, QObject>(rb_mQt6QtQuick, "QQuickItem");
}
