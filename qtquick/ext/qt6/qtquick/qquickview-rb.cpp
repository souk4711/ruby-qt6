#include "qquickview-rb.hpp"
#include <qquickview.h>

using namespace Rice;

Rice::Class rb_cQQuickView;

void Init_qquickview(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickView =
        // RubyQt6::QtQuick::QQuickView
        define_class_under<QQuickView, QQuickWindow>(rb_mQt6QtQuick, "QQuickView")
            .define_constructor(Constructor<QQuickView, QWindow *>(), Arg("parent") = static_cast<QWindow *>(nullptr))
            .define_method("set_source", &QQuickView::setSource, Arg("url"));
}
