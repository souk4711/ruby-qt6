#include "qt-enum-af-rb.hpp"
#include <qnamespace.h>
#include <rice/qenum.hpp>

using namespace Rice;

void Init_qt_enum_af(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Enum<Qt::AlignmentFlag> rb_cQtAlignmentFlag =
        // RubyQt6::QtCore::Qt::AlignmentFlag
        define_qenum_under<Qt::AlignmentFlag>("AlignmentFlag", rb_mQt)
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
        define_qenum_under<Qt::AnchorPoint>("AnchorPoint", rb_mQt)
            .define_value("AnchorLeft", Qt::AnchorPoint::AnchorLeft)
            .define_value("AnchorHorizontalCenter", Qt::AnchorPoint::AnchorHorizontalCenter)
            .define_value("AnchorRight", Qt::AnchorPoint::AnchorRight)
            .define_value("AnchorTop", Qt::AnchorPoint::AnchorTop)
            .define_value("AnchorVerticalCenter", Qt::AnchorPoint::AnchorVerticalCenter)
            .define_value("AnchorBottom", Qt::AnchorPoint::AnchorBottom);

    Enum<Qt::ApplicationAttribute> rb_cQtApplicationAttribute =
        // RubyQt6::QtCore::Qt::ApplicationAttribute
        define_qenum_under<Qt::ApplicationAttribute>("ApplicationAttribute", rb_mQt)
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
        define_qenum_under<Qt::ApplicationState>("ApplicationState", rb_mQt)
            .define_value("ApplicationSuspended", Qt::ApplicationState::ApplicationSuspended)
            .define_value("ApplicationHidden", Qt::ApplicationState::ApplicationHidden)
            .define_value("ApplicationInactive", Qt::ApplicationState::ApplicationInactive)
            .define_value("ApplicationActive", Qt::ApplicationState::ApplicationActive);

    Enum<Qt::ArrowType> rb_cQtArrowType =
        // RubyQt6::QtCore::Qt::ArrowType
        define_qenum_under<Qt::ArrowType>("ArrowType", rb_mQt)
            .define_value("NoArrow", Qt::ArrowType::NoArrow)
            .define_value("UpArrow", Qt::ArrowType::UpArrow)
            .define_value("DownArrow", Qt::ArrowType::DownArrow)
            .define_value("LeftArrow", Qt::ArrowType::LeftArrow)
            .define_value("RightArrow", Qt::ArrowType::RightArrow);

    Enum<Qt::AspectRatioMode> rb_cQtAspectRatioMode =
        // RubyQt6::QtCore::Qt::AspectRatioMode
        define_qenum_under<Qt::AspectRatioMode>("AspectRatioMode", rb_mQt)
            .define_value("IgnoreAspectRatio", Qt::AspectRatioMode::IgnoreAspectRatio)
            .define_value("KeepAspectRatio", Qt::AspectRatioMode::KeepAspectRatio)
            .define_value("KeepAspectRatioByExpanding", Qt::AspectRatioMode::KeepAspectRatioByExpanding);

    Enum<Qt::Axis> rb_cQtAxis =
        // RubyQt6::QtCore::Qt::Axis
        define_qenum_under<Qt::Axis>("Axis", rb_mQt)
            .define_value("XAxis", Qt::Axis::XAxis)
            .define_value("YAxis", Qt::Axis::YAxis)
            .define_value("ZAxis", Qt::Axis::ZAxis);

    Enum<Qt::BGMode> rb_cQtBGMode =
        // RubyQt6::QtCore::Qt::BGMode
        define_qenum_under<Qt::BGMode>("BGMode", rb_mQt)
            .define_value("TransparentMode", Qt::BGMode::TransparentMode)
            .define_value("OpaqueMode", Qt::BGMode::OpaqueMode);

    Enum<Qt::BrushStyle> rb_cQtBrushStyle =
        // RubyQt6::QtCore::Qt::BrushStyle
        define_qenum_under<Qt::BrushStyle>("BrushStyle", rb_mQt)
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
        define_qenum_under<Qt::CaseSensitivity>("CaseSensitivity", rb_mQt)
            .define_value("CaseInsensitive", Qt::CaseSensitivity::CaseInsensitive)
            .define_value("CaseSensitive", Qt::CaseSensitivity::CaseSensitive);

    Enum<Qt::CheckState> rb_cQtCheckState =
        // RubyQt6::QtCore::Qt::CheckState
        define_qenum_under<Qt::CheckState>("CheckState", rb_mQt)
            .define_value("Unchecked", Qt::CheckState::Unchecked)
            .define_value("PartiallyChecked", Qt::CheckState::PartiallyChecked)
            .define_value("Checked", Qt::CheckState::Checked);

    Enum<Qt::ChecksumType> rb_cQtChecksumType =
        // RubyQt6::QtCore::Qt::ChecksumType
        define_qenum_under<Qt::ChecksumType>("ChecksumType", rb_mQt)
            .define_value("ChecksumIso3309", Qt::ChecksumType::ChecksumIso3309)
            .define_value("ChecksumItuV41", Qt::ChecksumType::ChecksumItuV41);

    Enum<Qt::ClipOperation> rb_cQtClipOperation =
        // RubyQt6::QtCore::Qt::ClipOperation
        define_qenum_under<Qt::ClipOperation>("ClipOperation", rb_mQt)
            .define_value("NoClip", Qt::ClipOperation::NoClip)
            .define_value("ReplaceClip", Qt::ClipOperation::ReplaceClip)
            .define_value("IntersectClip", Qt::ClipOperation::IntersectClip);

    Enum<Qt::ColorScheme> rb_cQtColorScheme =
        // RubyQt6::QtCore::Qt::ColorScheme
        define_qenum_under<Qt::ColorScheme>("ColorScheme", rb_mQt)
            .define_value("Unknown", Qt::ColorScheme::Unknown)
            .define_value("Light", Qt::ColorScheme::Light)
            .define_value("Dark", Qt::ColorScheme::Dark);

    Enum<Qt::ConnectionType> rb_cQtConnectionType =
        // RubyQt6::QtCore::Qt::ConnectionType
        define_qenum_under<Qt::ConnectionType>("ConnectionType", rb_mQt)
            .define_value("AutoConnection", Qt::ConnectionType::AutoConnection)
            .define_value("DirectConnection", Qt::ConnectionType::DirectConnection)
            .define_value("QueuedConnection", Qt::ConnectionType::QueuedConnection)
            .define_value("BlockingQueuedConnection", Qt::ConnectionType::BlockingQueuedConnection)
            .define_value("UniqueConnection", Qt::ConnectionType::UniqueConnection)
            .define_value("SingleShotConnection", Qt::ConnectionType::SingleShotConnection);

    Enum<Qt::ContextMenuPolicy> rb_cQtContextMenuPolicy =
        // RubyQt6::QtCore::Qt::ContextMenuPolicy
        define_qenum_under<Qt::ContextMenuPolicy>("ContextMenuPolicy", rb_mQt)
            .define_value("NoContextMenu", Qt::ContextMenuPolicy::NoContextMenu)
            .define_value("DefaultContextMenu", Qt::ContextMenuPolicy::DefaultContextMenu)
            .define_value("ActionsContextMenu", Qt::ContextMenuPolicy::ActionsContextMenu)
            .define_value("CustomContextMenu", Qt::ContextMenuPolicy::CustomContextMenu)
            .define_value("PreventContextMenu", Qt::ContextMenuPolicy::PreventContextMenu);

    Enum<Qt::ContextMenuTrigger> rb_cQtContextMenuTrigger =
        // RubyQt6::QtCore::Qt::ContextMenuTrigger
        define_qenum_under<Qt::ContextMenuTrigger>("ContextMenuTrigger", rb_mQt)
            .define_value("Press", Qt::ContextMenuTrigger::Press)
            .define_value("Release", Qt::ContextMenuTrigger::Release);

    Enum<Qt::CoordinateSystem> rb_cQtCoordinateSystem =
        // RubyQt6::QtCore::Qt::CoordinateSystem
        define_qenum_under<Qt::CoordinateSystem>("CoordinateSystem", rb_mQt)
            .define_value("DeviceCoordinates", Qt::CoordinateSystem::DeviceCoordinates)
            .define_value("LogicalCoordinates", Qt::CoordinateSystem::LogicalCoordinates);

    Enum<Qt::Corner> rb_cQtCorner =
        // RubyQt6::QtCore::Qt::Corner
        define_qenum_under<Qt::Corner>("Corner", rb_mQt)
            .define_value("TopLeftCorner", Qt::Corner::TopLeftCorner)
            .define_value("TopRightCorner", Qt::Corner::TopRightCorner)
            .define_value("BottomLeftCorner", Qt::Corner::BottomLeftCorner)
            .define_value("BottomRightCorner", Qt::Corner::BottomRightCorner);

    Enum<Qt::CursorMoveStyle> rb_cQtCursorMoveStyle =
        // RubyQt6::QtCore::Qt::CursorMoveStyle
        define_qenum_under<Qt::CursorMoveStyle>("CursorMoveStyle", rb_mQt)
            .define_value("LogicalMoveStyle", Qt::CursorMoveStyle::LogicalMoveStyle)
            .define_value("VisualMoveStyle", Qt::CursorMoveStyle::VisualMoveStyle);

    Enum<Qt::CursorShape> rb_cQtCursorShape =
        // RubyQt6::QtCore::Qt::CursorShape
        define_qenum_under<Qt::CursorShape>("CursorShape", rb_mQt)
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
        define_qenum_under<Qt::DateFormat>("DateFormat", rb_mQt)
            .define_value("TextDate", Qt::DateFormat::TextDate)
            .define_value("ISODate", Qt::DateFormat::ISODate)
            .define_value("RFC2822Date", Qt::DateFormat::RFC2822Date)
            .define_value("ISODateWithMs", Qt::DateFormat::ISODateWithMs);

    Enum<Qt::DayOfWeek> rb_cQtDayOfWeek =
        // RubyQt6::QtCore::Qt::DayOfWeek
        define_qenum_under<Qt::DayOfWeek>("DayOfWeek", rb_mQt)
            .define_value("Monday", Qt::DayOfWeek::Monday)
            .define_value("Tuesday", Qt::DayOfWeek::Tuesday)
            .define_value("Wednesday", Qt::DayOfWeek::Wednesday)
            .define_value("Thursday", Qt::DayOfWeek::Thursday)
            .define_value("Friday", Qt::DayOfWeek::Friday)
            .define_value("Saturday", Qt::DayOfWeek::Saturday)
            .define_value("Sunday", Qt::DayOfWeek::Sunday);

    Enum<Qt::DockWidgetArea> rb_cQtDockWidgetArea =
        // RubyQt6::QtCore::Qt::DockWidgetArea
        define_qenum_under<Qt::DockWidgetArea>("DockWidgetArea", rb_mQt)
            .define_value("LeftDockWidgetArea", Qt::DockWidgetArea::LeftDockWidgetArea)
            .define_value("RightDockWidgetArea", Qt::DockWidgetArea::RightDockWidgetArea)
            .define_value("TopDockWidgetArea", Qt::DockWidgetArea::TopDockWidgetArea)
            .define_value("BottomDockWidgetArea", Qt::DockWidgetArea::BottomDockWidgetArea)
            .define_value("DockWidgetArea_Mask", Qt::DockWidgetArea::DockWidgetArea_Mask)
            .define_value("AllDockWidgetAreas", Qt::DockWidgetArea::AllDockWidgetAreas)
            .define_value("NoDockWidgetArea", Qt::DockWidgetArea::NoDockWidgetArea);

    Enum<Qt::DockWidgetAreaSizes> rb_cQtDockWidgetAreaSizes =
        // RubyQt6::QtCore::Qt::DockWidgetAreaSizes
        define_qenum_under<Qt::DockWidgetAreaSizes>("DockWidgetAreaSizes", rb_mQt)
            .define_value("NDockWidgetAreas", Qt::DockWidgetAreaSizes::NDockWidgetAreas);

    Enum<Qt::DropAction> rb_cQtDropAction =
        // RubyQt6::QtCore::Qt::DropAction
        define_qenum_under<Qt::DropAction>("DropAction", rb_mQt)
            .define_value("CopyAction", Qt::DropAction::CopyAction)
            .define_value("MoveAction", Qt::DropAction::MoveAction)
            .define_value("LinkAction", Qt::DropAction::LinkAction)
            .define_value("ActionMask", Qt::DropAction::ActionMask)
            .define_value("TargetMoveAction", Qt::DropAction::TargetMoveAction)
            .define_value("IgnoreAction", Qt::DropAction::IgnoreAction);

    Enum<Qt::Edge> rb_cQtEdge =
        // RubyQt6::QtCore::Qt::Edge
        define_qenum_under<Qt::Edge>("Edge", rb_mQt)
            .define_value("TopEdge", Qt::Edge::TopEdge)
            .define_value("LeftEdge", Qt::Edge::LeftEdge)
            .define_value("RightEdge", Qt::Edge::RightEdge)
            .define_value("BottomEdge", Qt::Edge::BottomEdge);

    Enum<Qt::EnterKeyType> rb_cQtEnterKeyType =
        // RubyQt6::QtCore::Qt::EnterKeyType
        define_qenum_under<Qt::EnterKeyType>("EnterKeyType", rb_mQt)
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
        define_qenum_under<Qt::EventPriority>("EventPriority", rb_mQt)
            .define_value("HighEventPriority", Qt::EventPriority::HighEventPriority)
            .define_value("NormalEventPriority", Qt::EventPriority::NormalEventPriority)
            .define_value("LowEventPriority", Qt::EventPriority::LowEventPriority);

    Enum<Qt::FillRule> rb_cQtFillRule =
        // RubyQt6::QtCore::Qt::FillRule
        define_qenum_under<Qt::FillRule>("FillRule", rb_mQt)
            .define_value("OddEvenFill", Qt::FillRule::OddEvenFill)
            .define_value("WindingFill", Qt::FillRule::WindingFill);

    Enum<Qt::FindChildOption> rb_cQtFindChildOption =
        // RubyQt6::QtCore::Qt::FindChildOption
        define_qenum_under<Qt::FindChildOption>("FindChildOption", rb_mQt)
            .define_value("FindDirectChildrenOnly", Qt::FindChildOption::FindDirectChildrenOnly)
            .define_value("FindChildrenRecursively", Qt::FindChildOption::FindChildrenRecursively);

    Enum<Qt::FocusPolicy> rb_cQtFocusPolicy =
        // RubyQt6::QtCore::Qt::FocusPolicy
        define_qenum_under<Qt::FocusPolicy>("FocusPolicy", rb_mQt)
            .define_value("NoFocus", Qt::FocusPolicy::NoFocus)
            .define_value("TabFocus", Qt::FocusPolicy::TabFocus)
            .define_value("ClickFocus", Qt::FocusPolicy::ClickFocus)
            .define_value("StrongFocus", Qt::FocusPolicy::StrongFocus)
            .define_value("WheelFocus", Qt::FocusPolicy::WheelFocus);

    Enum<Qt::FocusReason> rb_cQtFocusReason =
        // RubyQt6::QtCore::Qt::FocusReason
        define_qenum_under<Qt::FocusReason>("FocusReason", rb_mQt)
            .define_value("MouseFocusReason", Qt::FocusReason::MouseFocusReason)
            .define_value("TabFocusReason", Qt::FocusReason::TabFocusReason)
            .define_value("BacktabFocusReason", Qt::FocusReason::BacktabFocusReason)
            .define_value("ActiveWindowFocusReason", Qt::FocusReason::ActiveWindowFocusReason)
            .define_value("PopupFocusReason", Qt::FocusReason::PopupFocusReason)
            .define_value("ShortcutFocusReason", Qt::FocusReason::ShortcutFocusReason)
            .define_value("MenuBarFocusReason", Qt::FocusReason::MenuBarFocusReason)
            .define_value("OtherFocusReason", Qt::FocusReason::OtherFocusReason)
            .define_value("NoFocusReason", Qt::FocusReason::NoFocusReason);
}
