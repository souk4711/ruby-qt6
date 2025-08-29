#include "qabstractslider-rb.hpp"
#include <qabstractslider.h>

using namespace Rice;

Rice::Class rb_cQAbstractSlider;

void Init_qabstractslider(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractSlider =
        // RubyQt6::QtWidgets::QAbstractSlider
        define_class_under<QAbstractSlider, QWidget>(rb_mQt6QtWidgets, "QAbstractSlider")
            .define_method("_inverted_appearance?", &QAbstractSlider::invertedAppearance)
            .define_method("_inverted_controls?", &QAbstractSlider::invertedControls)
            .define_method("_maximum", &QAbstractSlider::maximum)
            .define_method("_minimum", &QAbstractSlider::minimum)
            .define_method("_orientation", &QAbstractSlider::orientation)
            .define_method("_page_step", &QAbstractSlider::pageStep)
            .define_method("_single_step", &QAbstractSlider::singleStep)
            .define_method("_slider_down?", &QAbstractSlider::isSliderDown)
            .define_method("_slider_position", &QAbstractSlider::sliderPosition)
            .define_method("_has_tracking?", &QAbstractSlider::hasTracking)
            .define_method("_value", &QAbstractSlider::value)
            .define_method("_set_inverted_appearance", &QAbstractSlider::setInvertedAppearance, Arg("b"))
            .define_method("_set_inverted_controls", &QAbstractSlider::setInvertedControls, Arg("b"))
            .define_method("_set_maximum", &QAbstractSlider::setMaximum, Arg("max"))
            .define_method("_set_minimum", &QAbstractSlider::setMinimum, Arg("min"))
            .define_method("_set_orientation", &QAbstractSlider::setOrientation, Arg("orientation"))
            .define_method("_set_page_step", &QAbstractSlider::setPageStep, Arg("i"))
            .define_method("_set_single_step", &QAbstractSlider::setSingleStep, Arg("i"))
            .define_method("_set_slider_down", &QAbstractSlider::setSliderDown, Arg("b"))
            .define_method("_set_slider_position", &QAbstractSlider::setSliderPosition, Arg("i"))
            .define_method("_set_tracking", &QAbstractSlider::setTracking, Arg("b"))
            .define_method("_set_value", &QAbstractSlider::setValue, Arg("value"))
            .define_method("_set_range", &QAbstractSlider::setRange, Arg("min"), Arg("max"))
            .define_method("_trigger_action", &QAbstractSlider::triggerAction, Arg("action"));

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
