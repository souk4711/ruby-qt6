#include "qt-enum-mr-rb.hpp"
#include <qnamespace.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qt_enum_mr(Module rb_mQt6QtCore)
{
    Module rb_mQt =
        // RubyQt6::QtCore::Qt
        define_module_under(rb_mQt6QtCore, "Qt");

    Data_Type<Qt::MaskMode> rb_cQtMaskMode =
        // RubyQt6::QtCore::Qt::MaskMode
        define_qenum_under<Qt::MaskMode>(rb_mQt, "MaskMode");
        define_qenum_value_under(rb_cQtMaskMode, "MaskInColor", Qt::MaskMode::MaskInColor);
        define_qenum_value_under(rb_cQtMaskMode, "MaskOutColor", Qt::MaskMode::MaskOutColor);

    Data_Type<Qt::MatchFlag> rb_cQtMatchFlag =
        // RubyQt6::QtCore::Qt::MatchFlag
        define_qenum_under<Qt::MatchFlag>(rb_mQt, "MatchFlag");
        define_qenum_value_under(rb_cQtMatchFlag, "MatchExactly", Qt::MatchFlag::MatchExactly);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchContains", Qt::MatchFlag::MatchContains);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchStartsWith", Qt::MatchFlag::MatchStartsWith);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchEndsWith", Qt::MatchFlag::MatchEndsWith);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchRegularExpression", Qt::MatchFlag::MatchRegularExpression);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchWildcard", Qt::MatchFlag::MatchWildcard);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchFixedString", Qt::MatchFlag::MatchFixedString);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchTypeMask", Qt::MatchFlag::MatchTypeMask);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchCaseSensitive", Qt::MatchFlag::MatchCaseSensitive);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchWrap", Qt::MatchFlag::MatchWrap);
        define_qenum_value_under(rb_cQtMatchFlag, "MatchRecursive", Qt::MatchFlag::MatchRecursive);

    Data_Type<Qt::Modifier> rb_cQtModifier =
        // RubyQt6::QtCore::Qt::Modifier
        define_qenum_under<Qt::Modifier>(rb_mQt, "Modifier");
        define_qenum_value_under(rb_cQtModifier, "META", Qt::Modifier::META);
        define_qenum_value_under(rb_cQtModifier, "SHIFT", Qt::Modifier::SHIFT);
        define_qenum_value_under(rb_cQtModifier, "CTRL", Qt::Modifier::CTRL);
        define_qenum_value_under(rb_cQtModifier, "ALT", Qt::Modifier::ALT);
        define_qenum_value_under(rb_cQtModifier, "MODIFIER_MASK", Qt::Modifier::MODIFIER_MASK);

    Data_Type<Qt::MouseButton> rb_cQtMouseButton =
        // RubyQt6::QtCore::Qt::MouseButton
        define_qenum_under<Qt::MouseButton>(rb_mQt, "MouseButton");
        define_qenum_value_under(rb_cQtMouseButton, "NoButton", Qt::MouseButton::NoButton);
        define_qenum_value_under(rb_cQtMouseButton, "LeftButton", Qt::MouseButton::LeftButton);
        define_qenum_value_under(rb_cQtMouseButton, "RightButton", Qt::MouseButton::RightButton);
        define_qenum_value_under(rb_cQtMouseButton, "MiddleButton", Qt::MouseButton::MiddleButton);
        define_qenum_value_under(rb_cQtMouseButton, "BackButton", Qt::MouseButton::BackButton);
        define_qenum_value_under(rb_cQtMouseButton, "XButton1", Qt::MouseButton::XButton1);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton1", Qt::MouseButton::ExtraButton1);
        define_qenum_value_under(rb_cQtMouseButton, "ForwardButton", Qt::MouseButton::ForwardButton);
        define_qenum_value_under(rb_cQtMouseButton, "XButton2", Qt::MouseButton::XButton2);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton2", Qt::MouseButton::ExtraButton2);
        define_qenum_value_under(rb_cQtMouseButton, "TaskButton", Qt::MouseButton::TaskButton);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton3", Qt::MouseButton::ExtraButton3);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton4", Qt::MouseButton::ExtraButton4);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton5", Qt::MouseButton::ExtraButton5);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton6", Qt::MouseButton::ExtraButton6);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton7", Qt::MouseButton::ExtraButton7);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton8", Qt::MouseButton::ExtraButton8);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton9", Qt::MouseButton::ExtraButton9);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton10", Qt::MouseButton::ExtraButton10);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton11", Qt::MouseButton::ExtraButton11);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton12", Qt::MouseButton::ExtraButton12);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton13", Qt::MouseButton::ExtraButton13);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton14", Qt::MouseButton::ExtraButton14);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton15", Qt::MouseButton::ExtraButton15);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton16", Qt::MouseButton::ExtraButton16);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton17", Qt::MouseButton::ExtraButton17);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton18", Qt::MouseButton::ExtraButton18);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton19", Qt::MouseButton::ExtraButton19);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton20", Qt::MouseButton::ExtraButton20);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton21", Qt::MouseButton::ExtraButton21);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton22", Qt::MouseButton::ExtraButton22);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton23", Qt::MouseButton::ExtraButton23);
        define_qenum_value_under(rb_cQtMouseButton, "ExtraButton24", Qt::MouseButton::ExtraButton24);
        define_qenum_value_under(rb_cQtMouseButton, "AllButtons", Qt::MouseButton::AllButtons);
        define_qenum_value_under(rb_cQtMouseButton, "MaxMouseButton", Qt::MouseButton::MaxMouseButton);
        define_qenum_value_under(rb_cQtMouseButton, "MouseButtonMask", Qt::MouseButton::MouseButtonMask);

    Data_Type<Qt::MouseEventFlag> rb_cQtMouseEventFlag =
        // RubyQt6::QtCore::Qt::MouseEventFlag
        define_qenum_under<Qt::MouseEventFlag>(rb_mQt, "MouseEventFlag");
        define_qenum_value_under(rb_cQtMouseEventFlag, "NoMouseEventFlag", Qt::MouseEventFlag::NoMouseEventFlag);
        define_qenum_value_under(rb_cQtMouseEventFlag, "MouseEventCreatedDoubleClick", Qt::MouseEventFlag::MouseEventCreatedDoubleClick);
        define_qenum_value_under(rb_cQtMouseEventFlag, "MouseEventFlagMask", Qt::MouseEventFlag::MouseEventFlagMask);

    Data_Type<Qt::MouseEventSource> rb_cQtMouseEventSource =
        // RubyQt6::QtCore::Qt::MouseEventSource
        define_qenum_under<Qt::MouseEventSource>(rb_mQt, "MouseEventSource");
        define_qenum_value_under(rb_cQtMouseEventSource, "MouseEventNotSynthesized", Qt::MouseEventSource::MouseEventNotSynthesized);
        define_qenum_value_under(rb_cQtMouseEventSource, "MouseEventSynthesizedBySystem", Qt::MouseEventSource::MouseEventSynthesizedBySystem);
        define_qenum_value_under(rb_cQtMouseEventSource, "MouseEventSynthesizedByQt", Qt::MouseEventSource::MouseEventSynthesizedByQt);
        define_qenum_value_under(rb_cQtMouseEventSource, "MouseEventSynthesizedByApplication", Qt::MouseEventSource::MouseEventSynthesizedByApplication);

    Data_Type<Qt::NativeGestureType> rb_cQtNativeGestureType =
        // RubyQt6::QtCore::Qt::NativeGestureType
        define_qenum_under<Qt::NativeGestureType>(rb_mQt, "NativeGestureType");
        define_qenum_value_under(rb_cQtNativeGestureType, "BeginNativeGesture", Qt::NativeGestureType::BeginNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "EndNativeGesture", Qt::NativeGestureType::EndNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "PanNativeGesture", Qt::NativeGestureType::PanNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "ZoomNativeGesture", Qt::NativeGestureType::ZoomNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "SmartZoomNativeGesture", Qt::NativeGestureType::SmartZoomNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "RotateNativeGesture", Qt::NativeGestureType::RotateNativeGesture);
        define_qenum_value_under(rb_cQtNativeGestureType, "SwipeNativeGesture", Qt::NativeGestureType::SwipeNativeGesture);

    Data_Type<Qt::NavigationMode> rb_cQtNavigationMode =
        // RubyQt6::QtCore::Qt::NavigationMode
        define_qenum_under<Qt::NavigationMode>(rb_mQt, "NavigationMode");
        define_qenum_value_under(rb_cQtNavigationMode, "NavigationModeNone", Qt::NavigationMode::NavigationModeNone);
        define_qenum_value_under(rb_cQtNavigationMode, "NavigationModeKeypadTabOrder", Qt::NavigationMode::NavigationModeKeypadTabOrder);
        define_qenum_value_under(rb_cQtNavigationMode, "NavigationModeKeypadDirectional", Qt::NavigationMode::NavigationModeKeypadDirectional);
        define_qenum_value_under(rb_cQtNavigationMode, "NavigationModeCursorAuto", Qt::NavigationMode::NavigationModeCursorAuto);
        define_qenum_value_under(rb_cQtNavigationMode, "NavigationModeCursorForceVisible", Qt::NavigationMode::NavigationModeCursorForceVisible);

    Data_Type<Qt::Orientation> rb_cQtOrientation =
        // RubyQt6::QtCore::Qt::Orientation
        define_qenum_under<Qt::Orientation>(rb_mQt, "Orientation");
        define_qenum_value_under(rb_cQtOrientation, "Horizontal", Qt::Orientation::Horizontal);
        define_qenum_value_under(rb_cQtOrientation, "Vertical", Qt::Orientation::Vertical);

    Data_Type<Qt::PenCapStyle> rb_cQtPenCapStyle =
        // RubyQt6::QtCore::Qt::PenCapStyle
        define_qenum_under<Qt::PenCapStyle>(rb_mQt, "PenCapStyle");
        define_qenum_value_under(rb_cQtPenCapStyle, "FlatCap", Qt::PenCapStyle::FlatCap);
        define_qenum_value_under(rb_cQtPenCapStyle, "SquareCap", Qt::PenCapStyle::SquareCap);
        define_qenum_value_under(rb_cQtPenCapStyle, "RoundCap", Qt::PenCapStyle::RoundCap);
        define_qenum_value_under(rb_cQtPenCapStyle, "MPenCapStyle", Qt::PenCapStyle::MPenCapStyle);

    Data_Type<Qt::PenJoinStyle> rb_cQtPenJoinStyle =
        // RubyQt6::QtCore::Qt::PenJoinStyle
        define_qenum_under<Qt::PenJoinStyle>(rb_mQt, "PenJoinStyle");
        define_qenum_value_under(rb_cQtPenJoinStyle, "MiterJoin", Qt::PenJoinStyle::MiterJoin);
        define_qenum_value_under(rb_cQtPenJoinStyle, "BevelJoin", Qt::PenJoinStyle::BevelJoin);
        define_qenum_value_under(rb_cQtPenJoinStyle, "RoundJoin", Qt::PenJoinStyle::RoundJoin);
        define_qenum_value_under(rb_cQtPenJoinStyle, "SvgMiterJoin", Qt::PenJoinStyle::SvgMiterJoin);
        define_qenum_value_under(rb_cQtPenJoinStyle, "MPenJoinStyle", Qt::PenJoinStyle::MPenJoinStyle);

    Data_Type<Qt::PenStyle> rb_cQtPenStyle =
        // RubyQt6::QtCore::Qt::PenStyle
        define_qenum_under<Qt::PenStyle>(rb_mQt, "PenStyle");
        define_qenum_value_under(rb_cQtPenStyle, "NoPen", Qt::PenStyle::NoPen);
        define_qenum_value_under(rb_cQtPenStyle, "SolidLine", Qt::PenStyle::SolidLine);
        define_qenum_value_under(rb_cQtPenStyle, "DashLine", Qt::PenStyle::DashLine);
        define_qenum_value_under(rb_cQtPenStyle, "DotLine", Qt::PenStyle::DotLine);
        define_qenum_value_under(rb_cQtPenStyle, "DashDotLine", Qt::PenStyle::DashDotLine);
        define_qenum_value_under(rb_cQtPenStyle, "DashDotDotLine", Qt::PenStyle::DashDotDotLine);
        define_qenum_value_under(rb_cQtPenStyle, "CustomDashLine", Qt::PenStyle::CustomDashLine);
        define_qenum_value_under(rb_cQtPenStyle, "MPenStyle", Qt::PenStyle::MPenStyle);

    Data_Type<Qt::PermissionStatus> rb_cQtPermissionStatus =
        // RubyQt6::QtCore::Qt::PermissionStatus
        define_qenum_under<Qt::PermissionStatus>(rb_mQt, "PermissionStatus");
        define_qenum_value_under(rb_cQtPermissionStatus, "Undetermined", Qt::PermissionStatus::Undetermined);
        define_qenum_value_under(rb_cQtPermissionStatus, "Granted", Qt::PermissionStatus::Granted);
        define_qenum_value_under(rb_cQtPermissionStatus, "Denied", Qt::PermissionStatus::Denied);
}
