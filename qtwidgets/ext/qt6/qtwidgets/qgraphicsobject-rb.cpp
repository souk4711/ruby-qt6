#include "qgraphicsobject-rb.hpp"
#include <qgraphicsitem.h>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQGraphicsObject;

void Init_qgraphicsobject(Module rb_mQt6QtWidgets)
{
    rb_cQGraphicsObject =
        // RubyQt6::QtWidgets::QGraphicsObject
        define_qlass_under<QGraphicsObject, QObject>(rb_mQt6QtWidgets, "QGraphicsObject")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QGraphicsObject::staticMetaObject; })
            // Public Functions
            .define_method("grab_gesture", &QGraphicsObject::grabGesture, Arg("type"), Arg("flags") = static_cast<Qt::GestureFlags>(Qt::GestureFlags()))
            .define_method("ungrab_gesture", &QGraphicsObject::ungrabGesture, Arg("type"));
            // Signals
            // .define_method("children_changed", &QGraphicsObject::childrenChanged)
            // .define_method("enabled_changed", &QGraphicsObject::enabledChanged)
            // .define_method("height_changed", &QGraphicsObject::heightChanged)
            // .define_method("opacity_changed", &QGraphicsObject::opacityChanged)
            // .define_method("parent_changed", &QGraphicsObject::parentChanged)
            // .define_method("rotation_changed", &QGraphicsObject::rotationChanged)
            // .define_method("scale_changed", &QGraphicsObject::scaleChanged)
            // .define_method("visible_changed", &QGraphicsObject::visibleChanged)
            // .define_method("width_changed", &QGraphicsObject::widthChanged)
            // .define_method("x_changed", &QGraphicsObject::xChanged)
            // .define_method("y_changed", &QGraphicsObject::yChanged)
            // .define_method("z_changed", &QGraphicsObject::zChanged);
}
