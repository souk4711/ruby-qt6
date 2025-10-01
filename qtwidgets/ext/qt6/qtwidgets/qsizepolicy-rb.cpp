#include "qsizepolicy-rb.hpp"
#include <qsizepolicy.h>

using namespace Rice;

Rice::Class rb_cQSizePolicy;

void Init_qsizepolicy(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSizePolicy =
        // RubyQt6::QtWidgets::QSizePolicy
        define_class_under<QSizePolicy>(rb_mQt6QtWidgets, "QSizePolicy")
            // Constructor
            .define_constructor(Constructor<QSizePolicy, QSizePolicy::Policy, QSizePolicy::Policy>(), Arg("horizontal"), Arg("vertical"))
            .define_constructor(Constructor<QSizePolicy, QSizePolicy::Policy, QSizePolicy::Policy, QSizePolicy::ControlType>(), Arg("horizontal"), Arg("vertical"), Arg("type"))
            // Public Functions
            .define_method("control_type", &QSizePolicy::controlType)
            .define_method("expanding_directions", &QSizePolicy::expandingDirections)
            .define_method("has_height_for_width", &QSizePolicy::hasHeightForWidth)
            .define_method("has_width_for_height", &QSizePolicy::hasWidthForHeight)
            .define_method("horizontal_policy", &QSizePolicy::horizontalPolicy)
            .define_method("horizontal_stretch", &QSizePolicy::horizontalStretch)
            .define_method("retain_size_when_hidden", &QSizePolicy::retainSizeWhenHidden)
            .define_method("set_control_type", &QSizePolicy::setControlType, Arg("type"))
            .define_method("set_height_for_width", &QSizePolicy::setHeightForWidth, Arg("b"))
            .define_method("set_horizontal_policy", &QSizePolicy::setHorizontalPolicy, Arg("d"))
            .define_method("set_horizontal_stretch", &QSizePolicy::setHorizontalStretch, Arg("stretch_factor"))
            .define_method("set_retain_size_when_hidden", &QSizePolicy::setRetainSizeWhenHidden, Arg("retain_size"))
            .define_method("set_vertical_policy", &QSizePolicy::setVerticalPolicy, Arg("d"))
            .define_method("set_vertical_stretch", &QSizePolicy::setVerticalStretch, Arg("stretch_factor"))
            .define_method("set_width_for_height", &QSizePolicy::setWidthForHeight, Arg("b"))
            .define_method("transpose", &QSizePolicy::transpose)
            .define_method("transposed", &QSizePolicy::transposed)
            .define_method("vertical_policy", &QSizePolicy::verticalPolicy)
            .define_method("vertical_stretch", &QSizePolicy::verticalStretch);

    Enum<QSizePolicy::ControlType> rb_cQSizePolicyControlType =
        // RubyQt6::QtWidgets::QSizePolicy::ControlType
        define_enum_under<QSizePolicy::ControlType>("ControlType", rb_cQSizePolicy)
            .define_value("DefaultType", QSizePolicy::ControlType::DefaultType)
            .define_value("ButtonBox", QSizePolicy::ControlType::ButtonBox)
            .define_value("CheckBox", QSizePolicy::ControlType::CheckBox)
            .define_value("ComboBox", QSizePolicy::ControlType::ComboBox)
            .define_value("Frame", QSizePolicy::ControlType::Frame)
            .define_value("GroupBox", QSizePolicy::ControlType::GroupBox)
            .define_value("Label", QSizePolicy::ControlType::Label)
            .define_value("Line", QSizePolicy::ControlType::Line)
            .define_value("LineEdit", QSizePolicy::ControlType::LineEdit)
            .define_value("PushButton", QSizePolicy::ControlType::PushButton)
            .define_value("RadioButton", QSizePolicy::ControlType::RadioButton)
            .define_value("Slider", QSizePolicy::ControlType::Slider)
            .define_value("SpinBox", QSizePolicy::ControlType::SpinBox)
            .define_value("TabWidget", QSizePolicy::ControlType::TabWidget)
            .define_value("ToolButton", QSizePolicy::ControlType::ToolButton);

    Enum<QSizePolicy::Policy> rb_cQSizePolicyPolicy =
        // RubyQt6::QtWidgets::QSizePolicy::Policy
        define_enum_under<QSizePolicy::Policy>("Policy", rb_cQSizePolicy)
            .define_value("Fixed", QSizePolicy::Policy::Fixed)
            .define_value("Minimum", QSizePolicy::Policy::Minimum)
            .define_value("Maximum", QSizePolicy::Policy::Maximum)
            .define_value("Preferred", QSizePolicy::Policy::Preferred)
            .define_value("MinimumExpanding", QSizePolicy::Policy::MinimumExpanding)
            .define_value("Expanding", QSizePolicy::Policy::Expanding)
            .define_value("Ignored", QSizePolicy::Policy::Ignored);

    Enum<QSizePolicy::PolicyFlag> rb_cQSizePolicyPolicyFlag =
        // RubyQt6::QtWidgets::QSizePolicy::PolicyFlag
        define_enum_under<QSizePolicy::PolicyFlag>("PolicyFlag", rb_cQSizePolicy)
            .define_value("GrowFlag", QSizePolicy::PolicyFlag::GrowFlag)
            .define_value("ExpandFlag", QSizePolicy::PolicyFlag::ExpandFlag)
            .define_value("ShrinkFlag", QSizePolicy::PolicyFlag::ShrinkFlag)
            .define_value("IgnoreFlag", QSizePolicy::PolicyFlag::IgnoreFlag);
}
