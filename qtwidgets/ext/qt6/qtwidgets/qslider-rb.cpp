#include "qslider-rb.hpp"
#include <qslider.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQSlider;

void Init_qslider(Module rb_mQt6QtWidgets)
{
    rb_cQSlider =
        // RubyQt6::QtWidgets::QSlider
        define_qlass_under<QSlider, QAbstractSlider>(rb_mQt6QtWidgets, "QSlider")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSlider::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSlider, Qt::Orientation, QWidget *>(), Arg("orientation"), Arg("parent"))
            // Public Functions
            .define_method("set_tick_interval", &QSlider::setTickInterval, Arg("ti"))
            .define_method("set_tick_position", &QSlider::setTickPosition, Arg("position"))
            .define_method("tick_interval", &QSlider::tickInterval)
            .define_method("tick_position", &QSlider::tickPosition);

    Data_Type<QSlider::TickPosition> rb_cQSliderTickPosition =
        // RubyQt6::QtWidgets::QSlider::TickPosition
        define_qenum_under<QSlider::TickPosition>(rb_cQSlider, "TickPosition");
        define_qenum_value_under(rb_cQSliderTickPosition, "NoTicks", QSlider::TickPosition::NoTicks);
        define_qenum_value_under(rb_cQSliderTickPosition, "TicksAbove", QSlider::TickPosition::TicksAbove);
        define_qenum_value_under(rb_cQSliderTickPosition, "TicksLeft", QSlider::TickPosition::TicksLeft);
        define_qenum_value_under(rb_cQSliderTickPosition, "TicksBelow", QSlider::TickPosition::TicksBelow);
        define_qenum_value_under(rb_cQSliderTickPosition, "TicksRight", QSlider::TickPosition::TicksRight);
        define_qenum_value_under(rb_cQSliderTickPosition, "TicksBothSides", QSlider::TickPosition::TicksBothSides);
}
