#include "qslider-rb.hpp"
#include <qslider.h>

#include <QEvent>

using namespace Rice;

Rice::Class rb_cQSlider;

void Init_qslider(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSlider =
        // RubyQt6::QtWidgets::QSlider
        define_class_under<QSlider, QAbstractSlider>(rb_mQt6QtWidgets, "QSlider")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSlider::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("event", &QSlider::event, Arg("event"))
            .define_method("minimum_size_hint", &QSlider::minimumSizeHint)
            .define_method("set_tick_interval", &QSlider::setTickInterval, Arg("ti"))
            .define_method("set_tick_position", &QSlider::setTickPosition, Arg("position"))
            .define_method("size_hint", &QSlider::sizeHint)
            .define_method("tick_interval", &QSlider::tickInterval)
            .define_method("tick_position", &QSlider::tickPosition);

    Enum<QSlider::TickPosition> rb_cQSliderTickPosition =
        // RubyQt6::QtWidgets::QSlider::TickPosition
        define_enum_under<QSlider::TickPosition>("TickPosition", rb_cQSlider)
            .define_value("NoTicks", QSlider::TickPosition::NoTicks)
            .define_value("TicksAbove", QSlider::TickPosition::TicksAbove)
            .define_value("TicksLeft", QSlider::TickPosition::TicksLeft)
            .define_value("TicksBelow", QSlider::TickPosition::TicksBelow)
            .define_value("TicksRight", QSlider::TickPosition::TicksRight)
            .define_value("TicksBothSides", QSlider::TickPosition::TicksBothSides);
}
