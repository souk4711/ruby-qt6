#include "qslider-rb.hpp"
#include <qslider.h>

using namespace Rice;

Rice::Class rb_cQSlider;

void Init_qslider(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSlider =
        // RubyQt6::QtWidgets::QSlider
        define_class_under<QSlider, QAbstractSlider>(rb_mQt6QtWidgets, "QSlider")
            .define_constructor(Constructor<QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent") = static_cast<QWidget *>(nullptr))
            .define_method("_tick_interval", &QSlider::tickInterval)
            .define_method("_tick_position", &QSlider::tickPosition)
            .define_method("_set_tick_interval", &QSlider::setTickInterval, Arg("interval"))
            .define_method("_set_tick_position", &QSlider::setTickPosition, Arg("position"))
            .define_method("_size_hint", &QSlider::sizeHint)
            .define_method("_minimum_size_hint", &QSlider::minimumSizeHint);

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
