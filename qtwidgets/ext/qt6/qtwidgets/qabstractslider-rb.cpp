#include "qabstractslider-rb.hpp"
#include <qabstractslider.h>
#include <rice/qenum.hpp>

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
            .define_method("set_inverted_appearance", &QAbstractSlider::setInvertedAppearance, Arg("inverted_appearance"))
            .define_method("set_inverted_controls", &QAbstractSlider::setInvertedControls, Arg("inverted_controls"))
            .define_method("set_maximum", &QAbstractSlider::setMaximum, Arg("maximum"))
            .define_method("set_minimum", &QAbstractSlider::setMinimum, Arg("minimum"))
            .define_method("set_page_step", &QAbstractSlider::setPageStep, Arg("page_step"))
            .define_method("set_single_step", &QAbstractSlider::setSingleStep, Arg("single_step"))
            .define_method("set_slider_down", &QAbstractSlider::setSliderDown, Arg("slider_down"))
            .define_method("set_slider_position", &QAbstractSlider::setSliderPosition, Arg("slider_position"))
            .define_method("set_tracking", &QAbstractSlider::setTracking, Arg("enable"))
            .define_method("single_step", &QAbstractSlider::singleStep)
            .define_method("slider_position", &QAbstractSlider::sliderPosition)
            .define_method("trigger_action", &QAbstractSlider::triggerAction, Arg("action"))
            .define_method("value", &QAbstractSlider::value)
            // Public Slots
            .define_method("set_orientation", &QAbstractSlider::setOrientation, Arg("orientation"))
            .define_method("set_range", &QAbstractSlider::setRange, Arg("min"), Arg("max"))
            .define_method("set_value", &QAbstractSlider::setValue, Arg("value"))
            // Signals
            .define_method("action_triggered", &QAbstractSlider::actionTriggered, Arg("action"))
            .define_method("range_changed", &QAbstractSlider::rangeChanged, Arg("min"), Arg("max"))
            .define_method("slider_moved", &QAbstractSlider::sliderMoved, Arg("position"))
            .define_method("slider_pressed", &QAbstractSlider::sliderPressed)
            .define_method("slider_released", &QAbstractSlider::sliderReleased)
            .define_method("value_changed", &QAbstractSlider::valueChanged, Arg("value"));

    Data_Type<QAbstractSlider::SliderAction> rb_cQAbstractSliderSliderAction =
        // RubyQt6::QtWidgets::QAbstractSlider::SliderAction
        define_qenum_under<QAbstractSlider::SliderAction>(rb_cQAbstractSlider, "SliderAction");
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderNoAction", QAbstractSlider::SliderAction::SliderNoAction);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderSingleStepAdd", QAbstractSlider::SliderAction::SliderSingleStepAdd);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderSingleStepSub", QAbstractSlider::SliderAction::SliderSingleStepSub);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderPageStepAdd", QAbstractSlider::SliderAction::SliderPageStepAdd);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderPageStepSub", QAbstractSlider::SliderAction::SliderPageStepSub);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderToMinimum", QAbstractSlider::SliderAction::SliderToMinimum);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderToMaximum", QAbstractSlider::SliderAction::SliderToMaximum);
        define_qenum_value_under(rb_cQAbstractSliderSliderAction, "SliderMove", QAbstractSlider::SliderAction::SliderMove);
}
