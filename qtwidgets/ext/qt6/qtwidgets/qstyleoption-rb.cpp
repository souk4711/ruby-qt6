#include "qstyleoption-rb.hpp"
#include <qstyleoption.h>
#include <rice/qenum.hpp>

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

    Enum<QStyleOption::OptionType> rb_cQStyleOptionOptionType =
        // RubyQt6::QtWidgets::QStyleOption::OptionType
        define_qenum_under<QStyleOption::OptionType>("OptionType", rb_cQStyleOption)
            .define_value("SO_Default", QStyleOption::OptionType::SO_Default)
            .define_value("SO_FocusRect", QStyleOption::OptionType::SO_FocusRect)
            .define_value("SO_Button", QStyleOption::OptionType::SO_Button)
            .define_value("SO_Tab", QStyleOption::OptionType::SO_Tab)
            .define_value("SO_MenuItem", QStyleOption::OptionType::SO_MenuItem)
            .define_value("SO_Frame", QStyleOption::OptionType::SO_Frame)
            .define_value("SO_ProgressBar", QStyleOption::OptionType::SO_ProgressBar)
            .define_value("SO_ToolBox", QStyleOption::OptionType::SO_ToolBox)
            .define_value("SO_Header", QStyleOption::OptionType::SO_Header)
            .define_value("SO_DockWidget", QStyleOption::OptionType::SO_DockWidget)
            .define_value("SO_ViewItem", QStyleOption::OptionType::SO_ViewItem)
            .define_value("SO_TabWidgetFrame", QStyleOption::OptionType::SO_TabWidgetFrame)
            .define_value("SO_TabBarBase", QStyleOption::OptionType::SO_TabBarBase)
            .define_value("SO_RubberBand", QStyleOption::OptionType::SO_RubberBand)
            .define_value("SO_ToolBar", QStyleOption::OptionType::SO_ToolBar)
            .define_value("SO_GraphicsItem", QStyleOption::OptionType::SO_GraphicsItem)
            .define_value("SO_Complex", QStyleOption::OptionType::SO_Complex)
            .define_value("SO_Slider", QStyleOption::OptionType::SO_Slider)
            .define_value("SO_SpinBox", QStyleOption::OptionType::SO_SpinBox)
            .define_value("SO_ToolButton", QStyleOption::OptionType::SO_ToolButton)
            .define_value("SO_ComboBox", QStyleOption::OptionType::SO_ComboBox)
            .define_value("SO_TitleBar", QStyleOption::OptionType::SO_TitleBar)
            .define_value("SO_GroupBox", QStyleOption::OptionType::SO_GroupBox)
            .define_value("SO_SizeGrip", QStyleOption::OptionType::SO_SizeGrip)
            .define_value("SO_CustomBase", QStyleOption::OptionType::SO_CustomBase)
            .define_value("SO_ComplexCustomBase", QStyleOption::OptionType::SO_ComplexCustomBase);

    Enum<QStyleOption::StyleOptionType> rb_cQStyleOptionStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOption::StyleOptionType
        define_qenum_under<QStyleOption::StyleOptionType>("StyleOptionType", rb_cQStyleOption)
            .define_value("Type", QStyleOption::StyleOptionType::Type);

    Enum<QStyleOption::StyleOptionVersion> rb_cQStyleOptionStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOption::StyleOptionVersion
        define_qenum_under<QStyleOption::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOption)
            .define_value("Version", QStyleOption::StyleOptionVersion::Version);

    rb_cQStyleOptionButton =
        // RubyQt6::QtWidgets::QStyleOptionButton
        define_class_under<QStyleOptionButton, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionButton")
            .define_attr("features", &QStyleOptionButton::features)
            .define_attr("icon", &QStyleOptionButton::icon)
            .define_attr("icon_size", &QStyleOptionButton::iconSize)
            .define_attr("text", &QStyleOptionButton::text);

    Enum<QStyleOptionButton::StyleOptionType> rb_cQStyleOptionButtonStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionButton::StyleOptionType
        define_qenum_under<QStyleOptionButton::StyleOptionType>("StyleOptionType", rb_cQStyleOptionButton)
            .define_value("Type", QStyleOptionButton::StyleOptionType::Type);

    Enum<QStyleOptionButton::StyleOptionVersion> rb_cQStyleOptionButtonStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionButton::StyleOptionVersion
        define_qenum_under<QStyleOptionButton::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionButton)
            .define_value("Version", QStyleOptionButton::StyleOptionVersion::Version);

    Enum<QStyleOptionButton::ButtonFeature> rb_cQStyleOptionButtonButtonFeature =
        // RubyQt6::QtWidgets::QStyleOptionButton::ButtonFeature
        define_qenum_under<QStyleOptionButton::ButtonFeature>("ButtonFeature", rb_cQStyleOptionButton)
            .define_value("None", QStyleOptionButton::ButtonFeature::None)
            .define_value("Flat", QStyleOptionButton::ButtonFeature::Flat)
            .define_value("HasMenu", QStyleOptionButton::ButtonFeature::HasMenu)
            .define_value("DefaultButton", QStyleOptionButton::ButtonFeature::DefaultButton)
            .define_value("AutoDefaultButton", QStyleOptionButton::ButtonFeature::AutoDefaultButton)
            .define_value("CommandLinkButton", QStyleOptionButton::ButtonFeature::CommandLinkButton);

    rb_cQStyleOptionComplex =
        // RubyQt6::QtWidgets::QStyleOptionComplex
        define_class_under<QStyleOptionComplex, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionComplex")
            .define_attr("active_sub_controls", &QStyleOptionComplex::activeSubControls)
            .define_attr("sub_controls", &QStyleOptionComplex::subControls);

    Enum<QStyleOptionComplex::StyleOptionType> rb_cQStyleOptionComplexStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionComplex::StyleOptionType
        define_qenum_under<QStyleOptionComplex::StyleOptionType>("StyleOptionType", rb_cQStyleOptionComplex)
            .define_value("Type", QStyleOptionComplex::StyleOptionType::Type);

    Enum<QStyleOptionComplex::StyleOptionVersion> rb_cQStyleOptionComplexStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionComplex::StyleOptionVersion
        define_qenum_under<QStyleOptionComplex::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionComplex)
            .define_value("Version", QStyleOptionComplex::StyleOptionVersion::Version);

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

    Enum<QStyleOptionComboBox::StyleOptionType> rb_cQStyleOptionComboBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionComboBox::StyleOptionType
        define_qenum_under<QStyleOptionComboBox::StyleOptionType>("StyleOptionType", rb_cQStyleOptionComboBox)
            .define_value("Type", QStyleOptionComboBox::StyleOptionType::Type);

    Enum<QStyleOptionComboBox::StyleOptionVersion> rb_cQStyleOptionComboBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionComboBox::StyleOptionVersion
        define_qenum_under<QStyleOptionComboBox::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionComboBox)
            .define_value("Version", QStyleOptionComboBox::StyleOptionVersion::Version);

    rb_cQStyleOptionGroupBox =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox
        define_class_under<QStyleOptionGroupBox, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionGroupBox")
            .define_attr("features", &QStyleOptionGroupBox::features)
            .define_attr("line_width", &QStyleOptionGroupBox::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionGroupBox::midLineWidth)
            .define_attr("text", &QStyleOptionGroupBox::text)
            .define_attr("text_alignment", &QStyleOptionGroupBox::textAlignment)
            .define_attr("text_color", &QStyleOptionGroupBox::textColor);

    Enum<QStyleOptionGroupBox::StyleOptionType> rb_cQStyleOptionGroupBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox::StyleOptionType
        define_qenum_under<QStyleOptionGroupBox::StyleOptionType>("StyleOptionType", rb_cQStyleOptionGroupBox)
            .define_value("Type", QStyleOptionGroupBox::StyleOptionType::Type);

    Enum<QStyleOptionGroupBox::StyleOptionVersion> rb_cQStyleOptionGroupBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionGroupBox::StyleOptionVersion
        define_qenum_under<QStyleOptionGroupBox::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionGroupBox)
            .define_value("Version", QStyleOptionGroupBox::StyleOptionVersion::Version);

    rb_cQStyleOptionSizeGrip =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip
        define_class_under<QStyleOptionSizeGrip, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionSizeGrip")
            .define_attr("corner", &QStyleOptionSizeGrip::corner, Rice::AttrAccess::Read);

    Enum<QStyleOptionSizeGrip::StyleOptionType> rb_cQStyleOptionSizeGripStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip::StyleOptionType
        define_qenum_under<QStyleOptionSizeGrip::StyleOptionType>("StyleOptionType", rb_cQStyleOptionSizeGrip)
            .define_value("Type", QStyleOptionSizeGrip::StyleOptionType::Type);

    Enum<QStyleOptionSizeGrip::StyleOptionVersion> rb_cQStyleOptionSizeGripStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSizeGrip::StyleOptionVersion
        define_qenum_under<QStyleOptionSizeGrip::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionSizeGrip)
            .define_value("Version", QStyleOptionSizeGrip::StyleOptionVersion::Version);

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

    Enum<QStyleOptionSlider::StyleOptionType> rb_cQStyleOptionSliderStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSlider::StyleOptionType
        define_qenum_under<QStyleOptionSlider::StyleOptionType>("StyleOptionType", rb_cQStyleOptionSlider)
            .define_value("Type", QStyleOptionSlider::StyleOptionType::Type);

    Enum<QStyleOptionSlider::StyleOptionVersion> rb_cQStyleOptionSliderStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSlider::StyleOptionVersion
        define_qenum_under<QStyleOptionSlider::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionSlider)
            .define_value("Version", QStyleOptionSlider::StyleOptionVersion::Version);

    rb_cQStyleOptionSpinBox =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox
        define_class_under<QStyleOptionSpinBox, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionSpinBox")
            .define_attr("button_symbols", &QStyleOptionSpinBox::buttonSymbols, Rice::AttrAccess::Read)
            .define_attr("frame", &QStyleOptionSpinBox::frame)
            .define_attr("step_enabled", &QStyleOptionSpinBox::stepEnabled);

    Enum<QStyleOptionSpinBox::StyleOptionType> rb_cQStyleOptionSpinBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox::StyleOptionType
        define_qenum_under<QStyleOptionSpinBox::StyleOptionType>("StyleOptionType", rb_cQStyleOptionSpinBox)
            .define_value("Type", QStyleOptionSpinBox::StyleOptionType::Type);

    Enum<QStyleOptionSpinBox::StyleOptionVersion> rb_cQStyleOptionSpinBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionSpinBox::StyleOptionVersion
        define_qenum_under<QStyleOptionSpinBox::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionSpinBox)
            .define_value("Version", QStyleOptionSpinBox::StyleOptionVersion::Version);

    rb_cQStyleOptionTitleBar =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar
        define_class_under<QStyleOptionTitleBar, QStyleOptionComplex>(rb_mQt6QtWidgets, "QStyleOptionTitleBar")
            .define_attr("icon", &QStyleOptionTitleBar::icon)
            .define_attr("text", &QStyleOptionTitleBar::text)
            .define_attr("title_bar_flags", &QStyleOptionTitleBar::titleBarFlags)
            .define_attr("title_bar_state", &QStyleOptionTitleBar::titleBarState);

    Enum<QStyleOptionTitleBar::StyleOptionType> rb_cQStyleOptionTitleBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar::StyleOptionType
        define_qenum_under<QStyleOptionTitleBar::StyleOptionType>("StyleOptionType", rb_cQStyleOptionTitleBar)
            .define_value("Type", QStyleOptionTitleBar::StyleOptionType::Type);

    Enum<QStyleOptionTitleBar::StyleOptionVersion> rb_cQStyleOptionTitleBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTitleBar::StyleOptionVersion
        define_qenum_under<QStyleOptionTitleBar::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionTitleBar)
            .define_value("Version", QStyleOptionTitleBar::StyleOptionVersion::Version);

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

    Enum<QStyleOptionToolButton::StyleOptionType> rb_cQStyleOptionToolButtonStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::StyleOptionType
        define_qenum_under<QStyleOptionToolButton::StyleOptionType>("StyleOptionType", rb_cQStyleOptionToolButton)
            .define_value("Type", QStyleOptionToolButton::StyleOptionType::Type);

    Enum<QStyleOptionToolButton::StyleOptionVersion> rb_cQStyleOptionToolButtonStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::StyleOptionVersion
        define_qenum_under<QStyleOptionToolButton::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionToolButton)
            .define_value("Version", QStyleOptionToolButton::StyleOptionVersion::Version);

    Enum<QStyleOptionToolButton::ToolButtonFeature> rb_cQStyleOptionToolButtonToolButtonFeature =
        // RubyQt6::QtWidgets::QStyleOptionToolButton::ToolButtonFeature
        define_qenum_under<QStyleOptionToolButton::ToolButtonFeature>("ToolButtonFeature", rb_cQStyleOptionToolButton)
            .define_value("None", QStyleOptionToolButton::ToolButtonFeature::None)
            .define_value("Arrow", QStyleOptionToolButton::ToolButtonFeature::Arrow)
            .define_value("Menu", QStyleOptionToolButton::ToolButtonFeature::Menu)
            .define_value("MenuButtonPopup", QStyleOptionToolButton::ToolButtonFeature::MenuButtonPopup)
            .define_value("PopupDelay", QStyleOptionToolButton::ToolButtonFeature::PopupDelay)
            .define_value("HasMenu", QStyleOptionToolButton::ToolButtonFeature::HasMenu);

    rb_cQStyleOptionDockWidget =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget
        define_class_under<QStyleOptionDockWidget, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionDockWidget")
            .define_attr("closable", &QStyleOptionDockWidget::closable)
            .define_attr("floatable", &QStyleOptionDockWidget::floatable)
            .define_attr("movable", &QStyleOptionDockWidget::movable)
            .define_attr("title", &QStyleOptionDockWidget::title)
            .define_attr("vertical_title_bar", &QStyleOptionDockWidget::verticalTitleBar);

    Enum<QStyleOptionDockWidget::StyleOptionType> rb_cQStyleOptionDockWidgetStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget::StyleOptionType
        define_qenum_under<QStyleOptionDockWidget::StyleOptionType>("StyleOptionType", rb_cQStyleOptionDockWidget)
            .define_value("Type", QStyleOptionDockWidget::StyleOptionType::Type);

    Enum<QStyleOptionDockWidget::StyleOptionVersion> rb_cQStyleOptionDockWidgetStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionDockWidget::StyleOptionVersion
        define_qenum_under<QStyleOptionDockWidget::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionDockWidget)
            .define_value("Version", QStyleOptionDockWidget::StyleOptionVersion::Version);

    rb_cQStyleOptionFocusRect =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect
        define_class_under<QStyleOptionFocusRect, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionFocusRect")
            .define_attr("background_color", &QStyleOptionFocusRect::backgroundColor);

    Enum<QStyleOptionFocusRect::StyleOptionType> rb_cQStyleOptionFocusRectStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect::StyleOptionType
        define_qenum_under<QStyleOptionFocusRect::StyleOptionType>("StyleOptionType", rb_cQStyleOptionFocusRect)
            .define_value("Type", QStyleOptionFocusRect::StyleOptionType::Type);

    Enum<QStyleOptionFocusRect::StyleOptionVersion> rb_cQStyleOptionFocusRectStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionFocusRect::StyleOptionVersion
        define_qenum_under<QStyleOptionFocusRect::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionFocusRect)
            .define_value("Version", QStyleOptionFocusRect::StyleOptionVersion::Version);

    rb_cQStyleOptionFrame =
        // RubyQt6::QtWidgets::QStyleOptionFrame
        define_class_under<QStyleOptionFrame, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionFrame")
            .define_attr("features", &QStyleOptionFrame::features)
            .define_attr("frame_shape", &QStyleOptionFrame::frameShape, Rice::AttrAccess::Read)
            .define_attr("line_width", &QStyleOptionFrame::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionFrame::midLineWidth);

    Enum<QStyleOptionFrame::StyleOptionType> rb_cQStyleOptionFrameStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionFrame::StyleOptionType
        define_qenum_under<QStyleOptionFrame::StyleOptionType>("StyleOptionType", rb_cQStyleOptionFrame)
            .define_value("Type", QStyleOptionFrame::StyleOptionType::Type);

    Enum<QStyleOptionFrame::StyleOptionVersion> rb_cQStyleOptionFrameStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionFrame::StyleOptionVersion
        define_qenum_under<QStyleOptionFrame::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionFrame)
            .define_value("Version", QStyleOptionFrame::StyleOptionVersion::Version);

    Enum<QStyleOptionFrame::FrameFeature> rb_cQStyleOptionFrameFrameFeature =
        // RubyQt6::QtWidgets::QStyleOptionFrame::FrameFeature
        define_qenum_under<QStyleOptionFrame::FrameFeature>("FrameFeature", rb_cQStyleOptionFrame)
            .define_value("None", QStyleOptionFrame::FrameFeature::None)
            .define_value("Flat", QStyleOptionFrame::FrameFeature::Flat)
            .define_value("Rounded", QStyleOptionFrame::FrameFeature::Rounded);

    rb_cQStyleOptionGraphicsItem =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem
        define_class_under<QStyleOptionGraphicsItem, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionGraphicsItem")
            .define_attr("exposed_rect", &QStyleOptionGraphicsItem::exposedRect);

    Enum<QStyleOptionGraphicsItem::StyleOptionType> rb_cQStyleOptionGraphicsItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem::StyleOptionType
        define_qenum_under<QStyleOptionGraphicsItem::StyleOptionType>("StyleOptionType", rb_cQStyleOptionGraphicsItem)
            .define_value("Type", QStyleOptionGraphicsItem::StyleOptionType::Type);

    Enum<QStyleOptionGraphicsItem::StyleOptionVersion> rb_cQStyleOptionGraphicsItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionGraphicsItem::StyleOptionVersion
        define_qenum_under<QStyleOptionGraphicsItem::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionGraphicsItem)
            .define_value("Version", QStyleOptionGraphicsItem::StyleOptionVersion::Version);

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

    Enum<QStyleOptionHeader::StyleOptionType> rb_cQStyleOptionHeaderStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionHeader::StyleOptionType
        define_qenum_under<QStyleOptionHeader::StyleOptionType>("StyleOptionType", rb_cQStyleOptionHeader)
            .define_value("Type", QStyleOptionHeader::StyleOptionType::Type);

    Enum<QStyleOptionHeader::StyleOptionVersion> rb_cQStyleOptionHeaderStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionHeader::StyleOptionVersion
        define_qenum_under<QStyleOptionHeader::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionHeader)
            .define_value("Version", QStyleOptionHeader::StyleOptionVersion::Version);

    Enum<QStyleOptionHeader::SectionPosition> rb_cQStyleOptionHeaderSectionPosition =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SectionPosition
        define_qenum_under<QStyleOptionHeader::SectionPosition>("SectionPosition", rb_cQStyleOptionHeader)
            .define_value("Beginning", QStyleOptionHeader::SectionPosition::Beginning)
            .define_value("Middle", QStyleOptionHeader::SectionPosition::Middle)
            .define_value("End", QStyleOptionHeader::SectionPosition::End)
            .define_value("OnlyOneSection", QStyleOptionHeader::SectionPosition::OnlyOneSection);

    Enum<QStyleOptionHeader::SelectedPosition> rb_cQStyleOptionHeaderSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SelectedPosition
        define_qenum_under<QStyleOptionHeader::SelectedPosition>("SelectedPosition", rb_cQStyleOptionHeader)
            .define_value("NotAdjacent", QStyleOptionHeader::SelectedPosition::NotAdjacent)
            .define_value("NextIsSelected", QStyleOptionHeader::SelectedPosition::NextIsSelected)
            .define_value("PreviousIsSelected", QStyleOptionHeader::SelectedPosition::PreviousIsSelected)
            .define_value("NextAndPreviousAreSelected", QStyleOptionHeader::SelectedPosition::NextAndPreviousAreSelected);

    Enum<QStyleOptionHeader::SortIndicator> rb_cQStyleOptionHeaderSortIndicator =
        // RubyQt6::QtWidgets::QStyleOptionHeader::SortIndicator
        define_qenum_under<QStyleOptionHeader::SortIndicator>("SortIndicator", rb_cQStyleOptionHeader)
            .define_value("None", QStyleOptionHeader::SortIndicator::None)
            .define_value("SortUp", QStyleOptionHeader::SortIndicator::SortUp)
            .define_value("SortDown", QStyleOptionHeader::SortIndicator::SortDown);

    rb_cQStyleOptionHeaderV2 =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2
        define_class_under<QStyleOptionHeaderV2, QStyleOptionHeader>(rb_mQt6QtWidgets, "QStyleOptionHeaderV2");

    Enum<QStyleOptionHeaderV2::StyleOptionType> rb_cQStyleOptionHeaderV2StyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2::StyleOptionType
        define_qenum_under<QStyleOptionHeaderV2::StyleOptionType>("StyleOptionType", rb_cQStyleOptionHeaderV2)
            .define_value("Type", QStyleOptionHeaderV2::StyleOptionType::Type);

    Enum<QStyleOptionHeaderV2::StyleOptionVersion> rb_cQStyleOptionHeaderV2StyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionHeaderV2::StyleOptionVersion
        define_qenum_under<QStyleOptionHeaderV2::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionHeaderV2)
            .define_value("Version", QStyleOptionHeaderV2::StyleOptionVersion::Version);

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

    Enum<QStyleOptionMenuItem::StyleOptionType> rb_cQStyleOptionMenuItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::StyleOptionType
        define_qenum_under<QStyleOptionMenuItem::StyleOptionType>("StyleOptionType", rb_cQStyleOptionMenuItem)
            .define_value("Type", QStyleOptionMenuItem::StyleOptionType::Type);

    Enum<QStyleOptionMenuItem::StyleOptionVersion> rb_cQStyleOptionMenuItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::StyleOptionVersion
        define_qenum_under<QStyleOptionMenuItem::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionMenuItem)
            .define_value("Version", QStyleOptionMenuItem::StyleOptionVersion::Version);

    Enum<QStyleOptionMenuItem::MenuItemType> rb_cQStyleOptionMenuItemMenuItemType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::MenuItemType
        define_qenum_under<QStyleOptionMenuItem::MenuItemType>("MenuItemType", rb_cQStyleOptionMenuItem)
            .define_value("Normal", QStyleOptionMenuItem::MenuItemType::Normal)
            .define_value("DefaultItem", QStyleOptionMenuItem::MenuItemType::DefaultItem)
            .define_value("Separator", QStyleOptionMenuItem::MenuItemType::Separator)
            .define_value("SubMenu", QStyleOptionMenuItem::MenuItemType::SubMenu)
            .define_value("Scroller", QStyleOptionMenuItem::MenuItemType::Scroller)
            .define_value("TearOff", QStyleOptionMenuItem::MenuItemType::TearOff)
            .define_value("Margin", QStyleOptionMenuItem::MenuItemType::Margin)
            .define_value("EmptyArea", QStyleOptionMenuItem::MenuItemType::EmptyArea);

    Enum<QStyleOptionMenuItem::CheckType> rb_cQStyleOptionMenuItemCheckType =
        // RubyQt6::QtWidgets::QStyleOptionMenuItem::CheckType
        define_qenum_under<QStyleOptionMenuItem::CheckType>("CheckType", rb_cQStyleOptionMenuItem)
            .define_value("NotCheckable", QStyleOptionMenuItem::CheckType::NotCheckable)
            .define_value("Exclusive", QStyleOptionMenuItem::CheckType::Exclusive)
            .define_value("NonExclusive", QStyleOptionMenuItem::CheckType::NonExclusive);

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

    Enum<QStyleOptionProgressBar::StyleOptionType> rb_cQStyleOptionProgressBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionProgressBar::StyleOptionType
        define_qenum_under<QStyleOptionProgressBar::StyleOptionType>("StyleOptionType", rb_cQStyleOptionProgressBar)
            .define_value("Type", QStyleOptionProgressBar::StyleOptionType::Type);

    Enum<QStyleOptionProgressBar::StyleOptionVersion> rb_cQStyleOptionProgressBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionProgressBar::StyleOptionVersion
        define_qenum_under<QStyleOptionProgressBar::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionProgressBar)
            .define_value("Version", QStyleOptionProgressBar::StyleOptionVersion::Version);

    rb_cQStyleOptionRubberBand =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand
        define_class_under<QStyleOptionRubberBand, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionRubberBand")
            .define_attr("opaque", &QStyleOptionRubberBand::opaque)
            .define_attr("shape", &QStyleOptionRubberBand::shape, Rice::AttrAccess::Read);

    Enum<QStyleOptionRubberBand::StyleOptionType> rb_cQStyleOptionRubberBandStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand::StyleOptionType
        define_qenum_under<QStyleOptionRubberBand::StyleOptionType>("StyleOptionType", rb_cQStyleOptionRubberBand)
            .define_value("Type", QStyleOptionRubberBand::StyleOptionType::Type);

    Enum<QStyleOptionRubberBand::StyleOptionVersion> rb_cQStyleOptionRubberBandStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionRubberBand::StyleOptionVersion
        define_qenum_under<QStyleOptionRubberBand::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionRubberBand)
            .define_value("Version", QStyleOptionRubberBand::StyleOptionVersion::Version);

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

    Enum<QStyleOptionTab::StyleOptionType> rb_cQStyleOptionTabStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTab::StyleOptionType
        define_qenum_under<QStyleOptionTab::StyleOptionType>("StyleOptionType", rb_cQStyleOptionTab)
            .define_value("Type", QStyleOptionTab::StyleOptionType::Type);

    Enum<QStyleOptionTab::StyleOptionVersion> rb_cQStyleOptionTabStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTab::StyleOptionVersion
        define_qenum_under<QStyleOptionTab::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionTab)
            .define_value("Version", QStyleOptionTab::StyleOptionVersion::Version);

    Enum<QStyleOptionTab::TabPosition> rb_cQStyleOptionTabTabPosition =
        // RubyQt6::QtWidgets::QStyleOptionTab::TabPosition
        define_qenum_under<QStyleOptionTab::TabPosition>("TabPosition", rb_cQStyleOptionTab)
            .define_value("Beginning", QStyleOptionTab::TabPosition::Beginning)
            .define_value("Middle", QStyleOptionTab::TabPosition::Middle)
            .define_value("End", QStyleOptionTab::TabPosition::End)
            .define_value("OnlyOneTab", QStyleOptionTab::TabPosition::OnlyOneTab)
            .define_value("Moving", QStyleOptionTab::TabPosition::Moving);

    Enum<QStyleOptionTab::SelectedPosition> rb_cQStyleOptionTabSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionTab::SelectedPosition
        define_qenum_under<QStyleOptionTab::SelectedPosition>("SelectedPosition", rb_cQStyleOptionTab)
            .define_value("NotAdjacent", QStyleOptionTab::SelectedPosition::NotAdjacent)
            .define_value("NextIsSelected", QStyleOptionTab::SelectedPosition::NextIsSelected)
            .define_value("PreviousIsSelected", QStyleOptionTab::SelectedPosition::PreviousIsSelected);

    Enum<QStyleOptionTab::CornerWidget> rb_cQStyleOptionTabCornerWidget =
        // RubyQt6::QtWidgets::QStyleOptionTab::CornerWidget
        define_qenum_under<QStyleOptionTab::CornerWidget>("CornerWidget", rb_cQStyleOptionTab)
            .define_value("NoCornerWidgets", QStyleOptionTab::CornerWidget::NoCornerWidgets)
            .define_value("LeftCornerWidget", QStyleOptionTab::CornerWidget::LeftCornerWidget)
            .define_value("RightCornerWidget", QStyleOptionTab::CornerWidget::RightCornerWidget);

    Enum<QStyleOptionTab::TabFeature> rb_cQStyleOptionTabTabFeature =
        // RubyQt6::QtWidgets::QStyleOptionTab::TabFeature
        define_qenum_under<QStyleOptionTab::TabFeature>("TabFeature", rb_cQStyleOptionTab)
            .define_value("None", QStyleOptionTab::TabFeature::None)
            .define_value("HasFrame", QStyleOptionTab::TabFeature::HasFrame)
            .define_value("MinimumSizeHint", QStyleOptionTab::TabFeature::MinimumSizeHint);

    rb_cQStyleOptionTabBarBase =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase
        define_class_under<QStyleOptionTabBarBase, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionTabBarBase")
            .define_attr("document_mode", &QStyleOptionTabBarBase::documentMode)
            .define_attr("selected_tab_rect", &QStyleOptionTabBarBase::selectedTabRect)
            .define_attr("shape", &QStyleOptionTabBarBase::shape, Rice::AttrAccess::Read)
            .define_attr("tab_bar_rect", &QStyleOptionTabBarBase::tabBarRect);

    Enum<QStyleOptionTabBarBase::StyleOptionType> rb_cQStyleOptionTabBarBaseStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase::StyleOptionType
        define_qenum_under<QStyleOptionTabBarBase::StyleOptionType>("StyleOptionType", rb_cQStyleOptionTabBarBase)
            .define_value("Type", QStyleOptionTabBarBase::StyleOptionType::Type);

    Enum<QStyleOptionTabBarBase::StyleOptionVersion> rb_cQStyleOptionTabBarBaseStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTabBarBase::StyleOptionVersion
        define_qenum_under<QStyleOptionTabBarBase::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionTabBarBase)
            .define_value("Version", QStyleOptionTabBarBase::StyleOptionVersion::Version);

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

    Enum<QStyleOptionTabWidgetFrame::StyleOptionType> rb_cQStyleOptionTabWidgetFrameStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionTabWidgetFrame::StyleOptionType
        define_qenum_under<QStyleOptionTabWidgetFrame::StyleOptionType>("StyleOptionType", rb_cQStyleOptionTabWidgetFrame)
            .define_value("Type", QStyleOptionTabWidgetFrame::StyleOptionType::Type);

    Enum<QStyleOptionTabWidgetFrame::StyleOptionVersion> rb_cQStyleOptionTabWidgetFrameStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionTabWidgetFrame::StyleOptionVersion
        define_qenum_under<QStyleOptionTabWidgetFrame::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionTabWidgetFrame)
            .define_value("Version", QStyleOptionTabWidgetFrame::StyleOptionVersion::Version);

    rb_cQStyleOptionToolBar =
        // RubyQt6::QtWidgets::QStyleOptionToolBar
        define_class_under<QStyleOptionToolBar, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionToolBar")
            .define_attr("features", &QStyleOptionToolBar::features)
            .define_attr("line_width", &QStyleOptionToolBar::lineWidth)
            .define_attr("mid_line_width", &QStyleOptionToolBar::midLineWidth)
            .define_attr("position_of_line", &QStyleOptionToolBar::positionOfLine, Rice::AttrAccess::Read)
            .define_attr("position_within_line", &QStyleOptionToolBar::positionWithinLine, Rice::AttrAccess::Read)
            .define_attr("tool_bar_area", &QStyleOptionToolBar::toolBarArea, Rice::AttrAccess::Read);

    Enum<QStyleOptionToolBar::StyleOptionType> rb_cQStyleOptionToolBarStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::StyleOptionType
        define_qenum_under<QStyleOptionToolBar::StyleOptionType>("StyleOptionType", rb_cQStyleOptionToolBar)
            .define_value("Type", QStyleOptionToolBar::StyleOptionType::Type);

    Enum<QStyleOptionToolBar::StyleOptionVersion> rb_cQStyleOptionToolBarStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::StyleOptionVersion
        define_qenum_under<QStyleOptionToolBar::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionToolBar)
            .define_value("Version", QStyleOptionToolBar::StyleOptionVersion::Version);

    Enum<QStyleOptionToolBar::ToolBarPosition> rb_cQStyleOptionToolBarToolBarPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::ToolBarPosition
        define_qenum_under<QStyleOptionToolBar::ToolBarPosition>("ToolBarPosition", rb_cQStyleOptionToolBar)
            .define_value("Beginning", QStyleOptionToolBar::ToolBarPosition::Beginning)
            .define_value("Middle", QStyleOptionToolBar::ToolBarPosition::Middle)
            .define_value("End", QStyleOptionToolBar::ToolBarPosition::End)
            .define_value("OnlyOne", QStyleOptionToolBar::ToolBarPosition::OnlyOne);

    Enum<QStyleOptionToolBar::ToolBarFeature> rb_cQStyleOptionToolBarToolBarFeature =
        // RubyQt6::QtWidgets::QStyleOptionToolBar::ToolBarFeature
        define_qenum_under<QStyleOptionToolBar::ToolBarFeature>("ToolBarFeature", rb_cQStyleOptionToolBar)
            .define_value("None", QStyleOptionToolBar::ToolBarFeature::None).define_value("Movable", QStyleOptionToolBar::ToolBarFeature::Movable);

    rb_cQStyleOptionToolBox =
        // RubyQt6::QtWidgets::QStyleOptionToolBox
        define_class_under<QStyleOptionToolBox, QStyleOption>(rb_mQt6QtWidgets, "QStyleOptionToolBox")
            .define_attr("icon", &QStyleOptionToolBox::icon)
            .define_attr("position", &QStyleOptionToolBox::position, Rice::AttrAccess::Read)
            .define_attr("text", &QStyleOptionToolBox::text);

    Enum<QStyleOptionToolBox::StyleOptionType> rb_cQStyleOptionToolBoxStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::StyleOptionType
        define_qenum_under<QStyleOptionToolBox::StyleOptionType>("StyleOptionType", rb_cQStyleOptionToolBox)
            .define_value("Type", QStyleOptionToolBox::StyleOptionType::Type);

    Enum<QStyleOptionToolBox::StyleOptionVersion> rb_cQStyleOptionToolBoxStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::StyleOptionVersion
        define_qenum_under<QStyleOptionToolBox::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionToolBox)
            .define_value("Version", QStyleOptionToolBox::StyleOptionVersion::Version);

    Enum<QStyleOptionToolBox::TabPosition> rb_cQStyleOptionToolBoxTabPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::TabPosition
        define_qenum_under<QStyleOptionToolBox::TabPosition>("TabPosition", rb_cQStyleOptionToolBox)
            .define_value("Beginning", QStyleOptionToolBox::TabPosition::Beginning)
            .define_value("Middle", QStyleOptionToolBox::TabPosition::Middle)
            .define_value("End", QStyleOptionToolBox::TabPosition::End)
            .define_value("OnlyOneTab", QStyleOptionToolBox::TabPosition::OnlyOneTab);

    Enum<QStyleOptionToolBox::SelectedPosition> rb_cQStyleOptionToolBoxSelectedPosition =
        // RubyQt6::QtWidgets::QStyleOptionToolBox::SelectedPosition
        define_qenum_under<QStyleOptionToolBox::SelectedPosition>("SelectedPosition", rb_cQStyleOptionToolBox)
            .define_value("NotAdjacent", QStyleOptionToolBox::SelectedPosition::NotAdjacent)
            .define_value("NextIsSelected", QStyleOptionToolBox::SelectedPosition::NextIsSelected)
            .define_value("PreviousIsSelected", QStyleOptionToolBox::SelectedPosition::PreviousIsSelected);

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

    Enum<QStyleOptionViewItem::StyleOptionType> rb_cQStyleOptionViewItemStyleOptionType =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::StyleOptionType
        define_qenum_under<QStyleOptionViewItem::StyleOptionType>("StyleOptionType", rb_cQStyleOptionViewItem)
            .define_value("Type", QStyleOptionViewItem::StyleOptionType::Type);

    Enum<QStyleOptionViewItem::StyleOptionVersion> rb_cQStyleOptionViewItemStyleOptionVersion =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::StyleOptionVersion
        define_qenum_under<QStyleOptionViewItem::StyleOptionVersion>("StyleOptionVersion", rb_cQStyleOptionViewItem)
            .define_value("Version", QStyleOptionViewItem::StyleOptionVersion::Version);

    Enum<QStyleOptionViewItem::Position> rb_cQStyleOptionViewItemPosition =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::Position
        define_qenum_under<QStyleOptionViewItem::Position>("Position", rb_cQStyleOptionViewItem)
            .define_value("Left", QStyleOptionViewItem::Position::Left)
            .define_value("Right", QStyleOptionViewItem::Position::Right)
            .define_value("Top", QStyleOptionViewItem::Position::Top)
            .define_value("Bottom", QStyleOptionViewItem::Position::Bottom);

    Enum<QStyleOptionViewItem::ViewItemFeature> rb_cQStyleOptionViewItemViewItemFeature =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::ViewItemFeature
        define_qenum_under<QStyleOptionViewItem::ViewItemFeature>("ViewItemFeature", rb_cQStyleOptionViewItem)
            .define_value("None", QStyleOptionViewItem::ViewItemFeature::None)
            .define_value("WrapText", QStyleOptionViewItem::ViewItemFeature::WrapText)
            .define_value("Alternate", QStyleOptionViewItem::ViewItemFeature::Alternate)
            .define_value("HasCheckIndicator", QStyleOptionViewItem::ViewItemFeature::HasCheckIndicator)
            .define_value("HasDisplay", QStyleOptionViewItem::ViewItemFeature::HasDisplay)
            .define_value("HasDecoration", QStyleOptionViewItem::ViewItemFeature::HasDecoration)
            .define_value("IsDecoratedRootColumn", QStyleOptionViewItem::ViewItemFeature::IsDecoratedRootColumn)
            .define_value("IsDecorationForRootColumn", QStyleOptionViewItem::ViewItemFeature::IsDecorationForRootColumn);

    Enum<QStyleOptionViewItem::ViewItemPosition> rb_cQStyleOptionViewItemViewItemPosition =
        // RubyQt6::QtWidgets::QStyleOptionViewItem::ViewItemPosition
        define_qenum_under<QStyleOptionViewItem::ViewItemPosition>("ViewItemPosition", rb_cQStyleOptionViewItem)
            .define_value("Invalid", QStyleOptionViewItem::ViewItemPosition::Invalid)
            .define_value("Beginning", QStyleOptionViewItem::ViewItemPosition::Beginning)
            .define_value("Middle", QStyleOptionViewItem::ViewItemPosition::Middle)
            .define_value("End", QStyleOptionViewItem::ViewItemPosition::End)
            .define_value("OnlyOne", QStyleOptionViewItem::ViewItemPosition::OnlyOne);
}
