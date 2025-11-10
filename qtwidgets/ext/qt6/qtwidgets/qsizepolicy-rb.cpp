#include "qsizepolicy-rb.hpp"
#include <qsizepolicy.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

using namespace Rice;

Rice::Class rb_cQSizePolicy;

void Init_qsizepolicy(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQSizePolicy =
        // RubyQt6::QtWidgets::QSizePolicy
        define_class_under<QSizePolicy>(rb_mQt6QtWidgets, "QSizePolicy")
            // Constructor
            .define_constructor(Constructor<QSizePolicy>())
            .define_constructor(Constructor<QSizePolicy, QSizePolicy::Policy, QSizePolicy::Policy>(), Arg("horizontal"), Arg("vertical"))
            .define_constructor(Constructor<QSizePolicy, QSizePolicy::Policy, QSizePolicy::Policy, QSizePolicy::ControlType>(), Arg("horizontal"), Arg("vertical"), Arg("type"))
            // Public Functions
            .define_method("control_type", &QSizePolicy::controlType)
            .define_method("expanding_directions", &QSizePolicy::expandingDirections)
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

    Data_Type<QSizePolicy::ControlType> rb_cQSizePolicyControlType =
        // RubyQt6::QtWidgets::QSizePolicy::ControlType
        define_qenum_under<QSizePolicy::ControlType>(rb_cQSizePolicy, "ControlType");
        define_qenum_value_under(rb_cQSizePolicyControlType, "DefaultType", QSizePolicy::ControlType::DefaultType);
        define_qenum_value_under(rb_cQSizePolicyControlType, "ButtonBox", QSizePolicy::ControlType::ButtonBox);
        define_qenum_value_under(rb_cQSizePolicyControlType, "CheckBox", QSizePolicy::ControlType::CheckBox);
        define_qenum_value_under(rb_cQSizePolicyControlType, "ComboBox", QSizePolicy::ControlType::ComboBox);
        define_qenum_value_under(rb_cQSizePolicyControlType, "Frame", QSizePolicy::ControlType::Frame);
        define_qenum_value_under(rb_cQSizePolicyControlType, "GroupBox", QSizePolicy::ControlType::GroupBox);
        define_qenum_value_under(rb_cQSizePolicyControlType, "Label", QSizePolicy::ControlType::Label);
        define_qenum_value_under(rb_cQSizePolicyControlType, "Line", QSizePolicy::ControlType::Line);
        define_qenum_value_under(rb_cQSizePolicyControlType, "LineEdit", QSizePolicy::ControlType::LineEdit);
        define_qenum_value_under(rb_cQSizePolicyControlType, "PushButton", QSizePolicy::ControlType::PushButton);
        define_qenum_value_under(rb_cQSizePolicyControlType, "RadioButton", QSizePolicy::ControlType::RadioButton);
        define_qenum_value_under(rb_cQSizePolicyControlType, "Slider", QSizePolicy::ControlType::Slider);
        define_qenum_value_under(rb_cQSizePolicyControlType, "SpinBox", QSizePolicy::ControlType::SpinBox);
        define_qenum_value_under(rb_cQSizePolicyControlType, "TabWidget", QSizePolicy::ControlType::TabWidget);
        define_qenum_value_under(rb_cQSizePolicyControlType, "ToolButton", QSizePolicy::ControlType::ToolButton);

    Data_Type<QSizePolicy::Policy> rb_cQSizePolicyPolicy =
        // RubyQt6::QtWidgets::QSizePolicy::Policy
        define_qenum_under<QSizePolicy::Policy>(rb_cQSizePolicy, "Policy");
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Fixed", QSizePolicy::Policy::Fixed);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Minimum", QSizePolicy::Policy::Minimum);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Maximum", QSizePolicy::Policy::Maximum);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Preferred", QSizePolicy::Policy::Preferred);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "MinimumExpanding", QSizePolicy::Policy::MinimumExpanding);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Expanding", QSizePolicy::Policy::Expanding);
        define_qenum_value_under(rb_cQSizePolicyPolicy, "Ignored", QSizePolicy::Policy::Ignored);

    Data_Type<QSizePolicy::PolicyFlag> rb_cQSizePolicyPolicyFlag =
        // RubyQt6::QtWidgets::QSizePolicy::PolicyFlag
        define_qenum_under<QSizePolicy::PolicyFlag>(rb_cQSizePolicy, "PolicyFlag");
        define_qenum_value_under(rb_cQSizePolicyPolicyFlag, "GrowFlag", QSizePolicy::PolicyFlag::GrowFlag);
        define_qenum_value_under(rb_cQSizePolicyPolicyFlag, "ExpandFlag", QSizePolicy::PolicyFlag::ExpandFlag);
        define_qenum_value_under(rb_cQSizePolicyPolicyFlag, "ShrinkFlag", QSizePolicy::PolicyFlag::ShrinkFlag);
        define_qenum_value_under(rb_cQSizePolicyPolicyFlag, "IgnoreFlag", QSizePolicy::PolicyFlag::IgnoreFlag);

    Data_Type<QFlags<QSizePolicy::ControlType>> rb_cQSizePolicyControlTypes =
        // RubyQt6::QtWidgets::QSizePolicy::ControlTypes
        define_qflags_under<QSizePolicy::ControlType>(rb_cQSizePolicy, "ControlTypes");
}
