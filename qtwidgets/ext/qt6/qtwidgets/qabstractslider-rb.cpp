#include "qabstractslider-rb.hpp"
#include <qabstractslider.h>

using namespace Rice;

Rice::Class rb_cQAbstractSlider;

void Init_qabstractslider(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractSlider =
        // RubyQt6::QtWidgets::QAbstractSlider
        define_class_under<QAbstractSlider, QWidget>(rb_mQt6QtWidgets, "QAbstractSlider")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractSlider::staticMetaObject; })
            // Public Functions
            .define_method("has_tracking", &QAbstractSlider::hasTracking)
            .define_method("inverted_appearance", &QAbstractSlider::invertedAppearance)
            .define_method("inverted_controls", &QAbstractSlider::invertedControls)
            .define_method("slider_down?", &QAbstractSlider::isSliderDown)
            .define_method("maximum", &QAbstractSlider::maximum)
            .define_method("minimum", &QAbstractSlider::minimum)
            .define_method("orientation", &QAbstractSlider::orientation)
            .define_method("page_step", &QAbstractSlider::pageStep)
            .define_method("set_inverted_appearance", &QAbstractSlider::setInvertedAppearance, Arg(""))
            .define_method("set_inverted_controls", &QAbstractSlider::setInvertedControls, Arg(""))
            .define_method("set_maximum", &QAbstractSlider::setMaximum, Arg(""))
            .define_method("set_minimum", &QAbstractSlider::setMinimum, Arg(""))
            .define_method("set_page_step", &QAbstractSlider::setPageStep, Arg(""))
            .define_method("set_single_step", &QAbstractSlider::setSingleStep, Arg(""))
            .define_method("set_slider_down", &QAbstractSlider::setSliderDown, Arg(""))
            .define_method("set_slider_position", &QAbstractSlider::setSliderPosition, Arg(""))
            .define_method("set_tracking", &QAbstractSlider::setTracking, Arg("enable"))
            .define_method("single_step", &QAbstractSlider::singleStep)
            .define_method("slider_position", &QAbstractSlider::sliderPosition)
            .define_method("trigger_action", &QAbstractSlider::triggerAction, Arg("action"))
            .define_method("value", &QAbstractSlider::value)
            // Public Slots
            .define_method("set_orientation", &QAbstractSlider::setOrientation, Arg(""))
            .define_method("set_range", &QAbstractSlider::setRange, Arg("min"), Arg("max"))
            .define_method("set_value", &QAbstractSlider::setValue, Arg(""))
            // Signals
            .define_method("action_triggered", &QAbstractSlider::actionTriggered, Arg("action"))
            .define_method("range_changed", &QAbstractSlider::rangeChanged, Arg("min"), Arg("max"))
            .define_method("slider_moved", &QAbstractSlider::sliderMoved, Arg("position"))
            .define_method("slider_pressed", &QAbstractSlider::sliderPressed)
            .define_method("slider_released", &QAbstractSlider::sliderReleased)
            .define_method("value_changed", &QAbstractSlider::valueChanged, Arg("value"));


    Enum<QAbstractSlider::SliderAction> rb_cQAbstractSliderSliderAction =
        // RubyQt6::QtWidgets::QAbstractSlider::SliderAction
        define_enum_under<QAbstractSlider::SliderAction>("SliderAction", rb_cQAbstractSlider)
            .define_value("SliderNoAction", QAbstractSlider::SliderAction::SliderNoAction)
            .define_value("SliderSingleStepAdd", QAbstractSlider::SliderAction::SliderSingleStepAdd)
            .define_value("SliderSingleStepSub", QAbstractSlider::SliderAction::SliderSingleStepSub)
            .define_value("SliderPageStepAdd", QAbstractSlider::SliderAction::SliderPageStepAdd)
            .define_value("SliderPageStepSub", QAbstractSlider::SliderAction::SliderPageStepSub)
            .define_value("SliderToMinimum", QAbstractSlider::SliderAction::SliderToMinimum)
            .define_value("SliderToMaximum", QAbstractSlider::SliderAction::SliderToMaximum)
            .define_value("SliderMove", QAbstractSlider::SliderAction::SliderMove);
}
