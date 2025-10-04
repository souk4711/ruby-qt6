#include "qt-enum-mz-rb.hpp"
#include <qnamespace.h>

using namespace Rice;

void Init_qt_enum_mz(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Enum<Qt::MaskMode> rb_cQtMaskMode =
        // RubyQt6::QtCore::Qt::MaskMode
        define_enum_under<Qt::MaskMode>("MaskMode", rb_mQt)
            .define_value("MaskInColor", Qt::MaskMode::MaskInColor)
            .define_value("MaskOutColor", Qt::MaskMode::MaskOutColor);

    Enum<Qt::MatchFlag> rb_cQtMatchFlag =
        // RubyQt6::QtCore::Qt::MatchFlag
        define_enum_under<Qt::MatchFlag>("MatchFlag", rb_mQt)
            .define_value("MatchExactly", Qt::MatchFlag::MatchExactly)
            .define_value("MatchContains", Qt::MatchFlag::MatchContains)
            .define_value("MatchStartsWith", Qt::MatchFlag::MatchStartsWith)
            .define_value("MatchEndsWith", Qt::MatchFlag::MatchEndsWith)
            .define_value("MatchRegularExpression", Qt::MatchFlag::MatchRegularExpression)
            .define_value("MatchWildcard", Qt::MatchFlag::MatchWildcard)
            .define_value("MatchFixedString", Qt::MatchFlag::MatchFixedString)
            .define_value("MatchTypeMask", Qt::MatchFlag::MatchTypeMask)
            .define_value("MatchCaseSensitive", Qt::MatchFlag::MatchCaseSensitive)
            .define_value("MatchWrap", Qt::MatchFlag::MatchWrap)
            .define_value("MatchRecursive", Qt::MatchFlag::MatchRecursive);

    Enum<Qt::Modifier> rb_cQtModifier =
        // RubyQt6::QtCore::Qt::Modifier
        define_enum_under<Qt::Modifier>("Modifier", rb_mQt)
            .define_value("META", Qt::Modifier::META)
            .define_value("SHIFT", Qt::Modifier::SHIFT)
            .define_value("CTRL", Qt::Modifier::CTRL)
            .define_value("ALT", Qt::Modifier::ALT)
            .define_value("MODIFIER_MASK", Qt::Modifier::MODIFIER_MASK);

    Enum<Qt::MouseButton> rb_cQtMouseButton =
        // RubyQt6::QtCore::Qt::MouseButton
        define_enum_under<Qt::MouseButton>("MouseButton", rb_mQt)
            .define_value("NoButton", Qt::MouseButton::NoButton)
            .define_value("LeftButton", Qt::MouseButton::LeftButton)
            .define_value("RightButton", Qt::MouseButton::RightButton)
            .define_value("MiddleButton", Qt::MouseButton::MiddleButton)
            .define_value("BackButton", Qt::MouseButton::BackButton)
            .define_value("XButton1", Qt::MouseButton::XButton1)
            .define_value("ExtraButton1", Qt::MouseButton::ExtraButton1)
            .define_value("ForwardButton", Qt::MouseButton::ForwardButton)
            .define_value("XButton2", Qt::MouseButton::XButton2)
            .define_value("ExtraButton2", Qt::MouseButton::ExtraButton2)
            .define_value("TaskButton", Qt::MouseButton::TaskButton)
            .define_value("ExtraButton3", Qt::MouseButton::ExtraButton3)
            .define_value("ExtraButton4", Qt::MouseButton::ExtraButton4)
            .define_value("ExtraButton5", Qt::MouseButton::ExtraButton5)
            .define_value("ExtraButton6", Qt::MouseButton::ExtraButton6)
            .define_value("ExtraButton7", Qt::MouseButton::ExtraButton7)
            .define_value("ExtraButton8", Qt::MouseButton::ExtraButton8)
            .define_value("ExtraButton9", Qt::MouseButton::ExtraButton9)
            .define_value("ExtraButton10", Qt::MouseButton::ExtraButton10)
            .define_value("ExtraButton11", Qt::MouseButton::ExtraButton11)
            .define_value("ExtraButton12", Qt::MouseButton::ExtraButton12)
            .define_value("ExtraButton13", Qt::MouseButton::ExtraButton13)
            .define_value("ExtraButton14", Qt::MouseButton::ExtraButton14)
            .define_value("ExtraButton15", Qt::MouseButton::ExtraButton15)
            .define_value("ExtraButton16", Qt::MouseButton::ExtraButton16)
            .define_value("ExtraButton17", Qt::MouseButton::ExtraButton17)
            .define_value("ExtraButton18", Qt::MouseButton::ExtraButton18)
            .define_value("ExtraButton19", Qt::MouseButton::ExtraButton19)
            .define_value("ExtraButton20", Qt::MouseButton::ExtraButton20)
            .define_value("ExtraButton21", Qt::MouseButton::ExtraButton21)
            .define_value("ExtraButton22", Qt::MouseButton::ExtraButton22)
            .define_value("ExtraButton23", Qt::MouseButton::ExtraButton23)
            .define_value("ExtraButton24", Qt::MouseButton::ExtraButton24)
            .define_value("AllButtons", Qt::MouseButton::AllButtons)
            .define_value("MaxMouseButton", Qt::MouseButton::MaxMouseButton)
            .define_value("MouseButtonMask", Qt::MouseButton::MouseButtonMask);

    Enum<Qt::MouseEventFlag> rb_cQtMouseEventFlag =
        // RubyQt6::QtCore::Qt::MouseEventFlag
        define_enum_under<Qt::MouseEventFlag>("MouseEventFlag", rb_mQt)
            .define_value("NoMouseEventFlag", Qt::MouseEventFlag::NoMouseEventFlag)
            .define_value("MouseEventCreatedDoubleClick", Qt::MouseEventFlag::MouseEventCreatedDoubleClick)
            .define_value("MouseEventFlagMask", Qt::MouseEventFlag::MouseEventFlagMask);

    Enum<Qt::MouseEventSource> rb_cQtMouseEventSource =
        // RubyQt6::QtCore::Qt::MouseEventSource
        define_enum_under<Qt::MouseEventSource>("MouseEventSource", rb_mQt)
            .define_value("MouseEventNotSynthesized", Qt::MouseEventSource::MouseEventNotSynthesized)
            .define_value("MouseEventSynthesizedBySystem", Qt::MouseEventSource::MouseEventSynthesizedBySystem)
            .define_value("MouseEventSynthesizedByQt", Qt::MouseEventSource::MouseEventSynthesizedByQt)
            .define_value("MouseEventSynthesizedByApplication", Qt::MouseEventSource::MouseEventSynthesizedByApplication);

    Enum<Qt::NativeGestureType> rb_cQtNativeGestureType =
        // RubyQt6::QtCore::Qt::NativeGestureType
        define_enum_under<Qt::NativeGestureType>("NativeGestureType", rb_mQt)
            .define_value("BeginNativeGesture", Qt::NativeGestureType::BeginNativeGesture)
            .define_value("EndNativeGesture", Qt::NativeGestureType::EndNativeGesture)
            .define_value("PanNativeGesture", Qt::NativeGestureType::PanNativeGesture)
            .define_value("ZoomNativeGesture", Qt::NativeGestureType::ZoomNativeGesture)
            .define_value("SmartZoomNativeGesture", Qt::NativeGestureType::SmartZoomNativeGesture)
            .define_value("RotateNativeGesture", Qt::NativeGestureType::RotateNativeGesture)
            .define_value("SwipeNativeGesture", Qt::NativeGestureType::SwipeNativeGesture);

    Enum<Qt::NavigationMode> rb_cQtNavigationMode =
        // RubyQt6::QtCore::Qt::NavigationMode
        define_enum_under<Qt::NavigationMode>("NavigationMode", rb_mQt)
            .define_value("NavigationModeNone", Qt::NavigationMode::NavigationModeNone)
            .define_value("NavigationModeKeypadTabOrder", Qt::NavigationMode::NavigationModeKeypadTabOrder)
            .define_value("NavigationModeKeypadDirectional", Qt::NavigationMode::NavigationModeKeypadDirectional)
            .define_value("NavigationModeCursorAuto", Qt::NavigationMode::NavigationModeCursorAuto)
            .define_value("NavigationModeCursorForceVisible", Qt::NavigationMode::NavigationModeCursorForceVisible);

    Enum<Qt::Orientation> rb_cQtOrientation =
        // RubyQt6::QtCore::Qt::Orientation
        define_enum_under<Qt::Orientation>("Orientation", rb_mQt)
            .define_value("Horizontal", Qt::Orientation::Horizontal)
            .define_value("Vertical", Qt::Orientation::Vertical);

    Enum<Qt::PenCapStyle> rb_cQtPenCapStyle =
        // RubyQt6::QtCore::Qt::PenCapStyle
        define_enum_under<Qt::PenCapStyle>("PenCapStyle", rb_mQt)
            .define_value("FlatCap", Qt::PenCapStyle::FlatCap)
            .define_value("SquareCap", Qt::PenCapStyle::SquareCap)
            .define_value("RoundCap", Qt::PenCapStyle::RoundCap)
            .define_value("MPenCapStyle", Qt::PenCapStyle::MPenCapStyle);

    Enum<Qt::PenJoinStyle> rb_cQtPenJoinStyle =
        // RubyQt6::QtCore::Qt::PenJoinStyle
        define_enum_under<Qt::PenJoinStyle>("PenJoinStyle", rb_mQt)
            .define_value("MiterJoin", Qt::PenJoinStyle::MiterJoin)
            .define_value("BevelJoin", Qt::PenJoinStyle::BevelJoin)
            .define_value("RoundJoin", Qt::PenJoinStyle::RoundJoin)
            .define_value("SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin)
            .define_value("MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle);

    Enum<Qt::PenStyle> rb_cQtPenStyle =
        // RubyQt6::QtCore::Qt::PenStyle
        define_enum_under<Qt::PenStyle>("PenStyle", rb_mQt)
            .define_value("NoPen", Qt::PenStyle::NoPen)
            .define_value("SolidLine", Qt::PenStyle::SolidLine)
            .define_value("DashLine", Qt::PenStyle::DashLine)
            .define_value("DotLine", Qt::PenStyle::DotLine)
            .define_value("DashDotLine", Qt::PenStyle::DashDotLine)
            .define_value("DashDotDotLine", Qt::PenStyle::DashDotDotLine)
            .define_value("CustomDashLine", Qt::PenStyle::CustomDashLine)
            .define_value("MPenStyle", Qt::PenStyle::MPenStyle);

    Enum<Qt::PermissionStatus> rb_cQtPermissionStatus =
        // RubyQt6::QtCore::Qt::PermissionStatus
        define_enum_under<Qt::PermissionStatus>("PermissionStatus", rb_mQt)
            .define_value("Undetermined", Qt::PermissionStatus::Undetermined)
            .define_value("Granted", Qt::PermissionStatus::Granted)
            .define_value("Denied", Qt::PermissionStatus::Denied);

    Enum<Qt::ScreenOrientation> rb_cQtScreenOrientation =
        // RubyQt6::QtCore::Qt::ScreenOrientation
        define_enum_under<Qt::ScreenOrientation>("ScreenOrientation", rb_mQt)
            .define_value("PrimaryOrientation", Qt::ScreenOrientation::PrimaryOrientation)
            .define_value("PortraitOrientation", Qt::ScreenOrientation::PortraitOrientation)
            .define_value("LandscapeOrientation", Qt::ScreenOrientation::LandscapeOrientation)
            .define_value("InvertedPortraitOrientation", Qt::ScreenOrientation::InvertedPortraitOrientation)
            .define_value("InvertedLandscapeOrientation", Qt::ScreenOrientation::InvertedLandscapeOrientation);

    Enum<Qt::ScrollBarPolicy> rb_cQtScrollBarPolicy =
        // RubyQt6::QtCore::Qt::ScrollBarPolicy
        define_enum_under<Qt::ScrollBarPolicy>("ScrollBarPolicy", rb_mQt)
            .define_value("ScrollBarAsNeeded", Qt::ScrollBarPolicy::ScrollBarAsNeeded)
            .define_value("ScrollBarAlwaysOff", Qt::ScrollBarPolicy::ScrollBarAlwaysOff)
            .define_value("ScrollBarAlwaysOn", Qt::ScrollBarPolicy::ScrollBarAlwaysOn);

    Enum<Qt::ScrollPhase> rb_cQtScrollPhase =
        // RubyQt6::QtCore::Qt::ScrollPhase
        define_enum_under<Qt::ScrollPhase>("ScrollPhase", rb_mQt)
            .define_value("NoScrollPhase", Qt::ScrollPhase::NoScrollPhase)
            .define_value("ScrollBegin", Qt::ScrollPhase::ScrollBegin)
            .define_value("ScrollUpdate", Qt::ScrollPhase::ScrollUpdate)
            .define_value("ScrollEnd", Qt::ScrollPhase::ScrollEnd)
            .define_value("ScrollMomentum", Qt::ScrollPhase::ScrollMomentum);

    Enum<Qt::ShortcutContext> rb_cQtShortcutContext =
        // RubyQt6::QtCore::Qt::ShortcutContext
        define_enum_under<Qt::ShortcutContext>("ShortcutContext", rb_mQt)
            .define_value("WidgetShortcut", Qt::ShortcutContext::WidgetShortcut)
            .define_value("WindowShortcut", Qt::ShortcutContext::WindowShortcut)
            .define_value("ApplicationShortcut", Qt::ShortcutContext::ApplicationShortcut)
            .define_value("WidgetWithChildrenShortcut", Qt::ShortcutContext::WidgetWithChildrenShortcut);

    Enum<Qt::SizeHint> rb_cQtSizeHint =
        // RubyQt6::QtCore::Qt::SizeHint
        define_enum_under<Qt::SizeHint>("SizeHint", rb_mQt)
            .define_value("MinimumSize", Qt::SizeHint::MinimumSize)
            .define_value("PreferredSize", Qt::SizeHint::PreferredSize)
            .define_value("MaximumSize", Qt::SizeHint::MaximumSize)
            .define_value("MinimumDescent", Qt::SizeHint::MinimumDescent)
            .define_value("NSizeHints", Qt::SizeHint::NSizeHints);

    Enum<Qt::SizeMode> rb_cQtSizeMode =
        // RubyQt6::QtCore::Qt::SizeMode
        define_enum_under<Qt::SizeMode>("SizeMode", rb_mQt)
            .define_value("AbsoluteSize", Qt::SizeMode::AbsoluteSize)
            .define_value("RelativeSize", Qt::SizeMode::RelativeSize);

    Enum<Qt::SortOrder> rb_cQtSortOrder =
        // RubyQt6::QtCore::Qt::SortOrder
        define_enum_under<Qt::SortOrder>("SortOrder", rb_mQt)
            .define_value("AscendingOrder", Qt::SortOrder::AscendingOrder)
            .define_value("DescendingOrder", Qt::SortOrder::DescendingOrder);

    Enum<Qt::SplitBehaviorFlags> rb_cQtSplitBehaviorFlags =
        // RubyQt6::QtCore::Qt::SplitBehaviorFlags
        define_enum_under<Qt::SplitBehaviorFlags>("SplitBehaviorFlags", rb_mQt)
            .define_value("KeepEmptyParts", Qt::SplitBehaviorFlags::KeepEmptyParts)
            .define_value("SkipEmptyParts", Qt::SplitBehaviorFlags::SkipEmptyParts);

    Enum<Qt::TabFocusBehavior> rb_cQtTabFocusBehavior =
        // RubyQt6::QtCore::Qt::TabFocusBehavior
        define_enum_under<Qt::TabFocusBehavior>("TabFocusBehavior", rb_mQt)
            .define_value("NoTabFocus", Qt::TabFocusBehavior::NoTabFocus)
            .define_value("TabFocusTextControls", Qt::TabFocusBehavior::TabFocusTextControls)
            .define_value("TabFocusListControls", Qt::TabFocusBehavior::TabFocusListControls)
            .define_value("TabFocusAllControls", Qt::TabFocusBehavior::TabFocusAllControls);

    Enum<Qt::TextElideMode> rb_cQtTextElideMode =
        // RubyQt6::QtCore::Qt::TextElideMode
        define_enum_under<Qt::TextElideMode>("TextElideMode", rb_mQt)
            .define_value("ElideLeft", Qt::TextElideMode::ElideLeft)
            .define_value("ElideRight", Qt::TextElideMode::ElideRight)
            .define_value("ElideMiddle", Qt::TextElideMode::ElideMiddle)
            .define_value("ElideNone", Qt::TextElideMode::ElideNone);

    Enum<Qt::TextFlag> rb_cQtTextFlag =
        // RubyQt6::QtCore::Qt::TextFlag
        define_enum_under<Qt::TextFlag>("TextFlag", rb_mQt)
            .define_value("TextSingleLine", Qt::TextFlag::TextSingleLine)
            .define_value("TextDontClip", Qt::TextFlag::TextDontClip)
            .define_value("TextExpandTabs", Qt::TextFlag::TextExpandTabs)
            .define_value("TextShowMnemonic", Qt::TextFlag::TextShowMnemonic)
            .define_value("TextWordWrap", Qt::TextFlag::TextWordWrap)
            .define_value("TextWrapAnywhere", Qt::TextFlag::TextWrapAnywhere)
            .define_value("TextDontPrint", Qt::TextFlag::TextDontPrint)
            .define_value("TextIncludeTrailingSpaces", Qt::TextFlag::TextIncludeTrailingSpaces)
            .define_value("TextHideMnemonic", Qt::TextFlag::TextHideMnemonic)
            .define_value("TextJustificationForced", Qt::TextFlag::TextJustificationForced)
            .define_value("TextForceLeftToRight", Qt::TextFlag::TextForceLeftToRight)
            .define_value("TextForceRightToLeft", Qt::TextFlag::TextForceRightToLeft)
            .define_value("TextLongestVariant", Qt::TextFlag::TextLongestVariant);

    Enum<Qt::TextFormat> rb_cQtTextFormat =
        // RubyQt6::QtCore::Qt::TextFormat
        define_enum_under<Qt::TextFormat>("TextFormat", rb_mQt)
            .define_value("PlainText", Qt::TextFormat::PlainText)
            .define_value("RichText", Qt::TextFormat::RichText)
            .define_value("AutoText", Qt::TextFormat::AutoText)
            .define_value("MarkdownText", Qt::TextFormat::MarkdownText);

    Enum<Qt::TextInteractionFlag> rb_cQtTextInteractionFlag =
        // RubyQt6::QtCore::Qt::TextInteractionFlag
        define_enum_under<Qt::TextInteractionFlag>("TextInteractionFlag", rb_mQt)
            .define_value("NoTextInteraction", Qt::TextInteractionFlag::NoTextInteraction)
            .define_value("TextSelectableByMouse", Qt::TextInteractionFlag::TextSelectableByMouse)
            .define_value("TextSelectableByKeyboard", Qt::TextInteractionFlag::TextSelectableByKeyboard)
            .define_value("LinksAccessibleByMouse", Qt::TextInteractionFlag::LinksAccessibleByMouse)
            .define_value("LinksAccessibleByKeyboard", Qt::TextInteractionFlag::LinksAccessibleByKeyboard)
            .define_value("TextEditable", Qt::TextInteractionFlag::TextEditable)
            .define_value("TextEditorInteraction", Qt::TextInteractionFlag::TextEditorInteraction)
            .define_value("TextBrowserInteraction", Qt::TextInteractionFlag::TextBrowserInteraction);

    Enum<Qt::TileRule> rb_cQtTileRule =
        // RubyQt6::QtCore::Qt::TileRule
        define_enum_under<Qt::TileRule>("TileRule", rb_mQt)
            .define_value("StretchTile", Qt::TileRule::StretchTile)
            .define_value("RepeatTile", Qt::TileRule::RepeatTile)
            .define_value("RoundTile", Qt::TileRule::RoundTile);

    Enum<Qt::TimeSpec> rb_cQtTimeSpec =
        // RubyQt6::QtCore::Qt::TimeSpec
        define_enum_under<Qt::TimeSpec>("TimeSpec", rb_mQt)
            .define_value("LocalTime", Qt::TimeSpec::LocalTime)
            .define_value("UTC", Qt::TimeSpec::UTC)
            .define_value("OffsetFromUTC", Qt::TimeSpec::OffsetFromUTC)
            .define_value("TimeZone", Qt::TimeSpec::TimeZone);

    Enum<Qt::TimerId> rb_cQtTimerId =
        // RubyQt6::QtCore::Qt::TimerId
        define_enum_under<Qt::TimerId>("TimerId", rb_mQt)
            .define_value("Invalid", Qt::TimerId::Invalid);

    Enum<Qt::TimerType> rb_cQtTimerType =
        // RubyQt6::QtCore::Qt::TimerType
        define_enum_under<Qt::TimerType>("TimerType", rb_mQt)
            .define_value("PreciseTimer", Qt::TimerType::PreciseTimer)
            .define_value("CoarseTimer", Qt::TimerType::CoarseTimer)
            .define_value("VeryCoarseTimer", Qt::TimerType::VeryCoarseTimer);

    Enum<Qt::ToolBarArea> rb_cQtToolBarArea =
        // RubyQt6::QtCore::Qt::ToolBarArea
        define_enum_under<Qt::ToolBarArea>("ToolBarArea", rb_mQt)
            .define_value("LeftToolBarArea", Qt::ToolBarArea::LeftToolBarArea)
            .define_value("RightToolBarArea", Qt::ToolBarArea::RightToolBarArea)
            .define_value("TopToolBarArea", Qt::ToolBarArea::TopToolBarArea)
            .define_value("BottomToolBarArea", Qt::ToolBarArea::BottomToolBarArea)
            .define_value("ToolBarArea_Mask", Qt::ToolBarArea::ToolBarArea_Mask)
            .define_value("AllToolBarAreas", Qt::ToolBarArea::AllToolBarAreas)
            .define_value("NoToolBarArea", Qt::ToolBarArea::NoToolBarArea);

    Enum<Qt::ToolBarAreaSizes> rb_cQtToolBarAreaSizes =
        // RubyQt6::QtCore::Qt::ToolBarAreaSizes
        define_enum_under<Qt::ToolBarAreaSizes>("ToolBarAreaSizes", rb_mQt)
            .define_value("NToolBarAreas", Qt::ToolBarAreaSizes::NToolBarAreas);

    Enum<Qt::ToolButtonStyle> rb_cQtToolButtonStyle =
        // RubyQt6::QtCore::Qt::ToolButtonStyle
        define_enum_under<Qt::ToolButtonStyle>("ToolButtonStyle", rb_mQt)
            .define_value("ToolButtonIconOnly", Qt::ToolButtonStyle::ToolButtonIconOnly)
            .define_value("ToolButtonTextOnly", Qt::ToolButtonStyle::ToolButtonTextOnly)
            .define_value("ToolButtonTextBesideIcon", Qt::ToolButtonStyle::ToolButtonTextBesideIcon)
            .define_value("ToolButtonTextUnderIcon", Qt::ToolButtonStyle::ToolButtonTextUnderIcon)
            .define_value("ToolButtonFollowStyle", Qt::ToolButtonStyle::ToolButtonFollowStyle);

    Enum<Qt::TouchPointState> rb_cQtTouchPointState =
        // RubyQt6::QtCore::Qt::TouchPointState
        define_enum_under<Qt::TouchPointState>("TouchPointState", rb_mQt)
            .define_value("TouchPointUnknownState", Qt::TouchPointState::TouchPointUnknownState)
            .define_value("TouchPointPressed", Qt::TouchPointState::TouchPointPressed)
            .define_value("TouchPointMoved", Qt::TouchPointState::TouchPointMoved)
            .define_value("TouchPointStationary", Qt::TouchPointState::TouchPointStationary)
            .define_value("TouchPointReleased", Qt::TouchPointState::TouchPointReleased);

    Enum<Qt::TransformationMode> rb_cQtTransformationMode =
        // RubyQt6::QtCore::Qt::TransformationMode
        define_enum_under<Qt::TransformationMode>("TransformationMode", rb_mQt)
            .define_value("FastTransformation", Qt::TransformationMode::FastTransformation)
            .define_value("SmoothTransformation", Qt::TransformationMode::SmoothTransformation);

    Enum<Qt::UIEffect> rb_cQtUIEffect =
        // RubyQt6::QtCore::Qt::UIEffect
        define_enum_under<Qt::UIEffect>("UIEffect", rb_mQt)
            .define_value("UI_General", Qt::UIEffect::UI_General)
            .define_value("UI_AnimateMenu", Qt::UIEffect::UI_AnimateMenu)
            .define_value("UI_FadeMenu", Qt::UIEffect::UI_FadeMenu)
            .define_value("UI_AnimateCombo", Qt::UIEffect::UI_AnimateCombo)
            .define_value("UI_AnimateTooltip", Qt::UIEffect::UI_AnimateTooltip)
            .define_value("UI_FadeTooltip", Qt::UIEffect::UI_FadeTooltip)
            .define_value("UI_AnimateToolBox", Qt::UIEffect::UI_AnimateToolBox);

    Enum<Qt::WhiteSpaceMode> rb_cQtWhiteSpaceMode =
        // RubyQt6::QtCore::Qt::WhiteSpaceMode
        define_enum_under<Qt::WhiteSpaceMode>("WhiteSpaceMode", rb_mQt)
            .define_value("WhiteSpaceNormal", Qt::WhiteSpaceMode::WhiteSpaceNormal)
            .define_value("WhiteSpacePre", Qt::WhiteSpaceMode::WhiteSpacePre)
            .define_value("WhiteSpaceNoWrap", Qt::WhiteSpaceMode::WhiteSpaceNoWrap)
            .define_value("WhiteSpaceModeUndefined", Qt::WhiteSpaceMode::WhiteSpaceModeUndefined);

    Enum<Qt::WidgetAttribute> rb_cQtWidgetAttribute =
        // RubyQt6::QtCore::Qt::WidgetAttribute
        define_enum_under<Qt::WidgetAttribute>("WidgetAttribute", rb_mQt)
            .define_value("WA_Disabled", Qt::WidgetAttribute::WA_Disabled)
            .define_value("WA_UnderMouse", Qt::WidgetAttribute::WA_UnderMouse)
            .define_value("WA_MouseTracking", Qt::WidgetAttribute::WA_MouseTracking)
            .define_value("WA_OpaquePaintEvent", Qt::WidgetAttribute::WA_OpaquePaintEvent)
            .define_value("WA_StaticContents", Qt::WidgetAttribute::WA_StaticContents)
            .define_value("WA_LaidOut", Qt::WidgetAttribute::WA_LaidOut)
            .define_value("WA_PaintOnScreen", Qt::WidgetAttribute::WA_PaintOnScreen)
            .define_value("WA_NoSystemBackground", Qt::WidgetAttribute::WA_NoSystemBackground)
            .define_value("WA_UpdatesDisabled", Qt::WidgetAttribute::WA_UpdatesDisabled)
            .define_value("WA_Mapped", Qt::WidgetAttribute::WA_Mapped)
            .define_value("WA_InputMethodEnabled", Qt::WidgetAttribute::WA_InputMethodEnabled)
            .define_value("WA_WState_Visible", Qt::WidgetAttribute::WA_WState_Visible)
            .define_value("WA_WState_Hidden", Qt::WidgetAttribute::WA_WState_Hidden)
            .define_value("WA_ForceDisabled", Qt::WidgetAttribute::WA_ForceDisabled)
            .define_value("WA_KeyCompression", Qt::WidgetAttribute::WA_KeyCompression)
            .define_value("WA_PendingMoveEvent", Qt::WidgetAttribute::WA_PendingMoveEvent)
            .define_value("WA_PendingResizeEvent", Qt::WidgetAttribute::WA_PendingResizeEvent)
            .define_value("WA_SetPalette", Qt::WidgetAttribute::WA_SetPalette)
            .define_value("WA_SetFont", Qt::WidgetAttribute::WA_SetFont)
            .define_value("WA_SetCursor", Qt::WidgetAttribute::WA_SetCursor)
            .define_value("WA_NoChildEventsFromChildren", Qt::WidgetAttribute::WA_NoChildEventsFromChildren)
            .define_value("WA_WindowModified", Qt::WidgetAttribute::WA_WindowModified)
            .define_value("WA_Resized", Qt::WidgetAttribute::WA_Resized)
            .define_value("WA_Moved", Qt::WidgetAttribute::WA_Moved)
            .define_value("WA_PendingUpdate", Qt::WidgetAttribute::WA_PendingUpdate)
            .define_value("WA_InvalidSize", Qt::WidgetAttribute::WA_InvalidSize)
            .define_value("WA_CustomWhatsThis", Qt::WidgetAttribute::WA_CustomWhatsThis)
            .define_value("WA_LayoutOnEntireRect", Qt::WidgetAttribute::WA_LayoutOnEntireRect)
            .define_value("WA_OutsideWSRange", Qt::WidgetAttribute::WA_OutsideWSRange)
            .define_value("WA_GrabbedShortcut", Qt::WidgetAttribute::WA_GrabbedShortcut)
            .define_value("WA_TransparentForMouseEvents", Qt::WidgetAttribute::WA_TransparentForMouseEvents)
            .define_value("WA_PaintUnclipped", Qt::WidgetAttribute::WA_PaintUnclipped)
            .define_value("WA_SetWindowIcon", Qt::WidgetAttribute::WA_SetWindowIcon)
            .define_value("WA_NoMouseReplay", Qt::WidgetAttribute::WA_NoMouseReplay)
            .define_value("WA_DeleteOnClose", Qt::WidgetAttribute::WA_DeleteOnClose)
            .define_value("WA_RightToLeft", Qt::WidgetAttribute::WA_RightToLeft)
            .define_value("WA_SetLayoutDirection", Qt::WidgetAttribute::WA_SetLayoutDirection)
            .define_value("WA_NoChildEventsForParent", Qt::WidgetAttribute::WA_NoChildEventsForParent)
            .define_value("WA_ForceUpdatesDisabled", Qt::WidgetAttribute::WA_ForceUpdatesDisabled)
            .define_value("WA_WState_Created", Qt::WidgetAttribute::WA_WState_Created)
            .define_value("WA_WState_CompressKeys", Qt::WidgetAttribute::WA_WState_CompressKeys)
            .define_value("WA_WState_InPaintEvent", Qt::WidgetAttribute::WA_WState_InPaintEvent)
            .define_value("WA_WState_Reparented", Qt::WidgetAttribute::WA_WState_Reparented)
            .define_value("WA_WState_ConfigPending", Qt::WidgetAttribute::WA_WState_ConfigPending)
            .define_value("WA_WState_Polished", Qt::WidgetAttribute::WA_WState_Polished)
            .define_value("WA_WState_OwnSizePolicy", Qt::WidgetAttribute::WA_WState_OwnSizePolicy)
            .define_value("WA_WState_ExplicitShowHide", Qt::WidgetAttribute::WA_WState_ExplicitShowHide)
            .define_value("WA_ShowModal", Qt::WidgetAttribute::WA_ShowModal)
            .define_value("WA_MouseNoMask", Qt::WidgetAttribute::WA_MouseNoMask)
            .define_value("WA_NoMousePropagation", Qt::WidgetAttribute::WA_NoMousePropagation)
            .define_value("WA_Hover", Qt::WidgetAttribute::WA_Hover)
            .define_value("WA_InputMethodTransparent", Qt::WidgetAttribute::WA_InputMethodTransparent)
            .define_value("WA_QuitOnClose", Qt::WidgetAttribute::WA_QuitOnClose)
            .define_value("WA_KeyboardFocusChange", Qt::WidgetAttribute::WA_KeyboardFocusChange)
            .define_value("WA_AcceptDrops", Qt::WidgetAttribute::WA_AcceptDrops)
            .define_value("WA_DropSiteRegistered", Qt::WidgetAttribute::WA_DropSiteRegistered)
            .define_value("WA_WindowPropagation", Qt::WidgetAttribute::WA_WindowPropagation)
            .define_value("WA_NoX11EventCompression", Qt::WidgetAttribute::WA_NoX11EventCompression)
            .define_value("WA_TintedBackground", Qt::WidgetAttribute::WA_TintedBackground)
            .define_value("WA_X11OpenGLOverlay", Qt::WidgetAttribute::WA_X11OpenGLOverlay)
            .define_value("WA_AlwaysShowToolTips", Qt::WidgetAttribute::WA_AlwaysShowToolTips)
            .define_value("WA_MacOpaqueSizeGrip", Qt::WidgetAttribute::WA_MacOpaqueSizeGrip)
            .define_value("WA_SetStyle", Qt::WidgetAttribute::WA_SetStyle)
            .define_value("WA_SetLocale", Qt::WidgetAttribute::WA_SetLocale)
            .define_value("WA_MacShowFocusRect", Qt::WidgetAttribute::WA_MacShowFocusRect)
            .define_value("WA_MacNormalSize", Qt::WidgetAttribute::WA_MacNormalSize)
            .define_value("WA_MacSmallSize", Qt::WidgetAttribute::WA_MacSmallSize)
            .define_value("WA_MacMiniSize", Qt::WidgetAttribute::WA_MacMiniSize)
            .define_value("WA_LayoutUsesWidgetRect", Qt::WidgetAttribute::WA_LayoutUsesWidgetRect)
            .define_value("WA_StyledBackground", Qt::WidgetAttribute::WA_StyledBackground)
            .define_value("WA_CanHostQMdiSubWindowTitleBar", Qt::WidgetAttribute::WA_CanHostQMdiSubWindowTitleBar)
            .define_value("WA_MacAlwaysShowToolWindow", Qt::WidgetAttribute::WA_MacAlwaysShowToolWindow)
            .define_value("WA_StyleSheet", Qt::WidgetAttribute::WA_StyleSheet)
            .define_value("WA_ShowWithoutActivating", Qt::WidgetAttribute::WA_ShowWithoutActivating)
            .define_value("WA_X11BypassTransientForHint", Qt::WidgetAttribute::WA_X11BypassTransientForHint)
            .define_value("WA_NativeWindow", Qt::WidgetAttribute::WA_NativeWindow)
            .define_value("WA_DontCreateNativeAncestors", Qt::WidgetAttribute::WA_DontCreateNativeAncestors)
            .define_value("WA_DontShowOnScreen", Qt::WidgetAttribute::WA_DontShowOnScreen)
            .define_value("WA_X11NetWmWindowTypeDesktop", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDesktop)
            .define_value("WA_X11NetWmWindowTypeDock", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDock)
            .define_value("WA_X11NetWmWindowTypeToolBar", Qt::WidgetAttribute::WA_X11NetWmWindowTypeToolBar)
            .define_value("WA_X11NetWmWindowTypeMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypeMenu)
            .define_value("WA_X11NetWmWindowTypeUtility", Qt::WidgetAttribute::WA_X11NetWmWindowTypeUtility)
            .define_value("WA_X11NetWmWindowTypeSplash", Qt::WidgetAttribute::WA_X11NetWmWindowTypeSplash)
            .define_value("WA_X11NetWmWindowTypeDialog", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDialog)
            .define_value("WA_X11NetWmWindowTypeDropDownMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDropDownMenu)
            .define_value("WA_X11NetWmWindowTypePopupMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypePopupMenu)
            .define_value("WA_X11NetWmWindowTypeToolTip", Qt::WidgetAttribute::WA_X11NetWmWindowTypeToolTip)
            .define_value("WA_X11NetWmWindowTypeNotification", Qt::WidgetAttribute::WA_X11NetWmWindowTypeNotification)
            .define_value("WA_X11NetWmWindowTypeCombo", Qt::WidgetAttribute::WA_X11NetWmWindowTypeCombo)
            .define_value("WA_X11NetWmWindowTypeDND", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDND)
            .define_value("WA_SetWindowModality", Qt::WidgetAttribute::WA_SetWindowModality)
            .define_value("WA_WState_WindowOpacitySet", Qt::WidgetAttribute::WA_WState_WindowOpacitySet)
            .define_value("WA_TranslucentBackground", Qt::WidgetAttribute::WA_TranslucentBackground)
            .define_value("WA_AcceptTouchEvents", Qt::WidgetAttribute::WA_AcceptTouchEvents)
            .define_value("WA_WState_AcceptedTouchBeginEvent", Qt::WidgetAttribute::WA_WState_AcceptedTouchBeginEvent)
            .define_value("WA_TouchPadAcceptSingleTouchEvents", Qt::WidgetAttribute::WA_TouchPadAcceptSingleTouchEvents)
            .define_value("WA_X11DoNotAcceptFocus", Qt::WidgetAttribute::WA_X11DoNotAcceptFocus)
            .define_value("WA_AlwaysStackOnTop", Qt::WidgetAttribute::WA_AlwaysStackOnTop)
            .define_value("WA_TabletTracking", Qt::WidgetAttribute::WA_TabletTracking)
            .define_value("WA_ContentsMarginsRespectsSafeArea", Qt::WidgetAttribute::WA_ContentsMarginsRespectsSafeArea)
            .define_value("WA_StyleSheetTarget", Qt::WidgetAttribute::WA_StyleSheetTarget)
            .define_value("WA_AttributeCount", Qt::WidgetAttribute::WA_AttributeCount);

    Enum<Qt::WindowFrameSection> rb_cQtWindowFrameSection =
        // RubyQt6::QtCore::Qt::WindowFrameSection
        define_enum_under<Qt::WindowFrameSection>("WindowFrameSection", rb_mQt)
            .define_value("NoSection", Qt::WindowFrameSection::NoSection)
            .define_value("LeftSection", Qt::WindowFrameSection::LeftSection)
            .define_value("TopLeftSection", Qt::WindowFrameSection::TopLeftSection)
            .define_value("TopSection", Qt::WindowFrameSection::TopSection)
            .define_value("TopRightSection", Qt::WindowFrameSection::TopRightSection)
            .define_value("RightSection", Qt::WindowFrameSection::RightSection)
            .define_value("BottomRightSection", Qt::WindowFrameSection::BottomRightSection)
            .define_value("BottomSection", Qt::WindowFrameSection::BottomSection)
            .define_value("BottomLeftSection", Qt::WindowFrameSection::BottomLeftSection)
            .define_value("TitleBarArea", Qt::WindowFrameSection::TitleBarArea);

    Enum<Qt::WindowModality> rb_cQtWindowModality =
        // RubyQt6::QtCore::Qt::WindowModality
        define_enum_under<Qt::WindowModality>("WindowModality", rb_mQt)
            .define_value("NonModal", Qt::WindowModality::NonModal)
            .define_value("WindowModal", Qt::WindowModality::WindowModal)
            .define_value("ApplicationModal", Qt::WindowModality::ApplicationModal);

    Enum<Qt::WindowState> rb_cQtWindowState =
        // RubyQt6::QtCore::Qt::WindowState
        define_enum_under<Qt::WindowState>("WindowState", rb_mQt)
            .define_value("WindowNoState", Qt::WindowState::WindowNoState)
            .define_value("WindowMinimized", Qt::WindowState::WindowMinimized)
            .define_value("WindowMaximized", Qt::WindowState::WindowMaximized)
            .define_value("WindowFullScreen", Qt::WindowState::WindowFullScreen)
            .define_value("WindowActive", Qt::WindowState::WindowActive);

    Enum<Qt::WindowType> rb_cQtWindowType =
        // RubyQt6::QtCore::Qt::WindowType
        define_enum_under<Qt::WindowType>("WindowType", rb_mQt)
            .define_value("Widget", Qt::WindowType::Widget)
            .define_value("Window", Qt::WindowType::Window)
            .define_value("Dialog", Qt::WindowType::Dialog)
            .define_value("Sheet", Qt::WindowType::Sheet)
            .define_value("Drawer", Qt::WindowType::Drawer)
            .define_value("Popup", Qt::WindowType::Popup)
            .define_value("Tool", Qt::WindowType::Tool)
            .define_value("ToolTip", Qt::WindowType::ToolTip)
            .define_value("SplashScreen", Qt::WindowType::SplashScreen)
            .define_value("Desktop", Qt::WindowType::Desktop)
            .define_value("SubWindow", Qt::WindowType::SubWindow)
            .define_value("ForeignWindow", Qt::WindowType::ForeignWindow)
            .define_value("CoverWindow", Qt::WindowType::CoverWindow)
            .define_value("WindowType_Mask", Qt::WindowType::WindowType_Mask)
            .define_value("MSWindowsFixedSizeDialogHint", Qt::WindowType::MSWindowsFixedSizeDialogHint)
            .define_value("MSWindowsOwnDC", Qt::WindowType::MSWindowsOwnDC)
            .define_value("BypassWindowManagerHint", Qt::WindowType::BypassWindowManagerHint)
            .define_value("X11BypassWindowManagerHint", Qt::WindowType::X11BypassWindowManagerHint)
            .define_value("FramelessWindowHint", Qt::WindowType::FramelessWindowHint)
            .define_value("WindowTitleHint", Qt::WindowType::WindowTitleHint)
            .define_value("WindowSystemMenuHint", Qt::WindowType::WindowSystemMenuHint)
            .define_value("WindowMinimizeButtonHint", Qt::WindowType::WindowMinimizeButtonHint)
            .define_value("WindowMaximizeButtonHint", Qt::WindowType::WindowMaximizeButtonHint)
            .define_value("WindowMinMaxButtonsHint", Qt::WindowType::WindowMinMaxButtonsHint)
            .define_value("WindowContextHelpButtonHint", Qt::WindowType::WindowContextHelpButtonHint)
            .define_value("WindowShadeButtonHint", Qt::WindowType::WindowShadeButtonHint)
            .define_value("WindowStaysOnTopHint", Qt::WindowType::WindowStaysOnTopHint)
            .define_value("WindowTransparentForInput", Qt::WindowType::WindowTransparentForInput)
            .define_value("WindowOverridesSystemGestures", Qt::WindowType::WindowOverridesSystemGestures)
            .define_value("WindowDoesNotAcceptFocus", Qt::WindowType::WindowDoesNotAcceptFocus)
            .define_value("ExpandedClientAreaHint", Qt::WindowType::ExpandedClientAreaHint)
            .define_value("NoTitleBarBackgroundHint", Qt::WindowType::NoTitleBarBackgroundHint)
            .define_value("CustomizeWindowHint", Qt::WindowType::CustomizeWindowHint)
            .define_value("WindowStaysOnBottomHint", Qt::WindowType::WindowStaysOnBottomHint)
            .define_value("WindowCloseButtonHint", Qt::WindowType::WindowCloseButtonHint)
            .define_value("BypassGraphicsProxyWidget", Qt::WindowType::BypassGraphicsProxyWidget)
            .define_value("NoDropShadowWindowHint", Qt::WindowType::NoDropShadowWindowHint)
            .define_value("WindowFullscreenButtonHint", Qt::WindowType::WindowFullscreenButtonHint);
}
