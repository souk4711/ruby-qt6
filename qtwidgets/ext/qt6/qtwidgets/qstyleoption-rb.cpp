#include "qstyleoption-rb.hpp"
#include <qstyleoption.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

Rice::Class rb_cQStyleOption;
Rice::Class rb_cQStyleOptionButton;
Rice::Class rb_cQStyleOptionComplex;
Rice::Class rb_cQStyleOptionComboBox;
Rice::Class rb_cQStyleOptionGroupBox;
Rice::Class rb_cQStyleOptionSizeGrip;
Rice::Class rb_cQStyleOptionSlider;
Rice::Class rb_cQStyleOptionSpinBox;
Rice::Class rb_cQStyleOptionTitleBar;
Rice::Class rb_cQStyleOptionToolButton;
Rice::Class rb_cQStyleOptionDockWidget;
Rice::Class rb_cQStyleOptionFocusRect;
Rice::Class rb_cQStyleOptionFrame;
Rice::Class rb_cQStyleOptionGraphicsItem;
Rice::Class rb_cQStyleOptionHeader;
Rice::Class rb_cQStyleOptionHeaderV2;
Rice::Class rb_cQStyleOptionMenuItem;
Rice::Class rb_cQStyleOptionProgressBar;
Rice::Class rb_cQStyleOptionRubberBand;
Rice::Class rb_cQStyleOptionTab;
Rice::Class rb_cQStyleOptionTabBarBase;
Rice::Class rb_cQStyleOptionTabWidgetFrame;
Rice::Class rb_cQStyleOptionToolBar;
Rice::Class rb_cQStyleOptionToolBox;
Rice::Class rb_cQStyleOptionViewItem;

