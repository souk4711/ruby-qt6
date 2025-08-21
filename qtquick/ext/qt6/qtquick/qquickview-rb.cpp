#include "qquickview-rb.hpp"
#include <qquickview.h>

using namespace Rice;

Rice::Class rb_cQQuickView;

void Init_qquickview(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickView =
        // Qt6::QtQuick::QQuickView
        define_class_under<QQuickView, QQuickWindow>(rb_mQt6QtQuick, "QQuickView");
}
