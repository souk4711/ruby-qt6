#include "qstyle-rb.hpp"
#include <qstyle.h>
#include <rice/qt6/qenum.hpp>
#include <rice/qt6/qflags.hpp>

#include <QApplication>
#include <QFontMetrics>
#include <QPainter>
#include <QStyleHintReturn>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQStyle;

void Init_qstyle(Module rb_mQt6QtWidgets)
{
    rb_cQStyle =
        // RubyQt6::QtWidgets::QStyle
        define_qlass_under<QStyle, QObject>(rb_mQt6QtWidgets, "QStyle")
            // RubyQt6-Defined Functions
            .define_singleton_function("_static_meta_object", []() -> const QMetaObject * { return &QStyle::staticMetaObject; })
            // Public Functions
            .define_method("combined_layout_spacing", &QStyle::combinedLayoutSpacing, Arg("controls1"), Arg("controls2"), Arg("orientation"), Arg("option") = static_cast<QStyleOption *>(nullptr), Arg("widget") = static_cast<QWidget *>(nullptr))
            .define_method("draw_complex_control", &QStyle::drawComplexControl, Arg("cc"), Arg("opt"), Arg("p"), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("draw_control", &QStyle::drawControl, Arg("element"), Arg("opt"), Arg("p"), Arg("w") = static_cast<const QWidget *>(nullptr))
            .define_method("draw_item_pixmap", &QStyle::drawItemPixmap, Arg("painter"), Arg("rect"), Arg("alignment"), Arg("pixmap"))
            .define_method("draw_item_text", &QStyle::drawItemText, Arg("painter"), Arg("rect"), Arg("flags"), Arg("pal"), Arg("enabled"), Arg("text"), Arg("text_role") = static_cast<QPalette::ColorRole>(QPalette::NoRole))
            .define_method("draw_primitive", &QStyle::drawPrimitive, Arg("pe"), Arg("opt"), Arg("p"), Arg("w") = static_cast<const QWidget *>(nullptr))
            .define_method("generated_icon_pixmap", &QStyle::generatedIconPixmap, Arg("icon_mode"), Arg("pixmap"), Arg("opt"))
            .define_method("hit_test_complex_control", &QStyle::hitTestComplexControl, Arg("cc"), Arg("opt"), Arg("pt"), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("item_pixmap_rect", &QStyle::itemPixmapRect, Arg("r"), Arg("flags"), Arg("pixmap"))
            .define_method("item_text_rect", &QStyle::itemTextRect, Arg("fm"), Arg("r"), Arg("flags"), Arg("enabled"), Arg("text"))
            .define_method("layout_spacing", &QStyle::layoutSpacing, Arg("control1"), Arg("control2"), Arg("orientation"), Arg("option") = static_cast<const QStyleOption *>(nullptr), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("name", &QStyle::name)
            .define_method("pixel_metric", &QStyle::pixelMetric, Arg("metric"), Arg("option") = static_cast<const QStyleOption *>(nullptr), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method<void (QStyle::*)(QApplication *)>("polish", &QStyle::polish, Arg("application"))
            .define_method<void (QStyle::*)(QPalette &)>("polish", &QStyle::polish, Arg("palette"))
            .define_method<void (QStyle::*)(QWidget *)>("polish", &QStyle::polish, Arg("widget"))
            .define_method("proxy", &QStyle::proxy)
            .define_method("size_from_contents", &QStyle::sizeFromContents, Arg("ct"), Arg("opt"), Arg("contents_size"), Arg("w") = static_cast<const QWidget *>(nullptr))
            .define_method("standard_icon", &QStyle::standardIcon, Arg("standard_icon"), Arg("option") = static_cast<const QStyleOption *>(nullptr), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("standard_palette", &QStyle::standardPalette)
            .define_method("standard_pixmap", &QStyle::standardPixmap, Arg("standard_pixmap"), Arg("opt") = static_cast<const QStyleOption *>(nullptr), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("style_hint", &QStyle::styleHint, Arg("stylehint"), Arg("opt") = static_cast<const QStyleOption *>(nullptr), Arg("widget") = static_cast<const QWidget *>(nullptr), Arg("return_data") = static_cast<QStyleHintReturn *>(nullptr))
            .define_method("sub_control_rect", &QStyle::subControlRect, Arg("cc"), Arg("opt"), Arg("sc"), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method("sub_element_rect", &QStyle::subElementRect, Arg("sub_element"), Arg("option"), Arg("widget") = static_cast<const QWidget *>(nullptr))
            .define_method<void (QStyle::*)(QApplication *)>("unpolish", &QStyle::unpolish, Arg("application"))
            .define_method<void (QStyle::*)(QWidget *)>("unpolish", &QStyle::unpolish, Arg("widget"))
            // Static Public Members
            .define_singleton_function("aligned_rect", &QStyle::alignedRect, Arg("direction"), Arg("alignment"), Arg("size"), Arg("rectangle"))
            .define_singleton_function("slider_position_from_value", &QStyle::sliderPositionFromValue, Arg("min"), Arg("max"), Arg("val"), Arg("space"), Arg("upside_down") = static_cast<bool>(false))
            .define_singleton_function("slider_value_from_position", &QStyle::sliderValueFromPosition, Arg("min"), Arg("max"), Arg("pos"), Arg("space"), Arg("upside_down") = static_cast<bool>(false))
            .define_singleton_function("visual_alignment", &QStyle::visualAlignment, Arg("direction"), Arg("alignment"))
            .define_singleton_function("visual_pos", &QStyle::visualPos, Arg("direction"), Arg("bounding_rect"), Arg("logical_pos"))
            .define_singleton_function("visual_rect", &QStyle::visualRect, Arg("direction"), Arg("bounding_rect"), Arg("logical_rect"));

    Data_Type<QStyle::StateFlag> rb_cQStyleStateFlag =
        // RubyQt6::QtWidgets::QStyle::StateFlag
        define_qenum_under<QStyle::StateFlag>(rb_cQStyle, "StateFlag");
        define_qenum_value_under(rb_cQStyleStateFlag, "State_None", QStyle::StateFlag::State_None);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Enabled", QStyle::StateFlag::State_Enabled);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Raised", QStyle::StateFlag::State_Raised);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Sunken", QStyle::StateFlag::State_Sunken);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Off", QStyle::StateFlag::State_Off);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_NoChange", QStyle::StateFlag::State_NoChange);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_On", QStyle::StateFlag::State_On);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_DownArrow", QStyle::StateFlag::State_DownArrow);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Horizontal", QStyle::StateFlag::State_Horizontal);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_HasFocus", QStyle::StateFlag::State_HasFocus);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Top", QStyle::StateFlag::State_Top);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Bottom", QStyle::StateFlag::State_Bottom);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_FocusAtBorder", QStyle::StateFlag::State_FocusAtBorder);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_AutoRaise", QStyle::StateFlag::State_AutoRaise);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_MouseOver", QStyle::StateFlag::State_MouseOver);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_UpArrow", QStyle::StateFlag::State_UpArrow);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Selected", QStyle::StateFlag::State_Selected);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Active", QStyle::StateFlag::State_Active);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Window", QStyle::StateFlag::State_Window);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Open", QStyle::StateFlag::State_Open);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Children", QStyle::StateFlag::State_Children);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Item", QStyle::StateFlag::State_Item);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Sibling", QStyle::StateFlag::State_Sibling);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Editing", QStyle::StateFlag::State_Editing);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_KeyboardFocusChange", QStyle::StateFlag::State_KeyboardFocusChange);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_ReadOnly", QStyle::StateFlag::State_ReadOnly);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Small", QStyle::StateFlag::State_Small);
        define_qenum_value_under(rb_cQStyleStateFlag, "State_Mini", QStyle::StateFlag::State_Mini);

    Data_Type<QStyle::PrimitiveElement> rb_cQStylePrimitiveElement =
        // RubyQt6::QtWidgets::QStyle::PrimitiveElement
        define_qenum_under<QStyle::PrimitiveElement>(rb_cQStyle, "PrimitiveElement");
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_Frame", QStyle::PrimitiveElement::PE_Frame);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameDefaultButton", QStyle::PrimitiveElement::PE_FrameDefaultButton);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameDockWidget", QStyle::PrimitiveElement::PE_FrameDockWidget);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameFocusRect", QStyle::PrimitiveElement::PE_FrameFocusRect);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameGroupBox", QStyle::PrimitiveElement::PE_FrameGroupBox);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameLineEdit", QStyle::PrimitiveElement::PE_FrameLineEdit);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameMenu", QStyle::PrimitiveElement::PE_FrameMenu);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameStatusBarItem", QStyle::PrimitiveElement::PE_FrameStatusBarItem);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameTabWidget", QStyle::PrimitiveElement::PE_FrameTabWidget);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameWindow", QStyle::PrimitiveElement::PE_FrameWindow);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameButtonBevel", QStyle::PrimitiveElement::PE_FrameButtonBevel);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameButtonTool", QStyle::PrimitiveElement::PE_FrameButtonTool);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_FrameTabBarBase", QStyle::PrimitiveElement::PE_FrameTabBarBase);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelButtonCommand", QStyle::PrimitiveElement::PE_PanelButtonCommand);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelButtonBevel", QStyle::PrimitiveElement::PE_PanelButtonBevel);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelButtonTool", QStyle::PrimitiveElement::PE_PanelButtonTool);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelMenuBar", QStyle::PrimitiveElement::PE_PanelMenuBar);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelToolBar", QStyle::PrimitiveElement::PE_PanelToolBar);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelLineEdit", QStyle::PrimitiveElement::PE_PanelLineEdit);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorArrowDown", QStyle::PrimitiveElement::PE_IndicatorArrowDown);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorArrowLeft", QStyle::PrimitiveElement::PE_IndicatorArrowLeft);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorArrowRight", QStyle::PrimitiveElement::PE_IndicatorArrowRight);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorArrowUp", QStyle::PrimitiveElement::PE_IndicatorArrowUp);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorBranch", QStyle::PrimitiveElement::PE_IndicatorBranch);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorButtonDropDown", QStyle::PrimitiveElement::PE_IndicatorButtonDropDown);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorItemViewItemCheck", QStyle::PrimitiveElement::PE_IndicatorItemViewItemCheck);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorCheckBox", QStyle::PrimitiveElement::PE_IndicatorCheckBox);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorDockWidgetResizeHandle", QStyle::PrimitiveElement::PE_IndicatorDockWidgetResizeHandle);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorHeaderArrow", QStyle::PrimitiveElement::PE_IndicatorHeaderArrow);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorMenuCheckMark", QStyle::PrimitiveElement::PE_IndicatorMenuCheckMark);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorProgressChunk", QStyle::PrimitiveElement::PE_IndicatorProgressChunk);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorRadioButton", QStyle::PrimitiveElement::PE_IndicatorRadioButton);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorSpinDown", QStyle::PrimitiveElement::PE_IndicatorSpinDown);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorSpinMinus", QStyle::PrimitiveElement::PE_IndicatorSpinMinus);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorSpinPlus", QStyle::PrimitiveElement::PE_IndicatorSpinPlus);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorSpinUp", QStyle::PrimitiveElement::PE_IndicatorSpinUp);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorToolBarHandle", QStyle::PrimitiveElement::PE_IndicatorToolBarHandle);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorToolBarSeparator", QStyle::PrimitiveElement::PE_IndicatorToolBarSeparator);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelTipLabel", QStyle::PrimitiveElement::PE_PanelTipLabel);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorTabTear", QStyle::PrimitiveElement::PE_IndicatorTabTear);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorTabTearLeft", QStyle::PrimitiveElement::PE_IndicatorTabTearLeft);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelScrollAreaCorner", QStyle::PrimitiveElement::PE_PanelScrollAreaCorner);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_Widget", QStyle::PrimitiveElement::PE_Widget);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorColumnViewArrow", QStyle::PrimitiveElement::PE_IndicatorColumnViewArrow);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorItemViewItemDrop", QStyle::PrimitiveElement::PE_IndicatorItemViewItemDrop);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelItemViewItem", QStyle::PrimitiveElement::PE_PanelItemViewItem);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelItemViewRow", QStyle::PrimitiveElement::PE_PanelItemViewRow);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelStatusBar", QStyle::PrimitiveElement::PE_PanelStatusBar);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorTabClose", QStyle::PrimitiveElement::PE_IndicatorTabClose);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_PanelMenu", QStyle::PrimitiveElement::PE_PanelMenu);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_IndicatorTabTearRight", QStyle::PrimitiveElement::PE_IndicatorTabTearRight);
        define_qenum_value_under(rb_cQStylePrimitiveElement, "PE_CustomBase", QStyle::PrimitiveElement::PE_CustomBase);

    Data_Type<QStyle::ControlElement> rb_cQStyleControlElement =
        // RubyQt6::QtWidgets::QStyle::ControlElement
        define_qenum_under<QStyle::ControlElement>(rb_cQStyle, "ControlElement");
        define_qenum_value_under(rb_cQStyleControlElement, "CE_PushButton", QStyle::ControlElement::CE_PushButton);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_PushButtonBevel", QStyle::ControlElement::CE_PushButtonBevel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_PushButtonLabel", QStyle::ControlElement::CE_PushButtonLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_CheckBox", QStyle::ControlElement::CE_CheckBox);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_CheckBoxLabel", QStyle::ControlElement::CE_CheckBoxLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_RadioButton", QStyle::ControlElement::CE_RadioButton);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_RadioButtonLabel", QStyle::ControlElement::CE_RadioButtonLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_TabBarTab", QStyle::ControlElement::CE_TabBarTab);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_TabBarTabShape", QStyle::ControlElement::CE_TabBarTabShape);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_TabBarTabLabel", QStyle::ControlElement::CE_TabBarTabLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ProgressBar", QStyle::ControlElement::CE_ProgressBar);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ProgressBarGroove", QStyle::ControlElement::CE_ProgressBarGroove);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ProgressBarContents", QStyle::ControlElement::CE_ProgressBarContents);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ProgressBarLabel", QStyle::ControlElement::CE_ProgressBarLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuItem", QStyle::ControlElement::CE_MenuItem);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuScroller", QStyle::ControlElement::CE_MenuScroller);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuVMargin", QStyle::ControlElement::CE_MenuVMargin);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuHMargin", QStyle::ControlElement::CE_MenuHMargin);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuTearoff", QStyle::ControlElement::CE_MenuTearoff);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuEmptyArea", QStyle::ControlElement::CE_MenuEmptyArea);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuBarItem", QStyle::ControlElement::CE_MenuBarItem);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_MenuBarEmptyArea", QStyle::ControlElement::CE_MenuBarEmptyArea);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ToolButtonLabel", QStyle::ControlElement::CE_ToolButtonLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_Header", QStyle::ControlElement::CE_Header);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_HeaderSection", QStyle::ControlElement::CE_HeaderSection);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_HeaderLabel", QStyle::ControlElement::CE_HeaderLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ToolBoxTab", QStyle::ControlElement::CE_ToolBoxTab);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_SizeGrip", QStyle::ControlElement::CE_SizeGrip);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_Splitter", QStyle::ControlElement::CE_Splitter);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_RubberBand", QStyle::ControlElement::CE_RubberBand);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_DockWidgetTitle", QStyle::ControlElement::CE_DockWidgetTitle);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarAddLine", QStyle::ControlElement::CE_ScrollBarAddLine);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarSubLine", QStyle::ControlElement::CE_ScrollBarSubLine);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarAddPage", QStyle::ControlElement::CE_ScrollBarAddPage);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarSubPage", QStyle::ControlElement::CE_ScrollBarSubPage);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarSlider", QStyle::ControlElement::CE_ScrollBarSlider);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarFirst", QStyle::ControlElement::CE_ScrollBarFirst);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ScrollBarLast", QStyle::ControlElement::CE_ScrollBarLast);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_FocusFrame", QStyle::ControlElement::CE_FocusFrame);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ComboBoxLabel", QStyle::ControlElement::CE_ComboBoxLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ToolBar", QStyle::ControlElement::CE_ToolBar);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ToolBoxTabShape", QStyle::ControlElement::CE_ToolBoxTabShape);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ToolBoxTabLabel", QStyle::ControlElement::CE_ToolBoxTabLabel);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_HeaderEmptyArea", QStyle::ControlElement::CE_HeaderEmptyArea);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ColumnViewGrip", QStyle::ControlElement::CE_ColumnViewGrip);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ItemViewItem", QStyle::ControlElement::CE_ItemViewItem);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_ShapedFrame", QStyle::ControlElement::CE_ShapedFrame);
        define_qenum_value_under(rb_cQStyleControlElement, "CE_CustomBase", QStyle::ControlElement::CE_CustomBase);

    Data_Type<QStyle::SubElement> rb_cQStyleSubElement =
        // RubyQt6::QtWidgets::QStyle::SubElement
        define_qenum_under<QStyle::SubElement>(rb_cQStyle, "SubElement");
        define_qenum_value_under(rb_cQStyleSubElement, "SE_PushButtonContents", QStyle::SubElement::SE_PushButtonContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_PushButtonFocusRect", QStyle::SubElement::SE_PushButtonFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CheckBoxIndicator", QStyle::SubElement::SE_CheckBoxIndicator);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CheckBoxContents", QStyle::SubElement::SE_CheckBoxContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CheckBoxFocusRect", QStyle::SubElement::SE_CheckBoxFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CheckBoxClickRect", QStyle::SubElement::SE_CheckBoxClickRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_RadioButtonIndicator", QStyle::SubElement::SE_RadioButtonIndicator);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_RadioButtonContents", QStyle::SubElement::SE_RadioButtonContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_RadioButtonFocusRect", QStyle::SubElement::SE_RadioButtonFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_RadioButtonClickRect", QStyle::SubElement::SE_RadioButtonClickRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ComboBoxFocusRect", QStyle::SubElement::SE_ComboBoxFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_SliderFocusRect", QStyle::SubElement::SE_SliderFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ProgressBarGroove", QStyle::SubElement::SE_ProgressBarGroove);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ProgressBarContents", QStyle::SubElement::SE_ProgressBarContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ProgressBarLabel", QStyle::SubElement::SE_ProgressBarLabel);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ToolBoxTabContents", QStyle::SubElement::SE_ToolBoxTabContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_HeaderLabel", QStyle::SubElement::SE_HeaderLabel);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_HeaderArrow", QStyle::SubElement::SE_HeaderArrow);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetTabBar", QStyle::SubElement::SE_TabWidgetTabBar);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetTabPane", QStyle::SubElement::SE_TabWidgetTabPane);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetTabContents", QStyle::SubElement::SE_TabWidgetTabContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetLeftCorner", QStyle::SubElement::SE_TabWidgetLeftCorner);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetRightCorner", QStyle::SubElement::SE_TabWidgetRightCorner);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ItemViewItemCheckIndicator", QStyle::SubElement::SE_ItemViewItemCheckIndicator);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTearIndicator", QStyle::SubElement::SE_TabBarTearIndicator);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTearIndicatorLeft", QStyle::SubElement::SE_TabBarTearIndicatorLeft);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TreeViewDisclosureItem", QStyle::SubElement::SE_TreeViewDisclosureItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_LineEditContents", QStyle::SubElement::SE_LineEditContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_FrameContents", QStyle::SubElement::SE_FrameContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_DockWidgetCloseButton", QStyle::SubElement::SE_DockWidgetCloseButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_DockWidgetFloatButton", QStyle::SubElement::SE_DockWidgetFloatButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_DockWidgetTitleBarText", QStyle::SubElement::SE_DockWidgetTitleBarText);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_DockWidgetIcon", QStyle::SubElement::SE_DockWidgetIcon);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CheckBoxLayoutItem", QStyle::SubElement::SE_CheckBoxLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ComboBoxLayoutItem", QStyle::SubElement::SE_ComboBoxLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_DateTimeEditLayoutItem", QStyle::SubElement::SE_DateTimeEditLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_LabelLayoutItem", QStyle::SubElement::SE_LabelLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ProgressBarLayoutItem", QStyle::SubElement::SE_ProgressBarLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_PushButtonLayoutItem", QStyle::SubElement::SE_PushButtonLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_RadioButtonLayoutItem", QStyle::SubElement::SE_RadioButtonLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_SliderLayoutItem", QStyle::SubElement::SE_SliderLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_SpinBoxLayoutItem", QStyle::SubElement::SE_SpinBoxLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ToolButtonLayoutItem", QStyle::SubElement::SE_ToolButtonLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_FrameLayoutItem", QStyle::SubElement::SE_FrameLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_GroupBoxLayoutItem", QStyle::SubElement::SE_GroupBoxLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabWidgetLayoutItem", QStyle::SubElement::SE_TabWidgetLayoutItem);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ItemViewItemDecoration", QStyle::SubElement::SE_ItemViewItemDecoration);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ItemViewItemText", QStyle::SubElement::SE_ItemViewItemText);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ItemViewItemFocusRect", QStyle::SubElement::SE_ItemViewItemFocusRect);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTabLeftButton", QStyle::SubElement::SE_TabBarTabLeftButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTabRightButton", QStyle::SubElement::SE_TabBarTabRightButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTabText", QStyle::SubElement::SE_TabBarTabText);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ShapedFrameContents", QStyle::SubElement::SE_ShapedFrameContents);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_ToolBarHandle", QStyle::SubElement::SE_ToolBarHandle);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarScrollLeftButton", QStyle::SubElement::SE_TabBarScrollLeftButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarScrollRightButton", QStyle::SubElement::SE_TabBarScrollRightButton);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_TabBarTearIndicatorRight", QStyle::SubElement::SE_TabBarTearIndicatorRight);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_PushButtonBevel", QStyle::SubElement::SE_PushButtonBevel);
        define_qenum_value_under(rb_cQStyleSubElement, "SE_CustomBase", QStyle::SubElement::SE_CustomBase);

    Data_Type<QStyle::ComplexControl> rb_cQStyleComplexControl =
        // RubyQt6::QtWidgets::QStyle::ComplexControl
        define_qenum_under<QStyle::ComplexControl>(rb_cQStyle, "ComplexControl");
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_SpinBox", QStyle::ComplexControl::CC_SpinBox);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_ComboBox", QStyle::ComplexControl::CC_ComboBox);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_ScrollBar", QStyle::ComplexControl::CC_ScrollBar);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_Slider", QStyle::ComplexControl::CC_Slider);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_ToolButton", QStyle::ComplexControl::CC_ToolButton);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_TitleBar", QStyle::ComplexControl::CC_TitleBar);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_Dial", QStyle::ComplexControl::CC_Dial);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_GroupBox", QStyle::ComplexControl::CC_GroupBox);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_MdiControls", QStyle::ComplexControl::CC_MdiControls);
        define_qenum_value_under(rb_cQStyleComplexControl, "CC_CustomBase", QStyle::ComplexControl::CC_CustomBase);

    Data_Type<QStyle::SubControl> rb_cQStyleSubControl =
        // RubyQt6::QtWidgets::QStyle::SubControl
        define_qenum_under<QStyle::SubControl>(rb_cQStyle, "SubControl");
        define_qenum_value_under(rb_cQStyleSubControl, "SC_None", QStyle::SubControl::SC_None);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarAddLine", QStyle::SubControl::SC_ScrollBarAddLine);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarSubLine", QStyle::SubControl::SC_ScrollBarSubLine);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarAddPage", QStyle::SubControl::SC_ScrollBarAddPage);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarSubPage", QStyle::SubControl::SC_ScrollBarSubPage);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarFirst", QStyle::SubControl::SC_ScrollBarFirst);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarLast", QStyle::SubControl::SC_ScrollBarLast);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarSlider", QStyle::SubControl::SC_ScrollBarSlider);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ScrollBarGroove", QStyle::SubControl::SC_ScrollBarGroove);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SpinBoxUp", QStyle::SubControl::SC_SpinBoxUp);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SpinBoxDown", QStyle::SubControl::SC_SpinBoxDown);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SpinBoxFrame", QStyle::SubControl::SC_SpinBoxFrame);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SpinBoxEditField", QStyle::SubControl::SC_SpinBoxEditField);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ComboBoxFrame", QStyle::SubControl::SC_ComboBoxFrame);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ComboBoxEditField", QStyle::SubControl::SC_ComboBoxEditField);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ComboBoxArrow", QStyle::SubControl::SC_ComboBoxArrow);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ComboBoxListBoxPopup", QStyle::SubControl::SC_ComboBoxListBoxPopup);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SliderGroove", QStyle::SubControl::SC_SliderGroove);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SliderHandle", QStyle::SubControl::SC_SliderHandle);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_SliderTickmarks", QStyle::SubControl::SC_SliderTickmarks);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ToolButton", QStyle::SubControl::SC_ToolButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_ToolButtonMenu", QStyle::SubControl::SC_ToolButtonMenu);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarSysMenu", QStyle::SubControl::SC_TitleBarSysMenu);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarMinButton", QStyle::SubControl::SC_TitleBarMinButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarMaxButton", QStyle::SubControl::SC_TitleBarMaxButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarCloseButton", QStyle::SubControl::SC_TitleBarCloseButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarNormalButton", QStyle::SubControl::SC_TitleBarNormalButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarShadeButton", QStyle::SubControl::SC_TitleBarShadeButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarUnshadeButton", QStyle::SubControl::SC_TitleBarUnshadeButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarContextHelpButton", QStyle::SubControl::SC_TitleBarContextHelpButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_TitleBarLabel", QStyle::SubControl::SC_TitleBarLabel);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_DialGroove", QStyle::SubControl::SC_DialGroove);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_DialHandle", QStyle::SubControl::SC_DialHandle);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_DialTickmarks", QStyle::SubControl::SC_DialTickmarks);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_GroupBoxCheckBox", QStyle::SubControl::SC_GroupBoxCheckBox);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_GroupBoxLabel", QStyle::SubControl::SC_GroupBoxLabel);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_GroupBoxContents", QStyle::SubControl::SC_GroupBoxContents);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_GroupBoxFrame", QStyle::SubControl::SC_GroupBoxFrame);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_MdiMinButton", QStyle::SubControl::SC_MdiMinButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_MdiNormalButton", QStyle::SubControl::SC_MdiNormalButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_MdiCloseButton", QStyle::SubControl::SC_MdiCloseButton);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_CustomBase", QStyle::SubControl::SC_CustomBase);
        define_qenum_value_under(rb_cQStyleSubControl, "SC_All", QStyle::SubControl::SC_All);

    Data_Type<QStyle::PixelMetric> rb_cQStylePixelMetric =
        // RubyQt6::QtWidgets::QStyle::PixelMetric
        define_qenum_under<QStyle::PixelMetric>(rb_cQStyle, "PixelMetric");
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ButtonMargin", QStyle::PixelMetric::PM_ButtonMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ButtonDefaultIndicator", QStyle::PixelMetric::PM_ButtonDefaultIndicator);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuButtonIndicator", QStyle::PixelMetric::PM_MenuButtonIndicator);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ButtonShiftHorizontal", QStyle::PixelMetric::PM_ButtonShiftHorizontal);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ButtonShiftVertical", QStyle::PixelMetric::PM_ButtonShiftVertical);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DefaultFrameWidth", QStyle::PixelMetric::PM_DefaultFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SpinBoxFrameWidth", QStyle::PixelMetric::PM_SpinBoxFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ComboBoxFrameWidth", QStyle::PixelMetric::PM_ComboBoxFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MaximumDragDistance", QStyle::PixelMetric::PM_MaximumDragDistance);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ScrollBarExtent", QStyle::PixelMetric::PM_ScrollBarExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ScrollBarSliderMin", QStyle::PixelMetric::PM_ScrollBarSliderMin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SliderThickness", QStyle::PixelMetric::PM_SliderThickness);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SliderControlThickness", QStyle::PixelMetric::PM_SliderControlThickness);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SliderLength", QStyle::PixelMetric::PM_SliderLength);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SliderTickmarkOffset", QStyle::PixelMetric::PM_SliderTickmarkOffset);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SliderSpaceAvailable", QStyle::PixelMetric::PM_SliderSpaceAvailable);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DockWidgetSeparatorExtent", QStyle::PixelMetric::PM_DockWidgetSeparatorExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DockWidgetHandleExtent", QStyle::PixelMetric::PM_DockWidgetHandleExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DockWidgetFrameWidth", QStyle::PixelMetric::PM_DockWidgetFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarTabOverlap", QStyle::PixelMetric::PM_TabBarTabOverlap);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarTabHSpace", QStyle::PixelMetric::PM_TabBarTabHSpace);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarTabVSpace", QStyle::PixelMetric::PM_TabBarTabVSpace);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarBaseHeight", QStyle::PixelMetric::PM_TabBarBaseHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarBaseOverlap", QStyle::PixelMetric::PM_TabBarBaseOverlap);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ProgressBarChunkWidth", QStyle::PixelMetric::PM_ProgressBarChunkWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SplitterWidth", QStyle::PixelMetric::PM_SplitterWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TitleBarHeight", QStyle::PixelMetric::PM_TitleBarHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuScrollerHeight", QStyle::PixelMetric::PM_MenuScrollerHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuHMargin", QStyle::PixelMetric::PM_MenuHMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuVMargin", QStyle::PixelMetric::PM_MenuVMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuPanelWidth", QStyle::PixelMetric::PM_MenuPanelWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuTearoffHeight", QStyle::PixelMetric::PM_MenuTearoffHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuDesktopFrameWidth", QStyle::PixelMetric::PM_MenuDesktopFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuBarPanelWidth", QStyle::PixelMetric::PM_MenuBarPanelWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuBarItemSpacing", QStyle::PixelMetric::PM_MenuBarItemSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuBarVMargin", QStyle::PixelMetric::PM_MenuBarVMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MenuBarHMargin", QStyle::PixelMetric::PM_MenuBarHMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_IndicatorWidth", QStyle::PixelMetric::PM_IndicatorWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_IndicatorHeight", QStyle::PixelMetric::PM_IndicatorHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ExclusiveIndicatorWidth", QStyle::PixelMetric::PM_ExclusiveIndicatorWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ExclusiveIndicatorHeight", QStyle::PixelMetric::PM_ExclusiveIndicatorHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MdiSubWindowFrameWidth", QStyle::PixelMetric::PM_MdiSubWindowFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MdiSubWindowMinimizedWidth", QStyle::PixelMetric::PM_MdiSubWindowMinimizedWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_HeaderMargin", QStyle::PixelMetric::PM_HeaderMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_HeaderMarkSize", QStyle::PixelMetric::PM_HeaderMarkSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_HeaderGripMargin", QStyle::PixelMetric::PM_HeaderGripMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarTabShiftHorizontal", QStyle::PixelMetric::PM_TabBarTabShiftHorizontal);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarTabShiftVertical", QStyle::PixelMetric::PM_TabBarTabShiftVertical);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarScrollButtonWidth", QStyle::PixelMetric::PM_TabBarScrollButtonWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarFrameWidth", QStyle::PixelMetric::PM_ToolBarFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarHandleExtent", QStyle::PixelMetric::PM_ToolBarHandleExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarItemSpacing", QStyle::PixelMetric::PM_ToolBarItemSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarItemMargin", QStyle::PixelMetric::PM_ToolBarItemMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarSeparatorExtent", QStyle::PixelMetric::PM_ToolBarSeparatorExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarExtensionExtent", QStyle::PixelMetric::PM_ToolBarExtensionExtent);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SpinBoxSliderHeight", QStyle::PixelMetric::PM_SpinBoxSliderHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolBarIconSize", QStyle::PixelMetric::PM_ToolBarIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ListViewIconSize", QStyle::PixelMetric::PM_ListViewIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_IconViewIconSize", QStyle::PixelMetric::PM_IconViewIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SmallIconSize", QStyle::PixelMetric::PM_SmallIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LargeIconSize", QStyle::PixelMetric::PM_LargeIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_FocusFrameVMargin", QStyle::PixelMetric::PM_FocusFrameVMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_FocusFrameHMargin", QStyle::PixelMetric::PM_FocusFrameHMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ToolTipLabelFrameWidth", QStyle::PixelMetric::PM_ToolTipLabelFrameWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_CheckBoxLabelSpacing", QStyle::PixelMetric::PM_CheckBoxLabelSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBarIconSize", QStyle::PixelMetric::PM_TabBarIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SizeGripSize", QStyle::PixelMetric::PM_SizeGripSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DockWidgetTitleMargin", QStyle::PixelMetric::PM_DockWidgetTitleMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_MessageBoxIconSize", QStyle::PixelMetric::PM_MessageBoxIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ButtonIconSize", QStyle::PixelMetric::PM_ButtonIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_DockWidgetTitleBarButtonMargin", QStyle::PixelMetric::PM_DockWidgetTitleBarButtonMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_RadioButtonLabelSpacing", QStyle::PixelMetric::PM_RadioButtonLabelSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutLeftMargin", QStyle::PixelMetric::PM_LayoutLeftMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutTopMargin", QStyle::PixelMetric::PM_LayoutTopMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutRightMargin", QStyle::PixelMetric::PM_LayoutRightMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutBottomMargin", QStyle::PixelMetric::PM_LayoutBottomMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutHorizontalSpacing", QStyle::PixelMetric::PM_LayoutHorizontalSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LayoutVerticalSpacing", QStyle::PixelMetric::PM_LayoutVerticalSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabBar_ScrollButtonOverlap", QStyle::PixelMetric::PM_TabBar_ScrollButtonOverlap);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TextCursorWidth", QStyle::PixelMetric::PM_TextCursorWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabCloseIndicatorWidth", QStyle::PixelMetric::PM_TabCloseIndicatorWidth);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TabCloseIndicatorHeight", QStyle::PixelMetric::PM_TabCloseIndicatorHeight);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ScrollView_ScrollBarSpacing", QStyle::PixelMetric::PM_ScrollView_ScrollBarSpacing);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_ScrollView_ScrollBarOverlap", QStyle::PixelMetric::PM_ScrollView_ScrollBarOverlap);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_SubMenuOverlap", QStyle::PixelMetric::PM_SubMenuOverlap);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TreeViewIndentation", QStyle::PixelMetric::PM_TreeViewIndentation);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_HeaderDefaultSectionSizeHorizontal", QStyle::PixelMetric::PM_HeaderDefaultSectionSizeHorizontal);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_HeaderDefaultSectionSizeVertical", QStyle::PixelMetric::PM_HeaderDefaultSectionSizeVertical);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TitleBarButtonIconSize", QStyle::PixelMetric::PM_TitleBarButtonIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_TitleBarButtonSize", QStyle::PixelMetric::PM_TitleBarButtonSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LineEditIconSize", QStyle::PixelMetric::PM_LineEditIconSize);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_LineEditIconMargin", QStyle::PixelMetric::PM_LineEditIconMargin);
        define_qenum_value_under(rb_cQStylePixelMetric, "PM_CustomBase", QStyle::PixelMetric::PM_CustomBase);

    Data_Type<QStyle::ContentsType> rb_cQStyleContentsType =
        // RubyQt6::QtWidgets::QStyle::ContentsType
        define_qenum_under<QStyle::ContentsType>(rb_cQStyle, "ContentsType");
        define_qenum_value_under(rb_cQStyleContentsType, "CT_PushButton", QStyle::ContentsType::CT_PushButton);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_CheckBox", QStyle::ContentsType::CT_CheckBox);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_RadioButton", QStyle::ContentsType::CT_RadioButton);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_ToolButton", QStyle::ContentsType::CT_ToolButton);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_ComboBox", QStyle::ContentsType::CT_ComboBox);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_Splitter", QStyle::ContentsType::CT_Splitter);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_ProgressBar", QStyle::ContentsType::CT_ProgressBar);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_MenuItem", QStyle::ContentsType::CT_MenuItem);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_MenuBarItem", QStyle::ContentsType::CT_MenuBarItem);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_MenuBar", QStyle::ContentsType::CT_MenuBar);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_Menu", QStyle::ContentsType::CT_Menu);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_TabBarTab", QStyle::ContentsType::CT_TabBarTab);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_Slider", QStyle::ContentsType::CT_Slider);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_ScrollBar", QStyle::ContentsType::CT_ScrollBar);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_LineEdit", QStyle::ContentsType::CT_LineEdit);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_SpinBox", QStyle::ContentsType::CT_SpinBox);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_SizeGrip", QStyle::ContentsType::CT_SizeGrip);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_TabWidget", QStyle::ContentsType::CT_TabWidget);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_DialogButtons", QStyle::ContentsType::CT_DialogButtons);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_HeaderSection", QStyle::ContentsType::CT_HeaderSection);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_GroupBox", QStyle::ContentsType::CT_GroupBox);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_MdiControls", QStyle::ContentsType::CT_MdiControls);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_ItemViewItem", QStyle::ContentsType::CT_ItemViewItem);
        define_qenum_value_under(rb_cQStyleContentsType, "CT_CustomBase", QStyle::ContentsType::CT_CustomBase);

    Data_Type<QStyle::RequestSoftwareInputPanel> rb_cQStyleRequestSoftwareInputPanel =
        // RubyQt6::QtWidgets::QStyle::RequestSoftwareInputPanel
        define_qenum_under<QStyle::RequestSoftwareInputPanel>(rb_cQStyle, "RequestSoftwareInputPanel");
        define_qenum_value_under(rb_cQStyleRequestSoftwareInputPanel, "RSIP_OnMouseClickAndAlreadyFocused", QStyle::RequestSoftwareInputPanel::RSIP_OnMouseClickAndAlreadyFocused);
        define_qenum_value_under(rb_cQStyleRequestSoftwareInputPanel, "RSIP_OnMouseClick", QStyle::RequestSoftwareInputPanel::RSIP_OnMouseClick);

    Data_Type<QStyle::StyleHint> rb_cQStyleStyleHint =
        // RubyQt6::QtWidgets::QStyle::StyleHint
        define_qenum_under<QStyle::StyleHint>(rb_cQStyle, "StyleHint");
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_EtchDisabledText", QStyle::StyleHint::SH_EtchDisabledText);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DitherDisabledText", QStyle::StyleHint::SH_DitherDisabledText);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_MiddleClickAbsolutePosition", QStyle::StyleHint::SH_ScrollBar_MiddleClickAbsolutePosition);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_ScrollWhenPointerLeavesControl", QStyle::StyleHint::SH_ScrollBar_ScrollWhenPointerLeavesControl);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_SelectMouseType", QStyle::StyleHint::SH_TabBar_SelectMouseType);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_Alignment", QStyle::StyleHint::SH_TabBar_Alignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Header_ArrowAlignment", QStyle::StyleHint::SH_Header_ArrowAlignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Slider_SnapToValue", QStyle::StyleHint::SH_Slider_SnapToValue);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Slider_SloppyKeyEvents", QStyle::StyleHint::SH_Slider_SloppyKeyEvents);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ProgressDialog_CenterCancelButton", QStyle::StyleHint::SH_ProgressDialog_CenterCancelButton);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ProgressDialog_TextLabelAlignment", QStyle::StyleHint::SH_ProgressDialog_TextLabelAlignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_PrintDialog_RightAlignButtons", QStyle::StyleHint::SH_PrintDialog_RightAlignButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MainWindow_SpaceBelowMenuBar", QStyle::StyleHint::SH_MainWindow_SpaceBelowMenuBar);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FontDialog_SelectAssociatedText", QStyle::StyleHint::SH_FontDialog_SelectAssociatedText);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_AllowActiveAndDisabled", QStyle::StyleHint::SH_Menu_AllowActiveAndDisabled);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SpaceActivatesItem", QStyle::StyleHint::SH_Menu_SpaceActivatesItem);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuPopupDelay", QStyle::StyleHint::SH_Menu_SubMenuPopupDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollView_FrameOnlyAroundContents", QStyle::StyleHint::SH_ScrollView_FrameOnlyAroundContents);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MenuBar_AltKeyNavigation", QStyle::StyleHint::SH_MenuBar_AltKeyNavigation);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_ListMouseTracking", QStyle::StyleHint::SH_ComboBox_ListMouseTracking);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_MouseTracking", QStyle::StyleHint::SH_Menu_MouseTracking);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MenuBar_MouseTracking", QStyle::StyleHint::SH_MenuBar_MouseTracking);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_ChangeHighlightOnFocus", QStyle::StyleHint::SH_ItemView_ChangeHighlightOnFocus);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Widget_ShareActivation", QStyle::StyleHint::SH_Widget_ShareActivation);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Workspace_FillSpaceOnMaximize", QStyle::StyleHint::SH_Workspace_FillSpaceOnMaximize);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_Popup", QStyle::StyleHint::SH_ComboBox_Popup);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TitleBar_NoBorder", QStyle::StyleHint::SH_TitleBar_NoBorder);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Slider_StopMouseOverSlider", QStyle::StyleHint::SH_Slider_StopMouseOverSlider);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_BlinkCursorWhenTextSelected", QStyle::StyleHint::SH_BlinkCursorWhenTextSelected);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_RichText_FullWidthSelection", QStyle::StyleHint::SH_RichText_FullWidthSelection);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_Scrollable", QStyle::StyleHint::SH_Menu_Scrollable);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_GroupBox_TextLabelVerticalAlignment", QStyle::StyleHint::SH_GroupBox_TextLabelVerticalAlignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_GroupBox_TextLabelColor", QStyle::StyleHint::SH_GroupBox_TextLabelColor);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SloppySubMenus", QStyle::StyleHint::SH_Menu_SloppySubMenus);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Table_GridLineColor", QStyle::StyleHint::SH_Table_GridLineColor);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_LineEdit_PasswordCharacter", QStyle::StyleHint::SH_LineEdit_PasswordCharacter);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DialogButtons_DefaultButton", QStyle::StyleHint::SH_DialogButtons_DefaultButton);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolBox_SelectedPageTitleBold", QStyle::StyleHint::SH_ToolBox_SelectedPageTitleBold);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_PreferNoArrows", QStyle::StyleHint::SH_TabBar_PreferNoArrows);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_LeftClickAbsolutePosition", QStyle::StyleHint::SH_ScrollBar_LeftClickAbsolutePosition);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ListViewExpand_SelectMouseType", QStyle::StyleHint::SH_ListViewExpand_SelectMouseType);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_UnderlineShortcut", QStyle::StyleHint::SH_UnderlineShortcut);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_AnimateButton", QStyle::StyleHint::SH_SpinBox_AnimateButton);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_KeyPressAutoRepeatRate", QStyle::StyleHint::SH_SpinBox_KeyPressAutoRepeatRate);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_ClickAutoRepeatRate", QStyle::StyleHint::SH_SpinBox_ClickAutoRepeatRate);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_FillScreenWithScroll", QStyle::StyleHint::SH_Menu_FillScreenWithScroll);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolTipLabel_Opacity", QStyle::StyleHint::SH_ToolTipLabel_Opacity);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DrawMenuBarSeparator", QStyle::StyleHint::SH_DrawMenuBarSeparator);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TitleBar_ModifyNotification", QStyle::StyleHint::SH_TitleBar_ModifyNotification);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Button_FocusPolicy", QStyle::StyleHint::SH_Button_FocusPolicy);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MessageBox_UseBorderForButtonSpacing", QStyle::StyleHint::SH_MessageBox_UseBorderForButtonSpacing);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TitleBar_AutoRaise", QStyle::StyleHint::SH_TitleBar_AutoRaise);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolButton_PopupDelay", QStyle::StyleHint::SH_ToolButton_PopupDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FocusFrame_Mask", QStyle::StyleHint::SH_FocusFrame_Mask);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_RubberBand_Mask", QStyle::StyleHint::SH_RubberBand_Mask);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_WindowFrame_Mask", QStyle::StyleHint::SH_WindowFrame_Mask);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinControls_DisableOnBounds", QStyle::StyleHint::SH_SpinControls_DisableOnBounds);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Dial_BackgroundRole", QStyle::StyleHint::SH_Dial_BackgroundRole);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_LayoutDirection", QStyle::StyleHint::SH_ComboBox_LayoutDirection);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_EllipsisLocation", QStyle::StyleHint::SH_ItemView_EllipsisLocation);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_ShowDecorationSelected", QStyle::StyleHint::SH_ItemView_ShowDecorationSelected);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_ActivateItemOnSingleClick", QStyle::StyleHint::SH_ItemView_ActivateItemOnSingleClick);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_ContextMenu", QStyle::StyleHint::SH_ScrollBar_ContextMenu);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_RollBetweenButtons", QStyle::StyleHint::SH_ScrollBar_RollBetweenButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Slider_AbsoluteSetButtons", QStyle::StyleHint::SH_Slider_AbsoluteSetButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Slider_PageSetButtons", QStyle::StyleHint::SH_Slider_PageSetButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_KeyboardSearch", QStyle::StyleHint::SH_Menu_KeyboardSearch);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_ElideMode", QStyle::StyleHint::SH_TabBar_ElideMode);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DialogButtonLayout", QStyle::StyleHint::SH_DialogButtonLayout);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_PopupFrameStyle", QStyle::StyleHint::SH_ComboBox_PopupFrameStyle);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MessageBox_TextInteractionFlags", QStyle::StyleHint::SH_MessageBox_TextInteractionFlags);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DialogButtonBox_ButtonsHaveIcons", QStyle::StyleHint::SH_DialogButtonBox_ButtonsHaveIcons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_MessageBox_CenterButtons", QStyle::StyleHint::SH_MessageBox_CenterButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SelectionWrap", QStyle::StyleHint::SH_Menu_SelectionWrap);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_MovementWithoutUpdatingSelection", QStyle::StyleHint::SH_ItemView_MovementWithoutUpdatingSelection);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolTip_Mask", QStyle::StyleHint::SH_ToolTip_Mask);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FocusFrame_AboveWidget", QStyle::StyleHint::SH_FocusFrame_AboveWidget);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TextControl_FocusIndicatorTextCharFormat", QStyle::StyleHint::SH_TextControl_FocusIndicatorTextCharFormat);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_WizardStyle", QStyle::StyleHint::SH_WizardStyle);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_ArrowKeysNavigateIntoChildren", QStyle::StyleHint::SH_ItemView_ArrowKeysNavigateIntoChildren);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_Mask", QStyle::StyleHint::SH_Menu_Mask);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_FlashTriggeredItem", QStyle::StyleHint::SH_Menu_FlashTriggeredItem);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_FadeOutOnHide", QStyle::StyleHint::SH_Menu_FadeOutOnHide);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_ClickAutoRepeatThreshold", QStyle::StyleHint::SH_SpinBox_ClickAutoRepeatThreshold);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_PaintAlternatingRowColorsForEmptyArea", QStyle::StyleHint::SH_ItemView_PaintAlternatingRowColorsForEmptyArea);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FormLayoutWrapPolicy", QStyle::StyleHint::SH_FormLayoutWrapPolicy);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabWidget_DefaultTabPosition", QStyle::StyleHint::SH_TabWidget_DefaultTabPosition);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolBar_Movable", QStyle::StyleHint::SH_ToolBar_Movable);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FormLayoutFieldGrowthPolicy", QStyle::StyleHint::SH_FormLayoutFieldGrowthPolicy);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FormLayoutFormAlignment", QStyle::StyleHint::SH_FormLayoutFormAlignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_FormLayoutLabelAlignment", QStyle::StyleHint::SH_FormLayoutLabelAlignment);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_DrawDelegateFrame", QStyle::StyleHint::SH_ItemView_DrawDelegateFrame);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_CloseButtonPosition", QStyle::StyleHint::SH_TabBar_CloseButtonPosition);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_DockWidget_ButtonsHaveFrame", QStyle::StyleHint::SH_DockWidget_ButtonsHaveFrame);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolButtonStyle", QStyle::StyleHint::SH_ToolButtonStyle);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_RequestSoftwareInputPanel", QStyle::StyleHint::SH_RequestSoftwareInputPanel);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ScrollBar_Transient", QStyle::StyleHint::SH_ScrollBar_Transient);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SupportsSections", QStyle::StyleHint::SH_Menu_SupportsSections);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolTip_WakeUpDelay", QStyle::StyleHint::SH_ToolTip_WakeUpDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ToolTip_FallAsleepDelay", QStyle::StyleHint::SH_ToolTip_FallAsleepDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Widget_Animate", QStyle::StyleHint::SH_Widget_Animate);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Splitter_OpaqueResize", QStyle::StyleHint::SH_Splitter_OpaqueResize);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_UseNativePopup", QStyle::StyleHint::SH_ComboBox_UseNativePopup);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_LineEdit_PasswordMaskDelay", QStyle::StyleHint::SH_LineEdit_PasswordMaskDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_ChangeCurrentDelay", QStyle::StyleHint::SH_TabBar_ChangeCurrentDelay);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuUniDirection", QStyle::StyleHint::SH_Menu_SubMenuUniDirection);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuUniDirectionFailCount", QStyle::StyleHint::SH_Menu_SubMenuUniDirectionFailCount);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuSloppySelectOtherActions", QStyle::StyleHint::SH_Menu_SubMenuSloppySelectOtherActions);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuSloppyCloseTimeout", QStyle::StyleHint::SH_Menu_SubMenuSloppyCloseTimeout);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuResetWhenReenteringParent", QStyle::StyleHint::SH_Menu_SubMenuResetWhenReenteringParent);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Menu_SubMenuDontStartSloppyOnLeave", QStyle::StyleHint::SH_Menu_SubMenuDontStartSloppyOnLeave);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ItemView_ScrollMode", QStyle::StyleHint::SH_ItemView_ScrollMode);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TitleBar_ShowToolTipsOnButtons", QStyle::StyleHint::SH_TitleBar_ShowToolTipsOnButtons);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Widget_Animation_Duration", QStyle::StyleHint::SH_Widget_Animation_Duration);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_ComboBox_AllowWheelScrolling", QStyle::StyleHint::SH_ComboBox_AllowWheelScrolling);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_ButtonsInsideFrame", QStyle::StyleHint::SH_SpinBox_ButtonsInsideFrame);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_StepModifier", QStyle::StyleHint::SH_SpinBox_StepModifier);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_TabBar_AllowWheelScrolling", QStyle::StyleHint::SH_TabBar_AllowWheelScrolling);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_Table_AlwaysDrawLeftTopGridLines", QStyle::StyleHint::SH_Table_AlwaysDrawLeftTopGridLines);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_SpinBox_SelectOnStep", QStyle::StyleHint::SH_SpinBox_SelectOnStep);
        define_qenum_value_under(rb_cQStyleStyleHint, "SH_CustomBase", QStyle::StyleHint::SH_CustomBase);

    Data_Type<QStyle::StandardPixmap> rb_cQStyleStandardPixmap =
        // RubyQt6::QtWidgets::QStyle::StandardPixmap
        define_qenum_under<QStyle::StandardPixmap>(rb_cQStyle, "StandardPixmap");
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarMenuButton", QStyle::StandardPixmap::SP_TitleBarMenuButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarMinButton", QStyle::StandardPixmap::SP_TitleBarMinButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarMaxButton", QStyle::StandardPixmap::SP_TitleBarMaxButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarCloseButton", QStyle::StandardPixmap::SP_TitleBarCloseButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarNormalButton", QStyle::StandardPixmap::SP_TitleBarNormalButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarShadeButton", QStyle::StandardPixmap::SP_TitleBarShadeButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarUnshadeButton", QStyle::StandardPixmap::SP_TitleBarUnshadeButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TitleBarContextHelpButton", QStyle::StandardPixmap::SP_TitleBarContextHelpButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DockWidgetCloseButton", QStyle::StandardPixmap::SP_DockWidgetCloseButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MessageBoxInformation", QStyle::StandardPixmap::SP_MessageBoxInformation);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MessageBoxWarning", QStyle::StandardPixmap::SP_MessageBoxWarning);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MessageBoxCritical", QStyle::StandardPixmap::SP_MessageBoxCritical);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MessageBoxQuestion", QStyle::StandardPixmap::SP_MessageBoxQuestion);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DesktopIcon", QStyle::StandardPixmap::SP_DesktopIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TrashIcon", QStyle::StandardPixmap::SP_TrashIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ComputerIcon", QStyle::StandardPixmap::SP_ComputerIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DriveFDIcon", QStyle::StandardPixmap::SP_DriveFDIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DriveHDIcon", QStyle::StandardPixmap::SP_DriveHDIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DriveCDIcon", QStyle::StandardPixmap::SP_DriveCDIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DriveDVDIcon", QStyle::StandardPixmap::SP_DriveDVDIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DriveNetIcon", QStyle::StandardPixmap::SP_DriveNetIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirOpenIcon", QStyle::StandardPixmap::SP_DirOpenIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirClosedIcon", QStyle::StandardPixmap::SP_DirClosedIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirLinkIcon", QStyle::StandardPixmap::SP_DirLinkIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirLinkOpenIcon", QStyle::StandardPixmap::SP_DirLinkOpenIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileIcon", QStyle::StandardPixmap::SP_FileIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileLinkIcon", QStyle::StandardPixmap::SP_FileLinkIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ToolBarHorizontalExtensionButton", QStyle::StandardPixmap::SP_ToolBarHorizontalExtensionButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ToolBarVerticalExtensionButton", QStyle::StandardPixmap::SP_ToolBarVerticalExtensionButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogStart", QStyle::StandardPixmap::SP_FileDialogStart);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogEnd", QStyle::StandardPixmap::SP_FileDialogEnd);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogToParent", QStyle::StandardPixmap::SP_FileDialogToParent);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogNewFolder", QStyle::StandardPixmap::SP_FileDialogNewFolder);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogDetailedView", QStyle::StandardPixmap::SP_FileDialogDetailedView);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogInfoView", QStyle::StandardPixmap::SP_FileDialogInfoView);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogContentsView", QStyle::StandardPixmap::SP_FileDialogContentsView);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogListView", QStyle::StandardPixmap::SP_FileDialogListView);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_FileDialogBack", QStyle::StandardPixmap::SP_FileDialogBack);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirIcon", QStyle::StandardPixmap::SP_DirIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogOkButton", QStyle::StandardPixmap::SP_DialogOkButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogCancelButton", QStyle::StandardPixmap::SP_DialogCancelButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogHelpButton", QStyle::StandardPixmap::SP_DialogHelpButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogOpenButton", QStyle::StandardPixmap::SP_DialogOpenButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogSaveButton", QStyle::StandardPixmap::SP_DialogSaveButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogCloseButton", QStyle::StandardPixmap::SP_DialogCloseButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogApplyButton", QStyle::StandardPixmap::SP_DialogApplyButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogResetButton", QStyle::StandardPixmap::SP_DialogResetButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogDiscardButton", QStyle::StandardPixmap::SP_DialogDiscardButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogYesButton", QStyle::StandardPixmap::SP_DialogYesButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogNoButton", QStyle::StandardPixmap::SP_DialogNoButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowUp", QStyle::StandardPixmap::SP_ArrowUp);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowDown", QStyle::StandardPixmap::SP_ArrowDown);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowLeft", QStyle::StandardPixmap::SP_ArrowLeft);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowRight", QStyle::StandardPixmap::SP_ArrowRight);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowBack", QStyle::StandardPixmap::SP_ArrowBack);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_ArrowForward", QStyle::StandardPixmap::SP_ArrowForward);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DirHomeIcon", QStyle::StandardPixmap::SP_DirHomeIcon);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_CommandLink", QStyle::StandardPixmap::SP_CommandLink);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_VistaShield", QStyle::StandardPixmap::SP_VistaShield);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_BrowserReload", QStyle::StandardPixmap::SP_BrowserReload);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_BrowserStop", QStyle::StandardPixmap::SP_BrowserStop);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaPlay", QStyle::StandardPixmap::SP_MediaPlay);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaStop", QStyle::StandardPixmap::SP_MediaStop);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaPause", QStyle::StandardPixmap::SP_MediaPause);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaSkipForward", QStyle::StandardPixmap::SP_MediaSkipForward);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaSkipBackward", QStyle::StandardPixmap::SP_MediaSkipBackward);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaSeekForward", QStyle::StandardPixmap::SP_MediaSeekForward);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaSeekBackward", QStyle::StandardPixmap::SP_MediaSeekBackward);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaVolume", QStyle::StandardPixmap::SP_MediaVolume);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_MediaVolumeMuted", QStyle::StandardPixmap::SP_MediaVolumeMuted);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_LineEditClearButton", QStyle::StandardPixmap::SP_LineEditClearButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogYesToAllButton", QStyle::StandardPixmap::SP_DialogYesToAllButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogNoToAllButton", QStyle::StandardPixmap::SP_DialogNoToAllButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogSaveAllButton", QStyle::StandardPixmap::SP_DialogSaveAllButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogAbortButton", QStyle::StandardPixmap::SP_DialogAbortButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogRetryButton", QStyle::StandardPixmap::SP_DialogRetryButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_DialogIgnoreButton", QStyle::StandardPixmap::SP_DialogIgnoreButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_RestoreDefaultsButton", QStyle::StandardPixmap::SP_RestoreDefaultsButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_TabCloseButton", QStyle::StandardPixmap::SP_TabCloseButton);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "NStandardPixmap", QStyle::StandardPixmap::NStandardPixmap);
        define_qenum_value_under(rb_cQStyleStandardPixmap, "SP_CustomBase", QStyle::StandardPixmap::SP_CustomBase);

    Data_Type<QFlags<QStyle::StateFlag>> rb_cQStyleState =
        // RubyQt6::QtWidgets::QStyle::State
        define_qflags_under<QStyle::StateFlag>(rb_cQStyle, "State");

    Data_Type<QFlags<QStyle::SubControl>> rb_cQStyleSubControls =
        // RubyQt6::QtWidgets::QStyle::SubControls
        define_qflags_under<QStyle::SubControl>(rb_cQStyle, "SubControls");
}