void Init_qstyleoption(Rice::Module rb_mQt6QtWidgets)
{
    rb_cQStyleOption =
        // RubyQt6::QtWidgets::QStyleOption
        define_class_under<QStyleOption>(rb_mQt6QtWidgets, "QStyleOption")
            .define_attr("direction", &QStyleOption::direction, Rice::AttrAccess::Read)
            .define_attr("font_metrics", &QStyleOption::fontMetrics)
            .define_attr("palette", &QStyleOption::palette)
            .define_attr("rect", &QStyleOption::rect)
            .define_attr("state", &QStyleOption::state)
            .define_attr("style_object", &QStyleOption::styleObject, Rice::AttrAccess::Read)
            .define_attr("type", &QStyleOption::type)
            .define_attr("version", &QStyleOption::version);

    Data_Type<QStyleOption::OptionType> rb_cQStyleOptionOptionType =
        // RubyQt6::QtWidgets::QStyleOption::OptionType
        define_qenum_under<QStyleOption::OptionType>(rb_cQStyleOption, "OptionType");
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Default", QStyleOption::OptionType::SO_Default);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_FocusRect", QStyleOption::OptionType::SO_FocusRect);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Button", QStyleOption::OptionType::SO_Button);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Tab", QStyleOption::OptionType::SO_Tab);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_MenuItem", QStyleOption::OptionType::SO_MenuItem);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Frame", QStyleOption::OptionType::SO_Frame);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ProgressBar", QStyleOption::OptionType::SO_ProgressBar);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ToolBox", QStyleOption::OptionType::SO_ToolBox);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Header", QStyleOption::OptionType::SO_Header);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_DockWidget", QStyleOption::OptionType::SO_DockWidget);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ViewItem", QStyleOption::OptionType::SO_ViewItem);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_TabWidgetFrame", QStyleOption::OptionType::SO_TabWidgetFrame);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_TabBarBase", QStyleOption::OptionType::SO_TabBarBase);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_RubberBand", QStyleOption::OptionType::SO_RubberBand);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ToolBar", QStyleOption::OptionType::SO_ToolBar);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_GraphicsItem", QStyleOption::OptionType::SO_GraphicsItem);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Complex", QStyleOption::OptionType::SO_Complex);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_Slider", QStyleOption::OptionType::SO_Slider);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_SpinBox", QStyleOption::OptionType::SO_SpinBox);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ToolButton", QStyleOption::OptionType::SO_ToolButton);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ComboBox", QStyleOption::OptionType::SO_ComboBox);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_TitleBar", QStyleOption::OptionType::SO_TitleBar);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_GroupBox", QStyleOption::OptionType::SO_GroupBox);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_SizeGrip", QStyleOption::OptionType::SO_SizeGrip);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_CustomBase", QStyleOption::OptionType::SO_CustomBase);
        define_qenum_value_under(rb_cQStyleOptionOptionType, "SO_ComplexCustomBase", QStyleOption::OptionType::SO_ComplexCustomBase);

    Data_Type<QStyleOption::StyleOptionType> rb_cQStyleOptionStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOption::StyleOptionType
        define_qenum_under<QStyleOption::StyleOptionType>(rb_cQStyleOption, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionStyleOptionType, "Type", QStyleOption::StyleOptionType::Type);

    Data_Type<QStyleOption::StyleOptionVersion> rb_cQStyleOptionStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOption::StyleOptionVersion
        define_qenum_under<QStyleOption::StyleOptionVersion>(rb_cQStyleOption, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionStyleOptionVersion, "Version", QStyleOption::StyleOptionVersion::Version);

    rb_cQStyleOptionButton =
        // RubyQt6::QtWidgets::QStyleOptionButton
        define_class_under<QStyleOptionButton, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionButton")
            .define_attr("features", &QStyleOptionButton::features)
            .define_attr("icon", &QStyleOptionButton::icon)
            .define_attr("icon_size", &QStyleOptionButton::iconSize)
            .define_attr("text", &QStyleOptionButton::text);

    Data_Type<QStyleOptionButton::StyleOptionType> rb_cQStyleOptionButtonStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionButton::StyleOptionType
        define_qenum_under<QStyleOptionButton::StyleOptionType>(rb_cQStyleOptionButton, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionButtonStyleOptionType, "Type", QStyleOptionButton::StyleOptionType::Type);

    Data_Type<QStyleOptionButton::StyleOptionVersion> rb_cQStyleOptionButtonStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionButton::StyleOptionVersion
        define_qenum_under<QStyleOptionButton::StyleOptionVersion>(rb_cQStyleOptionButton, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionButtonStyleOptionVersion, "Version", QStyleOptionButton::StyleOptionVersion::Version);

    Data_Type<QStyleOptionButton::ButtonFeature> rb_cQStyleOptionButtonButtonFeature =
        // RubyQt6::QtWidgets::QStyleOptionButton::ButtonFeature
        define_qenum_under<QStyleOptionButton::ButtonFeature>(rb_cQStyleOptionButton, "ButtonFeature");
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "None", QStyleOptionButton::ButtonFeature::None);
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "Flat", QStyleOptionButton::ButtonFeature::Flat);
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "HasMenu", QStyleOptionButton::ButtonFeature::HasMenu);
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "DefaultButton", QStyleOptionButton::ButtonFeature::DefaultButton);
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "AutoDefaultButton", QStyleOptionButton::ButtonFeature::AutoDefaultButton);
        define_qenum_value_under(rb_cQStyleOptionButtonButtonFeature, "CommandLinkButton", QStyleOptionButton::ButtonFeature::CommandLinkButton);

    rb_cQStyleOptionComplex =
        // RubyQt6::QtWidgets::QStyleOptionComplex
        define_class_under<QStyleOptionComplex, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionComplex")
            .define_attr("active_sub_controls", &QStyleOptionComplex::activeSubControls)
            .define_attr("sub_controls", &QStyleOptionComplex::subControls);

    Data_Type<QStyleOptionComplex::StyleOptionType> rb_cQStyleOptionComplexStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionComplex::StyleOptionType
        define_qenum_under<QStyleOptionComplex::StyleOptionType>(rb_cQStyleOptionComplex, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionComplexStyleOptionType, "Type", QStyleOptionComplex::StyleOptionType::Type);

    Data_Type<QStyleOptionComplex::StyleOptionVersion> rb_cQStyleOptionComplexStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionComplex::StyleOptionVersion
        define_qenum_under<QStyleOptionComplex::StyleOptionVersion>(rb_cQStyleOptionComplex, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionComplexStyleOptionVersion, "Version", QStyleOptionComplex::StyleOptionVersion::Version);

    rb_cQStyleOptionComboBox =
        // RubyQt6::QtWidgets::QStyleOptionComboBox
        define_class_under<QStyleOptionComboBox, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionComboBox")
            .define_attr("current_icon", &QStyleOptionComboBox::currentIcon)
            .define_attr("current_text", &QStyleOptionComboBox::currentText)
            .define_attr("editable", &QStyleOptionComboBox::editable)
            .define_attr("frame", &QStyleOptionComboBox::frame)
            .define_attr("icon_size", &QStyleOptionComboBox::iconSize)
            .define_attr("popup_rect", &QStyleOptionComboBox::popupRect)
            .define_attr("text_alignment", &QStyleOptionComboBox::textAlignment);

    Data_Type<QStyleOptionComboBox::StyleOptionType> rb_cQStyleOptionComboBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionComboBox::StyleOptionType
        define_qenum_under<QStyleOptionComboBox::StyleOptionType>(rb_cQStyleOptionComboBox, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionComboBoxStyleOptionType, "Type", QStyleOptionComboBox::StyleOptionType::Type);

    Data_Type<QStyleOptionComboBox::StyleOptionVersion> rb_cQStyleOptionComboBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionComboBox::StyleOptionVersion
        define_qenum_under<QStyleOptionComboBox::StyleOptionVersion>(rb_cQStyleOptionComboBox, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionComboBoxStyleOptionVersion, "Version", QStyleOptionComboBox::StyleOptionVersion::Version);

    rb_cQStyleOptionGroupBox =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox
        define_class_under<QStyleOptionGroupBox, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionGroupBox")
            .define_attr("features", &QStyleOptionGroupBox::features)
            .define_attr("line_width", &QStyleOptionGroupBox::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionGroupBox::midLineWidth)
            .define_attr("text", &QStyleOptionGroupBox::text)
            .define_attr("text_alignment", &QStyleOptionGroupBox::textAlignment)
            .define_attr("text_color", &QStyleOptionGroupBox::textColor);

    Data_Type<QStyleOptionGroupBox::StyleOptionType> rb_cQStyleOptionGroupBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox::StyleOptionType
        define_qenum_under<QStyleOptionGroupBox::StyleOptionType>(rb_cQStyleOptionGroupBox, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionGroupBoxStyleOptionType, "Type", QStyleOptionGroupBox::StyleOptionType::Type);

    Data_Type<QStyleOptionGroupBox::StyleOptionVersion> rb_cQStyleOptionGroupBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox::StyleOptionVersion
        define_qenum_under<QStyleOptionGroupBox::StyleOptionVersion>(rb_cQStyleOptionGroupBox, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionGroupBoxStyleOptionVersion, "Version", QStyleOptionGroupBox::StyleOptionVersion::Version);

    rb_cQStyleOptionSizeGrip =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip
        define_class_under<QStyleOptionSizeGrip, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionSizeGrip")
            .define_attr("corner", &QStyleOptionSizeGrip::corner, Rice::AttrAccess::Read);

    Data_Type<QStyleOptionSizeGrip::StyleOptionType> rb_cQStyleOptionSizeGripStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip::StyleOptionType
        define_qenum_under<QStyleOptionSizeGrip::StyleOptionType>(rb_cQStyleOptionSizeGrip, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionSizeGripStyleOptionType, "Type", QStyleOptionSizeGrip::StyleOptionType::Type);

    Data_Type<QStyleOptionSizeGrip::StyleOptionVersion> rb_cQStyleOptionSizeGripStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip::StyleOptionVersion
        define_qenum_under<QStyleOptionSizeGrip::StyleOptionVersion>(rb_cQStyleOptionSizeGrip, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionSizeGripStyleOptionVersion, "Version", QStyleOptionSizeGrip::StyleOptionVersion::Version);

    rb_cQStyleOptionSlider =
        // RubyQt6::QtWidgets::QStyleOptionSlider
        define_class_under<QStyleOptionSlider, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionSlider")
            .define_attr("dial_wrapping", &QStyleOptionSlider::dialWrapping)
            .define_attr("keyboard_modifiers", &QStyleOptionSlider::keyboardModifiers)
            .define_attr("maximum", &QStyleOptionSlider::maximum)
            .define_attr("minimum", &QStyleOptionSlider::minimum)
            .define_attr("notch_target", &QStyleOptionSlider::notchTarget)
            .define_attr("orientation", &QStyleOptionSlider::orientation, Rice::AttrAccess::Read)
            .define_attr("page_step", &QStyleOptionSlider::pageStep)
            .define_attr("slider_position", &QStyleOptionSlider::sliderPosition)
            .define_attr("single_step", &QStyleOptionSlider::singleStep)
            .define_attr("slider_value", &QStyleOptionSlider::sliderValue)
            .define_attr("tick_interval", &QStyleOptionSlider::tickInterval)
            .define_attr("tick_position", &QStyleOptionSlider::tickPosition, Rice::AttrAccess::Read)
            .define_attr("upside_down", &QStyleOptionSlider::upsideDown);

    Data_Type<QStyleOptionSlider::StyleOptionType> rb_cQStyleOptionSliderStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSlider::StyleOptionType
        define_qenum_under<QStyleOptionSlider::StyleOptionType>(rb_cQStyleOptionSlider, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionSliderStyleOptionType, "Type", QStyleOptionSlider::StyleOptionType::Type);

    Data_Type<QStyleOptionSlider::StyleOptionVersion> rb_cQStyleOptionSliderStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSlider::StyleOptionVersion
        define_qenum_under<QStyleOptionSlider::StyleOptionVersion>(rb_cQStyleOptionSlider, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionSliderStyleOptionVersion, "Version", QStyleOptionSlider::StyleOptionVersion::Version);

    rb_cQStyleOptionSpinBox =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox
        define_class_under<QStyleOptionSpinBox, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionSpinBox")
            .define_attr("button_symbols", &QStyleOptionSpinBox::buttonSymbols, Rice::AttrAccess::Read)
            .define_attr("frame", &QStyleOptionSpinBox::frame)
            .define_attr("step_enabled", &QStyleOptionSpinBox::stepEnabled);

    Data_Type<QStyleOptionSpinBox::StyleOptionType> rb_cQStyleOptionSpinBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox::StyleOptionType
        define_qenum_under<QStyleOptionSpinBox::StyleOptionType>(rb_cQStyleOptionSpinBox, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionSpinBoxStyleOptionType, "Type", QStyleOptionSpinBox::StyleOptionType::Type);

    Data_Type<QStyleOptionSpinBox::StyleOptionVersion> rb_cQStyleOptionSpinBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox::StyleOptionVersion
        define_qenum_under<QStyleOptionSpinBox::StyleOptionVersion>(rb_cQStyleOptionSpinBox, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionSpinBoxStyleOptionVersion, "Version", QStyleOptionSpinBox::StyleOptionVersion::Version);

    rb_cQStyleOptionTitleBar =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar
        define_class_under<QStyleOptionTitleBar, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionTitleBar")
            .define_attr("icon", &QStyleOptionTitleBar::icon)
            .define_attr("text", &QStyleOptionTitleBar::text)
            .define_attr("title_bar_flags", &QStyleOptionTitleBar::titleBarFlags)
            .define_attr("title_bar_state", &QStyleOptionTitleBar::titleBarState);

    Data_Type<QStyleOptionTitleBar::StyleOptionType> rb_cQStyleOptionTitleBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar::StyleOptionType
        define_qenum_under<QStyleOptionTitleBar::StyleOptionType>(rb_cQStyleOptionTitleBar, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionTitleBarStyleOptionType, "Type", QStyleOptionTitleBar::StyleOptionType::Type);

    Data_Type<QStyleOptionTitleBar::StyleOptionVersion> rb_cQStyleOptionTitleBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar::StyleOptionVersion
        define_qenum_under<QStyleOptionTitleBar::StyleOptionVersion>(rb_cQStyleOptionTitleBar, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionTitleBarStyleOptionVersion, "Version", QStyleOptionTitleBar::StyleOptionVersion::Version);

    rb_cQStyleOptionToolButton =
        // RubyQt6::QtWidgets::QStyleOptionToolButton
        define_class_under<QStyleOptionToolButton, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionToolButton")
            .define_attr("arrow_type", &QStyleOptionToolButton::arrowType, Rice::AttrAccess::Read)
            .define_attr("features", &QStyleOptionToolButton::features)
            .define_attr("font", &QStyleOptionToolButton::font)
            .define_attr("icon", &QStyleOptionToolButton::icon)
            .define_attr("icon_size", &QStyleOptionToolButton::iconSize)
            .define_attr("pos", &QStyleOptionToolButton::pos)
            .define_attr("text", &QStyleOptionToolButton::text)
            .define_attr("tool_button_style", &QStyleOptionToolButton::toolButtonStyle, Rice::AttrAccess::Read);

    Data_Type<QStyleOptionToolButton::StyleOptionType> rb_cQStyleOptionToolButtonStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::StyleOptionType
        define_qenum_under<QStyleOptionToolButton::StyleOptionType>(rb_cQStyleOptionToolButton, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionToolButtonStyleOptionType, "Type", QStyleOptionToolButton::StyleOptionType::Type);

    Data_Type<QStyleOptionToolButton::StyleOptionVersion> rb_cQStyleOptionToolButtonStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::StyleOptionVersion
        define_qenum_under<QStyleOptionToolButton::StyleOptionVersion>(rb_cQStyleOptionToolButton, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionToolButtonStyleOptionVersion, "Version", QStyleOptionToolButton::StyleOptionVersion::Version);

    Data_Type<QStyleOptionToolButton::ToolButtonFeature> rb_cQStyleOptionToolButtonToolButtonFeature =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::ToolButtonFeature
        define_qenum_under<QStyleOptionToolButton::ToolButtonFeature>(rb_cQStyleOptionToolButton, "ToolButtonFeature");
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "None", QStyleOptionToolButton::ToolButtonFeature::None);
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "Arrow", QStyleOptionToolButton::ToolButtonFeature::Arrow);
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "Menu", QStyleOptionToolButton::ToolButtonFeature::Menu);
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "MenuButtonPopup", QStyleOptionToolButton::ToolButtonFeature::MenuButtonPopup);
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "PopupDelay", QStyleOptionToolButton::ToolButtonFeature::PopupDelay);
        define_qenum_value_under(rb_cQStyleOptionToolButtonToolButtonFeature, "HasMenu", QStyleOptionToolButton::ToolButtonFeature::HasMenu);

    rb_cQStyleOptionDockWidget =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget
        define_class_under<QStyleOptionDockWidget, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionDockWidget")
            .define_attr("closable", &QStyleOptionDockWidget::closable)
            .define_attr("floatable", &QStyleOptionDockWidget::floatable)
            .define_attr("movable", &QStyleOptionDockWidget::movable)
            .define_attr("title", &QStyleOptionDockWidget::title)
            .define_attr("vertical_title_bar", &QStyleOptionDockWidget::verticalTitleBar);

    Data_Type<QStyleOptionDockWidget::StyleOptionType> rb_cQStyleOptionDockWidgetStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget::StyleOptionType
        define_qenum_under<QStyleOptionDockWidget::StyleOptionType>(rb_cQStyleOptionDockWidget, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionDockWidgetStyleOptionType, "Type", QStyleOptionDockWidget::StyleOptionType::Type);

    Data_Type<QStyleOptionDockWidget::StyleOptionVersion> rb_cQStyleOptionDockWidgetStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget::StyleOptionVersion
        define_qenum_under<QStyleOptionDockWidget::StyleOptionVersion>(rb_cQStyleOptionDockWidget, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionDockWidgetStyleOptionVersion, "Version", QStyleOptionDockWidget::StyleOptionVersion::Version);

    rb_cQStyleOptionFocusRect =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect
        define_class_under<QStyleOptionFocusRect, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionFocusRect")
            .define_attr("background_color", &QStyleOptionFocusRect::backgroundColor);

    Data_Type<QStyleOptionFocusRect::StyleOptionType> rb_cQStyleOptionFocusRectStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect::StyleOptionType
        define_qenum_under<QStyleOptionFocusRect::StyleOptionType>(rb_cQStyleOptionFocusRect, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionFocusRectStyleOptionType, "Type", QStyleOptionFocusRect::StyleOptionType::Type);

    Data_Type<QStyleOptionFocusRect::StyleOptionVersion> rb_cQStyleOptionFocusRectStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect::StyleOptionVersion
        define_qenum_under<QStyleOptionFocusRect::StyleOptionVersion>(rb_cQStyleOptionFocusRect, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionFocusRectStyleOptionVersion, "Version", QStyleOptionFocusRect::StyleOptionVersion::Version);

    rb_cQStyleOptionFrame =
        // RubyQt6::QtWidgets::QStyleOptionFrame
        define_class_under<QStyleOptionFrame, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionFrame")
            .define_attr("features", &QStyleOptionFrame::features)
            .define_attr("frame_shape", &QStyleOptionFrame::frameShape, Rice::AttrAccess::Read)
            .define_attr("line_width", &QStyleOptionFrame::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionFrame::midLineWidth);

    Data_Type<QStyleOptionFrame::StyleOptionType> rb_cQStyleOptionFrameStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionFrame::StyleOptionType
        define_qenum_under<QStyleOptionFrame::StyleOptionType>(rb_cQStyleOptionFrame, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionFrameStyleOptionType, "Type", QStyleOptionFrame::StyleOptionType::Type);

    Data_Type<QStyleOptionFrame::StyleOptionVersion> rb_cQStyleOptionFrameStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionFrame::StyleOptionVersion
        define_qenum_under<QStyleOptionFrame::StyleOptionVersion>(rb_cQStyleOptionFrame, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionFrameStyleOptionVersion, "Version", QStyleOptionFrame::StyleOptionVersion::Version);

    Data_Type<QStyleOptionFrame::FrameFeature> rb_cQStyleOptionFrameFrameFeature =
        // RubyQt6::QtWidgets::QStyleOptionFrame::FrameFeature
        define_qenum_under<QStyleOptionFrame::FrameFeature>(rb_cQStyleOptionFrame, "FrameFeature");
        define_qenum_value_under(rb_cQStyleOptionFrameFrameFeature, "None", QStyleOptionFrame::FrameFeature::None);
        define_qenum_value_under(rb_cQStyleOptionFrameFrameFeature, "Flat", QStyleOptionFrame::FrameFeature::Flat);
        define_qenum_value_under(rb_cQStyleOptionFrameFrameFeature, "Rounded", QStyleOptionFrame::FrameFeature::Rounded);

    rb_cQStyleOptionGraphicsItem =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem
        define_class_under<QStyleOptionGraphicsItem, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionGraphicsItem")
            .define_attr("exposed_rect", &QStyleOptionGraphicsItem::exposedRect);

    Data_Type<QStyleOptionGraphicsItem::StyleOptionType> rb_cQStyleOptionGraphicsItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem::StyleOptionType
        define_qenum_under<QStyleOptionGraphicsItem::StyleOptionType>(rb_cQStyleOptionGraphicsItem, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionGraphicsItemStyleOptionType, "Type", QStyleOptionGraphicsItem::StyleOptionType::Type);

    Data_Type<QStyleOptionGraphicsItem::StyleOptionVersion> rb_cQStyleOptionGraphicsItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem::StyleOptionVersion
        define_qenum_under<QStyleOptionGraphicsItem::StyleOptionVersion>(rb_cQStyleOptionGraphicsItem, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionGraphicsItemStyleOptionVersion, "Version", QStyleOptionGraphicsItem::StyleOptionVersion::Version);

    rb_cQStyleOptionHeader =
        // RubyQt6::QtWidgets::QStyleOptionHeader
        define_class_under<QStyleOptionHeader, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionHeader")
            .define_attr("icon", &QStyleOptionHeader::icon)
            .define_attr("icon_alignment", &QStyleOptionHeader::iconAlignment)
            .define_attr("orientation", &QStyleOptionHeader::orientation, Rice::AttrAccess::Read)
            .define_attr("position", &QStyleOptionHeader::position, Rice::AttrAccess::Read)
            .define_attr("section", &QStyleOptionHeader::section)
            .define_attr("selected_position", &QStyleOptionHeader::selectedPosition, Rice::AttrAccess::Read)
            .define_attr("sort_indicator", &QStyleOptionHeader::sortIndicator, Rice::AttrAccess::Read)
            .define_attr("text", &QStyleOptionHeader::text)
            .define_attr("text_alignment", &QStyleOptionHeader::textAlignment);

    Data_Type<QStyleOptionHeader::StyleOptionType> rb_cQStyleOptionHeaderStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionHeader::StyleOptionType
        define_qenum_under<QStyleOptionHeader::StyleOptionType>(rb_cQStyleOptionHeader, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionHeaderStyleOptionType, "Type", QStyleOptionHeader::StyleOptionType::Type);

    Data_Type<QStyleOptionHeader::StyleOptionVersion> rb_cQStyleOptionHeaderStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionHeader::StyleOptionVersion
        define_qenum_under<QStyleOptionHeader::StyleOptionVersion>(rb_cQStyleOptionHeader, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionHeaderStyleOptionVersion, "Version", QStyleOptionHeader::StyleOptionVersion::Version);

    Data_Type<QStyleOptionHeader::SectionPosition> rb_cQStyleOptionHeaderSectionPosition =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SectionPosition
        define_qenum_under<QStyleOptionHeader::SectionPosition>(rb_cQStyleOptionHeader, "SectionPosition");
        define_qenum_value_under(rb_cQStyleOptionHeaderSectionPosition, "Beginning", QStyleOptionHeader::SectionPosition::Beginning);
        define_qenum_value_under(rb_cQStyleOptionHeaderSectionPosition, "Middle", QStyleOptionHeader::SectionPosition::Middle);
        define_qenum_value_under(rb_cQStyleOptionHeaderSectionPosition, "End", QStyleOptionHeader::SectionPosition::End);
        define_qenum_value_under(rb_cQStyleOptionHeaderSectionPosition, "OnlyOneSection", QStyleOptionHeader::SectionPosition::OnlyOneSection);

    Data_Type<QStyleOptionHeader::SelectedPosition> rb_cQStyleOptionHeaderSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SelectedPosition
        define_qenum_under<QStyleOptionHeader::SelectedPosition>(rb_cQStyleOptionHeader, "SelectedPosition");
        define_qenum_value_under(rb_cQStyleOptionHeaderSelectedPosition, "NotAdjacent", QStyleOptionHeader::SelectedPosition::NotAdjacent);
        define_qenum_value_under(rb_cQStyleOptionHeaderSelectedPosition, "NextIsSelected", QStyleOptionHeader::SelectedPosition::NextIsSelected);
        define_qenum_value_under(rb_cQStyleOptionHeaderSelectedPosition, "PreviousIsSelected", QStyleOptionHeader::SelectedPosition::PreviousIsSelected);
        define_qenum_value_under(rb_cQStyleOptionHeaderSelectedPosition, "NextAndPreviousAreSelected", QStyleOptionHeader::SelectedPosition::NextAndPreviousAreSelected);

    Data_Type<QStyleOptionHeader::SortIndicator> rb_cQStyleOptionHeaderSortIndicator =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SortIndicator
        define_qenum_under<QStyleOptionHeader::SortIndicator>(rb_cQStyleOptionHeader, "SortIndicator");
        define_qenum_value_under(rb_cQStyleOptionHeaderSortIndicator, "None", QStyleOptionHeader::SortIndicator::None);
        define_qenum_value_under(rb_cQStyleOptionHeaderSortIndicator, "SortUp", QStyleOptionHeader::SortIndicator::SortUp);
        define_qenum_value_under(rb_cQStyleOptionHeaderSortIndicator, "SortDown", QStyleOptionHeader::SortIndicator::SortDown);

    rb_cQStyleOptionHeaderV2 =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2
        define_class_under<QStyleOptionHeaderV2, QStyleOptionHeader>(rb_mQt6QtWidgets, "QStyleOptionHeaderV2");

    Data_Type<QStyleOptionHeaderV2::StyleOptionType> rb_cQStyleOptionHeaderV2StyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2::StyleOptionType
        define_qenum_under<QStyleOptionHeaderV2::StyleOptionType>(rb_cQStyleOptionHeaderV2, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionHeaderV2StyleOptionType, "Type", QStyleOptionHeaderV2::StyleOptionType::Type);

    Data_Type<QStyleOptionHeaderV2::StyleOptionVersion> rb_cQStyleOptionHeaderV2StyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2::StyleOptionVersion
        define_qenum_under<QStyleOptionHeaderV2::StyleOptionVersion>(rb_cQStyleOptionHeaderV2, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionHeaderV2StyleOptionVersion, "Version", QStyleOptionHeaderV2::StyleOptionVersion::Version);

    rb_cQStyleOptionMenuItem =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem
        define_class_under<QStyleOptionMenuItem, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionMenuItem")
            .define_attr("check_type", &QStyleOptionMenuItem::checkType, Rice::AttrAccess::Read)
            .define_attr("checked", &QStyleOptionMenuItem::checked)
            .define_attr("font", &QStyleOptionMenuItem::font)
            .define_attr("icon", &QStyleOptionMenuItem::icon)
            .define_attr("max_icon_width", &QStyleOptionMenuItem::maxIconWidth)
            .define_attr("menu_has_checkable_items", &QStyleOptionMenuItem::menuHasCheckableItems)
            .define_attr("menu_item_type", &QStyleOptionMenuItem::menuItemType, Rice::AttrAccess::Read)
            .define_attr("menu_rect", &QStyleOptionMenuItem::menuRect)
            .define_attr("reserved_shortcut_width", &QStyleOptionMenuItem::reservedShortcutWidth)
            .define_attr("text", &QStyleOptionMenuItem::text);

    Data_Type<QStyleOptionMenuItem::StyleOptionType> rb_cQStyleOptionMenuItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::StyleOptionType
        define_qenum_under<QStyleOptionMenuItem::StyleOptionType>(rb_cQStyleOptionMenuItem, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionMenuItemStyleOptionType, "Type", QStyleOptionMenuItem::StyleOptionType::Type);

    Data_Type<QStyleOptionMenuItem::StyleOptionVersion> rb_cQStyleOptionMenuItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::StyleOptionVersion
        define_qenum_under<QStyleOptionMenuItem::StyleOptionVersion>(rb_cQStyleOptionMenuItem, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionMenuItemStyleOptionVersion, "Version", QStyleOptionMenuItem::StyleOptionVersion::Version);

    Data_Type<QStyleOptionMenuItem::MenuItemType> rb_cQStyleOptionMenuItemMenuItemType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::MenuItemType
        define_qenum_under<QStyleOptionMenuItem::MenuItemType>(rb_cQStyleOptionMenuItem, "MenuItemType");
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "Normal", QStyleOptionMenuItem::MenuItemType::Normal);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "DefaultItem", QStyleOptionMenuItem::MenuItemType::DefaultItem);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "Separator", QStyleOptionMenuItem::MenuItemType::Separator);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "SubMenu", QStyleOptionMenuItem::MenuItemType::SubMenu);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "Scroller", QStyleOptionMenuItem::MenuItemType::Scroller);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "TearOff", QStyleOptionMenuItem::MenuItemType::TearOff);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "Margin", QStyleOptionMenuItem::MenuItemType::Margin);
        define_qenum_value_under(rb_cQStyleOptionMenuItemMenuItemType, "EmptyArea", QStyleOptionMenuItem::MenuItemType::EmptyArea);

    Data_Type<QStyleOptionMenuItem::CheckType> rb_cQStyleOptionMenuItemCheckType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::CheckType
        define_qenum_under<QStyleOptionMenuItem::CheckType>(rb_cQStyleOptionMenuItem, "CheckType");
        define_qenum_value_under(rb_cQStyleOptionMenuItemCheckType, "NotCheckable", QStyleOptionMenuItem::CheckType::NotCheckable);
        define_qenum_value_under(rb_cQStyleOptionMenuItemCheckType, "Exclusive", QStyleOptionMenuItem::CheckType::Exclusive);
        define_qenum_value_under(rb_cQStyleOptionMenuItemCheckType, "NonExclusive", QStyleOptionMenuItem::CheckType::NonExclusive);

    rb_cQStyleOptionProgressBar =
        // RubyQt6::QtWidgets::QStyleOptionProgressBar
        define_class_under<QStyleOptionProgressBar, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionProgressBar")
            .define_attr("bottom_to_top", &QStyleOptionProgressBar::bottomToTop)
            .define_attr("inverted_appearance", &QStyleOptionProgressBar::invertedAppearance)
            .define_attr("maximum", &QStyleOptionProgressBar::maximum)
            .define_attr("minimum", &QStyleOptionProgressBar::minimum)
            .define_attr("progress", &QStyleOptionProgressBar::progress)
            .define_attr("text", &QStyleOptionProgressBar::text)
            .define_attr("text_alignment", &QStyleOptionProgressBar::textAlignment)
            .define_attr("text_visible", &QStyleOptionProgressBar::textVisible);

    Data_Type<QStyleOptionProgressBar::StyleOptionType> rb_cQStyleOptionProgressBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionProgressBar::StyleOptionType
        define_qenum_under<QStyleOptionProgressBar::StyleOptionType>(rb_cQStyleOptionProgressBar, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionProgressBarStyleOptionType, "Type", QStyleOptionProgressBar::StyleOptionType::Type);

    Data_Type<QStyleOptionProgressBar::StyleOptionVersion> rb_cQStyleOptionProgressBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionProgressBar::StyleOptionVersion
        define_qenum_under<QStyleOptionProgressBar::StyleOptionVersion>(rb_cQStyleOptionProgressBar, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionProgressBarStyleOptionVersion, "Version", QStyleOptionProgressBar::StyleOptionVersion::Version);

    rb_cQStyleOptionRubberBand =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand
        define_class_under<QStyleOptionRubberBand, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionRubberBand")
            .define_attr("opaque", &QStyleOptionRubberBand::opaque)
            .define_attr("shape", &QStyleOptionRubberBand::shape, Rice::AttrAccess::Read);

    Data_Type<QStyleOptionRubberBand::StyleOptionType> rb_cQStyleOptionRubberBandStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand::StyleOptionType
        define_qenum_under<QStyleOptionRubberBand::StyleOptionType>(rb_cQStyleOptionRubberBand, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionRubberBandStyleOptionType, "Type", QStyleOptionRubberBand::StyleOptionType::Type);

    Data_Type<QStyleOptionRubberBand::StyleOptionVersion> rb_cQStyleOptionRubberBandStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand::StyleOptionVersion
        define_qenum_under<QStyleOptionRubberBand::StyleOptionVersion>(rb_cQStyleOptionRubberBand, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionRubberBandStyleOptionVersion, "Version", QStyleOptionRubberBand::StyleOptionVersion::Version);

    rb_cQStyleOptionTab =
        // RubyQt6::QtWidgets::QStyleOptionTab
        define_class_under<QStyleOptionTab, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionTab")
            .define_attr("corner_widgets", &QStyleOptionTab::cornerWidgets)
            .define_attr("document_mode", &QStyleOptionTab::documentMode)
            .define_attr("features", &QStyleOptionTab::features)
            .define_attr("icon", &QStyleOptionTab::icon)
            .define_attr("icon_size", &QStyleOptionTab::iconSize)
            .define_attr("left_button_size", &QStyleOptionTab::leftButtonSize)
            .define_attr("position", &QStyleOptionTab::position, Rice::AttrAccess::Read)
            .define_attr("right_button_size", &QStyleOptionTab::rightButtonSize)
            .define_attr("row", &QStyleOptionTab::row)
            .define_attr("selected_position", &QStyleOptionTab::selectedPosition, Rice::AttrAccess::Read)
            .define_attr("shape", &QStyleOptionTab::shape, Rice::AttrAccess::Read)
            .define_attr("tab_index", &QStyleOptionTab::tabIndex)
            .define_attr("text", &QStyleOptionTab::text);

    Data_Type<QStyleOptionTab::StyleOptionType> rb_cQStyleOptionTabStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTab::StyleOptionType
        define_qenum_under<QStyleOptionTab::StyleOptionType>(rb_cQStyleOptionTab, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionTabStyleOptionType, "Type", QStyleOptionTab::StyleOptionType::Type);

    Data_Type<QStyleOptionTab::StyleOptionVersion> rb_cQStyleOptionTabStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTab::StyleOptionVersion
        define_qenum_under<QStyleOptionTab::StyleOptionVersion>(rb_cQStyleOptionTab, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionTabStyleOptionVersion, "Version", QStyleOptionTab::StyleOptionVersion::Version);

    Data_Type<QStyleOptionTab::TabPosition> rb_cQStyleOptionTabTabPosition =
        // RubyQt6::QtWidgets::QStyleOptionTab::TabPosition
        define_qenum_under<QStyleOptionTab::TabPosition>(rb_cQStyleOptionTab, "TabPosition");
        define_qenum_value_under(rb_cQStyleOptionTabTabPosition, "Beginning", QStyleOptionTab::TabPosition::Beginning);
        define_qenum_value_under(rb_cQStyleOptionTabTabPosition, "Middle", QStyleOptionTab::TabPosition::Middle);
        define_qenum_value_under(rb_cQStyleOptionTabTabPosition, "End", QStyleOptionTab::TabPosition::End);
        define_qenum_value_under(rb_cQStyleOptionTabTabPosition, "OnlyOneTab", QStyleOptionTab::TabPosition::OnlyOneTab);
        define_qenum_value_under(rb_cQStyleOptionTabTabPosition, "Moving", QStyleOptionTab::TabPosition::Moving);

    Data_Type<QStyleOptionTab::SelectedPosition> rb_cQStyleOptionTabSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionTab::SelectedPosition
        define_qenum_under<QStyleOptionTab::SelectedPosition>(rb_cQStyleOptionTab, "SelectedPosition");
        define_qenum_value_under(rb_cQStyleOptionTabSelectedPosition, "NotAdjacent", QStyleOptionTab::SelectedPosition::NotAdjacent);
        define_qenum_value_under(rb_cQStyleOptionTabSelectedPosition, "NextIsSelected", QStyleOptionTab::SelectedPosition::NextIsSelected);
        define_qenum_value_under(rb_cQStyleOptionTabSelectedPosition, "PreviousIsSelected", QStyleOptionTab::SelectedPosition::PreviousIsSelected);

    Data_Type<QStyleOptionTab::CornerWidget> rb_cQStyleOptionTabCornerWidget =
        // RubyQt6::QtWidgets::QStyleOptionTab::CornerWidget
        define_qenum_under<QStyleOptionTab::CornerWidget>(rb_cQStyleOptionTab, "CornerWidget");
        define_qenum_value_under(rb_cQStyleOptionTabCornerWidget, "NoCornerWidgets", QStyleOptionTab::CornerWidget::NoCornerWidgets);
        define_qenum_value_under(rb_cQStyleOptionTabCornerWidget, "LeftCornerWidget", QStyleOptionTab::CornerWidget::LeftCornerWidget);
        define_qenum_value_under(rb_cQStyleOptionTabCornerWidget, "RightCornerWidget", QStyleOptionTab::CornerWidget::RightCornerWidget);

    Data_Type<QStyleOptionTab::TabFeature> rb_cQStyleOptionTabTabFeature =
        // RubyQt6::QtWidgets::QStyleOptionTab::TabFeature
        define_qenum_under<QStyleOptionTab::TabFeature>(rb_cQStyleOptionTab, "TabFeature");
        define_qenum_value_under(rb_cQStyleOptionTabTabFeature, "None", QStyleOptionTab::TabFeature::None);
        define_qenum_value_under(rb_cQStyleOptionTabTabFeature, "HasFrame", QStyleOptionTab::TabFeature::HasFrame);
        define_qenum_value_under(rb_cQStyleOptionTabTabFeature, "MinimumSizeHint", QStyleOptionTab::TabFeature::MinimumSizeHint);

    rb_cQStyleOptionTabBarBase =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase
        define_class_under<QStyleOptionTabBarBase, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionTabBarBase")
            .define_attr("document_mode", &QStyleOptionTabBarBase::documentMode)
            .define_attr("selected_tab_rect", &QStyleOptionTabBarBase::selectedTabRect)
            .define_attr("shape", &QStyleOptionTabBarBase::shape, Rice::AttrAccess::Read)
            .define_attr("tab_bar_rect", &QStyleOptionTabBarBase::tabBarRect);

    Data_Type<QStyleOptionTabBarBase::StyleOptionType> rb_cQStyleOptionTabBarBaseStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase::StyleOptionType
        define_qenum_under<QStyleOptionTabBarBase::StyleOptionType>(rb_cQStyleOptionTabBarBase, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionTabBarBaseStyleOptionType, "Type", QStyleOptionTabBarBase::StyleOptionType::Type);

    Data_Type<QStyleOptionTabBarBase::StyleOptionVersion> rb_cQStyleOptionTabBarBaseStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase::StyleOptionVersion
        define_qenum_under<QStyleOptionTabBarBase::StyleOptionVersion>(rb_cQStyleOptionTabBarBase, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionTabBarBaseStyleOptionVersion, "Version", QStyleOptionTabBarBase::StyleOptionVersion::Version);

    rb_cQStyleOptionTabWidgetFrame =
        // RubyQt6::QtWidgets::QStyleOptionTabWidgetFrame
        define_class_under<QStyleOptionTabWidgetFrame, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionTabWidgetFrame")
            .define_attr("left_corner_widget_size", &QStyleOptionTabWidgetFrame::leftCornerWidgetSize)
            .define_attr("line_width", &QStyleOptionTabWidgetFrame::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionTabWidgetFrame::midLineWidth)
            .define_attr("right_corner_widget_size", &QStyleOptionTabWidgetFrame::rightCornerWidgetSize)
            .define_attr("selected_tab_rect", &QStyleOptionTabWidgetFrame::selectedTabRect)
            .define_attr("shape", &QStyleOptionTabWidgetFrame::shape, Rice::AttrAccess::Read)
            .define_attr("tab_bar_rect", &QStyleOptionTabWidgetFrame::tabBarRect)
            .define_attr("tab_bar_size", &QStyleOptionTabWidgetFrame::tabBarSize);

    Data_Type<QStyleOptionTabWidgetFrame::StyleOptionType> rb_cQStyleOptionTabWidgetFrameStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTabWidgetFrame::StyleOptionType
        define_qenum_under<QStyleOptionTabWidgetFrame::StyleOptionType>(rb_cQStyleOptionTabWidgetFrame, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionTabWidgetFrameStyleOptionType, "Type", QStyleOptionTabWidgetFrame::StyleOptionType::Type);

    Data_Type<QStyleOptionTabWidgetFrame::StyleOptionVersion> rb_cQStyleOptionTabWidgetFrameStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTabWidgetFrame::StyleOptionVersion
        define_qenum_under<QStyleOptionTabWidgetFrame::StyleOptionVersion>(rb_cQStyleOptionTabWidgetFrame, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionTabWidgetFrameStyleOptionVersion, "Version", QStyleOptionTabWidgetFrame::StyleOptionVersion::Version);

    rb_cQStyleOptionToolBar =
        // RubyQt6::QtWidgets::QStyleOptionToolBar
        define_class_under<QStyleOptionToolBar, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionToolBar")
            .define_attr("features", &QStyleOptionToolBar::features)
            .define_attr("line_width", &QStyleOptionToolBar::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionToolBar::midLineWidth)
            .define_attr("position_of_line", &QStyleOptionToolBar::positionOfLine, Rice::AttrAccess::Read)
            .define_attr("position_within_line", &QStyleOptionToolBar::positionWithinLine, Rice::AttrAccess::Read)
            .define_attr("tool_bar_area", &QStyleOptionToolBar::toolBarArea, Rice::AttrAccess::Read);

    Data_Type<QStyleOptionToolBar::StyleOptionType> rb_cQStyleOptionToolBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::StyleOptionType
        define_qenum_under<QStyleOptionToolBar::StyleOptionType>(rb_cQStyleOptionToolBar, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionToolBarStyleOptionType, "Type", QStyleOptionToolBar::StyleOptionType::Type);

    Data_Type<QStyleOptionToolBar::StyleOptionVersion> rb_cQStyleOptionToolBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::StyleOptionVersion
        define_qenum_under<QStyleOptionToolBar::StyleOptionVersion>(rb_cQStyleOptionToolBar, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionToolBarStyleOptionVersion, "Version", QStyleOptionToolBar::StyleOptionVersion::Version);

    Data_Type<QStyleOptionToolBar::ToolBarPosition> rb_cQStyleOptionToolBarToolBarPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::ToolBarPosition
        define_qenum_under<QStyleOptionToolBar::ToolBarPosition>(rb_cQStyleOptionToolBar, "ToolBarPosition");
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarPosition, "Beginning", QStyleOptionToolBar::ToolBarPosition::Beginning);
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarPosition, "Middle", QStyleOptionToolBar::ToolBarPosition::Middle);
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarPosition, "End", QStyleOptionToolBar::ToolBarPosition::End);
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarPosition, "OnlyOne", QStyleOptionToolBar::ToolBarPosition::OnlyOne);

    Data_Type<QStyleOptionToolBar::ToolBarFeature> rb_cQStyleOptionToolBarToolBarFeature =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::ToolBarFeature
        define_qenum_under<QStyleOptionToolBar::ToolBarFeature>(rb_cQStyleOptionToolBar, "ToolBarFeature");
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarFeature, "None", QStyleOptionToolBar::ToolBarFeature::None);
        define_qenum_value_under(rb_cQStyleOptionToolBarToolBarFeature, "Movable", QStyleOptionToolBar::ToolBarFeature::Movable);

    rb_cQStyleOptionToolBox =
        // RubyQt6::QtWidgets::QStyleOptionToolBox
        define_class_under<QStyleOptionToolBox, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionToolBox")
            .define_attr("icon", &QStyleOptionToolBox::icon)
            .define_attr("position", &QStyleOptionToolBox::position, Rice::AttrAccess::Read)
            .define_attr("text", &QStyleOptionToolBox::text);

    Data_Type<QStyleOptionToolBox::StyleOptionType> rb_cQStyleOptionToolBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::StyleOptionType
        define_qenum_under<QStyleOptionToolBox::StyleOptionType>(rb_cQStyleOptionToolBox, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionToolBoxStyleOptionType, "Type", QStyleOptionToolBox::StyleOptionType::Type);

    Data_Type<QStyleOptionToolBox::StyleOptionVersion> rb_cQStyleOptionToolBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::StyleOptionVersion
        define_qenum_under<QStyleOptionToolBox::StyleOptionVersion>(rb_cQStyleOptionToolBox, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionToolBoxStyleOptionVersion, "Version", QStyleOptionToolBox::StyleOptionVersion::Version);

    Data_Type<QStyleOptionToolBox::TabPosition> rb_cQStyleOptionToolBoxTabPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::TabPosition
        define_qenum_under<QStyleOptionToolBox::TabPosition>(rb_cQStyleOptionToolBox, "TabPosition");
        define_qenum_value_under(rb_cQStyleOptionToolBoxTabPosition, "Beginning", QStyleOptionToolBox::TabPosition::Beginning);
        define_qenum_value_under(rb_cQStyleOptionToolBoxTabPosition, "Middle", QStyleOptionToolBox::TabPosition::Middle);
        define_qenum_value_under(rb_cQStyleOptionToolBoxTabPosition, "End", QStyleOptionToolBox::TabPosition::End);
        define_qenum_value_under(rb_cQStyleOptionToolBoxTabPosition, "OnlyOneTab", QStyleOptionToolBox::TabPosition::OnlyOneTab);

    Data_Type<QStyleOptionToolBox::SelectedPosition> rb_cQStyleOptionToolBoxSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::SelectedPosition
        define_qenum_under<QStyleOptionToolBox::SelectedPosition>(rb_cQStyleOptionToolBox, "SelectedPosition");
        define_qenum_value_under(rb_cQStyleOptionToolBoxSelectedPosition, "NotAdjacent", QStyleOptionToolBox::SelectedPosition::NotAdjacent);
        define_qenum_value_under(rb_cQStyleOptionToolBoxSelectedPosition, "NextIsSelected", QStyleOptionToolBox::SelectedPosition::NextIsSelected);
        define_qenum_value_under(rb_cQStyleOptionToolBoxSelectedPosition, "PreviousIsSelected", QStyleOptionToolBox::SelectedPosition::PreviousIsSelected);

    rb_cQStyleOptionViewItem =
        // RubyQt6::QtWidgets::QStyleOptionViewItem
        define_class_under<QStyleOptionViewItem, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionViewItem")
            .define_attr("background_brush", &QStyleOptionViewItem::backgroundBrush)
            .define_attr("check_state", &QStyleOptionViewItem::checkState, Rice::AttrAccess::Read)
            .define_attr("decoration_alignment", &QStyleOptionViewItem::decorationAlignment)
            .define_attr("decoration_position", &QStyleOptionViewItem::decorationPosition, Rice::AttrAccess::Read)
            .define_attr("decoration_size", &QStyleOptionViewItem::decorationSize)
            .define_attr("display_alignment", &QStyleOptionViewItem::displayAlignment)
            .define_attr("features", &QStyleOptionViewItem::features)
            .define_attr("font", &QStyleOptionViewItem::font)
            .define_attr("icon", &QStyleOptionViewItem::icon)
            .define_attr("index", &QStyleOptionViewItem::index)
            .define_attr("locale", &QStyleOptionViewItem::locale)
            .define_attr("show_decoration_selected", &QStyleOptionViewItem::showDecorationSelected)
            .define_attr("text", &QStyleOptionViewItem::text)
            .define_attr("text_elide_mode", &QStyleOptionViewItem::textElideMode, Rice::AttrAccess::Read)
            .define_attr("view_item_position", &QStyleOptionViewItem::viewItemPosition, Rice::AttrAccess::Read)
            .define_attr("widget", &QStyleOptionViewItem::widget, Rice::AttrAccess::Read);

    Data_Type<QStyleOptionViewItem::StyleOptionType> rb_cQStyleOptionViewItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::StyleOptionType
        define_qenum_under<QStyleOptionViewItem::StyleOptionType>(rb_cQStyleOptionViewItem, "StyleOptionType");
        define_qenum_value_under(rb_cQStyleOptionViewItemStyleOptionType, "Type", QStyleOptionViewItem::StyleOptionType::Type);

    Data_Type<QStyleOptionViewItem::StyleOptionVersion> rb_cQStyleOptionViewItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::StyleOptionVersion
        define_qenum_under<QStyleOptionViewItem::StyleOptionVersion>(rb_cQStyleOptionViewItem, "StyleOptionVersion");
        define_qenum_value_under(rb_cQStyleOptionViewItemStyleOptionVersion, "Version", QStyleOptionViewItem::StyleOptionVersion::Version);

    Data_Type<QStyleOptionViewItem::Position> rb_cQStyleOptionViewItemPosition =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::Position
        define_qenum_under<QStyleOptionViewItem::Position>(rb_cQStyleOptionViewItem, "Position");
        define_qenum_value_under(rb_cQStyleOptionViewItemPosition, "Left", QStyleOptionViewItem::Position::Left);
        define_qenum_value_under(rb_cQStyleOptionViewItemPosition, "Right", QStyleOptionViewItem::Position::Right);
        define_qenum_value_under(rb_cQStyleOptionViewItemPosition, "Top", QStyleOptionViewItem::Position::Top);
        define_qenum_value_under(rb_cQStyleOptionViewItemPosition, "Bottom", QStyleOptionViewItem::Position::Bottom);

    Data_Type<QStyleOptionViewItem::ViewItemFeature> rb_cQStyleOptionViewItemViewItemFeature =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::ViewItemFeature
        define_qenum_under<QStyleOptionViewItem::ViewItemFeature>(rb_cQStyleOptionViewItem, "ViewItemFeature");
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "None", QStyleOptionViewItem::ViewItemFeature::None);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "WrapText", QStyleOptionViewItem::ViewItemFeature::WrapText);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "Alternate", QStyleOptionViewItem::ViewItemFeature::Alternate);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "HasCheckIndicator", QStyleOptionViewItem::ViewItemFeature::HasCheckIndicator);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "HasDisplay", QStyleOptionViewItem::ViewItemFeature::HasDisplay);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "HasDecoration", QStyleOptionViewItem::ViewItemFeature::HasDecoration);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "IsDecoratedRootColumn", QStyleOptionViewItem::ViewItemFeature::IsDecoratedRootColumn);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemFeature, "IsDecorationForRootColumn", QStyleOptionViewItem::ViewItemFeature::IsDecorationForRootColumn);

    Data_Type<QStyleOptionViewItem::ViewItemPosition> rb_cQStyleOptionViewItemViewItemPosition =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::ViewItemPosition
        define_qenum_under<QStyleOptionViewItem::ViewItemPosition>(rb_cQStyleOptionViewItem, "ViewItemPosition");
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemPosition, "Invalid", QStyleOptionViewItem::ViewItemPosition::Invalid);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemPosition, "Beginning", QStyleOptionViewItem::ViewItemPosition::Beginning);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemPosition, "Middle", QStyleOptionViewItem::ViewItemPosition::Middle);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemPosition, "End", QStyleOptionViewItem::ViewItemPosition::End);
        define_qenum_value_under(rb_cQStyleOptionViewItemViewItemPosition, "OnlyOne", QStyleOptionViewItem::ViewItemPosition::OnlyOne);
}
