#include "qspinbox-rb.hpp"
#include <qspinbox.h>

using namespace Rice;

Rice::Class rb_cQDoubleSpinBox;
Rice::Class rb_cQSpinBox;

void Init_qspinbox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQDoubleSpinBox =
        // RubyQt6::QtWidgets::QDoubleSpinBox
        define_class_under<QDoubleSpinBox, QAbstractSpinBox>(rb_mQt6QtWidgets, "QDoubleSpinBox")
            // RubyQt6-Defined Functions
            .define_method("set_prefix", [](QDoubleSpinBox *self, const char *prefix) -> void { return self->setPrefix(prefix); }, Arg("prefix"))
            .define_method("set_suffix", [](QDoubleSpinBox *self, const char *suffix) -> void { return self->setSuffix(suffix); }, Arg("suffix"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QDoubleSpinBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QDoubleSpinBox, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("clean_text", &QDoubleSpinBox::cleanText)
            .define_method("decimals", &QDoubleSpinBox::decimals)
            .define_method("fixup", &QDoubleSpinBox::fixup, Arg("str"))
            .define_method("maximum", &QDoubleSpinBox::maximum)
            .define_method("minimum", &QDoubleSpinBox::minimum)
            .define_method("prefix", &QDoubleSpinBox::prefix)
            .define_method("set_decimals", &QDoubleSpinBox::setDecimals, Arg("prec"))
            .define_method("set_maximum", &QDoubleSpinBox::setMaximum, Arg("max"))
            .define_method("set_minimum", &QDoubleSpinBox::setMinimum, Arg("min"))
            .define_method("set_prefix", &QDoubleSpinBox::setPrefix, Arg("prefix"))
            .define_method("set_range", &QDoubleSpinBox::setRange, Arg("min"), Arg("max"))
            .define_method("set_single_step", &QDoubleSpinBox::setSingleStep, Arg("val"))
            .define_method("set_step_type", &QDoubleSpinBox::setStepType, Arg("step_type"))
            .define_method("set_suffix", &QDoubleSpinBox::setSuffix, Arg("suffix"))
            .define_method("single_step", &QDoubleSpinBox::singleStep)
            .define_method("step_type", &QDoubleSpinBox::stepType)
            .define_method("suffix", &QDoubleSpinBox::suffix)
            .define_method("text_from_value", &QDoubleSpinBox::textFromValue, Arg("val"))
            .define_method("validate", &QDoubleSpinBox::validate, Arg("input"), Arg("pos"))
            .define_method("value", &QDoubleSpinBox::value)
            .define_method("value_from_text", &QDoubleSpinBox::valueFromText, Arg("text"))
            // Public Slots
            .define_method("set_value", &QDoubleSpinBox::setValue, Arg("val"))
            // Signals
            .define_method("text_changed", &QDoubleSpinBox::textChanged, Arg("text"))
            .define_method("value_changed", &QDoubleSpinBox::valueChanged, Arg("val"));

    rb_cQSpinBox =
        // RubyQt6::QtWidgets::QSpinBox
        define_class_under<QSpinBox, QAbstractSpinBox>(rb_mQt6QtWidgets, "QSpinBox")
            // RubyQt6-Defined Functions
            .define_method("set_prefix", [](QSpinBox *self, const char *prefix) -> void { return self->setPrefix(prefix); }, Arg("prefix"))
            .define_method("set_suffix", [](QSpinBox *self, const char *suffix) -> void { return self->setSuffix(suffix); }, Arg("suffix"))
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QSpinBox::staticMetaObject; })
            // Constructor
            .define_constructor(Constructor<QSpinBox, QWidget *>(), Arg("parent"))
            // Public Functions
            .define_method("clean_text", &QSpinBox::cleanText)
            .define_method("display_integer_base", &QSpinBox::displayIntegerBase)
            .define_method("maximum", &QSpinBox::maximum)
            .define_method("minimum", &QSpinBox::minimum)
            .define_method("prefix", &QSpinBox::prefix)
            .define_method("set_display_integer_base", &QSpinBox::setDisplayIntegerBase, Arg("base"))
            .define_method("set_maximum", &QSpinBox::setMaximum, Arg("max"))
            .define_method("set_minimum", &QSpinBox::setMinimum, Arg("min"))
            .define_method("set_prefix", &QSpinBox::setPrefix, Arg("prefix"))
            .define_method("set_range", &QSpinBox::setRange, Arg("min"), Arg("max"))
            .define_method("set_single_step", &QSpinBox::setSingleStep, Arg("val"))
            .define_method("set_step_type", &QSpinBox::setStepType, Arg("step_type"))
            .define_method("set_suffix", &QSpinBox::setSuffix, Arg("suffix"))
            .define_method("single_step", &QSpinBox::singleStep)
            .define_method("step_type", &QSpinBox::stepType)
            .define_method("suffix", &QSpinBox::suffix)
            .define_method("value", &QSpinBox::value)
            // Public Slots
            .define_method("set_value", &QSpinBox::setValue, Arg("val"))
            // Signals
            .define_method("text_changed", &QSpinBox::textChanged, Arg("text"))
            .define_method("value_changed", &QSpinBox::valueChanged, Arg("val"));
}
