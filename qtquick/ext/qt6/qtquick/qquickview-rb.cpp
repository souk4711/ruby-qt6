#include "qquickview-rb.hpp"
#include <qquickview.h>

#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>

using namespace Rice;

Rice::Class rb_cQQuickView;

void Init_qquickview(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickView =
        // RubyQt6::QtQuick::QQuickView
        define_class_under<QQuickView, QQuickWindow>(rb_mQt6QtQuick, "QQuickView")
            // Constructor
            .define_constructor(Constructor<QQuickView, QWindow *>(), Arg("parent") = static_cast<QWindow *>(nullptr))
            // Properties
            .define_method("resize_mode", &QQuickView::resizeMode)
            .define_method("source", &QQuickView::source)
            .define_method("status", &QQuickView::status)
            .define_method("set_resize_mode", &QQuickView::setResizeMode, Arg("mode"))
            .define_method("set_source", &QQuickView::setSource, Arg("source"))
            // Public Functions
            .define_method("engine", &QQuickView::engine)
            .define_method("errors", &QQuickView::errors)
            .define_method("initial_size", &QQuickView::initialSize)
            .define_method("root_context", &QQuickView::rootContext)
            .define_method("root_object", &QQuickView::rootObject)
            // Public Slots
            .define_method("load_from_module", &QQuickView::loadFromModule, Arg("uri"), Arg("type_name"))
            .define_method("set_initial_properties", &QQuickView::setInitialProperties, Arg("initial_properties"))
            // Signals
            .define_method("status_changed", &QQuickView::statusChanged, Arg("status"));
}
