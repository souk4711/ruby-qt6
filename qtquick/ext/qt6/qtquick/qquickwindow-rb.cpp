#include "qquickwindow-rb.hpp"
#include <qquickwindow.h>

using namespace Rice;

Rice::Class rb_cQQuickWindow;

void Init_qquickwindow(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickWindow =
        // RubyQt6::QtQuick::QQuickWindow
        define_class_under<QQuickWindow, QWindow>(rb_mQt6QtQuick, "QQuickWindow");
}
