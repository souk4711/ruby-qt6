#include "qt-enum-sz-rb.hpp"
#include <qnamespace.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qt_enum_sz(Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Data_Type<Qt::ScreenOrientation> rb_cQtScreenOrientation =
        // RubyQt6::QtCore::Qt::ScreenOrientation
        define_qenum_under<Qt::ScreenOrientation>(rb_mQt, "ScreenOrientation");
        define_qenum_value_under(rb_cQtScreenOrientation, "PrimaryOrientation", Qt::ScreenOrientation::PrimaryOrientation);
        define_qenum_value_under(rb_cQtScreenOrientation, "PortraitOrientation", Qt::ScreenOrientation::PortraitOrientation);
        define_qenum_value_under(rb_cQtScreenOrientation, "LandscapeOrientation", Qt::ScreenOrientation::LandscapeOrientation);
        define_qenum_value_under(rb_cQtScreenOrientation, "InvertedPortraitOrientation", Qt::ScreenOrientation::InvertedPortraitOrientation);
        define_qenum_value_under(rb_cQtScreenOrientation, "InvertedLandscapeOrientation", Qt::ScreenOrientation::InvertedLandscapeOrientation);

    Data_Type<Qt::ScrollBarPolicy> rb_cQtScrollBarPolicy =
        // RubyQt6::QtCore::Qt::ScrollBarPolicy
        define_qenum_under<Qt::ScrollBarPolicy>(rb_mQt, "ScrollBarPolicy");
        define_qenum_value_under(rb_cQtScrollBarPolicy, "ScrollBarAsNeeded", Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        define_qenum_value_under(rb_cQtScrollBarPolicy, "ScrollBarAlwaysOff", Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        define_qenum_value_under(rb_cQtScrollBarPolicy, "ScrollBarAlwaysOn", Qt::ScrollBarPolicy::ScrollBarAlwaysOn);

    Data_Type<Qt::ScrollPhase> rb_cQtScrollPhase =
        // RubyQt6::QtCore::Qt::ScrollPhase
        define_qenum_under<Qt::ScrollPhase>(rb_mQt, "ScrollPhase");
        define_qenum_value_under(rb_cQtScrollPhase, "NoScrollPhase", Qt::ScrollPhase::NoScrollPhase);
        define_qenum_value_under(rb_cQtScrollPhase, "ScrollBegin", Qt::ScrollPhase::ScrollBegin);
        define_qenum_value_under(rb_cQtScrollPhase, "ScrollUpdate", Qt::ScrollPhase::ScrollUpdate);
        define_qenum_value_under(rb_cQtScrollPhase, "ScrollEnd", Qt::ScrollPhase::ScrollEnd);
        define_qenum_value_under(rb_cQtScrollPhase, "ScrollMomentum", Qt::ScrollPhase::ScrollMomentum);

    Data_Type<Qt::ShortcutContext> rb_cQtShortcutContext =
        // RubyQt6::QtCore::Qt::ShortcutContext
        define_qenum_under<Qt::ShortcutContext>(rb_mQt, "ShortcutContext");
        define_qenum_value_under(rb_cQtShortcutContext, "WidgetShortcut", Qt::ShortcutContext::WidgetShortcut);
        define_qenum_value_under(rb_cQtShortcutContext, "WindowShortcut", Qt::ShortcutContext::WindowShortcut);
        define_qenum_value_under(rb_cQtShortcutContext, "ApplicationShortcut", Qt::ShortcutContext::ApplicationShortcut);
        define_qenum_value_under(rb_cQtShortcutContext, "WidgetWithChildrenShortcut", Qt::ShortcutContext::WidgetWithChildrenShortcut);

    Data_Type<Qt::SizeHint> rb_cQtSizeHint =
        // RubyQt6::QtCore::Qt::SizeHint
        define_qenum_under<Qt::SizeHint>(rb_mQt, "SizeHint");
        define_qenum_value_under(rb_cQtSizeHint, "MinimumSize", Qt::SizeHint::MinimumSize);
        define_qenum_value_under(rb_cQtSizeHint, "PreferredSize", Qt::SizeHint::PreferredSize);
        define_qenum_value_under(rb_cQtSizeHint, "MaximumSize", Qt::SizeHint::MaximumSize);
        define_qenum_value_under(rb_cQtSizeHint, "MinimumDescent", Qt::SizeHint::MinimumDescent);
        define_qenum_value_under(rb_cQtSizeHint, "NSizeHints", Qt::SizeHint::NSizeHints);

    Data_Type<Qt::SizeMode> rb_cQtSizeMode =
        // RubyQt6::QtCore::Qt::SizeMode
        define_qenum_under<Qt::SizeMode>(rb_mQt, "SizeMode");
        define_qenum_value_under(rb_cQtSizeMode, "AbsoluteSize", Qt::SizeMode::AbsoluteSize);
        define_qenum_value_under(rb_cQtSizeMode, "RelativeSize", Qt::SizeMode::RelativeSize);

    Data_Type<Qt::SortOrder> rb_cQtSortOrder =
        // RubyQt6::QtCore::Qt::SortOrder
        define_qenum_under<Qt::SortOrder>(rb_mQt, "SortOrder");
        define_qenum_value_under(rb_cQtSortOrder, "AscendingOrder", Qt::SortOrder::AscendingOrder);
        define_qenum_value_under(rb_cQtSortOrder, "DescendingOrder", Qt::SortOrder::DescendingOrder);

    Data_Type<Qt::SplitBehaviorFlags> rb_cQtSplitBehaviorFlags =
        // RubyQt6::QtCore::Qt::SplitBehaviorFlags
        define_qenum_under<Qt::SplitBehaviorFlags>(rb_mQt, "SplitBehaviorFlags");
        define_qenum_value_under(rb_cQtSplitBehaviorFlags, "KeepEmptyParts", Qt::SplitBehaviorFlags::KeepEmptyParts);
        define_qenum_value_under(rb_cQtSplitBehaviorFlags, "SkipEmptyParts", Qt::SplitBehaviorFlags::SkipEmptyParts);

    Data_Type<Qt::TabFocusBehavior> rb_cQtTabFocusBehavior =
        // RubyQt6::QtCore::Qt::TabFocusBehavior
        define_qenum_under<Qt::TabFocusBehavior>(rb_mQt, "TabFocusBehavior");
        define_qenum_value_under(rb_cQtTabFocusBehavior, "NoTabFocus", Qt::TabFocusBehavior::NoTabFocus);
        define_qenum_value_under(rb_cQtTabFocusBehavior, "TabFocusTextControls", Qt::TabFocusBehavior::TabFocusTextControls);
        define_qenum_value_under(rb_cQtTabFocusBehavior, "TabFocusListControls", Qt::TabFocusBehavior::TabFocusListControls);
        define_qenum_value_under(rb_cQtTabFocusBehavior, "TabFocusAllControls", Qt::TabFocusBehavior::TabFocusAllControls);

    Data_Type<Qt::TextElideMode> rb_cQtTextElideMode =
        // RubyQt6::QtCore::Qt::TextElideMode
        define_qenum_under<Qt::TextElideMode>(rb_mQt, "TextElideMode");
        define_qenum_value_under(rb_cQtTextElideMode, "ElideLeft", Qt::TextElideMode::ElideLeft);
        define_qenum_value_under(rb_cQtTextElideMode, "ElideRight", Qt::TextElideMode::ElideRight);
        define_qenum_value_under(rb_cQtTextElideMode, "ElideMiddle", Qt::TextElideMode::ElideMiddle);
        define_qenum_value_under(rb_cQtTextElideMode, "ElideNone", Qt::TextElideMode::ElideNone);

    Data_Type<Qt::TextFlag> rb_cQtTextFlag =
        // RubyQt6::QtCore::Qt::TextFlag
        define_qenum_under<Qt::TextFlag>(rb_mQt, "TextFlag");
        define_qenum_value_under(rb_cQtTextFlag, "TextSingleLine", Qt::TextFlag::TextSingleLine);
        define_qenum_value_under(rb_cQtTextFlag, "TextDontClip", Qt::TextFlag::TextDontClip);
        define_qenum_value_under(rb_cQtTextFlag, "TextExpandTabs", Qt::TextFlag::TextExpandTabs);
        define_qenum_value_under(rb_cQtTextFlag, "TextShowMnemonic", Qt::TextFlag::TextShowMnemonic);
        define_qenum_value_under(rb_cQtTextFlag, "TextWordWrap", Qt::TextFlag::TextWordWrap);
        define_qenum_value_under(rb_cQtTextFlag, "TextWrapAnywhere", Qt::TextFlag::TextWrapAnywhere);
        define_qenum_value_under(rb_cQtTextFlag, "TextDontPrint", Qt::TextFlag::TextDontPrint);
        define_qenum_value_under(rb_cQtTextFlag, "TextIncludeTrailingSpaces", Qt::TextFlag::TextIncludeTrailingSpaces);
        define_qenum_value_under(rb_cQtTextFlag, "TextHideMnemonic", Qt::TextFlag::TextHideMnemonic);
        define_qenum_value_under(rb_cQtTextFlag, "TextJustificationForced", Qt::TextFlag::TextJustificationForced);
        define_qenum_value_under(rb_cQtTextFlag, "TextForceLeftToRight", Qt::TextFlag::TextForceLeftToRight);
        define_qenum_value_under(rb_cQtTextFlag, "TextForceRightToLeft", Qt::TextFlag::TextForceRightToLeft);
        define_qenum_value_under(rb_cQtTextFlag, "TextLongestVariant", Qt::TextFlag::TextLongestVariant);

    Data_Type<Qt::TextFormat> rb_cQtTextFormat =
        // RubyQt6::QtCore::Qt::TextFormat
        define_qenum_under<Qt::TextFormat>(rb_mQt, "TextFormat");
        define_qenum_value_under(rb_cQtTextFormat, "PlainText", Qt::TextFormat::PlainText);
        define_qenum_value_under(rb_cQtTextFormat, "RichText", Qt::TextFormat::RichText);
        define_qenum_value_under(rb_cQtTextFormat, "AutoText", Qt::TextFormat::AutoText);
        define_qenum_value_under(rb_cQtTextFormat, "MarkdownText", Qt::TextFormat::MarkdownText);

    Data_Type<Qt::TextInteractionFlag> rb_cQtTextInteractionFlag =
        // RubyQt6::QtCore::Qt::TextInteractionFlag
        define_qenum_under<Qt::TextInteractionFlag>(rb_mQt, "TextInteractionFlag");
        define_qenum_value_under(rb_cQtTextInteractionFlag, "NoTextInteraction", Qt::TextInteractionFlag::NoTextInteraction);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "TextSelectableByMouse", Qt::TextInteractionFlag::TextSelectableByMouse);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "TextSelectableByKeyboard", Qt::TextInteractionFlag::TextSelectableByKeyboard);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "LinksAccessibleByMouse", Qt::TextInteractionFlag::LinksAccessibleByMouse);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "LinksAccessibleByKeyboard", Qt::TextInteractionFlag::LinksAccessibleByKeyboard);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "TextEditable", Qt::TextInteractionFlag::TextEditable);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "TextEditorInteraction", Qt::TextInteractionFlag::TextEditorInteraction);
        define_qenum_value_under(rb_cQtTextInteractionFlag, "TextBrowserInteraction", Qt::TextInteractionFlag::TextBrowserInteraction);

    Data_Type<Qt::TileRule> rb_cQtTileRule =
        // RubyQt6::QtCore::Qt::TileRule
        define_qenum_under<Qt::TileRule>(rb_mQt, "TileRule");
        define_qenum_value_under(rb_cQtTileRule, "StretchTile", Qt::TileRule::StretchTile);
        define_qenum_value_under(rb_cQtTileRule, "RepeatTile", Qt::TileRule::RepeatTile);
        define_qenum_value_under(rb_cQtTileRule, "RoundTile", Qt::TileRule::RoundTile);

    Data_Type<Qt::TimeSpec> rb_cQtTimeSpec =
        // RubyQt6::QtCore::Qt::TimeSpec
        define_qenum_under<Qt::TimeSpec>(rb_mQt, "TimeSpec");
        define_qenum_value_under(rb_cQtTimeSpec, "LocalTime", Qt::TimeSpec::LocalTime);
        define_qenum_value_under(rb_cQtTimeSpec, "UTC", Qt::TimeSpec::UTC);
        define_qenum_value_under(rb_cQtTimeSpec, "OffsetFromUTC", Qt::TimeSpec::OffsetFromUTC);
        define_qenum_value_under(rb_cQtTimeSpec, "TimeZone", Qt::TimeSpec::TimeZone);

    Data_Type<Qt::TimerId> rb_cQtTimerId =
        // RubyQt6::QtCore::Qt::TimerId
        define_qenum_under<Qt::TimerId>(rb_mQt, "TimerId");
        define_qenum_value_under(rb_cQtTimerId, "Invalid", Qt::TimerId::Invalid);

    Data_Type<Qt::TimerType> rb_cQtTimerType =
        // RubyQt6::QtCore::Qt::TimerType
        define_qenum_under<Qt::TimerType>(rb_mQt, "TimerType");
        define_qenum_value_under(rb_cQtTimerType, "PreciseTimer", Qt::TimerType::PreciseTimer);
        define_qenum_value_under(rb_cQtTimerType, "CoarseTimer", Qt::TimerType::CoarseTimer);
        define_qenum_value_under(rb_cQtTimerType, "VeryCoarseTimer", Qt::TimerType::VeryCoarseTimer);

    Data_Type<Qt::ToolBarArea> rb_cQtToolBarArea =
        // RubyQt6::QtCore::Qt::ToolBarArea
        define_qenum_under<Qt::ToolBarArea>(rb_mQt, "ToolBarArea");
        define_qenum_value_under(rb_cQtToolBarArea, "LeftToolBarArea", Qt::ToolBarArea::LeftToolBarArea);
        define_qenum_value_under(rb_cQtToolBarArea, "RightToolBarArea", Qt::ToolBarArea::RightToolBarArea);
        define_qenum_value_under(rb_cQtToolBarArea, "TopToolBarArea", Qt::ToolBarArea::TopToolBarArea);
        define_qenum_value_under(rb_cQtToolBarArea, "BottomToolBarArea", Qt::ToolBarArea::BottomToolBarArea);
        define_qenum_value_under(rb_cQtToolBarArea, "ToolBarArea_Mask", Qt::ToolBarArea::ToolBarArea_Mask);
        define_qenum_value_under(rb_cQtToolBarArea, "AllToolBarAreas", Qt::ToolBarArea::AllToolBarAreas);
        define_qenum_value_under(rb_cQtToolBarArea, "NoToolBarArea", Qt::ToolBarArea::NoToolBarArea);

    Data_Type<Qt::ToolBarAreaSizes> rb_cQtToolBarAreaSizes =
        // RubyQt6::QtCore::Qt::ToolBarAreaSizes
        define_qenum_under<Qt::ToolBarAreaSizes>(rb_mQt, "ToolBarAreaSizes");
        define_qenum_value_under(rb_cQtToolBarAreaSizes, "NToolBarAreas", Qt::ToolBarAreaSizes::NToolBarAreas);

    Data_Type<Qt::ToolButtonStyle> rb_cQtToolButtonStyle =
        // RubyQt6::QtCore::Qt::ToolButtonStyle
        define_qenum_under<Qt::ToolButtonStyle>(rb_mQt, "ToolButtonStyle");
        define_qenum_value_under(rb_cQtToolButtonStyle, "ToolButtonIconOnly", Qt::ToolButtonStyle::ToolButtonIconOnly);
        define_qenum_value_under(rb_cQtToolButtonStyle, "ToolButtonTextOnly", Qt::ToolButtonStyle::ToolButtonTextOnly);
        define_qenum_value_under(rb_cQtToolButtonStyle, "ToolButtonTextBesideIcon", Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
        define_qenum_value_under(rb_cQtToolButtonStyle, "ToolButtonTextUnderIcon", Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        define_qenum_value_under(rb_cQtToolButtonStyle, "ToolButtonFollowStyle", Qt::ToolButtonStyle::ToolButtonFollowStyle);

    Data_Type<Qt::TouchPointState> rb_cQtTouchPointState =
        // RubyQt6::QtCore::Qt::TouchPointState
        define_qenum_under<Qt::TouchPointState>(rb_mQt, "TouchPointState");
        define_qenum_value_under(rb_cQtTouchPointState, "TouchPointUnknownState", Qt::TouchPointState::TouchPointUnknownState);
        define_qenum_value_under(rb_cQtTouchPointState, "TouchPointPressed", Qt::TouchPointState::TouchPointPressed);
        define_qenum_value_under(rb_cQtTouchPointState, "TouchPointMoved", Qt::TouchPointState::TouchPointMoved);
        define_qenum_value_under(rb_cQtTouchPointState, "TouchPointStationary", Qt::TouchPointState::TouchPointStationary);
        define_qenum_value_under(rb_cQtTouchPointState, "TouchPointReleased", Qt::TouchPointState::TouchPointReleased);

    Data_Type<Qt::TransformationMode> rb_cQtTransformationMode =
        // RubyQt6::QtCore::Qt::TransformationMode
        define_qenum_under<Qt::TransformationMode>(rb_mQt, "TransformationMode");
        define_qenum_value_under(rb_cQtTransformationMode, "FastTransformation", Qt::TransformationMode::FastTransformation);
        define_qenum_value_under(rb_cQtTransformationMode, "SmoothTransformation", Qt::TransformationMode::SmoothTransformation);

    Data_Type<Qt::UIEffect> rb_cQtUIEffect =
        // RubyQt6::QtCore::Qt::UIEffect
        define_qenum_under<Qt::UIEffect>(rb_mQt, "UIEffect");
        define_qenum_value_under(rb_cQtUIEffect, "UI_General", Qt::UIEffect::UI_General);
        define_qenum_value_under(rb_cQtUIEffect, "UI_AnimateMenu", Qt::UIEffect::UI_AnimateMenu);
        define_qenum_value_under(rb_cQtUIEffect, "UI_FadeMenu", Qt::UIEffect::UI_FadeMenu);
        define_qenum_value_under(rb_cQtUIEffect, "UI_AnimateCombo", Qt::UIEffect::UI_AnimateCombo);
        define_qenum_value_under(rb_cQtUIEffect, "UI_AnimateTooltip", Qt::UIEffect::UI_AnimateTooltip);
        define_qenum_value_under(rb_cQtUIEffect, "UI_FadeTooltip", Qt::UIEffect::UI_FadeTooltip);
        define_qenum_value_under(rb_cQtUIEffect, "UI_AnimateToolBox", Qt::UIEffect::UI_AnimateToolBox);

    Data_Type<Qt::WhiteSpaceMode> rb_cQtWhiteSpaceMode =
        // RubyQt6::QtCore::Qt::WhiteSpaceMode
        define_qenum_under<Qt::WhiteSpaceMode>(rb_mQt, "WhiteSpaceMode");
        define_qenum_value_under(rb_cQtWhiteSpaceMode, "WhiteSpaceNormal", Qt::WhiteSpaceMode::WhiteSpaceNormal);
        define_qenum_value_under(rb_cQtWhiteSpaceMode, "WhiteSpacePre", Qt::WhiteSpaceMode::WhiteSpacePre);
        define_qenum_value_under(rb_cQtWhiteSpaceMode, "WhiteSpaceNoWrap", Qt::WhiteSpaceMode::WhiteSpaceNoWrap);
        define_qenum_value_under(rb_cQtWhiteSpaceMode, "WhiteSpaceModeUndefined", Qt::WhiteSpaceMode::WhiteSpaceModeUndefined);

    Data_Type<Qt::WidgetAttribute> rb_cQtWidgetAttribute =
        // RubyQt6::QtCore::Qt::WidgetAttribute
        define_qenum_under<Qt::WidgetAttribute>(rb_mQt, "WidgetAttribute");
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_Disabled", Qt::WidgetAttribute::WA_Disabled);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_UnderMouse", Qt::WidgetAttribute::WA_UnderMouse);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MouseTracking", Qt::WidgetAttribute::WA_MouseTracking);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_OpaquePaintEvent", Qt::WidgetAttribute::WA_OpaquePaintEvent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_StaticContents", Qt::WidgetAttribute::WA_StaticContents);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_LaidOut", Qt::WidgetAttribute::WA_LaidOut);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_PaintOnScreen", Qt::WidgetAttribute::WA_PaintOnScreen);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoSystemBackground", Qt::WidgetAttribute::WA_NoSystemBackground);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_UpdatesDisabled", Qt::WidgetAttribute::WA_UpdatesDisabled);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_Mapped", Qt::WidgetAttribute::WA_Mapped);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_InputMethodEnabled", Qt::WidgetAttribute::WA_InputMethodEnabled);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_Visible", Qt::WidgetAttribute::WA_WState_Visible);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_Hidden", Qt::WidgetAttribute::WA_WState_Hidden);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_ForceDisabled", Qt::WidgetAttribute::WA_ForceDisabled);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_KeyCompression", Qt::WidgetAttribute::WA_KeyCompression);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_PendingMoveEvent", Qt::WidgetAttribute::WA_PendingMoveEvent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_PendingResizeEvent", Qt::WidgetAttribute::WA_PendingResizeEvent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetPalette", Qt::WidgetAttribute::WA_SetPalette);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetFont", Qt::WidgetAttribute::WA_SetFont);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetCursor", Qt::WidgetAttribute::WA_SetCursor);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoChildEventsFromChildren", Qt::WidgetAttribute::WA_NoChildEventsFromChildren);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WindowModified", Qt::WidgetAttribute::WA_WindowModified);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_Resized", Qt::WidgetAttribute::WA_Resized);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_Moved", Qt::WidgetAttribute::WA_Moved);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_PendingUpdate", Qt::WidgetAttribute::WA_PendingUpdate);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_InvalidSize", Qt::WidgetAttribute::WA_InvalidSize);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_CustomWhatsThis", Qt::WidgetAttribute::WA_CustomWhatsThis);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_LayoutOnEntireRect", Qt::WidgetAttribute::WA_LayoutOnEntireRect);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_OutsideWSRange", Qt::WidgetAttribute::WA_OutsideWSRange);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_GrabbedShortcut", Qt::WidgetAttribute::WA_GrabbedShortcut);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_TransparentForMouseEvents", Qt::WidgetAttribute::WA_TransparentForMouseEvents);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_PaintUnclipped", Qt::WidgetAttribute::WA_PaintUnclipped);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetWindowIcon", Qt::WidgetAttribute::WA_SetWindowIcon);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoMouseReplay", Qt::WidgetAttribute::WA_NoMouseReplay);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_DeleteOnClose", Qt::WidgetAttribute::WA_DeleteOnClose);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_RightToLeft", Qt::WidgetAttribute::WA_RightToLeft);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetLayoutDirection", Qt::WidgetAttribute::WA_SetLayoutDirection);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoChildEventsForParent", Qt::WidgetAttribute::WA_NoChildEventsForParent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_ForceUpdatesDisabled", Qt::WidgetAttribute::WA_ForceUpdatesDisabled);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_Created", Qt::WidgetAttribute::WA_WState_Created);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_CompressKeys", Qt::WidgetAttribute::WA_WState_CompressKeys);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_InPaintEvent", Qt::WidgetAttribute::WA_WState_InPaintEvent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_Reparented", Qt::WidgetAttribute::WA_WState_Reparented);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_ConfigPending", Qt::WidgetAttribute::WA_WState_ConfigPending);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_Polished", Qt::WidgetAttribute::WA_WState_Polished);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_OwnSizePolicy", Qt::WidgetAttribute::WA_WState_OwnSizePolicy);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_ExplicitShowHide", Qt::WidgetAttribute::WA_WState_ExplicitShowHide);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_ShowModal", Qt::WidgetAttribute::WA_ShowModal);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MouseNoMask", Qt::WidgetAttribute::WA_MouseNoMask);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoMousePropagation", Qt::WidgetAttribute::WA_NoMousePropagation);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_Hover", Qt::WidgetAttribute::WA_Hover);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_InputMethodTransparent", Qt::WidgetAttribute::WA_InputMethodTransparent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_QuitOnClose", Qt::WidgetAttribute::WA_QuitOnClose);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_KeyboardFocusChange", Qt::WidgetAttribute::WA_KeyboardFocusChange);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_AcceptDrops", Qt::WidgetAttribute::WA_AcceptDrops);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_DropSiteRegistered", Qt::WidgetAttribute::WA_DropSiteRegistered);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WindowPropagation", Qt::WidgetAttribute::WA_WindowPropagation);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NoX11EventCompression", Qt::WidgetAttribute::WA_NoX11EventCompression);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_TintedBackground", Qt::WidgetAttribute::WA_TintedBackground);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11OpenGLOverlay", Qt::WidgetAttribute::WA_X11OpenGLOverlay);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_AlwaysShowToolTips", Qt::WidgetAttribute::WA_AlwaysShowToolTips);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacOpaqueSizeGrip", Qt::WidgetAttribute::WA_MacOpaqueSizeGrip);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetStyle", Qt::WidgetAttribute::WA_SetStyle);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetLocale", Qt::WidgetAttribute::WA_SetLocale);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacShowFocusRect", Qt::WidgetAttribute::WA_MacShowFocusRect);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacNormalSize", Qt::WidgetAttribute::WA_MacNormalSize);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacSmallSize", Qt::WidgetAttribute::WA_MacSmallSize);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacMiniSize", Qt::WidgetAttribute::WA_MacMiniSize);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_LayoutUsesWidgetRect", Qt::WidgetAttribute::WA_LayoutUsesWidgetRect);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_StyledBackground", Qt::WidgetAttribute::WA_StyledBackground);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_CanHostQMdiSubWindowTitleBar", Qt::WidgetAttribute::WA_CanHostQMdiSubWindowTitleBar);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_MacAlwaysShowToolWindow", Qt::WidgetAttribute::WA_MacAlwaysShowToolWindow);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_StyleSheet", Qt::WidgetAttribute::WA_StyleSheet);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_ShowWithoutActivating", Qt::WidgetAttribute::WA_ShowWithoutActivating);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11BypassTransientForHint", Qt::WidgetAttribute::WA_X11BypassTransientForHint);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_NativeWindow", Qt::WidgetAttribute::WA_NativeWindow);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_DontCreateNativeAncestors", Qt::WidgetAttribute::WA_DontCreateNativeAncestors);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_DontShowOnScreen", Qt::WidgetAttribute::WA_DontShowOnScreen);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeDesktop", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDesktop);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeDock", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDock);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeToolBar", Qt::WidgetAttribute::WA_X11NetWmWindowTypeToolBar);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypeMenu);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeUtility", Qt::WidgetAttribute::WA_X11NetWmWindowTypeUtility);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeSplash", Qt::WidgetAttribute::WA_X11NetWmWindowTypeSplash);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeDialog", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDialog);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeDropDownMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDropDownMenu);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypePopupMenu", Qt::WidgetAttribute::WA_X11NetWmWindowTypePopupMenu);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeToolTip", Qt::WidgetAttribute::WA_X11NetWmWindowTypeToolTip);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeNotification", Qt::WidgetAttribute::WA_X11NetWmWindowTypeNotification);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeCombo", Qt::WidgetAttribute::WA_X11NetWmWindowTypeCombo);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11NetWmWindowTypeDND", Qt::WidgetAttribute::WA_X11NetWmWindowTypeDND);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_SetWindowModality", Qt::WidgetAttribute::WA_SetWindowModality);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_WindowOpacitySet", Qt::WidgetAttribute::WA_WState_WindowOpacitySet);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_TranslucentBackground", Qt::WidgetAttribute::WA_TranslucentBackground);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_AcceptTouchEvents", Qt::WidgetAttribute::WA_AcceptTouchEvents);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_WState_AcceptedTouchBeginEvent", Qt::WidgetAttribute::WA_WState_AcceptedTouchBeginEvent);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_TouchPadAcceptSingleTouchEvents", Qt::WidgetAttribute::WA_TouchPadAcceptSingleTouchEvents);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_X11DoNotAcceptFocus", Qt::WidgetAttribute::WA_X11DoNotAcceptFocus);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_AlwaysStackOnTop", Qt::WidgetAttribute::WA_AlwaysStackOnTop);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_TabletTracking", Qt::WidgetAttribute::WA_TabletTracking);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_ContentsMarginsRespectsSafeArea", Qt::WidgetAttribute::WA_ContentsMarginsRespectsSafeArea);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_StyleSheetTarget", Qt::WidgetAttribute::WA_StyleSheetTarget);
        define_qenum_value_under(rb_cQtWidgetAttribute, "WA_AttributeCount", Qt::WidgetAttribute::WA_AttributeCount);

    Data_Type<Qt::WindowFrameSection> rb_cQtWindowFrameSection =
        // RubyQt6::QtCore::Qt::WindowFrameSection
        define_qenum_under<Qt::WindowFrameSection>(rb_mQt, "WindowFrameSection");
        define_qenum_value_under(rb_cQtWindowFrameSection, "NoSection", Qt::WindowFrameSection::NoSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "LeftSection", Qt::WindowFrameSection::LeftSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "TopLeftSection", Qt::WindowFrameSection::TopLeftSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "TopSection", Qt::WindowFrameSection::TopSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "TopRightSection", Qt::WindowFrameSection::TopRightSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "RightSection", Qt::WindowFrameSection::RightSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "BottomRightSection", Qt::WindowFrameSection::BottomRightSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "BottomSection", Qt::WindowFrameSection::BottomSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "BottomLeftSection", Qt::WindowFrameSection::BottomLeftSection);
        define_qenum_value_under(rb_cQtWindowFrameSection, "TitleBarArea", Qt::WindowFrameSection::TitleBarArea);

    Data_Type<Qt::WindowModality> rb_cQtWindowModality =
        // RubyQt6::QtCore::Qt::WindowModality
        define_qenum_under<Qt::WindowModality>(rb_mQt, "WindowModality");
        define_qenum_value_under(rb_cQtWindowModality, "NonModal", Qt::WindowModality::NonModal);
        define_qenum_value_under(rb_cQtWindowModality, "WindowModal", Qt::WindowModality::WindowModal);
        define_qenum_value_under(rb_cQtWindowModality, "ApplicationModal", Qt::WindowModality::ApplicationModal);

    Data_Type<Qt::WindowState> rb_cQtWindowState =
        // RubyQt6::QtCore::Qt::WindowState
        define_qenum_under<Qt::WindowState>(rb_mQt, "WindowState");
        define_qenum_value_under(rb_cQtWindowState, "WindowNoState", Qt::WindowState::WindowNoState);
        define_qenum_value_under(rb_cQtWindowState, "WindowMinimized", Qt::WindowState::WindowMinimized);
        define_qenum_value_under(rb_cQtWindowState, "WindowMaximized", Qt::WindowState::WindowMaximized);
        define_qenum_value_under(rb_cQtWindowState, "WindowFullScreen", Qt::WindowState::WindowFullScreen);
        define_qenum_value_under(rb_cQtWindowState, "WindowActive", Qt::WindowState::WindowActive);

    Data_Type<Qt::WindowType> rb_cQtWindowType =
        // RubyQt6::QtCore::Qt::WindowType
        define_qenum_under<Qt::WindowType>(rb_mQt, "WindowType");
        define_qenum_value_under(rb_cQtWindowType, "Widget", Qt::WindowType::Widget);
        define_qenum_value_under(rb_cQtWindowType, "Window", Qt::WindowType::Window);
        define_qenum_value_under(rb_cQtWindowType, "Dialog", Qt::WindowType::Dialog);
        define_qenum_value_under(rb_cQtWindowType, "Sheet", Qt::WindowType::Sheet);
        define_qenum_value_under(rb_cQtWindowType, "Drawer", Qt::WindowType::Drawer);
        define_qenum_value_under(rb_cQtWindowType, "Popup", Qt::WindowType::Popup);
        define_qenum_value_under(rb_cQtWindowType, "Tool", Qt::WindowType::Tool);
        define_qenum_value_under(rb_cQtWindowType, "ToolTip", Qt::WindowType::ToolTip);
        define_qenum_value_under(rb_cQtWindowType, "SplashScreen", Qt::WindowType::SplashScreen);
        define_qenum_value_under(rb_cQtWindowType, "Desktop", Qt::WindowType::Desktop);
        define_qenum_value_under(rb_cQtWindowType, "SubWindow", Qt::WindowType::SubWindow);
        define_qenum_value_under(rb_cQtWindowType, "ForeignWindow", Qt::WindowType::ForeignWindow);
        define_qenum_value_under(rb_cQtWindowType, "CoverWindow", Qt::WindowType::CoverWindow);
        define_qenum_value_under(rb_cQtWindowType, "WindowType_Mask", Qt::WindowType::WindowType_Mask);
        define_qenum_value_under(rb_cQtWindowType, "MSWindowsFixedSizeDialogHint", Qt::WindowType::MSWindowsFixedSizeDialogHint);
        define_qenum_value_under(rb_cQtWindowType, "MSWindowsOwnDC", Qt::WindowType::MSWindowsOwnDC);
        define_qenum_value_under(rb_cQtWindowType, "BypassWindowManagerHint", Qt::WindowType::BypassWindowManagerHint);
        define_qenum_value_under(rb_cQtWindowType, "X11BypassWindowManagerHint", Qt::WindowType::X11BypassWindowManagerHint);
        define_qenum_value_under(rb_cQtWindowType, "FramelessWindowHint", Qt::WindowType::FramelessWindowHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowTitleHint", Qt::WindowType::WindowTitleHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowSystemMenuHint", Qt::WindowType::WindowSystemMenuHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowMinimizeButtonHint", Qt::WindowType::WindowMinimizeButtonHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowMaximizeButtonHint", Qt::WindowType::WindowMaximizeButtonHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowMinMaxButtonsHint", Qt::WindowType::WindowMinMaxButtonsHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowContextHelpButtonHint", Qt::WindowType::WindowContextHelpButtonHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowShadeButtonHint", Qt::WindowType::WindowShadeButtonHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowStaysOnTopHint", Qt::WindowType::WindowStaysOnTopHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowTransparentForInput", Qt::WindowType::WindowTransparentForInput);
        define_qenum_value_under(rb_cQtWindowType, "WindowOverridesSystemGestures", Qt::WindowType::WindowOverridesSystemGestures);
        define_qenum_value_under(rb_cQtWindowType, "WindowDoesNotAcceptFocus", Qt::WindowType::WindowDoesNotAcceptFocus);
        define_qenum_value_under(rb_cQtWindowType, "ExpandedClientAreaHint", Qt::WindowType::ExpandedClientAreaHint);
        define_qenum_value_under(rb_cQtWindowType, "NoTitleBarBackgroundHint", Qt::WindowType::NoTitleBarBackgroundHint);
        define_qenum_value_under(rb_cQtWindowType, "CustomizeWindowHint", Qt::WindowType::CustomizeWindowHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowStaysOnBottomHint", Qt::WindowType::WindowStaysOnBottomHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowCloseButtonHint", Qt::WindowType::WindowCloseButtonHint);
        define_qenum_value_under(rb_cQtWindowType, "BypassGraphicsProxyWidget", Qt::WindowType::BypassGraphicsProxyWidget);
        define_qenum_value_under(rb_cQtWindowType, "NoDropShadowWindowHint", Qt::WindowType::NoDropShadowWindowHint);
        define_qenum_value_under(rb_cQtWindowType, "WindowFullscreenButtonHint", Qt::WindowType::WindowFullscreenButtonHint);
}
