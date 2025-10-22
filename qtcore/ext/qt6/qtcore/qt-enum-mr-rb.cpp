#include "qt-enum-mr-rb.hpp"
#include <qnamespace.h>
#include <rice/qenum.hpp>

using namespace Rice;

void Init_qt_enum_mr(Rice::Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Enum<Qt::MaskMode> rb_cQtMaskMode =
        // RubyQt6::QtCore::Qt::MaskMode
        define_qenum_under<Qt::MaskMode>("MaskMode", rb_mQt)
            .define_value("MaskInColor", Qt::MaskMode::MaskInColor)
            .define_value("MaskOutColor", Qt::MaskMode::MaskOutColor);

    Enum<Qt::MatchFlag> rb_cQtMatchFlag =
        // RubyQt6::QtCore::Qt::MatchFlag
        define_qenum_under<Qt::MatchFlag>("MatchFlag", rb_mQt)
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
        define_qenum_under<Qt::Modifier>("Modifier", rb_mQt)
            .define_value("META", Qt::Modifier::META)
            .define_value("SHIFT", Qt::Modifier::SHIFT)
            .define_value("CTRL", Qt::Modifier::CTRL)
            .define_value("ALT", Qt::Modifier::ALT)
            .define_value("MODIFIER_MASK", Qt::Modifier::MODIFIER_MASK);

    Enum<Qt::MouseButton> rb_cQtMouseButton =
        // RubyQt6::QtCore::Qt::MouseButton
        define_qenum_under<Qt::MouseButton>("MouseButton", rb_mQt)
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
        define_qenum_under<Qt::MouseEventFlag>("MouseEventFlag", rb_mQt)
            .define_value("NoMouseEventFlag", Qt::MouseEventFlag::NoMouseEventFlag)
            .define_value("MouseEventCreatedDoubleClick", Qt::MouseEventFlag::MouseEventCreatedDoubleClick)
            .define_value("MouseEventFlagMask", Qt::MouseEventFlag::MouseEventFlagMask);

    Enum<Qt::MouseEventSource> rb_cQtMouseEventSource =
        // RubyQt6::QtCore::Qt::MouseEventSource
        define_qenum_under<Qt::MouseEventSource>("MouseEventSource", rb_mQt)
            .define_value("MouseEventNotSynthesized", Qt::MouseEventSource::MouseEventNotSynthesized)
            .define_value("MouseEventSynthesizedBySystem", Qt::MouseEventSource::MouseEventSynthesizedBySystem)
            .define_value("MouseEventSynthesizedByQt", Qt::MouseEventSource::MouseEventSynthesizedByQt)
            .define_value("MouseEventSynthesizedByApplication", Qt::MouseEventSource::MouseEventSynthesizedByApplication);

    Enum<Qt::NativeGestureType> rb_cQtNativeGestureType =
        // RubyQt6::QtCore::Qt::NativeGestureType
        define_qenum_under<Qt::NativeGestureType>("NativeGestureType", rb_mQt)
            .define_value("BeginNativeGesture", Qt::NativeGestureType::BeginNativeGesture)
            .define_value("EndNativeGesture", Qt::NativeGestureType::EndNativeGesture)
            .define_value("PanNativeGesture", Qt::NativeGestureType::PanNativeGesture)
            .define_value("ZoomNativeGesture", Qt::NativeGestureType::ZoomNativeGesture)
            .define_value("SmartZoomNativeGesture", Qt::NativeGestureType::SmartZoomNativeGesture)
            .define_value("RotateNativeGesture", Qt::NativeGestureType::RotateNativeGesture)
            .define_value("SwipeNativeGesture", Qt::NativeGestureType::SwipeNativeGesture);

    Enum<Qt::NavigationMode> rb_cQtNavigationMode =
        // RubyQt6::QtCore::Qt::NavigationMode
        define_qenum_under<Qt::NavigationMode>("NavigationMode", rb_mQt)
            .define_value("NavigationModeNone", Qt::NavigationMode::NavigationModeNone)
            .define_value("NavigationModeKeypadTabOrder", Qt::NavigationMode::NavigationModeKeypadTabOrder)
            .define_value("NavigationModeKeypadDirectional", Qt::NavigationMode::NavigationModeKeypadDirectional)
            .define_value("NavigationModeCursorAuto", Qt::NavigationMode::NavigationModeCursorAuto)
            .define_value("NavigationModeCursorForceVisible", Qt::NavigationMode::NavigationModeCursorForceVisible);

    Enum<Qt::Orientation> rb_cQtOrientation =
        // RubyQt6::QtCore::Qt::Orientation
        define_qenum_under<Qt::Orientation>("Orientation", rb_mQt)
            .define_value("Horizontal", Qt::Orientation::Horizontal)
            .define_value("Vertical", Qt::Orientation::Vertical);

    Enum<Qt::PenCapStyle> rb_cQtPenCapStyle =
        // RubyQt6::QtCore::Qt::PenCapStyle
        define_qenum_under<Qt::PenCapStyle>("PenCapStyle", rb_mQt)
            .define_value("FlatCap", Qt::PenCapStyle::FlatCap)
            .define_value("SquareCap", Qt::PenCapStyle::SquareCap)
            .define_value("RoundCap", Qt::PenCapStyle::RoundCap)
            .define_value("MPenCapStyle", Qt::PenCapStyle::MPenCapStyle);

    Enum<Qt::PenJoinStyle> rb_cQtPenJoinStyle =
        // RubyQt6::QtCore::Qt::PenJoinStyle
        define_qenum_under<Qt::PenJoinStyle>("PenJoinStyle", rb_mQt)
            .define_value("MiterJoin", Qt::PenJoinStyle::MiterJoin)
            .define_value("BevelJoin", Qt::PenJoinStyle::BevelJoin)
            .define_value("RoundJoin", Qt::PenJoinStyle::RoundJoin)
            .define_value("SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin)
            .define_value("MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle);

    Enum<Qt::PenStyle> rb_cQtPenStyle =
        // RubyQt6::QtCore::Qt::PenStyle
        define_qenum_under<Qt::PenStyle>("PenStyle", rb_mQt)
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
        define_qenum_under<Qt::PermissionStatus>("PermissionStatus", rb_mQt)
            .define_value("Undetermined", Qt::PermissionStatus::Undetermined)
            .define_value("Granted", Qt::PermissionStatus::Granted)
            .define_value("Denied", Qt::PermissionStatus::Denied);
}
