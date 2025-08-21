// clang-format off

#include "qt-rb.hpp"
#include <qnamespace.h>

using namespace Rice;

void Init_qt(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // Qt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Enum<Qt::GlobalColor> rb_cQtGlobalColor =
        // Qt6::QtCore::Qt::GlobalColor
        define_enum_under<Qt::GlobalColor>("GlobalColor", rb_mQt)
            .define_value("color0", Qt::GlobalColor::color0)
            .define_value("color1", Qt::GlobalColor::color1)
            .define_value("black", Qt::GlobalColor::black)
            .define_value("white", Qt::GlobalColor::white)
            .define_value("darkGray", Qt::GlobalColor::darkGray)
            .define_value("gray", Qt::GlobalColor::gray)
            .define_value("lightGray", Qt::GlobalColor::lightGray)
            .define_value("red", Qt::GlobalColor::red)
            .define_value("green", Qt::GlobalColor::green)
            .define_value("blue", Qt::GlobalColor::blue)
            .define_value("cyan", Qt::GlobalColor::cyan)
            .define_value("magenta", Qt::GlobalColor::magenta)
            .define_value("yellow", Qt::GlobalColor::yellow)
            .define_value("darkRed", Qt::GlobalColor::darkRed)
            .define_value("darkGreen", Qt::GlobalColor::darkGreen)
            .define_value("darkBlue", Qt::GlobalColor::darkBlue)
            .define_value("darkCyan", Qt::GlobalColor::darkCyan)
            .define_value("darkMagenta", Qt::GlobalColor::darkMagenta)
            .define_value("darkYellow", Qt::GlobalColor::darkYellow)
            .define_value("transparent", Qt::GlobalColor::transparent);

    Enum<Qt::ColorScheme> rb_cQtColorScheme =
        // Qt6::QtCore::Qt::ColorScheme
        define_enum_under<Qt::ColorScheme>("ColorScheme", rb_mQt)
            .define_value("Unknown", Qt::ColorScheme::Unknown)
            .define_value("Light", Qt::ColorScheme::Light)
            .define_value("Dark", Qt::ColorScheme::Dark);

    Enum<Qt::MouseButton> rb_cQtMouseButton =
        // Qt6::QtCore::Qt::MouseButton
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

    Enum<Qt::Orientation> rb_cQtOrientation =
        // Qt6::QtCore::Qt::Orientation
        define_enum_under<Qt::Orientation>("Orientation", rb_mQt)
            .define_value("Horizontal", Qt::Orientation::Horizontal)
            .define_value("Vertical", Qt::Orientation::Vertical);

    Enum<Qt::FocusPolicy> rb_cQtFocusPolicy =
        // Qt6::QtCore::Qt::FocusPolicy
        define_enum_under<Qt::FocusPolicy>("FocusPolicy", rb_mQt)
            .define_value("NoFocus", Qt::FocusPolicy::NoFocus)
            .define_value("TabFocus", Qt::FocusPolicy::TabFocus)
            .define_value("ClickFocus", Qt::FocusPolicy::ClickFocus)
            .define_value("StrongFocus", Qt::FocusPolicy::StrongFocus)
            .define_value("WheelFocus", Qt::FocusPolicy::WheelFocus);

    Enum<Qt::TabFocusBehavior> rb_cQtTabFocusBehavior =
        // Qt6::QtCore::Qt::TabFocusBehavior
        define_enum_under<Qt::TabFocusBehavior>("TabFocusBehavior", rb_mQt)
            .define_value("NoTabFocus", Qt::TabFocusBehavior::NoTabFocus)
            .define_value("TabFocusTextControls", Qt::TabFocusBehavior::TabFocusTextControls)
            .define_value("TabFocusListControls", Qt::TabFocusBehavior::TabFocusListControls)
            .define_value("TabFocusAllControls", Qt::TabFocusBehavior::TabFocusAllControls);

    Enum<Qt::SortOrder> rb_cQtSortOrder =
        // Qt6::QtCore::Qt::SortOrder
        define_enum_under<Qt::SortOrder>("SortOrder", rb_mQt)
            .define_value("AscendingOrder", Qt::SortOrder::AscendingOrder)
            .define_value("DescendingOrder", Qt::SortOrder::DescendingOrder);

    Enum<Qt::SplitBehaviorFlags> rb_cQtSplitBehaviorFlags =
        // Qt6::QtCore::Qt::SplitBehaviorFlags
        define_enum_under<Qt::SplitBehaviorFlags>("SplitBehaviorFlags", rb_mQt)
            .define_value("KeepEmptyParts", Qt::SplitBehaviorFlags::KeepEmptyParts)
            .define_value("SkipEmptyParts", Qt::SplitBehaviorFlags::SkipEmptyParts);

    Enum<Qt::TileRule> rb_cQtTileRule =
        // Qt6::QtCore::Qt::TileRule
        define_enum_under<Qt::TileRule>("TileRule", rb_mQt)
            .define_value("StretchTile", Qt::TileRule::StretchTile)
            .define_value("RepeatTile", Qt::TileRule::RepeatTile)
            .define_value("RoundTile", Qt::TileRule::RoundTile);

    Enum<Qt::AlignmentFlag> rb_cQtAlignmentFlag =
        // Qt6::QtCore::Qt::AlignmentFlag
        define_enum_under<Qt::AlignmentFlag>("AlignmentFlag", rb_mQt)
            .define_value("AlignLeft", Qt::AlignmentFlag::AlignLeft)
            .define_value("AlignLeading", Qt::AlignmentFlag::AlignLeading)
            .define_value("AlignRight", Qt::AlignmentFlag::AlignRight)
            .define_value("AlignTrailing", Qt::AlignmentFlag::AlignTrailing)
            .define_value("AlignHCenter", Qt::AlignmentFlag::AlignHCenter)
            .define_value("AlignJustify", Qt::AlignmentFlag::AlignJustify)
            .define_value("AlignAbsolute", Qt::AlignmentFlag::AlignAbsolute)
            .define_value("AlignHorizontal_Mask", Qt::AlignmentFlag::AlignHorizontal_Mask)
            .define_value("AlignTop", Qt::AlignmentFlag::AlignTop)
            .define_value("AlignBottom", Qt::AlignmentFlag::AlignBottom)
            .define_value("AlignVCenter", Qt::AlignmentFlag::AlignVCenter)
            .define_value("AlignBaseline", Qt::AlignmentFlag::AlignBaseline)
            .define_value("AlignVertical_Mask", Qt::AlignmentFlag::AlignVertical_Mask)
            .define_value("AlignCenter", Qt::AlignmentFlag::AlignCenter);

    Enum<Qt::TextFlag> rb_cQtTextFlag =
        // Qt6::QtCore::Qt::TextFlag
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

    Enum<Qt::TextElideMode> rb_cQtTextElideMode =
        // Qt6::QtCore::Qt::TextElideMode
        define_enum_under<Qt::TextElideMode>("TextElideMode", rb_mQt)
            .define_value("ElideLeft", Qt::TextElideMode::ElideLeft)
            .define_value("ElideRight", Qt::TextElideMode::ElideRight)
            .define_value("ElideMiddle", Qt::TextElideMode::ElideMiddle)
            .define_value("ElideNone", Qt::TextElideMode::ElideNone);

    Enum<Qt::WhiteSpaceMode> rb_cQtWhiteSpaceMode =
        // Qt6::QtCore::Qt::WhiteSpaceMode
        define_enum_under<Qt::WhiteSpaceMode>("WhiteSpaceMode", rb_mQt)
            .define_value("WhiteSpaceNormal", Qt::WhiteSpaceMode::WhiteSpaceNormal)
            .define_value("WhiteSpacePre", Qt::WhiteSpaceMode::WhiteSpacePre)
            .define_value("WhiteSpaceNoWrap", Qt::WhiteSpaceMode::WhiteSpaceNoWrap)
            .define_value("WhiteSpaceModeUndefined", Qt::WhiteSpaceMode::WhiteSpaceModeUndefined);

    Enum<Qt::HitTestAccuracy> rb_cQtHitTestAccuracy =
        // Qt6::QtCore::Qt::HitTestAccuracy
        define_enum_under<Qt::HitTestAccuracy>("HitTestAccuracy", rb_mQt)
            .define_value("ExactHit", Qt::HitTestAccuracy::ExactHit)
            .define_value("FuzzyHit", Qt::HitTestAccuracy::FuzzyHit);

    Enum<Qt::WindowType> rb_cQtWindowType =
        // Qt6::QtCore::Qt::WindowType
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

    Enum<Qt::WindowState> rb_cQtWindowState =
        // Qt6::QtCore::Qt::WindowState
        define_enum_under<Qt::WindowState>("WindowState", rb_mQt)
            .define_value("WindowNoState", Qt::WindowState::WindowNoState)
            .define_value("WindowMinimized", Qt::WindowState::WindowMinimized)
            .define_value("WindowMaximized", Qt::WindowState::WindowMaximized)
            .define_value("WindowFullScreen", Qt::WindowState::WindowFullScreen)
            .define_value("WindowActive", Qt::WindowState::WindowActive);

    Enum<Qt::ApplicationState> rb_cQtApplicationState =
        // Qt6::QtCore::Qt::ApplicationState
        define_enum_under<Qt::ApplicationState>("ApplicationState", rb_mQt)
            .define_value("ApplicationSuspended", Qt::ApplicationState::ApplicationSuspended)
            .define_value("ApplicationHidden", Qt::ApplicationState::ApplicationHidden)
            .define_value("ApplicationInactive", Qt::ApplicationState::ApplicationInactive)
            .define_value("ApplicationActive", Qt::ApplicationState::ApplicationActive);

    Enum<Qt::ScreenOrientation> rb_cQtScreenOrientation =
        // Qt6::QtCore::Qt::ScreenOrientation
        define_enum_under<Qt::ScreenOrientation>("ScreenOrientation", rb_mQt)
            .define_value("PrimaryOrientation", Qt::ScreenOrientation::PrimaryOrientation)
            .define_value("PortraitOrientation", Qt::ScreenOrientation::PortraitOrientation)
            .define_value("LandscapeOrientation", Qt::ScreenOrientation::LandscapeOrientation)
            .define_value("InvertedPortraitOrientation", Qt::ScreenOrientation::InvertedPortraitOrientation)
            .define_value("InvertedLandscapeOrientation", Qt::ScreenOrientation::InvertedLandscapeOrientation);

    Enum<Qt::WidgetAttribute> rb_cQtWidgetAttribute =
        // Qt6::QtCore::Qt::WidgetAttribute
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

    Enum<Qt::ApplicationAttribute> rb_cQtApplicationAttribute =
        // Qt6::QtCore::Qt::ApplicationAttribute
        define_enum_under<Qt::ApplicationAttribute>("ApplicationAttribute", rb_mQt)
            .define_value("AA_QtQuickUseDefaultSizePolicy", Qt::ApplicationAttribute::AA_QtQuickUseDefaultSizePolicy)
            .define_value("AA_DontShowIconsInMenus", Qt::ApplicationAttribute::AA_DontShowIconsInMenus)
            .define_value("AA_NativeWindows", Qt::ApplicationAttribute::AA_NativeWindows)
            .define_value("AA_DontCreateNativeWidgetSiblings", Qt::ApplicationAttribute::AA_DontCreateNativeWidgetSiblings)
            .define_value("AA_PluginApplication", Qt::ApplicationAttribute::AA_PluginApplication)
            .define_value("AA_DontUseNativeMenuBar", Qt::ApplicationAttribute::AA_DontUseNativeMenuBar)
            .define_value("AA_MacDontSwapCtrlAndMeta", Qt::ApplicationAttribute::AA_MacDontSwapCtrlAndMeta)
            .define_value("AA_Use96Dpi", Qt::ApplicationAttribute::AA_Use96Dpi)
            .define_value("AA_DisableNativeVirtualKeyboard", Qt::ApplicationAttribute::AA_DisableNativeVirtualKeyboard)
            .define_value("AA_DontUseNativeMenuWindows", Qt::ApplicationAttribute::AA_DontUseNativeMenuWindows)
            .define_value("AA_SynthesizeTouchForUnhandledMouseEvents", Qt::ApplicationAttribute::AA_SynthesizeTouchForUnhandledMouseEvents)
            .define_value("AA_SynthesizeMouseForUnhandledTouchEvents", Qt::ApplicationAttribute::AA_SynthesizeMouseForUnhandledTouchEvents)
            .define_value("AA_ForceRasterWidgets", Qt::ApplicationAttribute::AA_ForceRasterWidgets)
            .define_value("AA_UseDesktopOpenGL", Qt::ApplicationAttribute::AA_UseDesktopOpenGL)
            .define_value("AA_UseOpenGLES", Qt::ApplicationAttribute::AA_UseOpenGLES)
            .define_value("AA_UseSoftwareOpenGL", Qt::ApplicationAttribute::AA_UseSoftwareOpenGL)
            .define_value("AA_ShareOpenGLContexts", Qt::ApplicationAttribute::AA_ShareOpenGLContexts)
            .define_value("AA_SetPalette", Qt::ApplicationAttribute::AA_SetPalette)
            .define_value("AA_UseStyleSheetPropagationInWidgetStyles", Qt::ApplicationAttribute::AA_UseStyleSheetPropagationInWidgetStyles)
            .define_value("AA_DontUseNativeDialogs", Qt::ApplicationAttribute::AA_DontUseNativeDialogs)
            .define_value("AA_SynthesizeMouseForUnhandledTabletEvents", Qt::ApplicationAttribute::AA_SynthesizeMouseForUnhandledTabletEvents)
            .define_value("AA_CompressHighFrequencyEvents", Qt::ApplicationAttribute::AA_CompressHighFrequencyEvents)
            .define_value("AA_DontCheckOpenGLContextThreadAffinity", Qt::ApplicationAttribute::AA_DontCheckOpenGLContextThreadAffinity)
            .define_value("AA_DisableShaderDiskCache", Qt::ApplicationAttribute::AA_DisableShaderDiskCache)
            .define_value("AA_DontShowShortcutsInContextMenus", Qt::ApplicationAttribute::AA_DontShowShortcutsInContextMenus)
            .define_value("AA_CompressTabletEvents", Qt::ApplicationAttribute::AA_CompressTabletEvents)
            .define_value("AA_DisableSessionManager", Qt::ApplicationAttribute::AA_DisableSessionManager)
            .define_value("AA_AttributeCount", Qt::ApplicationAttribute::AA_AttributeCount);

    Enum<Qt::ImageConversionFlag> rb_cQtImageConversionFlag =
        // Qt6::QtCore::Qt::ImageConversionFlag
        define_enum_under<Qt::ImageConversionFlag>("ImageConversionFlag", rb_mQt)
            .define_value("ColorMode_Mask", Qt::ImageConversionFlag::ColorMode_Mask)
            .define_value("AutoColor", Qt::ImageConversionFlag::AutoColor)
            .define_value("ColorOnly", Qt::ImageConversionFlag::ColorOnly)
            .define_value("MonoOnly", Qt::ImageConversionFlag::MonoOnly)
            .define_value("AlphaDither_Mask", Qt::ImageConversionFlag::AlphaDither_Mask)
            .define_value("ThresholdAlphaDither", Qt::ImageConversionFlag::ThresholdAlphaDither)
            .define_value("OrderedAlphaDither", Qt::ImageConversionFlag::OrderedAlphaDither)
            .define_value("DiffuseAlphaDither", Qt::ImageConversionFlag::DiffuseAlphaDither)
            .define_value("NoAlpha", Qt::ImageConversionFlag::NoAlpha)
            .define_value("Dither_Mask", Qt::ImageConversionFlag::Dither_Mask)
            .define_value("DiffuseDither", Qt::ImageConversionFlag::DiffuseDither)
            .define_value("OrderedDither", Qt::ImageConversionFlag::OrderedDither)
            .define_value("ThresholdDither", Qt::ImageConversionFlag::ThresholdDither)
            .define_value("DitherMode_Mask", Qt::ImageConversionFlag::DitherMode_Mask)
            .define_value("AutoDither", Qt::ImageConversionFlag::AutoDither)
            .define_value("PreferDither", Qt::ImageConversionFlag::PreferDither)
            .define_value("AvoidDither", Qt::ImageConversionFlag::AvoidDither)
            .define_value("NoOpaqueDetection", Qt::ImageConversionFlag::NoOpaqueDetection)
            .define_value("NoFormatConversion", Qt::ImageConversionFlag::NoFormatConversion);

    Enum<Qt::BGMode> rb_cQtBGMode =
        // Qt6::QtCore::Qt::BGMode
        define_enum_under<Qt::BGMode>("BGMode", rb_mQt)
            .define_value("TransparentMode", Qt::BGMode::TransparentMode)
            .define_value("OpaqueMode", Qt::BGMode::OpaqueMode);

    Enum<Qt::Key> rb_cQtKey =
        // Qt6::QtCore::Qt::Key
        define_enum_under<Qt::Key>("Key", rb_mQt)
            .define_value("Key_Space", Qt::Key::Key_Space)
            .define_value("Key_Any", Qt::Key::Key_Any)
            .define_value("Key_Exclam", Qt::Key::Key_Exclam)
            .define_value("Key_QuoteDbl", Qt::Key::Key_QuoteDbl)
            .define_value("Key_NumberSign", Qt::Key::Key_NumberSign)
            .define_value("Key_Dollar", Qt::Key::Key_Dollar)
            .define_value("Key_Percent", Qt::Key::Key_Percent)
            .define_value("Key_Ampersand", Qt::Key::Key_Ampersand)
            .define_value("Key_Apostrophe", Qt::Key::Key_Apostrophe)
            .define_value("Key_ParenLeft", Qt::Key::Key_ParenLeft)
            .define_value("Key_ParenRight", Qt::Key::Key_ParenRight)
            .define_value("Key_Asterisk", Qt::Key::Key_Asterisk)
            .define_value("Key_Plus", Qt::Key::Key_Plus)
            .define_value("Key_Comma", Qt::Key::Key_Comma)
            .define_value("Key_Minus", Qt::Key::Key_Minus)
            .define_value("Key_Period", Qt::Key::Key_Period)
            .define_value("Key_Slash", Qt::Key::Key_Slash)
            .define_value("Key_0", Qt::Key::Key_0)
            .define_value("Key_1", Qt::Key::Key_1)
            .define_value("Key_2", Qt::Key::Key_2)
            .define_value("Key_3", Qt::Key::Key_3)
            .define_value("Key_4", Qt::Key::Key_4)
            .define_value("Key_5", Qt::Key::Key_5)
            .define_value("Key_6", Qt::Key::Key_6)
            .define_value("Key_7", Qt::Key::Key_7)
            .define_value("Key_8", Qt::Key::Key_8)
            .define_value("Key_9", Qt::Key::Key_9)
            .define_value("Key_Colon", Qt::Key::Key_Colon)
            .define_value("Key_Semicolon", Qt::Key::Key_Semicolon)
            .define_value("Key_Less", Qt::Key::Key_Less)
            .define_value("Key_Equal", Qt::Key::Key_Equal)
            .define_value("Key_Greater", Qt::Key::Key_Greater)
            .define_value("Key_Question", Qt::Key::Key_Question)
            .define_value("Key_At", Qt::Key::Key_At)
            .define_value("Key_A", Qt::Key::Key_A)
            .define_value("Key_B", Qt::Key::Key_B)
            .define_value("Key_C", Qt::Key::Key_C)
            .define_value("Key_D", Qt::Key::Key_D)
            .define_value("Key_E", Qt::Key::Key_E)
            .define_value("Key_F", Qt::Key::Key_F)
            .define_value("Key_G", Qt::Key::Key_G)
            .define_value("Key_H", Qt::Key::Key_H)
            .define_value("Key_I", Qt::Key::Key_I)
            .define_value("Key_J", Qt::Key::Key_J)
            .define_value("Key_K", Qt::Key::Key_K)
            .define_value("Key_L", Qt::Key::Key_L)
            .define_value("Key_M", Qt::Key::Key_M)
            .define_value("Key_N", Qt::Key::Key_N)
            .define_value("Key_O", Qt::Key::Key_O)
            .define_value("Key_P", Qt::Key::Key_P)
            .define_value("Key_Q", Qt::Key::Key_Q)
            .define_value("Key_R", Qt::Key::Key_R)
            .define_value("Key_S", Qt::Key::Key_S)
            .define_value("Key_T", Qt::Key::Key_T)
            .define_value("Key_U", Qt::Key::Key_U)
            .define_value("Key_V", Qt::Key::Key_V)
            .define_value("Key_W", Qt::Key::Key_W)
            .define_value("Key_X", Qt::Key::Key_X)
            .define_value("Key_Y", Qt::Key::Key_Y)
            .define_value("Key_Z", Qt::Key::Key_Z)
            .define_value("Key_BracketLeft", Qt::Key::Key_BracketLeft)
            .define_value("Key_Backslash", Qt::Key::Key_Backslash)
            .define_value("Key_BracketRight", Qt::Key::Key_BracketRight)
            .define_value("Key_AsciiCircum", Qt::Key::Key_AsciiCircum)
            .define_value("Key_Underscore", Qt::Key::Key_Underscore)
            .define_value("Key_QuoteLeft", Qt::Key::Key_QuoteLeft)
            .define_value("Key_BraceLeft", Qt::Key::Key_BraceLeft)
            .define_value("Key_Bar", Qt::Key::Key_Bar)
            .define_value("Key_BraceRight", Qt::Key::Key_BraceRight)
            .define_value("Key_AsciiTilde", Qt::Key::Key_AsciiTilde)
            .define_value("Key_nobreakspace", Qt::Key::Key_nobreakspace)
            .define_value("Key_exclamdown", Qt::Key::Key_exclamdown)
            .define_value("Key_cent", Qt::Key::Key_cent)
            .define_value("Key_sterling", Qt::Key::Key_sterling)
            .define_value("Key_currency", Qt::Key::Key_currency)
            .define_value("Key_yen", Qt::Key::Key_yen)
            .define_value("Key_brokenbar", Qt::Key::Key_brokenbar)
            .define_value("Key_section", Qt::Key::Key_section)
            .define_value("Key_diaeresis", Qt::Key::Key_diaeresis)
            .define_value("Key_copyright", Qt::Key::Key_copyright)
            .define_value("Key_ordfeminine", Qt::Key::Key_ordfeminine)
            .define_value("Key_guillemotleft", Qt::Key::Key_guillemotleft)
            .define_value("Key_notsign", Qt::Key::Key_notsign)
            .define_value("Key_hyphen", Qt::Key::Key_hyphen)
            .define_value("Key_registered", Qt::Key::Key_registered)
            .define_value("Key_macron", Qt::Key::Key_macron)
            .define_value("Key_degree", Qt::Key::Key_degree)
            .define_value("Key_plusminus", Qt::Key::Key_plusminus)
            .define_value("Key_twosuperior", Qt::Key::Key_twosuperior)
            .define_value("Key_threesuperior", Qt::Key::Key_threesuperior)
            .define_value("Key_acute", Qt::Key::Key_acute)
            .define_value("Key_micro", Qt::Key::Key_micro)
            .define_value("Key_paragraph", Qt::Key::Key_paragraph)
            .define_value("Key_periodcentered", Qt::Key::Key_periodcentered)
            .define_value("Key_cedilla", Qt::Key::Key_cedilla)
            .define_value("Key_onesuperior", Qt::Key::Key_onesuperior)
            .define_value("Key_masculine", Qt::Key::Key_masculine)
            .define_value("Key_guillemotright", Qt::Key::Key_guillemotright)
            .define_value("Key_onequarter", Qt::Key::Key_onequarter)
            .define_value("Key_onehalf", Qt::Key::Key_onehalf)
            .define_value("Key_threequarters", Qt::Key::Key_threequarters)
            .define_value("Key_questiondown", Qt::Key::Key_questiondown)
            .define_value("Key_Agrave", Qt::Key::Key_Agrave)
            .define_value("Key_Aacute", Qt::Key::Key_Aacute)
            .define_value("Key_Acircumflex", Qt::Key::Key_Acircumflex)
            .define_value("Key_Atilde", Qt::Key::Key_Atilde)
            .define_value("Key_Adiaeresis", Qt::Key::Key_Adiaeresis)
            .define_value("Key_Aring", Qt::Key::Key_Aring)
            .define_value("Key_AE", Qt::Key::Key_AE)
            .define_value("Key_Ccedilla", Qt::Key::Key_Ccedilla)
            .define_value("Key_Egrave", Qt::Key::Key_Egrave)
            .define_value("Key_Eacute", Qt::Key::Key_Eacute)
            .define_value("Key_Ecircumflex", Qt::Key::Key_Ecircumflex)
            .define_value("Key_Ediaeresis", Qt::Key::Key_Ediaeresis)
            .define_value("Key_Igrave", Qt::Key::Key_Igrave)
            .define_value("Key_Iacute", Qt::Key::Key_Iacute)
            .define_value("Key_Icircumflex", Qt::Key::Key_Icircumflex)
            .define_value("Key_Idiaeresis", Qt::Key::Key_Idiaeresis)
            .define_value("Key_ETH", Qt::Key::Key_ETH)
            .define_value("Key_Ntilde", Qt::Key::Key_Ntilde)
            .define_value("Key_Ograve", Qt::Key::Key_Ograve)
            .define_value("Key_Oacute", Qt::Key::Key_Oacute)
            .define_value("Key_Ocircumflex", Qt::Key::Key_Ocircumflex)
            .define_value("Key_Otilde", Qt::Key::Key_Otilde)
            .define_value("Key_Odiaeresis", Qt::Key::Key_Odiaeresis)
            .define_value("Key_multiply", Qt::Key::Key_multiply)
            .define_value("Key_Ooblique", Qt::Key::Key_Ooblique)
            .define_value("Key_Ugrave", Qt::Key::Key_Ugrave)
            .define_value("Key_Uacute", Qt::Key::Key_Uacute)
            .define_value("Key_Ucircumflex", Qt::Key::Key_Ucircumflex)
            .define_value("Key_Udiaeresis", Qt::Key::Key_Udiaeresis)
            .define_value("Key_Yacute", Qt::Key::Key_Yacute)
            .define_value("Key_THORN", Qt::Key::Key_THORN)
            .define_value("Key_ssharp", Qt::Key::Key_ssharp)
            .define_value("Key_division", Qt::Key::Key_division)
            .define_value("Key_ydiaeresis", Qt::Key::Key_ydiaeresis)
            .define_value("Key_Escape", Qt::Key::Key_Escape)
            .define_value("Key_Tab", Qt::Key::Key_Tab)
            .define_value("Key_Backtab", Qt::Key::Key_Backtab)
            .define_value("Key_Backspace", Qt::Key::Key_Backspace)
            .define_value("Key_Return", Qt::Key::Key_Return)
            .define_value("Key_Enter", Qt::Key::Key_Enter)
            .define_value("Key_Insert", Qt::Key::Key_Insert)
            .define_value("Key_Delete", Qt::Key::Key_Delete)
            .define_value("Key_Pause", Qt::Key::Key_Pause)
            .define_value("Key_Print", Qt::Key::Key_Print)
            .define_value("Key_SysReq", Qt::Key::Key_SysReq)
            .define_value("Key_Clear", Qt::Key::Key_Clear)
            .define_value("Key_Home", Qt::Key::Key_Home)
            .define_value("Key_End", Qt::Key::Key_End)
            .define_value("Key_Left", Qt::Key::Key_Left)
            .define_value("Key_Up", Qt::Key::Key_Up)
            .define_value("Key_Right", Qt::Key::Key_Right)
            .define_value("Key_Down", Qt::Key::Key_Down)
            .define_value("Key_PageUp", Qt::Key::Key_PageUp)
            .define_value("Key_PageDown", Qt::Key::Key_PageDown)
            .define_value("Key_Shift", Qt::Key::Key_Shift)
            .define_value("Key_Control", Qt::Key::Key_Control)
            .define_value("Key_Meta", Qt::Key::Key_Meta)
            .define_value("Key_Alt", Qt::Key::Key_Alt)
            .define_value("Key_CapsLock", Qt::Key::Key_CapsLock)
            .define_value("Key_NumLock", Qt::Key::Key_NumLock)
            .define_value("Key_ScrollLock", Qt::Key::Key_ScrollLock)
            .define_value("Key_F1", Qt::Key::Key_F1)
            .define_value("Key_F2", Qt::Key::Key_F2)
            .define_value("Key_F3", Qt::Key::Key_F3)
            .define_value("Key_F4", Qt::Key::Key_F4)
            .define_value("Key_F5", Qt::Key::Key_F5)
            .define_value("Key_F6", Qt::Key::Key_F6)
            .define_value("Key_F7", Qt::Key::Key_F7)
            .define_value("Key_F8", Qt::Key::Key_F8)
            .define_value("Key_F9", Qt::Key::Key_F9)
            .define_value("Key_F10", Qt::Key::Key_F10)
            .define_value("Key_F11", Qt::Key::Key_F11)
            .define_value("Key_F12", Qt::Key::Key_F12)
            .define_value("Key_F13", Qt::Key::Key_F13)
            .define_value("Key_F14", Qt::Key::Key_F14)
            .define_value("Key_F15", Qt::Key::Key_F15)
            .define_value("Key_F16", Qt::Key::Key_F16)
            .define_value("Key_F17", Qt::Key::Key_F17)
            .define_value("Key_F18", Qt::Key::Key_F18)
            .define_value("Key_F19", Qt::Key::Key_F19)
            .define_value("Key_F20", Qt::Key::Key_F20)
            .define_value("Key_F21", Qt::Key::Key_F21)
            .define_value("Key_F22", Qt::Key::Key_F22)
            .define_value("Key_F23", Qt::Key::Key_F23)
            .define_value("Key_F24", Qt::Key::Key_F24)
            .define_value("Key_F25", Qt::Key::Key_F25)
            .define_value("Key_F26", Qt::Key::Key_F26)
            .define_value("Key_F27", Qt::Key::Key_F27)
            .define_value("Key_F28", Qt::Key::Key_F28)
            .define_value("Key_F29", Qt::Key::Key_F29)
            .define_value("Key_F30", Qt::Key::Key_F30)
            .define_value("Key_F31", Qt::Key::Key_F31)
            .define_value("Key_F32", Qt::Key::Key_F32)
            .define_value("Key_F33", Qt::Key::Key_F33)
            .define_value("Key_F34", Qt::Key::Key_F34)
            .define_value("Key_F35", Qt::Key::Key_F35)
            .define_value("Key_Super_L", Qt::Key::Key_Super_L)
            .define_value("Key_Super_R", Qt::Key::Key_Super_R)
            .define_value("Key_Menu", Qt::Key::Key_Menu)
            .define_value("Key_Hyper_L", Qt::Key::Key_Hyper_L)
            .define_value("Key_Hyper_R", Qt::Key::Key_Hyper_R)
            .define_value("Key_Help", Qt::Key::Key_Help)
            .define_value("Key_Direction_L", Qt::Key::Key_Direction_L)
            .define_value("Key_Direction_R", Qt::Key::Key_Direction_R)
            .define_value("Key_AltGr", Qt::Key::Key_AltGr)
            .define_value("Key_Multi_key", Qt::Key::Key_Multi_key)
            .define_value("Key_Codeinput", Qt::Key::Key_Codeinput)
            .define_value("Key_SingleCandidate", Qt::Key::Key_SingleCandidate)
            .define_value("Key_MultipleCandidate", Qt::Key::Key_MultipleCandidate)
            .define_value("Key_PreviousCandidate", Qt::Key::Key_PreviousCandidate)
            .define_value("Key_Mode_switch", Qt::Key::Key_Mode_switch)
            .define_value("Key_Kanji", Qt::Key::Key_Kanji)
            .define_value("Key_Muhenkan", Qt::Key::Key_Muhenkan)
            .define_value("Key_Henkan", Qt::Key::Key_Henkan)
            .define_value("Key_Romaji", Qt::Key::Key_Romaji)
            .define_value("Key_Hiragana", Qt::Key::Key_Hiragana)
            .define_value("Key_Katakana", Qt::Key::Key_Katakana)
            .define_value("Key_Hiragana_Katakana", Qt::Key::Key_Hiragana_Katakana)
            .define_value("Key_Zenkaku", Qt::Key::Key_Zenkaku)
            .define_value("Key_Hankaku", Qt::Key::Key_Hankaku)
            .define_value("Key_Zenkaku_Hankaku", Qt::Key::Key_Zenkaku_Hankaku)
            .define_value("Key_Touroku", Qt::Key::Key_Touroku)
            .define_value("Key_Massyo", Qt::Key::Key_Massyo)
            .define_value("Key_Kana_Lock", Qt::Key::Key_Kana_Lock)
            .define_value("Key_Kana_Shift", Qt::Key::Key_Kana_Shift)
            .define_value("Key_Eisu_Shift", Qt::Key::Key_Eisu_Shift)
            .define_value("Key_Eisu_toggle", Qt::Key::Key_Eisu_toggle)
            .define_value("Key_Hangul", Qt::Key::Key_Hangul)
            .define_value("Key_Hangul_Start", Qt::Key::Key_Hangul_Start)
            .define_value("Key_Hangul_End", Qt::Key::Key_Hangul_End)
            .define_value("Key_Hangul_Hanja", Qt::Key::Key_Hangul_Hanja)
            .define_value("Key_Hangul_Jamo", Qt::Key::Key_Hangul_Jamo)
            .define_value("Key_Hangul_Romaja", Qt::Key::Key_Hangul_Romaja)
            .define_value("Key_Hangul_Jeonja", Qt::Key::Key_Hangul_Jeonja)
            .define_value("Key_Hangul_Banja", Qt::Key::Key_Hangul_Banja)
            .define_value("Key_Hangul_PreHanja", Qt::Key::Key_Hangul_PreHanja)
            .define_value("Key_Hangul_PostHanja", Qt::Key::Key_Hangul_PostHanja)
            .define_value("Key_Hangul_Special", Qt::Key::Key_Hangul_Special)
            .define_value("Key_Dead_Grave", Qt::Key::Key_Dead_Grave)
            .define_value("Key_Dead_Acute", Qt::Key::Key_Dead_Acute)
            .define_value("Key_Dead_Circumflex", Qt::Key::Key_Dead_Circumflex)
            .define_value("Key_Dead_Tilde", Qt::Key::Key_Dead_Tilde)
            .define_value("Key_Dead_Macron", Qt::Key::Key_Dead_Macron)
            .define_value("Key_Dead_Breve", Qt::Key::Key_Dead_Breve)
            .define_value("Key_Dead_Abovedot", Qt::Key::Key_Dead_Abovedot)
            .define_value("Key_Dead_Diaeresis", Qt::Key::Key_Dead_Diaeresis)
            .define_value("Key_Dead_Abovering", Qt::Key::Key_Dead_Abovering)
            .define_value("Key_Dead_Doubleacute", Qt::Key::Key_Dead_Doubleacute)
            .define_value("Key_Dead_Caron", Qt::Key::Key_Dead_Caron)
            .define_value("Key_Dead_Cedilla", Qt::Key::Key_Dead_Cedilla)
            .define_value("Key_Dead_Ogonek", Qt::Key::Key_Dead_Ogonek)
            .define_value("Key_Dead_Iota", Qt::Key::Key_Dead_Iota)
            .define_value("Key_Dead_Voiced_Sound", Qt::Key::Key_Dead_Voiced_Sound)
            .define_value("Key_Dead_Semivoiced_Sound", Qt::Key::Key_Dead_Semivoiced_Sound)
            .define_value("Key_Dead_Belowdot", Qt::Key::Key_Dead_Belowdot)
            .define_value("Key_Dead_Hook", Qt::Key::Key_Dead_Hook)
            .define_value("Key_Dead_Horn", Qt::Key::Key_Dead_Horn)
            .define_value("Key_Dead_Stroke", Qt::Key::Key_Dead_Stroke)
            .define_value("Key_Dead_Abovecomma", Qt::Key::Key_Dead_Abovecomma)
            .define_value("Key_Dead_Abovereversedcomma", Qt::Key::Key_Dead_Abovereversedcomma)
            .define_value("Key_Dead_Doublegrave", Qt::Key::Key_Dead_Doublegrave)
            .define_value("Key_Dead_Belowring", Qt::Key::Key_Dead_Belowring)
            .define_value("Key_Dead_Belowmacron", Qt::Key::Key_Dead_Belowmacron)
            .define_value("Key_Dead_Belowcircumflex", Qt::Key::Key_Dead_Belowcircumflex)
            .define_value("Key_Dead_Belowtilde", Qt::Key::Key_Dead_Belowtilde)
            .define_value("Key_Dead_Belowbreve", Qt::Key::Key_Dead_Belowbreve)
            .define_value("Key_Dead_Belowdiaeresis", Qt::Key::Key_Dead_Belowdiaeresis)
            .define_value("Key_Dead_Invertedbreve", Qt::Key::Key_Dead_Invertedbreve)
            .define_value("Key_Dead_Belowcomma", Qt::Key::Key_Dead_Belowcomma)
            .define_value("Key_Dead_Currency", Qt::Key::Key_Dead_Currency)
            .define_value("Key_Dead_a", Qt::Key::Key_Dead_a)
            .define_value("Key_Dead_A", Qt::Key::Key_Dead_A)
            .define_value("Key_Dead_e", Qt::Key::Key_Dead_e)
            .define_value("Key_Dead_E", Qt::Key::Key_Dead_E)
            .define_value("Key_Dead_i", Qt::Key::Key_Dead_i)
            .define_value("Key_Dead_I", Qt::Key::Key_Dead_I)
            .define_value("Key_Dead_o", Qt::Key::Key_Dead_o)
            .define_value("Key_Dead_O", Qt::Key::Key_Dead_O)
            .define_value("Key_Dead_u", Qt::Key::Key_Dead_u)
            .define_value("Key_Dead_U", Qt::Key::Key_Dead_U)
            .define_value("Key_Dead_Small_Schwa", Qt::Key::Key_Dead_Small_Schwa)
            .define_value("Key_Dead_Capital_Schwa", Qt::Key::Key_Dead_Capital_Schwa)
            .define_value("Key_Dead_Greek", Qt::Key::Key_Dead_Greek)
            .define_value("Key_Dead_Lowline", Qt::Key::Key_Dead_Lowline)
            .define_value("Key_Dead_Aboveverticalline", Qt::Key::Key_Dead_Aboveverticalline)
            .define_value("Key_Dead_Belowverticalline", Qt::Key::Key_Dead_Belowverticalline)
            .define_value("Key_Dead_Longsolidusoverlay", Qt::Key::Key_Dead_Longsolidusoverlay)
            .define_value("Key_Back", Qt::Key::Key_Back)
            .define_value("Key_Forward", Qt::Key::Key_Forward)
            .define_value("Key_Stop", Qt::Key::Key_Stop)
            .define_value("Key_Refresh", Qt::Key::Key_Refresh)
            .define_value("Key_VolumeDown", Qt::Key::Key_VolumeDown)
            .define_value("Key_VolumeMute", Qt::Key::Key_VolumeMute)
            .define_value("Key_VolumeUp", Qt::Key::Key_VolumeUp)
            .define_value("Key_BassBoost", Qt::Key::Key_BassBoost)
            .define_value("Key_BassUp", Qt::Key::Key_BassUp)
            .define_value("Key_BassDown", Qt::Key::Key_BassDown)
            .define_value("Key_TrebleUp", Qt::Key::Key_TrebleUp)
            .define_value("Key_TrebleDown", Qt::Key::Key_TrebleDown)
            .define_value("Key_MediaPlay", Qt::Key::Key_MediaPlay)
            .define_value("Key_MediaStop", Qt::Key::Key_MediaStop)
            .define_value("Key_MediaPrevious", Qt::Key::Key_MediaPrevious)
            .define_value("Key_MediaNext", Qt::Key::Key_MediaNext)
            .define_value("Key_MediaRecord", Qt::Key::Key_MediaRecord)
            .define_value("Key_MediaPause", Qt::Key::Key_MediaPause)
            .define_value("Key_MediaTogglePlayPause", Qt::Key::Key_MediaTogglePlayPause)
            .define_value("Key_HomePage", Qt::Key::Key_HomePage)
            .define_value("Key_Favorites", Qt::Key::Key_Favorites)
            .define_value("Key_Search", Qt::Key::Key_Search)
            .define_value("Key_Standby", Qt::Key::Key_Standby)
            .define_value("Key_OpenUrl", Qt::Key::Key_OpenUrl)
            .define_value("Key_LaunchMail", Qt::Key::Key_LaunchMail)
            .define_value("Key_LaunchMedia", Qt::Key::Key_LaunchMedia)
            .define_value("Key_Launch0", Qt::Key::Key_Launch0)
            .define_value("Key_Launch1", Qt::Key::Key_Launch1)
            .define_value("Key_Launch2", Qt::Key::Key_Launch2)
            .define_value("Key_Launch3", Qt::Key::Key_Launch3)
            .define_value("Key_Launch4", Qt::Key::Key_Launch4)
            .define_value("Key_Launch5", Qt::Key::Key_Launch5)
            .define_value("Key_Launch6", Qt::Key::Key_Launch6)
            .define_value("Key_Launch7", Qt::Key::Key_Launch7)
            .define_value("Key_Launch8", Qt::Key::Key_Launch8)
            .define_value("Key_Launch9", Qt::Key::Key_Launch9)
            .define_value("Key_LaunchA", Qt::Key::Key_LaunchA)
            .define_value("Key_LaunchB", Qt::Key::Key_LaunchB)
            .define_value("Key_LaunchC", Qt::Key::Key_LaunchC)
            .define_value("Key_LaunchD", Qt::Key::Key_LaunchD)
            .define_value("Key_LaunchE", Qt::Key::Key_LaunchE)
            .define_value("Key_LaunchF", Qt::Key::Key_LaunchF)
            .define_value("Key_MonBrightnessUp", Qt::Key::Key_MonBrightnessUp)
            .define_value("Key_MonBrightnessDown", Qt::Key::Key_MonBrightnessDown)
            .define_value("Key_KeyboardLightOnOff", Qt::Key::Key_KeyboardLightOnOff)
            .define_value("Key_KeyboardBrightnessUp", Qt::Key::Key_KeyboardBrightnessUp)
            .define_value("Key_KeyboardBrightnessDown", Qt::Key::Key_KeyboardBrightnessDown)
            .define_value("Key_PowerOff", Qt::Key::Key_PowerOff)
            .define_value("Key_WakeUp", Qt::Key::Key_WakeUp)
            .define_value("Key_Eject", Qt::Key::Key_Eject)
            .define_value("Key_ScreenSaver", Qt::Key::Key_ScreenSaver)
            .define_value("Key_WWW", Qt::Key::Key_WWW)
            .define_value("Key_Memo", Qt::Key::Key_Memo)
            .define_value("Key_LightBulb", Qt::Key::Key_LightBulb)
            .define_value("Key_Shop", Qt::Key::Key_Shop)
            .define_value("Key_History", Qt::Key::Key_History)
            .define_value("Key_AddFavorite", Qt::Key::Key_AddFavorite)
            .define_value("Key_HotLinks", Qt::Key::Key_HotLinks)
            .define_value("Key_BrightnessAdjust", Qt::Key::Key_BrightnessAdjust)
            .define_value("Key_Finance", Qt::Key::Key_Finance)
            .define_value("Key_Community", Qt::Key::Key_Community)
            .define_value("Key_AudioRewind", Qt::Key::Key_AudioRewind)
            .define_value("Key_BackForward", Qt::Key::Key_BackForward)
            .define_value("Key_ApplicationLeft", Qt::Key::Key_ApplicationLeft)
            .define_value("Key_ApplicationRight", Qt::Key::Key_ApplicationRight)
            .define_value("Key_Book", Qt::Key::Key_Book)
            .define_value("Key_CD", Qt::Key::Key_CD)
            .define_value("Key_Calculator", Qt::Key::Key_Calculator)
            .define_value("Key_ToDoList", Qt::Key::Key_ToDoList)
            .define_value("Key_ClearGrab", Qt::Key::Key_ClearGrab)
            .define_value("Key_Close", Qt::Key::Key_Close)
            .define_value("Key_Copy", Qt::Key::Key_Copy)
            .define_value("Key_Cut", Qt::Key::Key_Cut)
            .define_value("Key_Display", Qt::Key::Key_Display)
            .define_value("Key_DOS", Qt::Key::Key_DOS)
            .define_value("Key_Documents", Qt::Key::Key_Documents)
            .define_value("Key_Excel", Qt::Key::Key_Excel)
            .define_value("Key_Explorer", Qt::Key::Key_Explorer)
            .define_value("Key_Game", Qt::Key::Key_Game)
            .define_value("Key_Go", Qt::Key::Key_Go)
            .define_value("Key_iTouch", Qt::Key::Key_iTouch)
            .define_value("Key_LogOff", Qt::Key::Key_LogOff)
            .define_value("Key_Market", Qt::Key::Key_Market)
            .define_value("Key_Meeting", Qt::Key::Key_Meeting)
            .define_value("Key_MenuKB", Qt::Key::Key_MenuKB)
            .define_value("Key_MenuPB", Qt::Key::Key_MenuPB)
            .define_value("Key_MySites", Qt::Key::Key_MySites)
            .define_value("Key_News", Qt::Key::Key_News)
            .define_value("Key_OfficeHome", Qt::Key::Key_OfficeHome)
            .define_value("Key_Option", Qt::Key::Key_Option)
            .define_value("Key_Paste", Qt::Key::Key_Paste)
            .define_value("Key_Phone", Qt::Key::Key_Phone)
            .define_value("Key_Calendar", Qt::Key::Key_Calendar)
            .define_value("Key_Reply", Qt::Key::Key_Reply)
            .define_value("Key_Reload", Qt::Key::Key_Reload)
            .define_value("Key_RotateWindows", Qt::Key::Key_RotateWindows)
            .define_value("Key_RotationPB", Qt::Key::Key_RotationPB)
            .define_value("Key_RotationKB", Qt::Key::Key_RotationKB)
            .define_value("Key_Save", Qt::Key::Key_Save)
            .define_value("Key_Send", Qt::Key::Key_Send)
            .define_value("Key_Spell", Qt::Key::Key_Spell)
            .define_value("Key_SplitScreen", Qt::Key::Key_SplitScreen)
            .define_value("Key_Support", Qt::Key::Key_Support)
            .define_value("Key_TaskPane", Qt::Key::Key_TaskPane)
            .define_value("Key_Terminal", Qt::Key::Key_Terminal)
            .define_value("Key_Tools", Qt::Key::Key_Tools)
            .define_value("Key_Travel", Qt::Key::Key_Travel)
            .define_value("Key_Video", Qt::Key::Key_Video)
            .define_value("Key_Word", Qt::Key::Key_Word)
            .define_value("Key_Xfer", Qt::Key::Key_Xfer)
            .define_value("Key_ZoomIn", Qt::Key::Key_ZoomIn)
            .define_value("Key_ZoomOut", Qt::Key::Key_ZoomOut)
            .define_value("Key_Away", Qt::Key::Key_Away)
            .define_value("Key_Messenger", Qt::Key::Key_Messenger)
            .define_value("Key_WebCam", Qt::Key::Key_WebCam)
            .define_value("Key_MailForward", Qt::Key::Key_MailForward)
            .define_value("Key_Pictures", Qt::Key::Key_Pictures)
            .define_value("Key_Music", Qt::Key::Key_Music)
            .define_value("Key_Battery", Qt::Key::Key_Battery)
            .define_value("Key_Bluetooth", Qt::Key::Key_Bluetooth)
            .define_value("Key_WLAN", Qt::Key::Key_WLAN)
            .define_value("Key_UWB", Qt::Key::Key_UWB)
            .define_value("Key_AudioForward", Qt::Key::Key_AudioForward)
            .define_value("Key_AudioRepeat", Qt::Key::Key_AudioRepeat)
            .define_value("Key_AudioRandomPlay", Qt::Key::Key_AudioRandomPlay)
            .define_value("Key_Subtitle", Qt::Key::Key_Subtitle)
            .define_value("Key_AudioCycleTrack", Qt::Key::Key_AudioCycleTrack)
            .define_value("Key_Time", Qt::Key::Key_Time)
            .define_value("Key_Hibernate", Qt::Key::Key_Hibernate)
            .define_value("Key_View", Qt::Key::Key_View)
            .define_value("Key_TopMenu", Qt::Key::Key_TopMenu)
            .define_value("Key_PowerDown", Qt::Key::Key_PowerDown)
            .define_value("Key_Suspend", Qt::Key::Key_Suspend)
            .define_value("Key_ContrastAdjust", Qt::Key::Key_ContrastAdjust)
            .define_value("Key_LaunchG", Qt::Key::Key_LaunchG)
            .define_value("Key_LaunchH", Qt::Key::Key_LaunchH)
            .define_value("Key_TouchpadToggle", Qt::Key::Key_TouchpadToggle)
            .define_value("Key_TouchpadOn", Qt::Key::Key_TouchpadOn)
            .define_value("Key_TouchpadOff", Qt::Key::Key_TouchpadOff)
            .define_value("Key_MicMute", Qt::Key::Key_MicMute)
            .define_value("Key_Red", Qt::Key::Key_Red)
            .define_value("Key_Green", Qt::Key::Key_Green)
            .define_value("Key_Yellow", Qt::Key::Key_Yellow)
            .define_value("Key_Blue", Qt::Key::Key_Blue)
            .define_value("Key_ChannelUp", Qt::Key::Key_ChannelUp)
            .define_value("Key_ChannelDown", Qt::Key::Key_ChannelDown)
            .define_value("Key_Guide", Qt::Key::Key_Guide)
            .define_value("Key_Info", Qt::Key::Key_Info)
            .define_value("Key_Settings", Qt::Key::Key_Settings)
            .define_value("Key_MicVolumeUp", Qt::Key::Key_MicVolumeUp)
            .define_value("Key_MicVolumeDown", Qt::Key::Key_MicVolumeDown)
            .define_value("Key_New", Qt::Key::Key_New)
            .define_value("Key_Open", Qt::Key::Key_Open)
            .define_value("Key_Find", Qt::Key::Key_Find)
            .define_value("Key_Undo", Qt::Key::Key_Undo)
            .define_value("Key_Redo", Qt::Key::Key_Redo)
            .define_value("Key_MediaLast", Qt::Key::Key_MediaLast)
            .define_value("Key_Select", Qt::Key::Key_Select)
            .define_value("Key_Yes", Qt::Key::Key_Yes)
            .define_value("Key_No", Qt::Key::Key_No)
            .define_value("Key_Cancel", Qt::Key::Key_Cancel)
            .define_value("Key_Printer", Qt::Key::Key_Printer)
            .define_value("Key_Execute", Qt::Key::Key_Execute)
            .define_value("Key_Sleep", Qt::Key::Key_Sleep)
            .define_value("Key_Play", Qt::Key::Key_Play)
            .define_value("Key_Zoom", Qt::Key::Key_Zoom)
            .define_value("Key_Exit", Qt::Key::Key_Exit)
            .define_value("Key_Context1", Qt::Key::Key_Context1)
            .define_value("Key_Context2", Qt::Key::Key_Context2)
            .define_value("Key_Context3", Qt::Key::Key_Context3)
            .define_value("Key_Context4", Qt::Key::Key_Context4)
            .define_value("Key_Call", Qt::Key::Key_Call)
            .define_value("Key_Hangup", Qt::Key::Key_Hangup)
            .define_value("Key_Flip", Qt::Key::Key_Flip)
            .define_value("Key_ToggleCallHangup", Qt::Key::Key_ToggleCallHangup)
            .define_value("Key_VoiceDial", Qt::Key::Key_VoiceDial)
            .define_value("Key_LastNumberRedial", Qt::Key::Key_LastNumberRedial)
            .define_value("Key_Camera", Qt::Key::Key_Camera)
            .define_value("Key_CameraFocus", Qt::Key::Key_CameraFocus)
            .define_value("Key_unknown", Qt::Key::Key_unknown);

    Enum<Qt::KeyboardModifier> rb_cQtKeyboardModifier =
        // Qt6::QtCore::Qt::KeyboardModifier
        define_enum_under<Qt::KeyboardModifier>("KeyboardModifier", rb_mQt)
            .define_value("NoModifier", Qt::KeyboardModifier::NoModifier)
            .define_value("ShiftModifier", Qt::KeyboardModifier::ShiftModifier)
            .define_value("ControlModifier", Qt::KeyboardModifier::ControlModifier)
            .define_value("AltModifier", Qt::KeyboardModifier::AltModifier)
            .define_value("MetaModifier", Qt::KeyboardModifier::MetaModifier)
            .define_value("KeypadModifier", Qt::KeyboardModifier::KeypadModifier)
            .define_value("GroupSwitchModifier", Qt::KeyboardModifier::GroupSwitchModifier)
            .define_value("KeyboardModifierMask", Qt::KeyboardModifier::KeyboardModifierMask);

    Enum<Qt::Modifier> rb_cQtModifier =
        // Qt6::QtCore::Qt::Modifier
        define_enum_under<Qt::Modifier>("Modifier", rb_mQt)
            .define_value("META", Qt::Modifier::META)
            .define_value("SHIFT", Qt::Modifier::SHIFT)
            .define_value("CTRL", Qt::Modifier::CTRL)
            .define_value("ALT", Qt::Modifier::ALT)
            .define_value("MODIFIER_MASK", Qt::Modifier::MODIFIER_MASK);

    Enum<Qt::ArrowType> rb_cQtArrowType =
        // Qt6::QtCore::Qt::ArrowType
        define_enum_under<Qt::ArrowType>("ArrowType", rb_mQt)
            .define_value("NoArrow", Qt::ArrowType::NoArrow)
            .define_value("UpArrow", Qt::ArrowType::UpArrow)
            .define_value("DownArrow", Qt::ArrowType::DownArrow)
            .define_value("LeftArrow", Qt::ArrowType::LeftArrow)
            .define_value("RightArrow", Qt::ArrowType::RightArrow);

    Enum<Qt::PenStyle> rb_cQtPenStyle =
        // Qt6::QtCore::Qt::PenStyle
        define_enum_under<Qt::PenStyle>("PenStyle", rb_mQt)
            .define_value("NoPen", Qt::PenStyle::NoPen)
            .define_value("SolidLine", Qt::PenStyle::SolidLine)
            .define_value("DashLine", Qt::PenStyle::DashLine)
            .define_value("DotLine", Qt::PenStyle::DotLine)
            .define_value("DashDotLine", Qt::PenStyle::DashDotLine)
            .define_value("DashDotDotLine", Qt::PenStyle::DashDotDotLine)
            .define_value("CustomDashLine", Qt::PenStyle::CustomDashLine)
            .define_value("MPenStyle", Qt::PenStyle::MPenStyle);

    Enum<Qt::PenCapStyle> rb_cQtPenCapStyle =
        // Qt6::QtCore::Qt::PenCapStyle
        define_enum_under<Qt::PenCapStyle>("PenCapStyle", rb_mQt)
            .define_value("FlatCap", Qt::PenCapStyle::FlatCap)
            .define_value("SquareCap", Qt::PenCapStyle::SquareCap)
            .define_value("RoundCap", Qt::PenCapStyle::RoundCap)
            .define_value("MPenCapStyle", Qt::PenCapStyle::MPenCapStyle);

    Enum<Qt::PenJoinStyle> rb_cQtPenJoinStyle =
        // Qt6::QtCore::Qt::PenJoinStyle
        define_enum_under<Qt::PenJoinStyle>("PenJoinStyle", rb_mQt)
            .define_value("MiterJoin", Qt::PenJoinStyle::MiterJoin)
            .define_value("BevelJoin", Qt::PenJoinStyle::BevelJoin)
            .define_value("RoundJoin", Qt::PenJoinStyle::RoundJoin)
            .define_value("SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin)
            .define_value("MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle);

    Enum<Qt::BrushStyle> rb_cQtBrushStyle =
        // Qt6::QtCore::Qt::BrushStyle
        define_enum_under<Qt::BrushStyle>("BrushStyle", rb_mQt)
            .define_value("NoBrush", Qt::BrushStyle::NoBrush)
            .define_value("SolidPattern", Qt::BrushStyle::SolidPattern)
            .define_value("Dense1Pattern", Qt::BrushStyle::Dense1Pattern)
            .define_value("Dense2Pattern", Qt::BrushStyle::Dense2Pattern)
            .define_value("Dense3Pattern", Qt::BrushStyle::Dense3Pattern)
            .define_value("Dense4Pattern", Qt::BrushStyle::Dense4Pattern)
            .define_value("Dense5Pattern", Qt::BrushStyle::Dense5Pattern)
            .define_value("Dense6Pattern", Qt::BrushStyle::Dense6Pattern)
            .define_value("Dense7Pattern", Qt::BrushStyle::Dense7Pattern)
            .define_value("HorPattern", Qt::BrushStyle::HorPattern)
            .define_value("VerPattern", Qt::BrushStyle::VerPattern)
            .define_value("CrossPattern", Qt::BrushStyle::CrossPattern)
            .define_value("BDiagPattern", Qt::BrushStyle::BDiagPattern)
            .define_value("FDiagPattern", Qt::BrushStyle::FDiagPattern)
            .define_value("DiagCrossPattern", Qt::BrushStyle::DiagCrossPattern)
            .define_value("LinearGradientPattern", Qt::BrushStyle::LinearGradientPattern)
            .define_value("RadialGradientPattern", Qt::BrushStyle::RadialGradientPattern)
            .define_value("ConicalGradientPattern", Qt::BrushStyle::ConicalGradientPattern)
            .define_value("TexturePattern", Qt::BrushStyle::TexturePattern);

    Enum<Qt::SizeMode> rb_cQtSizeMode =
        // Qt6::QtCore::Qt::SizeMode
        define_enum_under<Qt::SizeMode>("SizeMode", rb_mQt)
            .define_value("AbsoluteSize", Qt::SizeMode::AbsoluteSize)
            .define_value("RelativeSize", Qt::SizeMode::RelativeSize);

    Enum<Qt::UIEffect> rb_cQtUIEffect =
        // Qt6::QtCore::Qt::UIEffect
        define_enum_under<Qt::UIEffect>("UIEffect", rb_mQt)
            .define_value("UI_General", Qt::UIEffect::UI_General)
            .define_value("UI_AnimateMenu", Qt::UIEffect::UI_AnimateMenu)
            .define_value("UI_FadeMenu", Qt::UIEffect::UI_FadeMenu)
            .define_value("UI_AnimateCombo", Qt::UIEffect::UI_AnimateCombo)
            .define_value("UI_AnimateTooltip", Qt::UIEffect::UI_AnimateTooltip)
            .define_value("UI_FadeTooltip", Qt::UIEffect::UI_FadeTooltip)
            .define_value("UI_AnimateToolBox", Qt::UIEffect::UI_AnimateToolBox);

    Enum<Qt::CursorShape> rb_cQtCursorShape =
        // Qt6::QtCore::Qt::CursorShape
        define_enum_under<Qt::CursorShape>("CursorShape", rb_mQt)
            .define_value("ArrowCursor", Qt::CursorShape::ArrowCursor)
            .define_value("UpArrowCursor", Qt::CursorShape::UpArrowCursor)
            .define_value("CrossCursor", Qt::CursorShape::CrossCursor)
            .define_value("WaitCursor", Qt::CursorShape::WaitCursor)
            .define_value("IBeamCursor", Qt::CursorShape::IBeamCursor)
            .define_value("SizeVerCursor", Qt::CursorShape::SizeVerCursor)
            .define_value("SizeHorCursor", Qt::CursorShape::SizeHorCursor)
            .define_value("SizeBDiagCursor", Qt::CursorShape::SizeBDiagCursor)
            .define_value("SizeFDiagCursor", Qt::CursorShape::SizeFDiagCursor)
            .define_value("SizeAllCursor", Qt::CursorShape::SizeAllCursor)
            .define_value("BlankCursor", Qt::CursorShape::BlankCursor)
            .define_value("SplitVCursor", Qt::CursorShape::SplitVCursor)
            .define_value("SplitHCursor", Qt::CursorShape::SplitHCursor)
            .define_value("PointingHandCursor", Qt::CursorShape::PointingHandCursor)
            .define_value("ForbiddenCursor", Qt::CursorShape::ForbiddenCursor)
            .define_value("WhatsThisCursor", Qt::CursorShape::WhatsThisCursor)
            .define_value("BusyCursor", Qt::CursorShape::BusyCursor)
            .define_value("OpenHandCursor", Qt::CursorShape::OpenHandCursor)
            .define_value("ClosedHandCursor", Qt::CursorShape::ClosedHandCursor)
            .define_value("DragCopyCursor", Qt::CursorShape::DragCopyCursor)
            .define_value("DragMoveCursor", Qt::CursorShape::DragMoveCursor)
            .define_value("DragLinkCursor", Qt::CursorShape::DragLinkCursor)
            .define_value("LastCursor", Qt::CursorShape::LastCursor)
            .define_value("BitmapCursor", Qt::CursorShape::BitmapCursor)
            .define_value("CustomCursor", Qt::CursorShape::CustomCursor);

    Enum<Qt::TextFormat> rb_cQtTextFormat =
        // Qt6::QtCore::Qt::TextFormat
        define_enum_under<Qt::TextFormat>("TextFormat", rb_mQt)
            .define_value("PlainText", Qt::TextFormat::PlainText)
            .define_value("RichText", Qt::TextFormat::RichText)
            .define_value("AutoText", Qt::TextFormat::AutoText)
            .define_value("MarkdownText", Qt::TextFormat::MarkdownText);

    Enum<Qt::AspectRatioMode> rb_cQtAspectRatioMode =
        // Qt6::QtCore::Qt::AspectRatioMode
        define_enum_under<Qt::AspectRatioMode>("AspectRatioMode", rb_mQt)
            .define_value("IgnoreAspectRatio", Qt::AspectRatioMode::IgnoreAspectRatio)
            .define_value("KeepAspectRatio", Qt::AspectRatioMode::KeepAspectRatio)
            .define_value("KeepAspectRatioByExpanding", Qt::AspectRatioMode::KeepAspectRatioByExpanding);

    Enum<Qt::DockWidgetArea> rb_cQtDockWidgetArea =
        // Qt6::QtCore::Qt::DockWidgetArea
        define_enum_under<Qt::DockWidgetArea>("DockWidgetArea", rb_mQt)
            .define_value("LeftDockWidgetArea", Qt::DockWidgetArea::LeftDockWidgetArea)
            .define_value("RightDockWidgetArea", Qt::DockWidgetArea::RightDockWidgetArea)
            .define_value("TopDockWidgetArea", Qt::DockWidgetArea::TopDockWidgetArea)
            .define_value("BottomDockWidgetArea", Qt::DockWidgetArea::BottomDockWidgetArea)
            .define_value("DockWidgetArea_Mask", Qt::DockWidgetArea::DockWidgetArea_Mask)
            .define_value("AllDockWidgetAreas", Qt::DockWidgetArea::AllDockWidgetAreas)
            .define_value("NoDockWidgetArea", Qt::DockWidgetArea::NoDockWidgetArea);

    Enum<Qt::DockWidgetAreaSizes> rb_cQtDockWidgetAreaSizes =
        // Qt6::QtCore::Qt::DockWidgetAreaSizes
        define_enum_under<Qt::DockWidgetAreaSizes>("DockWidgetAreaSizes", rb_mQt)
            .define_value("NDockWidgetAreas", Qt::DockWidgetAreaSizes::NDockWidgetAreas);

    Enum<Qt::ToolBarArea> rb_cQtToolBarArea =
        // Qt6::QtCore::Qt::ToolBarArea
        define_enum_under<Qt::ToolBarArea>("ToolBarArea", rb_mQt)
            .define_value("LeftToolBarArea", Qt::ToolBarArea::LeftToolBarArea)
            .define_value("RightToolBarArea", Qt::ToolBarArea::RightToolBarArea)
            .define_value("TopToolBarArea", Qt::ToolBarArea::TopToolBarArea)
            .define_value("BottomToolBarArea", Qt::ToolBarArea::BottomToolBarArea)
            .define_value("ToolBarArea_Mask", Qt::ToolBarArea::ToolBarArea_Mask)
            .define_value("AllToolBarAreas", Qt::ToolBarArea::AllToolBarAreas)
            .define_value("NoToolBarArea", Qt::ToolBarArea::NoToolBarArea);

    Enum<Qt::ToolBarAreaSizes> rb_cQtToolBarAreaSizes =
        // Qt6::QtCore::Qt::ToolBarAreaSizes
        define_enum_under<Qt::ToolBarAreaSizes>("ToolBarAreaSizes", rb_mQt)
            .define_value("NToolBarAreas", Qt::ToolBarAreaSizes::NToolBarAreas);

    Enum<Qt::DateFormat> rb_cQtDateFormat =
        // Qt6::QtCore::Qt::DateFormat
        define_enum_under<Qt::DateFormat>("DateFormat", rb_mQt)
            .define_value("TextDate", Qt::DateFormat::TextDate)
            .define_value("ISODate", Qt::DateFormat::ISODate)
            .define_value("RFC2822Date", Qt::DateFormat::RFC2822Date)
            .define_value("ISODateWithMs", Qt::DateFormat::ISODateWithMs);

    Enum<Qt::TimeSpec> rb_cQtTimeSpec =
        // Qt6::QtCore::Qt::TimeSpec
        define_enum_under<Qt::TimeSpec>("TimeSpec", rb_mQt)
            .define_value("LocalTime", Qt::TimeSpec::LocalTime)
            .define_value("UTC", Qt::TimeSpec::UTC)
            .define_value("OffsetFromUTC", Qt::TimeSpec::OffsetFromUTC)
            .define_value("TimeZone", Qt::TimeSpec::TimeZone);

    Enum<Qt::DayOfWeek> rb_cQtDayOfWeek =
        // Qt6::QtCore::Qt::DayOfWeek
        define_enum_under<Qt::DayOfWeek>("DayOfWeek", rb_mQt)
            .define_value("Monday", Qt::DayOfWeek::Monday)
            .define_value("Tuesday", Qt::DayOfWeek::Tuesday)
            .define_value("Wednesday", Qt::DayOfWeek::Wednesday)
            .define_value("Thursday", Qt::DayOfWeek::Thursday)
            .define_value("Friday", Qt::DayOfWeek::Friday)
            .define_value("Saturday", Qt::DayOfWeek::Saturday)
            .define_value("Sunday", Qt::DayOfWeek::Sunday);

    Enum<Qt::ScrollBarPolicy> rb_cQtScrollBarPolicy =
        // Qt6::QtCore::Qt::ScrollBarPolicy
        define_enum_under<Qt::ScrollBarPolicy>("ScrollBarPolicy", rb_mQt)
            .define_value("ScrollBarAsNeeded", Qt::ScrollBarPolicy::ScrollBarAsNeeded)
            .define_value("ScrollBarAlwaysOff", Qt::ScrollBarPolicy::ScrollBarAlwaysOff)
            .define_value("ScrollBarAlwaysOn", Qt::ScrollBarPolicy::ScrollBarAlwaysOn);

    Enum<Qt::CaseSensitivity> rb_cQtCaseSensitivity =
        // Qt6::QtCore::Qt::CaseSensitivity
        define_enum_under<Qt::CaseSensitivity>("CaseSensitivity", rb_mQt)
            .define_value("CaseInsensitive", Qt::CaseSensitivity::CaseInsensitive)
            .define_value("CaseSensitive", Qt::CaseSensitivity::CaseSensitive);

    Enum<Qt::Corner> rb_cQtCorner =
        // Qt6::QtCore::Qt::Corner
        define_enum_under<Qt::Corner>("Corner", rb_mQt)
            .define_value("TopLeftCorner", Qt::Corner::TopLeftCorner)
            .define_value("TopRightCorner", Qt::Corner::TopRightCorner)
            .define_value("BottomLeftCorner", Qt::Corner::BottomLeftCorner)
            .define_value("BottomRightCorner", Qt::Corner::BottomRightCorner);

    Enum<Qt::Edge> rb_cQtEdge =
        // Qt6::QtCore::Qt::Edge
        define_enum_under<Qt::Edge>("Edge", rb_mQt)
            .define_value("TopEdge", Qt::Edge::TopEdge)
            .define_value("LeftEdge", Qt::Edge::LeftEdge)
            .define_value("RightEdge", Qt::Edge::RightEdge)
            .define_value("BottomEdge", Qt::Edge::BottomEdge);

    Enum<Qt::ConnectionType> rb_cQtConnectionType =
        // Qt6::QtCore::Qt::ConnectionType
        define_enum_under<Qt::ConnectionType>("ConnectionType", rb_mQt)
            .define_value("AutoConnection", Qt::ConnectionType::AutoConnection)
            .define_value("DirectConnection", Qt::ConnectionType::DirectConnection)
            .define_value("QueuedConnection", Qt::ConnectionType::QueuedConnection)
            .define_value("BlockingQueuedConnection", Qt::ConnectionType::BlockingQueuedConnection)
            .define_value("UniqueConnection", Qt::ConnectionType::UniqueConnection)
            .define_value("SingleShotConnection", Qt::ConnectionType::SingleShotConnection);

    Enum<Qt::ShortcutContext> rb_cQtShortcutContext =
        // Qt6::QtCore::Qt::ShortcutContext
        define_enum_under<Qt::ShortcutContext>("ShortcutContext", rb_mQt)
            .define_value("WidgetShortcut", Qt::ShortcutContext::WidgetShortcut)
            .define_value("WindowShortcut", Qt::ShortcutContext::WindowShortcut)
            .define_value("ApplicationShortcut", Qt::ShortcutContext::ApplicationShortcut)
            .define_value("WidgetWithChildrenShortcut", Qt::ShortcutContext::WidgetWithChildrenShortcut);

    Enum<Qt::FillRule> rb_cQtFillRule =
        // Qt6::QtCore::Qt::FillRule
        define_enum_under<Qt::FillRule>("FillRule", rb_mQt)
            .define_value("OddEvenFill", Qt::FillRule::OddEvenFill)
            .define_value("WindingFill", Qt::FillRule::WindingFill);

    Enum<Qt::MaskMode> rb_cQtMaskMode =
        // Qt6::QtCore::Qt::MaskMode
        define_enum_under<Qt::MaskMode>("MaskMode", rb_mQt)
            .define_value("MaskInColor", Qt::MaskMode::MaskInColor)
            .define_value("MaskOutColor", Qt::MaskMode::MaskOutColor);

    Enum<Qt::ClipOperation> rb_cQtClipOperation =
        // Qt6::QtCore::Qt::ClipOperation
        define_enum_under<Qt::ClipOperation>("ClipOperation", rb_mQt)
            .define_value("NoClip", Qt::ClipOperation::NoClip)
            .define_value("ReplaceClip", Qt::ClipOperation::ReplaceClip)
            .define_value("IntersectClip", Qt::ClipOperation::IntersectClip);

    Enum<Qt::ItemSelectionMode> rb_cQtItemSelectionMode =
        // Qt6::QtCore::Qt::ItemSelectionMode
        define_enum_under<Qt::ItemSelectionMode>("ItemSelectionMode", rb_mQt)
            .define_value("ContainsItemShape", Qt::ItemSelectionMode::ContainsItemShape)
            .define_value("IntersectsItemShape", Qt::ItemSelectionMode::IntersectsItemShape)
            .define_value("ContainsItemBoundingRect", Qt::ItemSelectionMode::ContainsItemBoundingRect)
            .define_value("IntersectsItemBoundingRect", Qt::ItemSelectionMode::IntersectsItemBoundingRect);

    Enum<Qt::ItemSelectionOperation> rb_cQtItemSelectionOperation =
        // Qt6::QtCore::Qt::ItemSelectionOperation
        define_enum_under<Qt::ItemSelectionOperation>("ItemSelectionOperation", rb_mQt)
            .define_value("ReplaceSelection", Qt::ItemSelectionOperation::ReplaceSelection)
            .define_value("AddToSelection", Qt::ItemSelectionOperation::AddToSelection);

    Enum<Qt::TransformationMode> rb_cQtTransformationMode =
        // Qt6::QtCore::Qt::TransformationMode
        define_enum_under<Qt::TransformationMode>("TransformationMode", rb_mQt)
            .define_value("FastTransformation", Qt::TransformationMode::FastTransformation)
            .define_value("SmoothTransformation", Qt::TransformationMode::SmoothTransformation);

    Enum<Qt::Axis> rb_cQtAxis =
        // Qt6::QtCore::Qt::Axis
        define_enum_under<Qt::Axis>("Axis", rb_mQt)
            .define_value("XAxis", Qt::Axis::XAxis)
            .define_value("YAxis", Qt::Axis::YAxis)
            .define_value("ZAxis", Qt::Axis::ZAxis);

    Enum<Qt::FocusReason> rb_cQtFocusReason =
        // Qt6::QtCore::Qt::FocusReason
        define_enum_under<Qt::FocusReason>("FocusReason", rb_mQt)
            .define_value("MouseFocusReason", Qt::FocusReason::MouseFocusReason)
            .define_value("TabFocusReason", Qt::FocusReason::TabFocusReason)
            .define_value("BacktabFocusReason", Qt::FocusReason::BacktabFocusReason)
            .define_value("ActiveWindowFocusReason", Qt::FocusReason::ActiveWindowFocusReason)
            .define_value("PopupFocusReason", Qt::FocusReason::PopupFocusReason)
            .define_value("ShortcutFocusReason", Qt::FocusReason::ShortcutFocusReason)
            .define_value("MenuBarFocusReason", Qt::FocusReason::MenuBarFocusReason)
            .define_value("OtherFocusReason", Qt::FocusReason::OtherFocusReason)
            .define_value("NoFocusReason", Qt::FocusReason::NoFocusReason);

    Enum<Qt::ContextMenuPolicy> rb_cQtContextMenuPolicy =
        // Qt6::QtCore::Qt::ContextMenuPolicy
        define_enum_under<Qt::ContextMenuPolicy>("ContextMenuPolicy", rb_mQt)
            .define_value("NoContextMenu", Qt::ContextMenuPolicy::NoContextMenu)
            .define_value("DefaultContextMenu", Qt::ContextMenuPolicy::DefaultContextMenu)
            .define_value("ActionsContextMenu", Qt::ContextMenuPolicy::ActionsContextMenu)
            .define_value("CustomContextMenu", Qt::ContextMenuPolicy::CustomContextMenu)
            .define_value("PreventContextMenu", Qt::ContextMenuPolicy::PreventContextMenu);

    Enum<Qt::ContextMenuTrigger> rb_cQtContextMenuTrigger =
        // Qt6::QtCore::Qt::ContextMenuTrigger
        define_enum_under<Qt::ContextMenuTrigger>("ContextMenuTrigger", rb_mQt)
            .define_value("Press", Qt::ContextMenuTrigger::Press)
            .define_value("Release", Qt::ContextMenuTrigger::Release);

    Enum<Qt::InputMethodQuery> rb_cQtInputMethodQuery =
        // Qt6::QtCore::Qt::InputMethodQuery
        define_enum_under<Qt::InputMethodQuery>("InputMethodQuery", rb_mQt)
            .define_value("ImEnabled", Qt::InputMethodQuery::ImEnabled)
            .define_value("ImCursorRectangle", Qt::InputMethodQuery::ImCursorRectangle)
            .define_value("ImFont", Qt::InputMethodQuery::ImFont)
            .define_value("ImCursorPosition", Qt::InputMethodQuery::ImCursorPosition)
            .define_value("ImSurroundingText", Qt::InputMethodQuery::ImSurroundingText)
            .define_value("ImCurrentSelection", Qt::InputMethodQuery::ImCurrentSelection)
            .define_value("ImMaximumTextLength", Qt::InputMethodQuery::ImMaximumTextLength)
            .define_value("ImAnchorPosition", Qt::InputMethodQuery::ImAnchorPosition)
            .define_value("ImHints", Qt::InputMethodQuery::ImHints)
            .define_value("ImPreferredLanguage", Qt::InputMethodQuery::ImPreferredLanguage)
            .define_value("ImAbsolutePosition", Qt::InputMethodQuery::ImAbsolutePosition)
            .define_value("ImTextBeforeCursor", Qt::InputMethodQuery::ImTextBeforeCursor)
            .define_value("ImTextAfterCursor", Qt::InputMethodQuery::ImTextAfterCursor)
            .define_value("ImEnterKeyType", Qt::InputMethodQuery::ImEnterKeyType)
            .define_value("ImAnchorRectangle", Qt::InputMethodQuery::ImAnchorRectangle)
            .define_value("ImInputItemClipRectangle", Qt::InputMethodQuery::ImInputItemClipRectangle)
            .define_value("ImReadOnly", Qt::InputMethodQuery::ImReadOnly)
            .define_value("ImPlatformData", Qt::InputMethodQuery::ImPlatformData)
            .define_value("ImQueryInput", Qt::InputMethodQuery::ImQueryInput)
            .define_value("ImQueryAll", Qt::InputMethodQuery::ImQueryAll);

    Enum<Qt::InputMethodHint> rb_cQtInputMethodHint =
        // Qt6::QtCore::Qt::InputMethodHint
        define_enum_under<Qt::InputMethodHint>("InputMethodHint", rb_mQt)
            .define_value("ImhNone", Qt::InputMethodHint::ImhNone)
            .define_value("ImhHiddenText", Qt::InputMethodHint::ImhHiddenText)
            .define_value("ImhSensitiveData", Qt::InputMethodHint::ImhSensitiveData)
            .define_value("ImhNoAutoUppercase", Qt::InputMethodHint::ImhNoAutoUppercase)
            .define_value("ImhPreferNumbers", Qt::InputMethodHint::ImhPreferNumbers)
            .define_value("ImhPreferUppercase", Qt::InputMethodHint::ImhPreferUppercase)
            .define_value("ImhPreferLowercase", Qt::InputMethodHint::ImhPreferLowercase)
            .define_value("ImhNoPredictiveText", Qt::InputMethodHint::ImhNoPredictiveText)
            .define_value("ImhDate", Qt::InputMethodHint::ImhDate)
            .define_value("ImhTime", Qt::InputMethodHint::ImhTime)
            .define_value("ImhPreferLatin", Qt::InputMethodHint::ImhPreferLatin)
            .define_value("ImhMultiLine", Qt::InputMethodHint::ImhMultiLine)
            .define_value("ImhNoEditMenu", Qt::InputMethodHint::ImhNoEditMenu)
            .define_value("ImhNoTextHandles", Qt::InputMethodHint::ImhNoTextHandles)
            .define_value("ImhDigitsOnly", Qt::InputMethodHint::ImhDigitsOnly)
            .define_value("ImhFormattedNumbersOnly", Qt::InputMethodHint::ImhFormattedNumbersOnly)
            .define_value("ImhUppercaseOnly", Qt::InputMethodHint::ImhUppercaseOnly)
            .define_value("ImhLowercaseOnly", Qt::InputMethodHint::ImhLowercaseOnly)
            .define_value("ImhDialableCharactersOnly", Qt::InputMethodHint::ImhDialableCharactersOnly)
            .define_value("ImhEmailCharactersOnly", Qt::InputMethodHint::ImhEmailCharactersOnly)
            .define_value("ImhUrlCharactersOnly", Qt::InputMethodHint::ImhUrlCharactersOnly)
            .define_value("ImhLatinOnly", Qt::InputMethodHint::ImhLatinOnly)
            .define_value("ImhExclusiveInputMask", Qt::InputMethodHint::ImhExclusiveInputMask);

    Enum<Qt::EnterKeyType> rb_cQtEnterKeyType =
        // Qt6::QtCore::Qt::EnterKeyType
        define_enum_under<Qt::EnterKeyType>("EnterKeyType", rb_mQt)
            .define_value("EnterKeyDefault", Qt::EnterKeyType::EnterKeyDefault)
            .define_value("EnterKeyReturn", Qt::EnterKeyType::EnterKeyReturn)
            .define_value("EnterKeyDone", Qt::EnterKeyType::EnterKeyDone)
            .define_value("EnterKeyGo", Qt::EnterKeyType::EnterKeyGo)
            .define_value("EnterKeySend", Qt::EnterKeyType::EnterKeySend)
            .define_value("EnterKeySearch", Qt::EnterKeyType::EnterKeySearch)
            .define_value("EnterKeyNext", Qt::EnterKeyType::EnterKeyNext)
            .define_value("EnterKeyPrevious", Qt::EnterKeyType::EnterKeyPrevious);

    Enum<Qt::ToolButtonStyle> rb_cQtToolButtonStyle =
        // Qt6::QtCore::Qt::ToolButtonStyle
        define_enum_under<Qt::ToolButtonStyle>("ToolButtonStyle", rb_mQt)
            .define_value("ToolButtonIconOnly", Qt::ToolButtonStyle::ToolButtonIconOnly)
            .define_value("ToolButtonTextOnly", Qt::ToolButtonStyle::ToolButtonTextOnly)
            .define_value("ToolButtonTextBesideIcon", Qt::ToolButtonStyle::ToolButtonTextBesideIcon)
            .define_value("ToolButtonTextUnderIcon", Qt::ToolButtonStyle::ToolButtonTextUnderIcon)
            .define_value("ToolButtonFollowStyle", Qt::ToolButtonStyle::ToolButtonFollowStyle);

    Enum<Qt::LayoutDirection> rb_cQtLayoutDirection =
        // Qt6::QtCore::Qt::LayoutDirection
        define_enum_under<Qt::LayoutDirection>("LayoutDirection", rb_mQt)
            .define_value("LeftToRight", Qt::LayoutDirection::LeftToRight)
            .define_value("RightToLeft", Qt::LayoutDirection::RightToLeft)
            .define_value("LayoutDirectionAuto", Qt::LayoutDirection::LayoutDirectionAuto);

    Enum<Qt::AnchorPoint> rb_cQtAnchorPoint =
        // Qt6::QtCore::Qt::AnchorPoint
        define_enum_under<Qt::AnchorPoint>("AnchorPoint", rb_mQt)
            .define_value("AnchorLeft", Qt::AnchorPoint::AnchorLeft)
            .define_value("AnchorHorizontalCenter", Qt::AnchorPoint::AnchorHorizontalCenter)
            .define_value("AnchorRight", Qt::AnchorPoint::AnchorRight)
            .define_value("AnchorTop", Qt::AnchorPoint::AnchorTop)
            .define_value("AnchorVerticalCenter", Qt::AnchorPoint::AnchorVerticalCenter)
            .define_value("AnchorBottom", Qt::AnchorPoint::AnchorBottom);

    Enum<Qt::FindChildOption> rb_cQtFindChildOption =
        // Qt6::QtCore::Qt::FindChildOption
        define_enum_under<Qt::FindChildOption>("FindChildOption", rb_mQt)
            .define_value("FindDirectChildrenOnly", Qt::FindChildOption::FindDirectChildrenOnly)
            .define_value("FindChildrenRecursively", Qt::FindChildOption::FindChildrenRecursively);

    Enum<Qt::DropAction> rb_cQtDropAction =
        // Qt6::QtCore::Qt::DropAction
        define_enum_under<Qt::DropAction>("DropAction", rb_mQt)
            .define_value("CopyAction", Qt::DropAction::CopyAction)
            .define_value("MoveAction", Qt::DropAction::MoveAction)
            .define_value("LinkAction", Qt::DropAction::LinkAction)
            .define_value("ActionMask", Qt::DropAction::ActionMask)
            .define_value("TargetMoveAction", Qt::DropAction::TargetMoveAction)
            .define_value("IgnoreAction", Qt::DropAction::IgnoreAction);

    Enum<Qt::CheckState> rb_cQtCheckState =
        // Qt6::QtCore::Qt::CheckState
        define_enum_under<Qt::CheckState>("CheckState", rb_mQt)
            .define_value("Unchecked", Qt::CheckState::Unchecked)
            .define_value("PartiallyChecked", Qt::CheckState::PartiallyChecked)
            .define_value("Checked", Qt::CheckState::Checked);

    Enum<Qt::ItemDataRole> rb_cQtItemDataRole =
        // Qt6::QtCore::Qt::ItemDataRole
        define_enum_under<Qt::ItemDataRole>("ItemDataRole", rb_mQt)
            .define_value("DisplayRole", Qt::ItemDataRole::DisplayRole)
            .define_value("DecorationRole", Qt::ItemDataRole::DecorationRole)
            .define_value("EditRole", Qt::ItemDataRole::EditRole)
            .define_value("ToolTipRole", Qt::ItemDataRole::ToolTipRole)
            .define_value("StatusTipRole", Qt::ItemDataRole::StatusTipRole)
            .define_value("WhatsThisRole", Qt::ItemDataRole::WhatsThisRole)
            .define_value("FontRole", Qt::ItemDataRole::FontRole)
            .define_value("TextAlignmentRole", Qt::ItemDataRole::TextAlignmentRole)
            .define_value("BackgroundRole", Qt::ItemDataRole::BackgroundRole)
            .define_value("ForegroundRole", Qt::ItemDataRole::ForegroundRole)
            .define_value("CheckStateRole", Qt::ItemDataRole::CheckStateRole)
            .define_value("AccessibleTextRole", Qt::ItemDataRole::AccessibleTextRole)
            .define_value("AccessibleDescriptionRole", Qt::ItemDataRole::AccessibleDescriptionRole)
            .define_value("SizeHintRole", Qt::ItemDataRole::SizeHintRole)
            .define_value("InitialSortOrderRole", Qt::ItemDataRole::InitialSortOrderRole)
            .define_value("DisplayPropertyRole", Qt::ItemDataRole::DisplayPropertyRole)
            .define_value("DecorationPropertyRole", Qt::ItemDataRole::DecorationPropertyRole)
            .define_value("ToolTipPropertyRole", Qt::ItemDataRole::ToolTipPropertyRole)
            .define_value("StatusTipPropertyRole", Qt::ItemDataRole::StatusTipPropertyRole)
            .define_value("WhatsThisPropertyRole", Qt::ItemDataRole::WhatsThisPropertyRole)
            .define_value("UserRole", Qt::ItemDataRole::UserRole);

    Enum<Qt::ItemFlag> rb_cQtItemFlag =
        // Qt6::QtCore::Qt::ItemFlag
        define_enum_under<Qt::ItemFlag>("ItemFlag", rb_mQt)
            .define_value("NoItemFlags", Qt::ItemFlag::NoItemFlags)
            .define_value("ItemIsSelectable", Qt::ItemFlag::ItemIsSelectable)
            .define_value("ItemIsEditable", Qt::ItemFlag::ItemIsEditable)
            .define_value("ItemIsDragEnabled", Qt::ItemFlag::ItemIsDragEnabled)
            .define_value("ItemIsDropEnabled", Qt::ItemFlag::ItemIsDropEnabled)
            .define_value("ItemIsUserCheckable", Qt::ItemFlag::ItemIsUserCheckable)
            .define_value("ItemIsEnabled", Qt::ItemFlag::ItemIsEnabled)
            .define_value("ItemIsAutoTristate", Qt::ItemFlag::ItemIsAutoTristate)
            .define_value("ItemNeverHasChildren", Qt::ItemFlag::ItemNeverHasChildren)
            .define_value("ItemIsUserTristate", Qt::ItemFlag::ItemIsUserTristate);

    Enum<Qt::MatchFlag> rb_cQtMatchFlag =
        // Qt6::QtCore::Qt::MatchFlag
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

    Enum<Qt::WindowModality> rb_cQtWindowModality =
        // Qt6::QtCore::Qt::WindowModality
        define_enum_under<Qt::WindowModality>("WindowModality", rb_mQt)
            .define_value("NonModal", Qt::WindowModality::NonModal)
            .define_value("WindowModal", Qt::WindowModality::WindowModal)
            .define_value("ApplicationModal", Qt::WindowModality::ApplicationModal);

    Enum<Qt::TextInteractionFlag> rb_cQtTextInteractionFlag =
        // Qt6::QtCore::Qt::TextInteractionFlag
        define_enum_under<Qt::TextInteractionFlag>("TextInteractionFlag", rb_mQt)
            .define_value("NoTextInteraction", Qt::TextInteractionFlag::NoTextInteraction)
            .define_value("TextSelectableByMouse", Qt::TextInteractionFlag::TextSelectableByMouse)
            .define_value("TextSelectableByKeyboard", Qt::TextInteractionFlag::TextSelectableByKeyboard)
            .define_value("LinksAccessibleByMouse", Qt::TextInteractionFlag::LinksAccessibleByMouse)
            .define_value("LinksAccessibleByKeyboard", Qt::TextInteractionFlag::LinksAccessibleByKeyboard)
            .define_value("TextEditable", Qt::TextInteractionFlag::TextEditable)
            .define_value("TextEditorInteraction", Qt::TextInteractionFlag::TextEditorInteraction)
            .define_value("TextBrowserInteraction", Qt::TextInteractionFlag::TextBrowserInteraction);

    Enum<Qt::EventPriority> rb_cQtEventPriority =
        // Qt6::QtCore::Qt::EventPriority
        define_enum_under<Qt::EventPriority>("EventPriority", rb_mQt)
            .define_value("HighEventPriority", Qt::EventPriority::HighEventPriority)
            .define_value("NormalEventPriority", Qt::EventPriority::NormalEventPriority)
            .define_value("LowEventPriority", Qt::EventPriority::LowEventPriority);

    Enum<Qt::SizeHint> rb_cQtSizeHint =
        // Qt6::QtCore::Qt::SizeHint
        define_enum_under<Qt::SizeHint>("SizeHint", rb_mQt)
            .define_value("MinimumSize", Qt::SizeHint::MinimumSize)
            .define_value("PreferredSize", Qt::SizeHint::PreferredSize)
            .define_value("MaximumSize", Qt::SizeHint::MaximumSize)
            .define_value("MinimumDescent", Qt::SizeHint::MinimumDescent)
            .define_value("NSizeHints", Qt::SizeHint::NSizeHints);

    Enum<Qt::WindowFrameSection> rb_cQtWindowFrameSection =
        // Qt6::QtCore::Qt::WindowFrameSection
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

    Enum<Qt::Initialization> rb_cQtInitialization =
        // Qt6::QtCore::Qt::Initialization
        define_enum_under<Qt::Initialization>("Initialization", rb_mQt)
            .define_value("Uninitialized", Qt::Initialization::Uninitialized);

    Enum<Qt::CoordinateSystem> rb_cQtCoordinateSystem =
        // Qt6::QtCore::Qt::CoordinateSystem
        define_enum_under<Qt::CoordinateSystem>("CoordinateSystem", rb_mQt)
            .define_value("DeviceCoordinates", Qt::CoordinateSystem::DeviceCoordinates)
            .define_value("LogicalCoordinates", Qt::CoordinateSystem::LogicalCoordinates);

    Enum<Qt::TouchPointState> rb_cQtTouchPointState =
        // Qt6::QtCore::Qt::TouchPointState
        define_enum_under<Qt::TouchPointState>("TouchPointState", rb_mQt)
            .define_value("TouchPointUnknownState", Qt::TouchPointState::TouchPointUnknownState)
            .define_value("TouchPointPressed", Qt::TouchPointState::TouchPointPressed)
            .define_value("TouchPointMoved", Qt::TouchPointState::TouchPointMoved)
            .define_value("TouchPointStationary", Qt::TouchPointState::TouchPointStationary)
            .define_value("TouchPointReleased", Qt::TouchPointState::TouchPointReleased);

    Enum<Qt::GestureState> rb_cQtGestureState =
        // Qt6::QtCore::Qt::GestureState
        define_enum_under<Qt::GestureState>("GestureState", rb_mQt)
            .define_value("NoGesture", Qt::GestureState::NoGesture)
            .define_value("GestureStarted", Qt::GestureState::GestureStarted)
            .define_value("GestureUpdated", Qt::GestureState::GestureUpdated)
            .define_value("GestureFinished", Qt::GestureState::GestureFinished)
            .define_value("GestureCanceled", Qt::GestureState::GestureCanceled);

    Enum<Qt::GestureType> rb_cQtGestureType =
        // Qt6::QtCore::Qt::GestureType
        define_enum_under<Qt::GestureType>("GestureType", rb_mQt)
            .define_value("TapGesture", Qt::GestureType::TapGesture)
            .define_value("TapAndHoldGesture", Qt::GestureType::TapAndHoldGesture)
            .define_value("PanGesture", Qt::GestureType::PanGesture)
            .define_value("PinchGesture", Qt::GestureType::PinchGesture)
            .define_value("SwipeGesture", Qt::GestureType::SwipeGesture)
            .define_value("CustomGesture", Qt::GestureType::CustomGesture)
            .define_value("LastGestureType", Qt::GestureType::LastGestureType);

    Enum<Qt::GestureFlag> rb_cQtGestureFlag =
        // Qt6::QtCore::Qt::GestureFlag
        define_enum_under<Qt::GestureFlag>("GestureFlag", rb_mQt)
            .define_value("DontStartGestureOnChildren", Qt::GestureFlag::DontStartGestureOnChildren)
            .define_value("ReceivePartialGestures", Qt::GestureFlag::ReceivePartialGestures)
            .define_value("IgnoredGesturesPropagateToParent", Qt::GestureFlag::IgnoredGesturesPropagateToParent);

    Enum<Qt::NativeGestureType> rb_cQtNativeGestureType =
        // Qt6::QtCore::Qt::NativeGestureType
        define_enum_under<Qt::NativeGestureType>("NativeGestureType", rb_mQt)
            .define_value("BeginNativeGesture", Qt::NativeGestureType::BeginNativeGesture)
            .define_value("EndNativeGesture", Qt::NativeGestureType::EndNativeGesture)
            .define_value("PanNativeGesture", Qt::NativeGestureType::PanNativeGesture)
            .define_value("ZoomNativeGesture", Qt::NativeGestureType::ZoomNativeGesture)
            .define_value("SmartZoomNativeGesture", Qt::NativeGestureType::SmartZoomNativeGesture)
            .define_value("RotateNativeGesture", Qt::NativeGestureType::RotateNativeGesture)
            .define_value("SwipeNativeGesture", Qt::NativeGestureType::SwipeNativeGesture);

    Enum<Qt::NavigationMode> rb_cQtNavigationMode =
        // Qt6::QtCore::Qt::NavigationMode
        define_enum_under<Qt::NavigationMode>("NavigationMode", rb_mQt)
            .define_value("NavigationModeNone", Qt::NavigationMode::NavigationModeNone)
            .define_value("NavigationModeKeypadTabOrder", Qt::NavigationMode::NavigationModeKeypadTabOrder)
            .define_value("NavigationModeKeypadDirectional", Qt::NavigationMode::NavigationModeKeypadDirectional)
            .define_value("NavigationModeCursorAuto", Qt::NavigationMode::NavigationModeCursorAuto)
            .define_value("NavigationModeCursorForceVisible", Qt::NavigationMode::NavigationModeCursorForceVisible);

    Enum<Qt::CursorMoveStyle> rb_cQtCursorMoveStyle =
        // Qt6::QtCore::Qt::CursorMoveStyle
        define_enum_under<Qt::CursorMoveStyle>("CursorMoveStyle", rb_mQt)
            .define_value("LogicalMoveStyle", Qt::CursorMoveStyle::LogicalMoveStyle)
            .define_value("VisualMoveStyle", Qt::CursorMoveStyle::VisualMoveStyle);

    Enum<Qt::TimerType> rb_cQtTimerType =
        // Qt6::QtCore::Qt::TimerType
        define_enum_under<Qt::TimerType>("TimerType", rb_mQt)
            .define_value("PreciseTimer", Qt::TimerType::PreciseTimer)
            .define_value("CoarseTimer", Qt::TimerType::CoarseTimer)
            .define_value("VeryCoarseTimer", Qt::TimerType::VeryCoarseTimer);

    Enum<Qt::TimerId> rb_cQtTimerId =
        // Qt6::QtCore::Qt::TimerId
        define_enum_under<Qt::TimerId>("TimerId", rb_mQt)
            .define_value("Invalid", Qt::TimerId::Invalid);

    Enum<Qt::ScrollPhase> rb_cQtScrollPhase =
        // Qt6::QtCore::Qt::ScrollPhase
        define_enum_under<Qt::ScrollPhase>("ScrollPhase", rb_mQt)
            .define_value("NoScrollPhase", Qt::ScrollPhase::NoScrollPhase)
            .define_value("ScrollBegin", Qt::ScrollPhase::ScrollBegin)
            .define_value("ScrollUpdate", Qt::ScrollPhase::ScrollUpdate)
            .define_value("ScrollEnd", Qt::ScrollPhase::ScrollEnd)
            .define_value("ScrollMomentum", Qt::ScrollPhase::ScrollMomentum);

    Enum<Qt::MouseEventSource> rb_cQtMouseEventSource =
        // Qt6::QtCore::Qt::MouseEventSource
        define_enum_under<Qt::MouseEventSource>("MouseEventSource", rb_mQt)
            .define_value("MouseEventNotSynthesized", Qt::MouseEventSource::MouseEventNotSynthesized)
            .define_value("MouseEventSynthesizedBySystem", Qt::MouseEventSource::MouseEventSynthesizedBySystem)
            .define_value("MouseEventSynthesizedByQt", Qt::MouseEventSource::MouseEventSynthesizedByQt)
            .define_value("MouseEventSynthesizedByApplication", Qt::MouseEventSource::MouseEventSynthesizedByApplication);

    Enum<Qt::MouseEventFlag> rb_cQtMouseEventFlag =
        // Qt6::QtCore::Qt::MouseEventFlag
        define_enum_under<Qt::MouseEventFlag>("MouseEventFlag", rb_mQt)
            .define_value("NoMouseEventFlag", Qt::MouseEventFlag::NoMouseEventFlag)
            .define_value("MouseEventCreatedDoubleClick", Qt::MouseEventFlag::MouseEventCreatedDoubleClick)
            .define_value("MouseEventFlagMask", Qt::MouseEventFlag::MouseEventFlagMask);

    Enum<Qt::ChecksumType> rb_cQtChecksumType =
        // Qt6::QtCore::Qt::ChecksumType
        define_enum_under<Qt::ChecksumType>("ChecksumType", rb_mQt)
            .define_value("ChecksumIso3309", Qt::ChecksumType::ChecksumIso3309)
            .define_value("ChecksumItuV41", Qt::ChecksumType::ChecksumItuV41);

    Enum<Qt::HighDpiScaleFactorRoundingPolicy> rb_cQtHighDpiScaleFactorRoundingPolicy =
        // Qt6::QtCore::Qt::HighDpiScaleFactorRoundingPolicy
        define_enum_under<Qt::HighDpiScaleFactorRoundingPolicy>("HighDpiScaleFactorRoundingPolicy", rb_mQt)
            .define_value("Unset", Qt::HighDpiScaleFactorRoundingPolicy::Unset)
            .define_value("Round", Qt::HighDpiScaleFactorRoundingPolicy::Round)
            .define_value("Ceil", Qt::HighDpiScaleFactorRoundingPolicy::Ceil)
            .define_value("Floor", Qt::HighDpiScaleFactorRoundingPolicy::Floor)
            .define_value("RoundPreferFloor", Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor)
            .define_value("PassThrough", Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    Enum<Qt::PermissionStatus> rb_cQtPermissionStatus =
        // Qt6::QtCore::Qt::PermissionStatus
        define_enum_under<Qt::PermissionStatus>("PermissionStatus", rb_mQt)
            .define_value("Undetermined", Qt::PermissionStatus::Undetermined)
            .define_value("Granted", Qt::PermissionStatus::Granted)
            .define_value("Denied", Qt::PermissionStatus::Denied);
}
