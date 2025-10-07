#include "qabstractspinbox-rb.hpp"
#include <qabstractspinbox.h>

using namespace Rice;

Rice::Class rb_cQAbstractSpinBox;

void Init_qabstractspinbox(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQAbstractSpinBox =
        // RubyQt6::QtWidgets::QAbstractSpinBox
        define_class_under<QAbstractSpinBox, QWidget>(rb_mQt6QtWidgets, "QAbstractSpinBox")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QAbstractSpinBox::staticMetaObject; })
            // Public Functions
            .define_method("alignment", &QAbstractSpinBox::alignment)
            .define_method("button_symbols", &QAbstractSpinBox::buttonSymbols)
            .define_method("correction_mode", &QAbstractSpinBox::correctionMode)
            .define_method("fixup", &QAbstractSpinBox::fixup, Arg("input"))
            .define_method("has_acceptable_input", &QAbstractSpinBox::hasAcceptableInput)
            .define_method("has_frame", &QAbstractSpinBox::hasFrame)
            .define_method("interpret_text", &QAbstractSpinBox::interpretText)
            .define_method("accelerated?", &QAbstractSpinBox::isAccelerated)
            .define_method("group_separator_shown?", &QAbstractSpinBox::isGroupSeparatorShown)
            .define_method("read_only?", &QAbstractSpinBox::isReadOnly)
            .define_method("keyboard_tracking", &QAbstractSpinBox::keyboardTracking)
            .define_method("set_accelerated", &QAbstractSpinBox::setAccelerated, Arg("on"))
            .define_method("set_alignment", &QAbstractSpinBox::setAlignment, Arg("flag"))
            .define_method("set_button_symbols", &QAbstractSpinBox::setButtonSymbols, Arg("bs"))
            .define_method("set_correction_mode", &QAbstractSpinBox::setCorrectionMode, Arg("cm"))
            .define_method("set_frame", &QAbstractSpinBox::setFrame, Arg("enable"))
            .define_method("set_group_separator_shown", &QAbstractSpinBox::setGroupSeparatorShown, Arg("shown"))
            .define_method("set_keyboard_tracking", &QAbstractSpinBox::setKeyboardTracking, Arg("kt"))
            .define_method("set_read_only", &QAbstractSpinBox::setReadOnly, Arg("r"))
            .define_method("set_special_value_text", &QAbstractSpinBox::setSpecialValueText, Arg("txt"))
            .define_method("set_wrapping", &QAbstractSpinBox::setWrapping, Arg("w"))
            .define_method("special_value_text", &QAbstractSpinBox::specialValueText)
            .define_method("step_by", &QAbstractSpinBox::stepBy, Arg("steps"))
            .define_method("text", &QAbstractSpinBox::text)
            .define_method("validate", &QAbstractSpinBox::validate, Arg("input"), Arg("pos"))
            .define_method("wrapping", &QAbstractSpinBox::wrapping)
            // Public Slots
            .define_method("clear", &QAbstractSpinBox::clear)
            .define_method("select_all", &QAbstractSpinBox::selectAll)
            .define_method("step_down", &QAbstractSpinBox::stepDown)
            .define_method("step_up", &QAbstractSpinBox::stepUp)
            // Signals
            .define_method("editing_finished", &QAbstractSpinBox::editingFinished);

    Enum<QAbstractSpinBox::ButtonSymbols> rb_cQAbstractSpinBoxButtonSymbols =
        // RubyQt6::QtWidgets::QAbstractSpinBox::ButtonSymbols
        define_enum_under<QAbstractSpinBox::ButtonSymbols>("ButtonSymbols", rb_cQAbstractSpinBox)
            .define_value("UpDownArrows", QAbstractSpinBox::ButtonSymbols::UpDownArrows)
            .define_value("PlusMinus", QAbstractSpinBox::ButtonSymbols::PlusMinus)
            .define_value("NoButtons", QAbstractSpinBox::ButtonSymbols::NoButtons);

    Enum<QAbstractSpinBox::CorrectionMode> rb_cQAbstractSpinBoxCorrectionMode =
        // RubyQt6::QtWidgets::QAbstractSpinBox::CorrectionMode
        define_enum_under<QAbstractSpinBox::CorrectionMode>("CorrectionMode", rb_cQAbstractSpinBox)
            .define_value("CorrectToPreviousValue", QAbstractSpinBox::CorrectionMode::CorrectToPreviousValue)
            .define_value("CorrectToNearestValue", QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);

    Enum<QAbstractSpinBox::StepEnabledFlag> rb_cQAbstractSpinBoxStepEnabledFlag =
        // RubyQt6::QtWidgets::QAbstractSpinBox::StepEnabledFlag
        define_enum_under<QAbstractSpinBox::StepEnabledFlag>("StepEnabledFlag", rb_cQAbstractSpinBox)
            .define_value("StepNone", QAbstractSpinBox::StepEnabledFlag::StepNone)
            .define_value("StepUpEnabled", QAbstractSpinBox::StepEnabledFlag::StepUpEnabled)
            .define_value("StepDownEnabled", QAbstractSpinBox::StepEnabledFlag::StepDownEnabled);

    Enum<QAbstractSpinBox::StepType> rb_cQAbstractSpinBoxStepType =
        // RubyQt6::QtWidgets::QAbstractSpinBox::StepType
        define_enum_under<QAbstractSpinBox::StepType>("StepType", rb_cQAbstractSpinBox)
            .define_value("DefaultStepType", QAbstractSpinBox::StepType::DefaultStepType)
            .define_value("AdaptiveDecimalStepType", QAbstractSpinBox::StepType::AdaptiveDecimalStepType);
}
