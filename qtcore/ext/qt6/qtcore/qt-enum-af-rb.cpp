#include "qt-enum-af-rb.hpp"
#include <qnamespace.h>
#include <rice/qt6/qenum.hpp>

using namespace Rice;

void Init_qt_enum_af(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Data_Type<Qt::AlignmentFlag> rb_cQtAlignmentFlag =
        // RubyQt6::QtCore::Qt::AlignmentFlag
        define_qenum_under<Qt::AlignmentFlag>(rb_mQt, "AlignmentFlag");
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignLeft", Qt::AlignmentFlag::AlignLeft);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignLeading", Qt::AlignmentFlag::AlignLeading);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignRight", Qt::AlignmentFlag::AlignRight);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignTrailing", Qt::AlignmentFlag::AlignTrailing);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignHCenter", Qt::AlignmentFlag::AlignHCenter);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignJustify", Qt::AlignmentFlag::AlignJustify);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignAbsolute", Qt::AlignmentFlag::AlignAbsolute);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignHorizontal_Mask", Qt::AlignmentFlag::AlignHorizontal_Mask);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignTop", Qt::AlignmentFlag::AlignTop);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignBottom", Qt::AlignmentFlag::AlignBottom);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignVCenter", Qt::AlignmentFlag::AlignVCenter);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignBaseline", Qt::AlignmentFlag::AlignBaseline);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignVertical_Mask", Qt::AlignmentFlag::AlignVertical_Mask);
        define_qenum_value_under(rb_cQtAlignmentFlag, "AlignCenter", Qt::AlignmentFlag::AlignCenter);

    Data_Type<Qt::AnchorPoint> rb_cQtAnchorPoint =
        // RubyQt6::QtCore::Qt::AnchorPoint
        define_qenum_under<Qt::AnchorPoint>(rb_mQt, "AnchorPoint");
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorLeft", Qt::AnchorPoint::AnchorLeft);
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorHorizontalCenter", Qt::AnchorPoint::AnchorHorizontalCenter);
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorRight", Qt::AnchorPoint::AnchorRight);
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorTop", Qt::AnchorPoint::AnchorTop);
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorVerticalCenter", Qt::AnchorPoint::AnchorVerticalCenter);
        define_qenum_value_under(rb_cQtAnchorPoint, "AnchorBottom", Qt::AnchorPoint::AnchorBottom);

    Data_Type<Qt::ApplicationAttribute> rb_cQtApplicationAttribute =
        // RubyQt6::QtCore::Qt::ApplicationAttribute
        define_qenum_under<Qt::ApplicationAttribute>(rb_mQt, "ApplicationAttribute");
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_QtQuickUseDefaultSizePolicy", Qt::ApplicationAttribute::AA_QtQuickUseDefaultSizePolicy);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontShowIconsInMenus", Qt::ApplicationAttribute::AA_DontShowIconsInMenus);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_NativeWindows", Qt::ApplicationAttribute::AA_NativeWindows);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontCreateNativeWidgetSiblings", Qt::ApplicationAttribute::AA_DontCreateNativeWidgetSiblings);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_PluginApplication", Qt::ApplicationAttribute::AA_PluginApplication);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontUseNativeMenuBar", Qt::ApplicationAttribute::AA_DontUseNativeMenuBar);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_MacDontSwapCtrlAndMeta", Qt::ApplicationAttribute::AA_MacDontSwapCtrlAndMeta);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_Use96Dpi", Qt::ApplicationAttribute::AA_Use96Dpi);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DisableNativeVirtualKeyboard", Qt::ApplicationAttribute::AA_DisableNativeVirtualKeyboard);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontUseNativeMenuWindows", Qt::ApplicationAttribute::AA_DontUseNativeMenuWindows);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_SynthesizeTouchForUnhandledMouseEvents", Qt::ApplicationAttribute::AA_SynthesizeTouchForUnhandledMouseEvents);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_SynthesizeMouseForUnhandledTouchEvents", Qt::ApplicationAttribute::AA_SynthesizeMouseForUnhandledTouchEvents);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_ForceRasterWidgets", Qt::ApplicationAttribute::AA_ForceRasterWidgets);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_UseDesktopOpenGL", Qt::ApplicationAttribute::AA_UseDesktopOpenGL);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_UseOpenGLES", Qt::ApplicationAttribute::AA_UseOpenGLES);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_UseSoftwareOpenGL", Qt::ApplicationAttribute::AA_UseSoftwareOpenGL);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_ShareOpenGLContexts", Qt::ApplicationAttribute::AA_ShareOpenGLContexts);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_SetPalette", Qt::ApplicationAttribute::AA_SetPalette);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_UseStyleSheetPropagationInWidgetStyles", Qt::ApplicationAttribute::AA_UseStyleSheetPropagationInWidgetStyles);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontUseNativeDialogs", Qt::ApplicationAttribute::AA_DontUseNativeDialogs);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_SynthesizeMouseForUnhandledTabletEvents", Qt::ApplicationAttribute::AA_SynthesizeMouseForUnhandledTabletEvents);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_CompressHighFrequencyEvents", Qt::ApplicationAttribute::AA_CompressHighFrequencyEvents);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontCheckOpenGLContextThreadAffinity", Qt::ApplicationAttribute::AA_DontCheckOpenGLContextThreadAffinity);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DisableShaderDiskCache", Qt::ApplicationAttribute::AA_DisableShaderDiskCache);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DontShowShortcutsInContextMenus", Qt::ApplicationAttribute::AA_DontShowShortcutsInContextMenus);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_CompressTabletEvents", Qt::ApplicationAttribute::AA_CompressTabletEvents);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_DisableSessionManager", Qt::ApplicationAttribute::AA_DisableSessionManager);
        define_qenum_value_under(rb_cQtApplicationAttribute, "AA_AttributeCount", Qt::ApplicationAttribute::AA_AttributeCount);

    Data_Type<Qt::ApplicationState> rb_cQtApplicationState =
        // RubyQt6::QtCore::Qt::ApplicationState
        define_qenum_under<Qt::ApplicationState>(rb_mQt, "ApplicationState");
        define_qenum_value_under(rb_cQtApplicationState, "ApplicationSuspended", Qt::ApplicationState::ApplicationSuspended);
        define_qenum_value_under(rb_cQtApplicationState, "ApplicationHidden", Qt::ApplicationState::ApplicationHidden);
        define_qenum_value_under(rb_cQtApplicationState, "ApplicationInactive", Qt::ApplicationState::ApplicationInactive);
        define_qenum_value_under(rb_cQtApplicationState, "ApplicationActive", Qt::ApplicationState::ApplicationActive);

    Data_Type<Qt::ArrowType> rb_cQtArrowType =
        // RubyQt6::QtCore::Qt::ArrowType
        define_qenum_under<Qt::ArrowType>(rb_mQt, "ArrowType");
        define_qenum_value_under(rb_cQtArrowType, "NoArrow", Qt::ArrowType::NoArrow);
        define_qenum_value_under(rb_cQtArrowType, "UpArrow", Qt::ArrowType::UpArrow);
        define_qenum_value_under(rb_cQtArrowType, "DownArrow", Qt::ArrowType::DownArrow);
        define_qenum_value_under(rb_cQtArrowType, "LeftArrow", Qt::ArrowType::LeftArrow);
        define_qenum_value_under(rb_cQtArrowType, "RightArrow", Qt::ArrowType::RightArrow);

    Data_Type<Qt::AspectRatioMode> rb_cQtAspectRatioMode =
        // RubyQt6::QtCore::Qt::AspectRatioMode
        define_qenum_under<Qt::AspectRatioMode>(rb_mQt, "AspectRatioMode");
        define_qenum_value_under(rb_cQtAspectRatioMode, "IgnoreAspectRatio", Qt::AspectRatioMode::IgnoreAspectRatio);
        define_qenum_value_under(rb_cQtAspectRatioMode, "KeepAspectRatio", Qt::AspectRatioMode::KeepAspectRatio);
        define_qenum_value_under(rb_cQtAspectRatioMode, "KeepAspectRatioByExpanding", Qt::AspectRatioMode::KeepAspectRatioByExpanding);

    Data_Type<Qt::Axis> rb_cQtAxis =
        // RubyQt6::QtCore::Qt::Axis
        define_qenum_under<Qt::Axis>(rb_mQt, "Axis");
        define_qenum_value_under(rb_cQtAxis, "XAxis", Qt::Axis::XAxis);
        define_qenum_value_under(rb_cQtAxis, "YAxis", Qt::Axis::YAxis);
        define_qenum_value_under(rb_cQtAxis, "ZAxis", Qt::Axis::ZAxis);

    Data_Type<Qt::BGMode> rb_cQtBGMode =
        // RubyQt6::QtCore::Qt::BGMode
        define_qenum_under<Qt::BGMode>(rb_mQt, "BGMode");
        define_qenum_value_under(rb_cQtBGMode, "TransparentMode", Qt::BGMode::TransparentMode);
        define_qenum_value_under(rb_cQtBGMode, "OpaqueMode", Qt::BGMode::OpaqueMode);

    Data_Type<Qt::BrushStyle> rb_cQtBrushStyle =
        // RubyQt6::QtCore::Qt::BrushStyle
        define_qenum_under<Qt::BrushStyle>(rb_mQt, "BrushStyle");
        define_qenum_value_under(rb_cQtBrushStyle, "NoBrush", Qt::BrushStyle::NoBrush);
        define_qenum_value_under(rb_cQtBrushStyle, "SolidPattern", Qt::BrushStyle::SolidPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense1Pattern", Qt::BrushStyle::Dense1Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense2Pattern", Qt::BrushStyle::Dense2Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense3Pattern", Qt::BrushStyle::Dense3Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense4Pattern", Qt::BrushStyle::Dense4Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense5Pattern", Qt::BrushStyle::Dense5Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense6Pattern", Qt::BrushStyle::Dense6Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "Dense7Pattern", Qt::BrushStyle::Dense7Pattern);
        define_qenum_value_under(rb_cQtBrushStyle, "HorPattern", Qt::BrushStyle::HorPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "VerPattern", Qt::BrushStyle::VerPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "CrossPattern", Qt::BrushStyle::CrossPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "BDiagPattern", Qt::BrushStyle::BDiagPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "FDiagPattern", Qt::BrushStyle::FDiagPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "DiagCrossPattern", Qt::BrushStyle::DiagCrossPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "LinearGradientPattern", Qt::BrushStyle::LinearGradientPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "RadialGradientPattern", Qt::BrushStyle::RadialGradientPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "ConicalGradientPattern", Qt::BrushStyle::ConicalGradientPattern);
        define_qenum_value_under(rb_cQtBrushStyle, "TexturePattern", Qt::BrushStyle::TexturePattern);

    Data_Type<Qt::CaseSensitivity> rb_cQtCaseSensitivity =
        // RubyQt6::QtCore::Qt::CaseSensitivity
        define_qenum_under<Qt::CaseSensitivity>(rb_mQt, "CaseSensitivity");
        define_qenum_value_under(rb_cQtCaseSensitivity, "CaseInsensitive", Qt::CaseSensitivity::CaseInsensitive);
        define_qenum_value_under(rb_cQtCaseSensitivity, "CaseSensitive", Qt::CaseSensitivity::CaseSensitive);

    Data_Type<Qt::CheckState> rb_cQtCheckState =
        // RubyQt6::QtCore::Qt::CheckState
        define_qenum_under<Qt::CheckState>(rb_mQt, "CheckState");
        define_qenum_value_under(rb_cQtCheckState, "Unchecked", Qt::CheckState::Unchecked);
        define_qenum_value_under(rb_cQtCheckState, "PartiallyChecked", Qt::CheckState::PartiallyChecked);
        define_qenum_value_under(rb_cQtCheckState, "Checked", Qt::CheckState::Checked);

    Data_Type<Qt::ChecksumType> rb_cQtChecksumType =
        // RubyQt6::QtCore::Qt::ChecksumType
        define_qenum_under<Qt::ChecksumType>(rb_mQt, "ChecksumType");
        define_qenum_value_under(rb_cQtChecksumType, "ChecksumIso3309", Qt::ChecksumType::ChecksumIso3309);
        define_qenum_value_under(rb_cQtChecksumType, "ChecksumItuV41", Qt::ChecksumType::ChecksumItuV41);

    Data_Type<Qt::ClipOperation> rb_cQtClipOperation =
        // RubyQt6::QtCore::Qt::ClipOperation
        define_qenum_under<Qt::ClipOperation>(rb_mQt, "ClipOperation");
        define_qenum_value_under(rb_cQtClipOperation, "NoClip", Qt::ClipOperation::NoClip);
        define_qenum_value_under(rb_cQtClipOperation, "ReplaceClip", Qt::ClipOperation::ReplaceClip);
        define_qenum_value_under(rb_cQtClipOperation, "IntersectClip", Qt::ClipOperation::IntersectClip);

    Data_Type<Qt::ColorScheme> rb_cQtColorScheme =
        // RubyQt6::QtCore::Qt::ColorScheme
        define_qenum_under<Qt::ColorScheme>(rb_mQt, "ColorScheme");
        define_qenum_value_under(rb_cQtColorScheme, "Unknown", Qt::ColorScheme::Unknown);
        define_qenum_value_under(rb_cQtColorScheme, "Light", Qt::ColorScheme::Light);
        define_qenum_value_under(rb_cQtColorScheme, "Dark", Qt::ColorScheme::Dark);

    Data_Type<Qt::ConnectionType> rb_cQtConnectionType =
        // RubyQt6::QtCore::Qt::ConnectionType
        define_qenum_under<Qt::ConnectionType>(rb_mQt, "ConnectionType");
        define_qenum_value_under(rb_cQtConnectionType, "AutoConnection", Qt::ConnectionType::AutoConnection);
        define_qenum_value_under(rb_cQtConnectionType, "DirectConnection", Qt::ConnectionType::DirectConnection);
        define_qenum_value_under(rb_cQtConnectionType, "QueuedConnection", Qt::ConnectionType::QueuedConnection);
        define_qenum_value_under(rb_cQtConnectionType, "BlockingQueuedConnection", Qt::ConnectionType::BlockingQueuedConnection);
        define_qenum_value_under(rb_cQtConnectionType, "UniqueConnection", Qt::ConnectionType::UniqueConnection);
        define_qenum_value_under(rb_cQtConnectionType, "SingleShotConnection", Qt::ConnectionType::SingleShotConnection);

    Data_Type<Qt::ContextMenuPolicy> rb_cQtContextMenuPolicy =
        // RubyQt6::QtCore::Qt::ContextMenuPolicy
        define_qenum_under<Qt::ContextMenuPolicy>(rb_mQt, "ContextMenuPolicy");
        define_qenum_value_under(rb_cQtContextMenuPolicy, "NoContextMenu", Qt::ContextMenuPolicy::NoContextMenu);
        define_qenum_value_under(rb_cQtContextMenuPolicy, "DefaultContextMenu", Qt::ContextMenuPolicy::DefaultContextMenu);
        define_qenum_value_under(rb_cQtContextMenuPolicy, "ActionsContextMenu", Qt::ContextMenuPolicy::ActionsContextMenu);
        define_qenum_value_under(rb_cQtContextMenuPolicy, "CustomContextMenu", Qt::ContextMenuPolicy::CustomContextMenu);
        define_qenum_value_under(rb_cQtContextMenuPolicy, "PreventContextMenu", Qt::ContextMenuPolicy::PreventContextMenu);

    Data_Type<Qt::ContextMenuTrigger> rb_cQtContextMenuTrigger =
        // RubyQt6::QtCore::Qt::ContextMenuTrigger
        define_qenum_under<Qt::ContextMenuTrigger>(rb_mQt, "ContextMenuTrigger");
        define_qenum_value_under(rb_cQtContextMenuTrigger, "Press", Qt::ContextMenuTrigger::Press);
        define_qenum_value_under(rb_cQtContextMenuTrigger, "Release", Qt::ContextMenuTrigger::Release);

    Data_Type<Qt::CoordinateSystem> rb_cQtCoordinateSystem =
        // RubyQt6::QtCore::Qt::CoordinateSystem
        define_qenum_under<Qt::CoordinateSystem>(rb_mQt, "CoordinateSystem");
        define_qenum_value_under(rb_cQtCoordinateSystem, "DeviceCoordinates", Qt::CoordinateSystem::DeviceCoordinates);
        define_qenum_value_under(rb_cQtCoordinateSystem, "LogicalCoordinates", Qt::CoordinateSystem::LogicalCoordinates);

    Data_Type<Qt::Corner> rb_cQtCorner =
        // RubyQt6::QtCore::Qt::Corner
        define_qenum_under<Qt::Corner>(rb_mQt, "Corner");
        define_qenum_value_under(rb_cQtCorner, "TopLeftCorner", Qt::Corner::TopLeftCorner);
        define_qenum_value_under(rb_cQtCorner, "TopRightCorner", Qt::Corner::TopRightCorner);
        define_qenum_value_under(rb_cQtCorner, "BottomLeftCorner", Qt::Corner::BottomLeftCorner);
        define_qenum_value_under(rb_cQtCorner, "BottomRightCorner", Qt::Corner::BottomRightCorner);

    Data_Type<Qt::CursorMoveStyle> rb_cQtCursorMoveStyle =
        // RubyQt6::QtCore::Qt::CursorMoveStyle
        define_qenum_under<Qt::CursorMoveStyle>(rb_mQt, "CursorMoveStyle");
        define_qenum_value_under(rb_cQtCursorMoveStyle, "LogicalMoveStyle", Qt::CursorMoveStyle::LogicalMoveStyle);
        define_qenum_value_under(rb_cQtCursorMoveStyle, "VisualMoveStyle", Qt::CursorMoveStyle::VisualMoveStyle);

    Data_Type<Qt::CursorShape> rb_cQtCursorShape =
        // RubyQt6::QtCore::Qt::CursorShape
        define_qenum_under<Qt::CursorShape>(rb_mQt, "CursorShape");
        define_qenum_value_under(rb_cQtCursorShape, "ArrowCursor", Qt::CursorShape::ArrowCursor);
        define_qenum_value_under(rb_cQtCursorShape, "UpArrowCursor", Qt::CursorShape::UpArrowCursor);
        define_qenum_value_under(rb_cQtCursorShape, "CrossCursor", Qt::CursorShape::CrossCursor);
        define_qenum_value_under(rb_cQtCursorShape, "WaitCursor", Qt::CursorShape::WaitCursor);
        define_qenum_value_under(rb_cQtCursorShape, "IBeamCursor", Qt::CursorShape::IBeamCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SizeVerCursor", Qt::CursorShape::SizeVerCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SizeHorCursor", Qt::CursorShape::SizeHorCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SizeBDiagCursor", Qt::CursorShape::SizeBDiagCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SizeFDiagCursor", Qt::CursorShape::SizeFDiagCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SizeAllCursor", Qt::CursorShape::SizeAllCursor);
        define_qenum_value_under(rb_cQtCursorShape, "BlankCursor", Qt::CursorShape::BlankCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SplitVCursor", Qt::CursorShape::SplitVCursor);
        define_qenum_value_under(rb_cQtCursorShape, "SplitHCursor", Qt::CursorShape::SplitHCursor);
        define_qenum_value_under(rb_cQtCursorShape, "PointingHandCursor", Qt::CursorShape::PointingHandCursor);
        define_qenum_value_under(rb_cQtCursorShape, "ForbiddenCursor", Qt::CursorShape::ForbiddenCursor);
        define_qenum_value_under(rb_cQtCursorShape, "WhatsThisCursor", Qt::CursorShape::WhatsThisCursor);
        define_qenum_value_under(rb_cQtCursorShape, "BusyCursor", Qt::CursorShape::BusyCursor);
        define_qenum_value_under(rb_cQtCursorShape, "OpenHandCursor", Qt::CursorShape::OpenHandCursor);
        define_qenum_value_under(rb_cQtCursorShape, "ClosedHandCursor", Qt::CursorShape::ClosedHandCursor);
        define_qenum_value_under(rb_cQtCursorShape, "DragCopyCursor", Qt::CursorShape::DragCopyCursor);
        define_qenum_value_under(rb_cQtCursorShape, "DragMoveCursor", Qt::CursorShape::DragMoveCursor);
        define_qenum_value_under(rb_cQtCursorShape, "DragLinkCursor", Qt::CursorShape::DragLinkCursor);
        define_qenum_value_under(rb_cQtCursorShape, "LastCursor", Qt::CursorShape::LastCursor);
        define_qenum_value_under(rb_cQtCursorShape, "BitmapCursor", Qt::CursorShape::BitmapCursor);
        define_qenum_value_under(rb_cQtCursorShape, "CustomCursor", Qt::CursorShape::CustomCursor);

    Data_Type<Qt::DateFormat> rb_cQtDateFormat =
        // RubyQt6::QtCore::Qt::DateFormat
        define_qenum_under<Qt::DateFormat>(rb_mQt, "DateFormat");
        define_qenum_value_under(rb_cQtDateFormat, "TextDate", Qt::DateFormat::TextDate);
        define_qenum_value_under(rb_cQtDateFormat, "ISODate", Qt::DateFormat::ISODate);
        define_qenum_value_under(rb_cQtDateFormat, "RFC2822Date", Qt::DateFormat::RFC2822Date);
        define_qenum_value_under(rb_cQtDateFormat, "ISODateWithMs", Qt::DateFormat::ISODateWithMs);

    Data_Type<Qt::DayOfWeek> rb_cQtDayOfWeek =
        // RubyQt6::QtCore::Qt::DayOfWeek
        define_qenum_under<Qt::DayOfWeek>(rb_mQt, "DayOfWeek");
        define_qenum_value_under(rb_cQtDayOfWeek, "Monday", Qt::DayOfWeek::Monday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Tuesday", Qt::DayOfWeek::Tuesday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Wednesday", Qt::DayOfWeek::Wednesday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Thursday", Qt::DayOfWeek::Thursday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Friday", Qt::DayOfWeek::Friday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Saturday", Qt::DayOfWeek::Saturday);
        define_qenum_value_under(rb_cQtDayOfWeek, "Sunday", Qt::DayOfWeek::Sunday);

    Data_Type<Qt::DockWidgetArea> rb_cQtDockWidgetArea =
        // RubyQt6::QtCore::Qt::DockWidgetArea
        define_qenum_under<Qt::DockWidgetArea>(rb_mQt, "DockWidgetArea");
        define_qenum_value_under(rb_cQtDockWidgetArea, "LeftDockWidgetArea", Qt::DockWidgetArea::LeftDockWidgetArea);
        define_qenum_value_under(rb_cQtDockWidgetArea, "RightDockWidgetArea", Qt::DockWidgetArea::RightDockWidgetArea);
        define_qenum_value_under(rb_cQtDockWidgetArea, "TopDockWidgetArea", Qt::DockWidgetArea::TopDockWidgetArea);
        define_qenum_value_under(rb_cQtDockWidgetArea, "BottomDockWidgetArea", Qt::DockWidgetArea::BottomDockWidgetArea);
        define_qenum_value_under(rb_cQtDockWidgetArea, "DockWidgetArea_Mask", Qt::DockWidgetArea::DockWidgetArea_Mask);
        define_qenum_value_under(rb_cQtDockWidgetArea, "AllDockWidgetAreas", Qt::DockWidgetArea::AllDockWidgetAreas);
        define_qenum_value_under(rb_cQtDockWidgetArea, "NoDockWidgetArea", Qt::DockWidgetArea::NoDockWidgetArea);

    Data_Type<Qt::DockWidgetAreaSizes> rb_cQtDockWidgetAreaSizes =
        // RubyQt6::QtCore::Qt::DockWidgetAreaSizes
        define_qenum_under<Qt::DockWidgetAreaSizes>(rb_mQt, "DockWidgetAreaSizes");
        define_qenum_value_under(rb_cQtDockWidgetAreaSizes, "NDockWidgetAreas", Qt::DockWidgetAreaSizes::NDockWidgetAreas);

    Data_Type<Qt::DropAction> rb_cQtDropAction =
        // RubyQt6::QtCore::Qt::DropAction
        define_qenum_under<Qt::DropAction>(rb_mQt, "DropAction");
        define_qenum_value_under(rb_cQtDropAction, "CopyAction", Qt::DropAction::CopyAction);
        define_qenum_value_under(rb_cQtDropAction, "MoveAction", Qt::DropAction::MoveAction);
        define_qenum_value_under(rb_cQtDropAction, "LinkAction", Qt::DropAction::LinkAction);
        define_qenum_value_under(rb_cQtDropAction, "ActionMask", Qt::DropAction::ActionMask);
        define_qenum_value_under(rb_cQtDropAction, "TargetMoveAction", Qt::DropAction::TargetMoveAction);
        define_qenum_value_under(rb_cQtDropAction, "IgnoreAction", Qt::DropAction::IgnoreAction);

    Data_Type<Qt::Edge> rb_cQtEdge =
        // RubyQt6::QtCore::Qt::Edge
        define_qenum_under<Qt::Edge>(rb_mQt, "Edge");
        define_qenum_value_under(rb_cQtEdge, "TopEdge", Qt::Edge::TopEdge);
        define_qenum_value_under(rb_cQtEdge, "LeftEdge", Qt::Edge::LeftEdge);
        define_qenum_value_under(rb_cQtEdge, "RightEdge", Qt::Edge::RightEdge);
        define_qenum_value_under(rb_cQtEdge, "BottomEdge", Qt::Edge::BottomEdge);

    Data_Type<Qt::EnterKeyType> rb_cQtEnterKeyType =
        // RubyQt6::QtCore::Qt::EnterKeyType
        define_qenum_under<Qt::EnterKeyType>(rb_mQt, "EnterKeyType");
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyDefault", Qt::EnterKeyType::EnterKeyDefault);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyReturn", Qt::EnterKeyType::EnterKeyReturn);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyDone", Qt::EnterKeyType::EnterKeyDone);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyGo", Qt::EnterKeyType::EnterKeyGo);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeySend", Qt::EnterKeyType::EnterKeySend);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeySearch", Qt::EnterKeyType::EnterKeySearch);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyNext", Qt::EnterKeyType::EnterKeyNext);
        define_qenum_value_under(rb_cQtEnterKeyType, "EnterKeyPrevious", Qt::EnterKeyType::EnterKeyPrevious);

    Data_Type<Qt::EventPriority> rb_cQtEventPriority =
        // RubyQt6::QtCore::Qt::EventPriority
        define_qenum_under<Qt::EventPriority>(rb_mQt, "EventPriority");
        define_qenum_value_under(rb_cQtEventPriority, "HighEventPriority", Qt::EventPriority::HighEventPriority);
        define_qenum_value_under(rb_cQtEventPriority, "NormalEventPriority", Qt::EventPriority::NormalEventPriority);
        define_qenum_value_under(rb_cQtEventPriority, "LowEventPriority", Qt::EventPriority::LowEventPriority);

    Data_Type<Qt::FillRule> rb_cQtFillRule =
        // RubyQt6::QtCore::Qt::FillRule
        define_qenum_under<Qt::FillRule>(rb_mQt, "FillRule");
        define_qenum_value_under(rb_cQtFillRule, "OddEvenFill", Qt::FillRule::OddEvenFill);
        define_qenum_value_under(rb_cQtFillRule, "WindingFill", Qt::FillRule::WindingFill);

    Data_Type<Qt::FindChildOption> rb_cQtFindChildOption =
        // RubyQt6::QtCore::Qt::FindChildOption
        define_qenum_under<Qt::FindChildOption>(rb_mQt, "FindChildOption");
        define_qenum_value_under(rb_cQtFindChildOption, "FindDirectChildrenOnly", Qt::FindChildOption::FindDirectChildrenOnly);
        define_qenum_value_under(rb_cQtFindChildOption, "FindChildrenRecursively", Qt::FindChildOption::FindChildrenRecursively);

    Data_Type<Qt::FocusPolicy> rb_cQtFocusPolicy =
        // RubyQt6::QtCore::Qt::FocusPolicy
        define_qenum_under<Qt::FocusPolicy>(rb_mQt, "FocusPolicy");
        define_qenum_value_under(rb_cQtFocusPolicy, "NoFocus", Qt::FocusPolicy::NoFocus);
        define_qenum_value_under(rb_cQtFocusPolicy, "TabFocus", Qt::FocusPolicy::TabFocus);
        define_qenum_value_under(rb_cQtFocusPolicy, "ClickFocus", Qt::FocusPolicy::ClickFocus);
        define_qenum_value_under(rb_cQtFocusPolicy, "StrongFocus", Qt::FocusPolicy::StrongFocus);
        define_qenum_value_under(rb_cQtFocusPolicy, "WheelFocus", Qt::FocusPolicy::WheelFocus);

    Data_Type<Qt::FocusReason> rb_cQtFocusReason =
        // RubyQt6::QtCore::Qt::FocusReason
        define_qenum_under<Qt::FocusReason>(rb_mQt, "FocusReason");
        define_qenum_value_under(rb_cQtFocusReason, "MouseFocusReason", Qt::FocusReason::MouseFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "TabFocusReason", Qt::FocusReason::TabFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "BacktabFocusReason", Qt::FocusReason::BacktabFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "ActiveWindowFocusReason", Qt::FocusReason::ActiveWindowFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "PopupFocusReason", Qt::FocusReason::PopupFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "ShortcutFocusReason", Qt::FocusReason::ShortcutFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "MenuBarFocusReason", Qt::FocusReason::MenuBarFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "OtherFocusReason", Qt::FocusReason::OtherFocusReason);
        define_qenum_value_under(rb_cQtFocusReason, "NoFocusReason", Qt::FocusReason::NoFocusReason);
}
