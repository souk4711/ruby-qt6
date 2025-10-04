#include "qt-enum-al-rb.hpp"
#include <qnamespace.h>

using namespace Rice;

void Init_qt_enum_al(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Enum<Qt::AlignmentFlag> rb_cQtAlignmentFlag =
        // RubyQt6::QtCore::Qt::AlignmentFlag
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

    Enum<Qt::AnchorPoint> rb_cQtAnchorPoint =
        // RubyQt6::QtCore::Qt::AnchorPoint
        define_enum_under<Qt::AnchorPoint>("AnchorPoint", rb_mQt)
            .define_value("AnchorLeft", Qt::AnchorPoint::AnchorLeft)
            .define_value("AnchorHorizontalCenter", Qt::AnchorPoint::AnchorHorizontalCenter)
            .define_value("AnchorRight", Qt::AnchorPoint::AnchorRight)
            .define_value("AnchorTop", Qt::AnchorPoint::AnchorTop)
            .define_value("AnchorVerticalCenter", Qt::AnchorPoint::AnchorVerticalCenter)
            .define_value("AnchorBottom", Qt::AnchorPoint::AnchorBottom);

    Enum<Qt::ApplicationAttribute> rb_cQtApplicationAttribute =
        // RubyQt6::QtCore::Qt::ApplicationAttribute
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

    Enum<Qt::ApplicationState> rb_cQtApplicationState =
        // RubyQt6::QtCore::Qt::ApplicationState
        define_enum_under<Qt::ApplicationState>("ApplicationState", rb_mQt)
            .define_value("ApplicationSuspended", Qt::ApplicationState::ApplicationSuspended)
            .define_value("ApplicationHidden", Qt::ApplicationState::ApplicationHidden)
            .define_value("ApplicationInactive", Qt::ApplicationState::ApplicationInactive)
            .define_value("ApplicationActive", Qt::ApplicationState::ApplicationActive);

    Enum<Qt::ArrowType> rb_cQtArrowType =
        // RubyQt6::QtCore::Qt::ArrowType
        define_enum_under<Qt::ArrowType>("ArrowType", rb_mQt)
            .define_value("NoArrow", Qt::ArrowType::NoArrow)
            .define_value("UpArrow", Qt::ArrowType::UpArrow)
            .define_value("DownArrow", Qt::ArrowType::DownArrow)
            .define_value("LeftArrow", Qt::ArrowType::LeftArrow)
            .define_value("RightArrow", Qt::ArrowType::RightArrow);

    Enum<Qt::AspectRatioMode> rb_cQtAspectRatioMode =
        // RubyQt6::QtCore::Qt::AspectRatioMode
        define_enum_under<Qt::AspectRatioMode>("AspectRatioMode", rb_mQt)
            .define_value("IgnoreAspectRatio", Qt::AspectRatioMode::IgnoreAspectRatio)
            .define_value("KeepAspectRatio", Qt::AspectRatioMode::KeepAspectRatio)
            .define_value("KeepAspectRatioByExpanding", Qt::AspectRatioMode::KeepAspectRatioByExpanding);

    Enum<Qt::Axis> rb_cQtAxis =
        // RubyQt6::QtCore::Qt::Axis
        define_enum_under<Qt::Axis>("Axis", rb_mQt)
            .define_value("XAxis", Qt::Axis::XAxis)
            .define_value("YAxis", Qt::Axis::YAxis)
            .define_value("ZAxis", Qt::Axis::ZAxis);

    Enum<Qt::BGMode> rb_cQtBGMode =
        // RubyQt6::QtCore::Qt::BGMode
        define_enum_under<Qt::BGMode>("BGMode", rb_mQt)
            .define_value("TransparentMode", Qt::BGMode::TransparentMode)
            .define_value("OpaqueMode", Qt::BGMode::OpaqueMode);

    Enum<Qt::BrushStyle> rb_cQtBrushStyle =
        // RubyQt6::QtCore::Qt::BrushStyle
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

    Enum<Qt::CaseSensitivity> rb_cQtCaseSensitivity =
        // RubyQt6::QtCore::Qt::CaseSensitivity
        define_enum_under<Qt::CaseSensitivity>("CaseSensitivity", rb_mQt)
            .define_value("CaseInsensitive", Qt::CaseSensitivity::CaseInsensitive)
            .define_value("CaseSensitive", Qt::CaseSensitivity::CaseSensitive);

    Enum<Qt::CheckState> rb_cQtCheckState =
        // RubyQt6::QtCore::Qt::CheckState
        define_enum_under<Qt::CheckState>("CheckState", rb_mQt)
            .define_value("Unchecked", Qt::CheckState::Unchecked)
            .define_value("PartiallyChecked", Qt::CheckState::PartiallyChecked)
            .define_value("Checked", Qt::CheckState::Checked);

    Enum<Qt::ChecksumType> rb_cQtChecksumType =
        // RubyQt6::QtCore::Qt::ChecksumType
        define_enum_under<Qt::ChecksumType>("ChecksumType", rb_mQt)
            .define_value("ChecksumIso3309", Qt::ChecksumType::ChecksumIso3309)
            .define_value("ChecksumItuV41", Qt::ChecksumType::ChecksumItuV41);

    Enum<Qt::ClipOperation> rb_cQtClipOperation =
        // RubyQt6::QtCore::Qt::ClipOperation
        define_enum_under<Qt::ClipOperation>("ClipOperation", rb_mQt)
            .define_value("NoClip", Qt::ClipOperation::NoClip)
            .define_value("ReplaceClip", Qt::ClipOperation::ReplaceClip)
            .define_value("IntersectClip", Qt::ClipOperation::IntersectClip);

    Enum<Qt::ColorScheme> rb_cQtColorScheme =
        // RubyQt6::QtCore::Qt::ColorScheme
        define_enum_under<Qt::ColorScheme>("ColorScheme", rb_mQt)
            .define_value("Unknown", Qt::ColorScheme::Unknown)
            .define_value("Light", Qt::ColorScheme::Light)
            .define_value("Dark", Qt::ColorScheme::Dark);

    Enum<Qt::ConnectionType> rb_cQtConnectionType =
        // RubyQt6::QtCore::Qt::ConnectionType
        define_enum_under<Qt::ConnectionType>("ConnectionType", rb_mQt)
            .define_value("AutoConnection", Qt::ConnectionType::AutoConnection)
            .define_value("DirectConnection", Qt::ConnectionType::DirectConnection)
            .define_value("QueuedConnection", Qt::ConnectionType::QueuedConnection)
            .define_value("BlockingQueuedConnection", Qt::ConnectionType::BlockingQueuedConnection)
            .define_value("UniqueConnection", Qt::ConnectionType::UniqueConnection)
            .define_value("SingleShotConnection", Qt::ConnectionType::SingleShotConnection);

    Enum<Qt::ContextMenuPolicy> rb_cQtContextMenuPolicy =
        // RubyQt6::QtCore::Qt::ContextMenuPolicy
        define_enum_under<Qt::ContextMenuPolicy>("ContextMenuPolicy", rb_mQt)
            .define_value("NoContextMenu", Qt::ContextMenuPolicy::NoContextMenu)
            .define_value("DefaultContextMenu", Qt::ContextMenuPolicy::DefaultContextMenu)
            .define_value("ActionsContextMenu", Qt::ContextMenuPolicy::ActionsContextMenu)
            .define_value("CustomContextMenu", Qt::ContextMenuPolicy::CustomContextMenu)
            .define_value("PreventContextMenu", Qt::ContextMenuPolicy::PreventContextMenu);

    Enum<Qt::ContextMenuTrigger> rb_cQtContextMenuTrigger =
        // RubyQt6::QtCore::Qt::ContextMenuTrigger
        define_enum_under<Qt::ContextMenuTrigger>("ContextMenuTrigger", rb_mQt)
            .define_value("Press", Qt::ContextMenuTrigger::Press)
            .define_value("Release", Qt::ContextMenuTrigger::Release);

    Enum<Qt::CoordinateSystem> rb_cQtCoordinateSystem =
        // RubyQt6::QtCore::Qt::CoordinateSystem
        define_enum_under<Qt::CoordinateSystem>("CoordinateSystem", rb_mQt)
            .define_value("DeviceCoordinates", Qt::CoordinateSystem::DeviceCoordinates)
            .define_value("LogicalCoordinates", Qt::CoordinateSystem::LogicalCoordinates);

    Enum<Qt::Corner> rb_cQtCorner =
        // RubyQt6::QtCore::Qt::Corner
        define_enum_under<Qt::Corner>("Corner", rb_mQt)
            .define_value("TopLeftCorner", Qt::Corner::TopLeftCorner)
            .define_value("TopRightCorner", Qt::Corner::TopRightCorner)
            .define_value("BottomLeftCorner", Qt::Corner::BottomLeftCorner)
            .define_value("BottomRightCorner", Qt::Corner::BottomRightCorner);

    Enum<Qt::CursorMoveStyle> rb_cQtCursorMoveStyle =
        // RubyQt6::QtCore::Qt::CursorMoveStyle
        define_enum_under<Qt::CursorMoveStyle>("CursorMoveStyle", rb_mQt)
            .define_value("LogicalMoveStyle", Qt::CursorMoveStyle::LogicalMoveStyle)
            .define_value("VisualMoveStyle", Qt::CursorMoveStyle::VisualMoveStyle);

    Enum<Qt::CursorShape> rb_cQtCursorShape =
        // RubyQt6::QtCore::Qt::CursorShape
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

    Enum<Qt::DateFormat> rb_cQtDateFormat =
        // RubyQt6::QtCore::Qt::DateFormat
        define_enum_under<Qt::DateFormat>("DateFormat", rb_mQt)
            .define_value("TextDate", Qt::DateFormat::TextDate)
            .define_value("ISODate", Qt::DateFormat::ISODate)
            .define_value("RFC2822Date", Qt::DateFormat::RFC2822Date)
            .define_value("ISODateWithMs", Qt::DateFormat::ISODateWithMs);

    Enum<Qt::DayOfWeek> rb_cQtDayOfWeek =
        // RubyQt6::QtCore::Qt::DayOfWeek
        define_enum_under<Qt::DayOfWeek>("DayOfWeek", rb_mQt)
            .define_value("Monday", Qt::DayOfWeek::Monday)
            .define_value("Tuesday", Qt::DayOfWeek::Tuesday)
            .define_value("Wednesday", Qt::DayOfWeek::Wednesday)
            .define_value("Thursday", Qt::DayOfWeek::Thursday)
            .define_value("Friday", Qt::DayOfWeek::Friday)
            .define_value("Saturday", Qt::DayOfWeek::Saturday)
            .define_value("Sunday", Qt::DayOfWeek::Sunday);

    Enum<Qt::DockWidgetArea> rb_cQtDockWidgetArea =
        // RubyQt6::QtCore::Qt::DockWidgetArea
        define_enum_under<Qt::DockWidgetArea>("DockWidgetArea", rb_mQt)
            .define_value("LeftDockWidgetArea", Qt::DockWidgetArea::LeftDockWidgetArea)
            .define_value("RightDockWidgetArea", Qt::DockWidgetArea::RightDockWidgetArea)
            .define_value("TopDockWidgetArea", Qt::DockWidgetArea::TopDockWidgetArea)
            .define_value("BottomDockWidgetArea", Qt::DockWidgetArea::BottomDockWidgetArea)
            .define_value("DockWidgetArea_Mask", Qt::DockWidgetArea::DockWidgetArea_Mask)
            .define_value("AllDockWidgetAreas", Qt::DockWidgetArea::AllDockWidgetAreas)
            .define_value("NoDockWidgetArea", Qt::DockWidgetArea::NoDockWidgetArea);

    Enum<Qt::DockWidgetAreaSizes> rb_cQtDockWidgetAreaSizes =
        // RubyQt6::QtCore::Qt::DockWidgetAreaSizes
        define_enum_under<Qt::DockWidgetAreaSizes>("DockWidgetAreaSizes", rb_mQt)
            .define_value("NDockWidgetAreas", Qt::DockWidgetAreaSizes::NDockWidgetAreas);

    Enum<Qt::DropAction> rb_cQtDropAction =
        // RubyQt6::QtCore::Qt::DropAction
        define_enum_under<Qt::DropAction>("DropAction", rb_mQt)
            .define_value("CopyAction", Qt::DropAction::CopyAction)
            .define_value("MoveAction", Qt::DropAction::MoveAction)
            .define_value("LinkAction", Qt::DropAction::LinkAction)
            .define_value("ActionMask", Qt::DropAction::ActionMask)
            .define_value("TargetMoveAction", Qt::DropAction::TargetMoveAction)
            .define_value("IgnoreAction", Qt::DropAction::IgnoreAction);

    Enum<Qt::Edge> rb_cQtEdge =
        // RubyQt6::QtCore::Qt::Edge
        define_enum_under<Qt::Edge>("Edge", rb_mQt)
            .define_value("TopEdge", Qt::Edge::TopEdge)
            .define_value("LeftEdge", Qt::Edge::LeftEdge)
            .define_value("RightEdge", Qt::Edge::RightEdge)
            .define_value("BottomEdge", Qt::Edge::BottomEdge);

    Enum<Qt::EnterKeyType> rb_cQtEnterKeyType =
        // RubyQt6::QtCore::Qt::EnterKeyType
        define_enum_under<Qt::EnterKeyType>("EnterKeyType", rb_mQt)
            .define_value("EnterKeyDefault", Qt::EnterKeyType::EnterKeyDefault)
            .define_value("EnterKeyReturn", Qt::EnterKeyType::EnterKeyReturn)
            .define_value("EnterKeyDone", Qt::EnterKeyType::EnterKeyDone)
            .define_value("EnterKeyGo", Qt::EnterKeyType::EnterKeyGo)
            .define_value("EnterKeySend", Qt::EnterKeyType::EnterKeySend)
            .define_value("EnterKeySearch", Qt::EnterKeyType::EnterKeySearch)
            .define_value("EnterKeyNext", Qt::EnterKeyType::EnterKeyNext)
            .define_value("EnterKeyPrevious", Qt::EnterKeyType::EnterKeyPrevious);

    Enum<Qt::EventPriority> rb_cQtEventPriority =
        // RubyQt6::QtCore::Qt::EventPriority
        define_enum_under<Qt::EventPriority>("EventPriority", rb_mQt)
            .define_value("HighEventPriority", Qt::EventPriority::HighEventPriority)
            .define_value("NormalEventPriority", Qt::EventPriority::NormalEventPriority)
            .define_value("LowEventPriority", Qt::EventPriority::LowEventPriority);

    Enum<Qt::FillRule> rb_cQtFillRule =
        // RubyQt6::QtCore::Qt::FillRule
        define_enum_under<Qt::FillRule>("FillRule", rb_mQt)
            .define_value("OddEvenFill", Qt::FillRule::OddEvenFill)
            .define_value("WindingFill", Qt::FillRule::WindingFill);

    Enum<Qt::FindChildOption> rb_cQtFindChildOption =
        // RubyQt6::QtCore::Qt::FindChildOption
        define_enum_under<Qt::FindChildOption>("FindChildOption", rb_mQt)
            .define_value("FindDirectChildrenOnly", Qt::FindChildOption::FindDirectChildrenOnly)
            .define_value("FindChildrenRecursively", Qt::FindChildOption::FindChildrenRecursively);

    Enum<Qt::FocusPolicy> rb_cQtFocusPolicy =
        // RubyQt6::QtCore::Qt::FocusPolicy
        define_enum_under<Qt::FocusPolicy>("FocusPolicy", rb_mQt)
            .define_value("NoFocus", Qt::FocusPolicy::NoFocus)
            .define_value("TabFocus", Qt::FocusPolicy::TabFocus)
            .define_value("ClickFocus", Qt::FocusPolicy::ClickFocus)
            .define_value("StrongFocus", Qt::FocusPolicy::StrongFocus)
            .define_value("WheelFocus", Qt::FocusPolicy::WheelFocus);

    Enum<Qt::FocusReason> rb_cQtFocusReason =
        // RubyQt6::QtCore::Qt::FocusReason
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

    Enum<Qt::GestureFlag> rb_cQtGestureFlag =
        // RubyQt6::QtCore::Qt::GestureFlag
        define_enum_under<Qt::GestureFlag>("GestureFlag", rb_mQt)
            .define_value("DontStartGestureOnChildren", Qt::GestureFlag::DontStartGestureOnChildren)
            .define_value("ReceivePartialGestures", Qt::GestureFlag::ReceivePartialGestures)
            .define_value("IgnoredGesturesPropagateToParent", Qt::GestureFlag::IgnoredGesturesPropagateToParent);

    Enum<Qt::GestureState> rb_cQtGestureState =
        // RubyQt6::QtCore::Qt::GestureState
        define_enum_under<Qt::GestureState>("GestureState", rb_mQt)
            .define_value("NoGesture", Qt::GestureState::NoGesture)
            .define_value("GestureStarted", Qt::GestureState::GestureStarted)
            .define_value("GestureUpdated", Qt::GestureState::GestureUpdated)
            .define_value("GestureFinished", Qt::GestureState::GestureFinished)
            .define_value("GestureCanceled", Qt::GestureState::GestureCanceled);

    Enum<Qt::GestureType> rb_cQtGestureType =
        // RubyQt6::QtCore::Qt::GestureType
        define_enum_under<Qt::GestureType>("GestureType", rb_mQt)
            .define_value("TapGesture", Qt::GestureType::TapGesture)
            .define_value("TapAndHoldGesture", Qt::GestureType::TapAndHoldGesture)
            .define_value("PanGesture", Qt::GestureType::PanGesture)
            .define_value("PinchGesture", Qt::GestureType::PinchGesture)
            .define_value("SwipeGesture", Qt::GestureType::SwipeGesture)
            .define_value("CustomGesture", Qt::GestureType::CustomGesture)
            .define_value("LastGestureType", Qt::GestureType::LastGestureType);

    Enum<Qt::GlobalColor> rb_cQtGlobalColor =
        // RubyQt6::QtCore::Qt::GlobalColor
        define_enum_under<Qt::GlobalColor>("GlobalColor", rb_mQt)
            .define_value("Color0", Qt::GlobalColor::color0)
            .define_value("Color1", Qt::GlobalColor::color1)
            .define_value("Black", Qt::GlobalColor::black)
            .define_value("White", Qt::GlobalColor::white)
            .define_value("DarkGray", Qt::GlobalColor::darkGray)
            .define_value("Gray", Qt::GlobalColor::gray)
            .define_value("LightGray", Qt::GlobalColor::lightGray)
            .define_value("Red", Qt::GlobalColor::red)
            .define_value("Green", Qt::GlobalColor::green)
            .define_value("Blue", Qt::GlobalColor::blue)
            .define_value("Cyan", Qt::GlobalColor::cyan)
            .define_value("Magenta", Qt::GlobalColor::magenta)
            .define_value("Yellow", Qt::GlobalColor::yellow)
            .define_value("DarkRed", Qt::GlobalColor::darkRed)
            .define_value("DarkGreen", Qt::GlobalColor::darkGreen)
            .define_value("DarkBlue", Qt::GlobalColor::darkBlue)
            .define_value("DarkCyan", Qt::GlobalColor::darkCyan)
            .define_value("DarkMagenta", Qt::GlobalColor::darkMagenta)
            .define_value("DarkYellow", Qt::GlobalColor::darkYellow)
            .define_value("Transparent", Qt::GlobalColor::transparent);

    Enum<Qt::HighDpiScaleFactorRoundingPolicy> rb_cQtHighDpiScaleFactorRoundingPolicy =
        // RubyQt6::QtCore::Qt::HighDpiScaleFactorRoundingPolicy
        define_enum_under<Qt::HighDpiScaleFactorRoundingPolicy>("HighDpiScaleFactorRoundingPolicy", rb_mQt)
            .define_value("Unset", Qt::HighDpiScaleFactorRoundingPolicy::Unset)
            .define_value("Round", Qt::HighDpiScaleFactorRoundingPolicy::Round)
            .define_value("Ceil", Qt::HighDpiScaleFactorRoundingPolicy::Ceil)
            .define_value("Floor", Qt::HighDpiScaleFactorRoundingPolicy::Floor)
            .define_value("RoundPreferFloor", Qt::HighDpiScaleFactorRoundingPolicy::RoundPreferFloor)
            .define_value("PassThrough", Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);

    Enum<Qt::HitTestAccuracy> rb_cQtHitTestAccuracy =
        // RubyQt6::QtCore::Qt::HitTestAccuracy
        define_enum_under<Qt::HitTestAccuracy>("HitTestAccuracy", rb_mQt)
            .define_value("ExactHit", Qt::HitTestAccuracy::ExactHit)
            .define_value("FuzzyHit", Qt::HitTestAccuracy::FuzzyHit);

    Enum<Qt::ImageConversionFlag> rb_cQtImageConversionFlag =
        // RubyQt6::QtCore::Qt::ImageConversionFlag
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

    Enum<Qt::Initialization> rb_cQtInitialization =
        // RubyQt6::QtCore::Qt::Initialization
        define_enum_under<Qt::Initialization>("Initialization", rb_mQt)
            .define_value("Uninitialized", Qt::Initialization::Uninitialized);

    Enum<Qt::InputMethodHint> rb_cQtInputMethodHint =
        // RubyQt6::QtCore::Qt::InputMethodHint
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

    Enum<Qt::InputMethodQuery> rb_cQtInputMethodQuery =
        // RubyQt6::QtCore::Qt::InputMethodQuery
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

    Enum<Qt::ItemDataRole> rb_cQtItemDataRole =
        // RubyQt6::QtCore::Qt::ItemDataRole
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
        // RubyQt6::QtCore::Qt::ItemFlag
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

    Enum<Qt::ItemSelectionMode> rb_cQtItemSelectionMode =
        // RubyQt6::QtCore::Qt::ItemSelectionMode
        define_enum_under<Qt::ItemSelectionMode>("ItemSelectionMode", rb_mQt)
            .define_value("ContainsItemShape", Qt::ItemSelectionMode::ContainsItemShape)
            .define_value("IntersectsItemShape", Qt::ItemSelectionMode::IntersectsItemShape)
            .define_value("ContainsItemBoundingRect", Qt::ItemSelectionMode::ContainsItemBoundingRect)
            .define_value("IntersectsItemBoundingRect", Qt::ItemSelectionMode::IntersectsItemBoundingRect);

    Enum<Qt::ItemSelectionOperation> rb_cQtItemSelectionOperation =
        // RubyQt6::QtCore::Qt::ItemSelectionOperation
        define_enum_under<Qt::ItemSelectionOperation>("ItemSelectionOperation", rb_mQt)
            .define_value("ReplaceSelection", Qt::ItemSelectionOperation::ReplaceSelection)
            .define_value("AddToSelection", Qt::ItemSelectionOperation::AddToSelection);

    Enum<Qt::Key> rb_cQtKey =
        // RubyQt6::QtCore::Qt::Key
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
        // RubyQt6::QtCore::Qt::KeyboardModifier
        define_enum_under<Qt::KeyboardModifier>("KeyboardModifier", rb_mQt)
            .define_value("NoModifier", Qt::KeyboardModifier::NoModifier)
            .define_value("ShiftModifier", Qt::KeyboardModifier::ShiftModifier)
            .define_value("ControlModifier", Qt::KeyboardModifier::ControlModifier)
            .define_value("AltModifier", Qt::KeyboardModifier::AltModifier)
            .define_value("MetaModifier", Qt::KeyboardModifier::MetaModifier)
            .define_value("KeypadModifier", Qt::KeyboardModifier::KeypadModifier)
            .define_value("GroupSwitchModifier", Qt::KeyboardModifier::GroupSwitchModifier)
            .define_value("KeyboardModifierMask", Qt::KeyboardModifier::KeyboardModifierMask);

    Enum<Qt::LayoutDirection> rb_cQtLayoutDirection =
        // RubyQt6::QtCore::Qt::LayoutDirection
        define_enum_under<Qt::LayoutDirection>("LayoutDirection", rb_mQt)
            .define_value("LeftToRight", Qt::LayoutDirection::LeftToRight)
            .define_value("RightToLeft", Qt::LayoutDirection::RightToLeft)
            .define_value("LayoutDirectionAuto", Qt::LayoutDirection::LayoutDirectionAuto);
}
