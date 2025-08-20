#include "qquickview-rb.hpp"
#include <qquickview.h>

#include <QQuickItem>
#include <QtQml/QQmlComponent>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>

using namespace Rice;

Rice::Class rb_cQQuickView;

void Init_QQuickView(Rice::Module rb_mQt6QtQuick)
{
    rb_cQQuickView =
        // Qt6::QtQuick::QQuickView
        define_class_under<QQuickView, QQuickWindow>(rb_mQt6QtQuick, "QQuickView")
            .define_constructor(Constructor<QQuickView, QWindow *>(), Arg("parent") = static_cast<QWindow *>(nullptr))
            .define_constructor(Constructor<QQuickView, QQmlEngine *, QWindow *>(), Arg("engine"), Arg("parent"))
            .define_constructor(Constructor<QQuickView, const QUrl &, QWindow *>(), Arg("source"), Arg("parent") = static_cast<QWindow *>(nullptr))
            .define_constructor(Constructor<QQuickView, QAnyStringView, QAnyStringView, QWindow *>(), Arg("uri"), Arg("type_name"), Arg("parent") = static_cast<QWindow *>(nullptr))
            // TODO: .define_constructor(Constructor<QQuickView, const QUrl &, QQuickRenderControl *>(), Arg("source"), Arg("render_control"))
            .define_method("source", &QQuickView::source)
            .define_method("engine", &QQuickView::engine)
            .define_method("root_context", &QQuickView::rootContext)
            .define_method("root_object", &QQuickView::rootObject)
            .define_method("resize_mode", &QQuickView::resizeMode)
            .define_method("set_resize_mode", &QQuickView::setResizeMode, Arg(""))
            .define_method("status", &QQuickView::status)
            .define_method("errors", &QQuickView::errors)
            .define_method("size_hint", &QQuickView::sizeHint)
            .define_method("initial_size", &QQuickView::initialSize)
            .define_method("set_source", &QQuickView::setSource, Arg(""))
            .define_method("load_from_module", &QQuickView::loadFromModule, Arg("uri"), Arg("type_name"))
            .define_method("set_initial_properties", &QQuickView::setInitialProperties, Arg("initial_properties"))
            .define_method("set_content", &QQuickView::setContent, Arg("url"), Arg("component"), Arg("item"))
            .define_method("status_changed", &QQuickView::statusChanged, Arg(""));

    // clang-format off
    Enum<QQuickView::ResizeMode> rb_cQQuickViewResizeMode =
        // Qt6::QtQuick::QQuickView::ResizeMode
        define_enum_under<QQuickView::ResizeMode>("ResizeMode", rb_cQQuickView)
            .define_value("SizeViewToRootObject", QQuickView::ResizeMode::SizeViewToRootObject)
            .define_value("SizeRootObjectToView", QQuickView::ResizeMode::SizeRootObjectToView);

    Enum<QQuickView::Status> rb_cQQuickViewStatus =
        // Qt6::QtQuick::QQuickView::Status
        define_enum_under<QQuickView::Status>("Status", rb_cQQuickView)
            .define_value("Null", QQuickView::Status::Null)
            .define_value("Ready", QQuickView::Status::Ready)
            .define_value("Loading", QQuickView::Status::Loading)
            .define_value("Error", QQuickView::Status::Error);
}
