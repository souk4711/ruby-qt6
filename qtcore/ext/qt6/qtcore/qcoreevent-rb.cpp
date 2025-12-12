#include "qcoreevent-rb.hpp"
#include <qcoreevent.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQEvent;
Class rb_cQChildEvent;
Class rb_cQTimerEvent;
Class rb_cQDynamicPropertyChangeEvent;

void Init_qcoreevent(Module rb_mQt6QtCore)
{
    rb_cQEvent =
        // RubyQt6::QtCore::QEvent
        define_class_under<QEvent>(rb_mQt6QtCore, "QEvent")
            // Public Functions
            .define_method("accept", &QEvent::accept)
            .define_method("ignore", &QEvent::ignore)
            .define_method("accepted?", &QEvent::isAccepted)
            .define_method("input_event?", &QEvent::isInputEvent)
            .define_method("pointer_event?", &QEvent::isPointerEvent)
            .define_method("single_point_event?", &QEvent::isSinglePointEvent)
            .define_method("set_accepted", &QEvent::setAccepted, Arg("accepted"))
            .define_method("spontaneous", &QEvent::spontaneous)
            .define_method("type", &QEvent::type);

    Data_Type<QEvent::Type> rb_cQEventType =
        // RubyQt6::QtCore::QEvent::Type
        define_qenum_under<QEvent::Type>(rb_cQEvent, "Type");
        define_qenum_value_under(rb_cQEventType, "None", QEvent::Type::None);
        define_qenum_value_under(rb_cQEventType, "Timer", QEvent::Type::Timer);
        define_qenum_value_under(rb_cQEventType, "MouseButtonPress", QEvent::Type::MouseButtonPress);
        define_qenum_value_under(rb_cQEventType, "MouseButtonRelease", QEvent::Type::MouseButtonRelease);
        define_qenum_value_under(rb_cQEventType, "MouseButtonDblClick", QEvent::Type::MouseButtonDblClick);
        define_qenum_value_under(rb_cQEventType, "MouseMove", QEvent::Type::MouseMove);
        define_qenum_value_under(rb_cQEventType, "KeyPress", QEvent::Type::KeyPress);
        define_qenum_value_under(rb_cQEventType, "KeyRelease", QEvent::Type::KeyRelease);
        define_qenum_value_under(rb_cQEventType, "FocusIn", QEvent::Type::FocusIn);
        define_qenum_value_under(rb_cQEventType, "FocusOut", QEvent::Type::FocusOut);
        define_qenum_value_under(rb_cQEventType, "FocusAboutToChange", QEvent::Type::FocusAboutToChange);
        define_qenum_value_under(rb_cQEventType, "Enter", QEvent::Type::Enter);
        define_qenum_value_under(rb_cQEventType, "Leave", QEvent::Type::Leave);
        define_qenum_value_under(rb_cQEventType, "Paint", QEvent::Type::Paint);
        define_qenum_value_under(rb_cQEventType, "Move", QEvent::Type::Move);
        define_qenum_value_under(rb_cQEventType, "Resize", QEvent::Type::Resize);
        define_qenum_value_under(rb_cQEventType, "Create", QEvent::Type::Create);
        define_qenum_value_under(rb_cQEventType, "Destroy", QEvent::Type::Destroy);
        define_qenum_value_under(rb_cQEventType, "Show", QEvent::Type::Show);
        define_qenum_value_under(rb_cQEventType, "Hide", QEvent::Type::Hide);
        define_qenum_value_under(rb_cQEventType, "Close", QEvent::Type::Close);
        define_qenum_value_under(rb_cQEventType, "Quit", QEvent::Type::Quit);
        define_qenum_value_under(rb_cQEventType, "ParentChange", QEvent::Type::ParentChange);
        define_qenum_value_under(rb_cQEventType, "ParentAboutToChange", QEvent::Type::ParentAboutToChange);
        define_qenum_value_under(rb_cQEventType, "ThreadChange", QEvent::Type::ThreadChange);
        define_qenum_value_under(rb_cQEventType, "WindowActivate", QEvent::Type::WindowActivate);
        define_qenum_value_under(rb_cQEventType, "WindowDeactivate", QEvent::Type::WindowDeactivate);
        define_qenum_value_under(rb_cQEventType, "ShowToParent", QEvent::Type::ShowToParent);
        define_qenum_value_under(rb_cQEventType, "HideToParent", QEvent::Type::HideToParent);
        define_qenum_value_under(rb_cQEventType, "Wheel", QEvent::Type::Wheel);
        define_qenum_value_under(rb_cQEventType, "WindowTitleChange", QEvent::Type::WindowTitleChange);
        define_qenum_value_under(rb_cQEventType, "WindowIconChange", QEvent::Type::WindowIconChange);
        define_qenum_value_under(rb_cQEventType, "ApplicationWindowIconChange", QEvent::Type::ApplicationWindowIconChange);
        define_qenum_value_under(rb_cQEventType, "ApplicationFontChange", QEvent::Type::ApplicationFontChange);
        define_qenum_value_under(rb_cQEventType, "ApplicationLayoutDirectionChange", QEvent::Type::ApplicationLayoutDirectionChange);
        define_qenum_value_under(rb_cQEventType, "ApplicationPaletteChange", QEvent::Type::ApplicationPaletteChange);
        define_qenum_value_under(rb_cQEventType, "PaletteChange", QEvent::Type::PaletteChange);
        define_qenum_value_under(rb_cQEventType, "Clipboard", QEvent::Type::Clipboard);
        define_qenum_value_under(rb_cQEventType, "Speech", QEvent::Type::Speech);
        define_qenum_value_under(rb_cQEventType, "MetaCall", QEvent::Type::MetaCall);
        define_qenum_value_under(rb_cQEventType, "SockAct", QEvent::Type::SockAct);
        define_qenum_value_under(rb_cQEventType, "WinEventAct", QEvent::Type::WinEventAct);
        define_qenum_value_under(rb_cQEventType, "DeferredDelete", QEvent::Type::DeferredDelete);
        define_qenum_value_under(rb_cQEventType, "DragEnter", QEvent::Type::DragEnter);
        define_qenum_value_under(rb_cQEventType, "DragMove", QEvent::Type::DragMove);
        define_qenum_value_under(rb_cQEventType, "DragLeave", QEvent::Type::DragLeave);
        define_qenum_value_under(rb_cQEventType, "Drop", QEvent::Type::Drop);
        define_qenum_value_under(rb_cQEventType, "DragResponse", QEvent::Type::DragResponse);
        define_qenum_value_under(rb_cQEventType, "ChildAdded", QEvent::Type::ChildAdded);
        define_qenum_value_under(rb_cQEventType, "ChildPolished", QEvent::Type::ChildPolished);
        define_qenum_value_under(rb_cQEventType, "ChildRemoved", QEvent::Type::ChildRemoved);
        define_qenum_value_under(rb_cQEventType, "ShowWindowRequest", QEvent::Type::ShowWindowRequest);
        define_qenum_value_under(rb_cQEventType, "PolishRequest", QEvent::Type::PolishRequest);
        define_qenum_value_under(rb_cQEventType, "Polish", QEvent::Type::Polish);
        define_qenum_value_under(rb_cQEventType, "LayoutRequest", QEvent::Type::LayoutRequest);
        define_qenum_value_under(rb_cQEventType, "UpdateRequest", QEvent::Type::UpdateRequest);
        define_qenum_value_under(rb_cQEventType, "UpdateLater", QEvent::Type::UpdateLater);
        define_qenum_value_under(rb_cQEventType, "EmbeddingControl", QEvent::Type::EmbeddingControl);
        define_qenum_value_under(rb_cQEventType, "ActivateControl", QEvent::Type::ActivateControl);
        define_qenum_value_under(rb_cQEventType, "DeactivateControl", QEvent::Type::DeactivateControl);
        define_qenum_value_under(rb_cQEventType, "ContextMenu", QEvent::Type::ContextMenu);
        define_qenum_value_under(rb_cQEventType, "InputMethod", QEvent::Type::InputMethod);
        define_qenum_value_under(rb_cQEventType, "TabletMove", QEvent::Type::TabletMove);
        define_qenum_value_under(rb_cQEventType, "LocaleChange", QEvent::Type::LocaleChange);
        define_qenum_value_under(rb_cQEventType, "LanguageChange", QEvent::Type::LanguageChange);
        define_qenum_value_under(rb_cQEventType, "LayoutDirectionChange", QEvent::Type::LayoutDirectionChange);
        define_qenum_value_under(rb_cQEventType, "Style", QEvent::Type::Style);
        define_qenum_value_under(rb_cQEventType, "TabletPress", QEvent::Type::TabletPress);
        define_qenum_value_under(rb_cQEventType, "TabletRelease", QEvent::Type::TabletRelease);
        define_qenum_value_under(rb_cQEventType, "OkRequest", QEvent::Type::OkRequest);
        define_qenum_value_under(rb_cQEventType, "HelpRequest", QEvent::Type::HelpRequest);
        define_qenum_value_under(rb_cQEventType, "IconDrag", QEvent::Type::IconDrag);
        define_qenum_value_under(rb_cQEventType, "FontChange", QEvent::Type::FontChange);
        define_qenum_value_under(rb_cQEventType, "EnabledChange", QEvent::Type::EnabledChange);
        define_qenum_value_under(rb_cQEventType, "ActivationChange", QEvent::Type::ActivationChange);
        define_qenum_value_under(rb_cQEventType, "StyleChange", QEvent::Type::StyleChange);
        define_qenum_value_under(rb_cQEventType, "IconTextChange", QEvent::Type::IconTextChange);
        define_qenum_value_under(rb_cQEventType, "ModifiedChange", QEvent::Type::ModifiedChange);
        define_qenum_value_under(rb_cQEventType, "MouseTrackingChange", QEvent::Type::MouseTrackingChange);
        define_qenum_value_under(rb_cQEventType, "WindowBlocked", QEvent::Type::WindowBlocked);
        define_qenum_value_under(rb_cQEventType, "WindowUnblocked", QEvent::Type::WindowUnblocked);
        define_qenum_value_under(rb_cQEventType, "WindowStateChange", QEvent::Type::WindowStateChange);
        define_qenum_value_under(rb_cQEventType, "ReadOnlyChange", QEvent::Type::ReadOnlyChange);
        define_qenum_value_under(rb_cQEventType, "ToolTip", QEvent::Type::ToolTip);
        define_qenum_value_under(rb_cQEventType, "WhatsThis", QEvent::Type::WhatsThis);
        define_qenum_value_under(rb_cQEventType, "StatusTip", QEvent::Type::StatusTip);
        define_qenum_value_under(rb_cQEventType, "ActionChanged", QEvent::Type::ActionChanged);
        define_qenum_value_under(rb_cQEventType, "ActionAdded", QEvent::Type::ActionAdded);
        define_qenum_value_under(rb_cQEventType, "ActionRemoved", QEvent::Type::ActionRemoved);
        define_qenum_value_under(rb_cQEventType, "FileOpen", QEvent::Type::FileOpen);
        define_qenum_value_under(rb_cQEventType, "Shortcut", QEvent::Type::Shortcut);
        define_qenum_value_under(rb_cQEventType, "ShortcutOverride", QEvent::Type::ShortcutOverride);
        define_qenum_value_under(rb_cQEventType, "WhatsThisClicked", QEvent::Type::WhatsThisClicked);
        define_qenum_value_under(rb_cQEventType, "ToolBarChange", QEvent::Type::ToolBarChange);
        define_qenum_value_under(rb_cQEventType, "ApplicationActivate", QEvent::Type::ApplicationActivate);
        define_qenum_value_under(rb_cQEventType, "ApplicationActivated", QEvent::Type::ApplicationActivated);
        define_qenum_value_under(rb_cQEventType, "ApplicationDeactivate", QEvent::Type::ApplicationDeactivate);
        define_qenum_value_under(rb_cQEventType, "ApplicationDeactivated", QEvent::Type::ApplicationDeactivated);
        define_qenum_value_under(rb_cQEventType, "QueryWhatsThis", QEvent::Type::QueryWhatsThis);
        define_qenum_value_under(rb_cQEventType, "EnterWhatsThisMode", QEvent::Type::EnterWhatsThisMode);
        define_qenum_value_under(rb_cQEventType, "LeaveWhatsThisMode", QEvent::Type::LeaveWhatsThisMode);
        define_qenum_value_under(rb_cQEventType, "ZOrderChange", QEvent::Type::ZOrderChange);
        define_qenum_value_under(rb_cQEventType, "HoverEnter", QEvent::Type::HoverEnter);
        define_qenum_value_under(rb_cQEventType, "HoverLeave", QEvent::Type::HoverLeave);
        define_qenum_value_under(rb_cQEventType, "HoverMove", QEvent::Type::HoverMove);
        define_qenum_value_under(rb_cQEventType, "AcceptDropsChange", QEvent::Type::AcceptDropsChange);
        define_qenum_value_under(rb_cQEventType, "ZeroTimerEvent", QEvent::Type::ZeroTimerEvent);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneMouseMove", QEvent::Type::GraphicsSceneMouseMove);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneMousePress", QEvent::Type::GraphicsSceneMousePress);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneMouseRelease", QEvent::Type::GraphicsSceneMouseRelease);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneMouseDoubleClick", QEvent::Type::GraphicsSceneMouseDoubleClick);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneContextMenu", QEvent::Type::GraphicsSceneContextMenu);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneHoverEnter", QEvent::Type::GraphicsSceneHoverEnter);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneHoverMove", QEvent::Type::GraphicsSceneHoverMove);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneHoverLeave", QEvent::Type::GraphicsSceneHoverLeave);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneHelp", QEvent::Type::GraphicsSceneHelp);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneDragEnter", QEvent::Type::GraphicsSceneDragEnter);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneDragMove", QEvent::Type::GraphicsSceneDragMove);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneDragLeave", QEvent::Type::GraphicsSceneDragLeave);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneDrop", QEvent::Type::GraphicsSceneDrop);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneWheel", QEvent::Type::GraphicsSceneWheel);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneLeave", QEvent::Type::GraphicsSceneLeave);
        define_qenum_value_under(rb_cQEventType, "KeyboardLayoutChange", QEvent::Type::KeyboardLayoutChange);
        define_qenum_value_under(rb_cQEventType, "DynamicPropertyChange", QEvent::Type::DynamicPropertyChange);
        define_qenum_value_under(rb_cQEventType, "TabletEnterProximity", QEvent::Type::TabletEnterProximity);
        define_qenum_value_under(rb_cQEventType, "TabletLeaveProximity", QEvent::Type::TabletLeaveProximity);
        define_qenum_value_under(rb_cQEventType, "NonClientAreaMouseMove", QEvent::Type::NonClientAreaMouseMove);
        define_qenum_value_under(rb_cQEventType, "NonClientAreaMouseButtonPress", QEvent::Type::NonClientAreaMouseButtonPress);
        define_qenum_value_under(rb_cQEventType, "NonClientAreaMouseButtonRelease", QEvent::Type::NonClientAreaMouseButtonRelease);
        define_qenum_value_under(rb_cQEventType, "NonClientAreaMouseButtonDblClick", QEvent::Type::NonClientAreaMouseButtonDblClick);
        define_qenum_value_under(rb_cQEventType, "MacSizeChange", QEvent::Type::MacSizeChange);
        define_qenum_value_under(rb_cQEventType, "ContentsRectChange", QEvent::Type::ContentsRectChange);
        define_qenum_value_under(rb_cQEventType, "MacGLWindowChange", QEvent::Type::MacGLWindowChange);
        define_qenum_value_under(rb_cQEventType, "FutureCallOut", QEvent::Type::FutureCallOut);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneResize", QEvent::Type::GraphicsSceneResize);
        define_qenum_value_under(rb_cQEventType, "GraphicsSceneMove", QEvent::Type::GraphicsSceneMove);
        define_qenum_value_under(rb_cQEventType, "CursorChange", QEvent::Type::CursorChange);
        define_qenum_value_under(rb_cQEventType, "ToolTipChange", QEvent::Type::ToolTipChange);
        define_qenum_value_under(rb_cQEventType, "NetworkReplyUpdated", QEvent::Type::NetworkReplyUpdated);
        define_qenum_value_under(rb_cQEventType, "GrabMouse", QEvent::Type::GrabMouse);
        define_qenum_value_under(rb_cQEventType, "UngrabMouse", QEvent::Type::UngrabMouse);
        define_qenum_value_under(rb_cQEventType, "GrabKeyboard", QEvent::Type::GrabKeyboard);
        define_qenum_value_under(rb_cQEventType, "UngrabKeyboard", QEvent::Type::UngrabKeyboard);
        define_qenum_value_under(rb_cQEventType, "StateMachineSignal", QEvent::Type::StateMachineSignal);
        define_qenum_value_under(rb_cQEventType, "StateMachineWrapped", QEvent::Type::StateMachineWrapped);
        define_qenum_value_under(rb_cQEventType, "TouchBegin", QEvent::Type::TouchBegin);
        define_qenum_value_under(rb_cQEventType, "TouchUpdate", QEvent::Type::TouchUpdate);
        define_qenum_value_under(rb_cQEventType, "TouchEnd", QEvent::Type::TouchEnd);
        define_qenum_value_under(rb_cQEventType, "NativeGesture", QEvent::Type::NativeGesture);
        define_qenum_value_under(rb_cQEventType, "RequestSoftwareInputPanel", QEvent::Type::RequestSoftwareInputPanel);
        define_qenum_value_under(rb_cQEventType, "CloseSoftwareInputPanel", QEvent::Type::CloseSoftwareInputPanel);
        define_qenum_value_under(rb_cQEventType, "WinIdChange", QEvent::Type::WinIdChange);
        define_qenum_value_under(rb_cQEventType, "Gesture", QEvent::Type::Gesture);
        define_qenum_value_under(rb_cQEventType, "GestureOverride", QEvent::Type::GestureOverride);
        define_qenum_value_under(rb_cQEventType, "ScrollPrepare", QEvent::Type::ScrollPrepare);
        define_qenum_value_under(rb_cQEventType, "Scroll", QEvent::Type::Scroll);
        define_qenum_value_under(rb_cQEventType, "Expose", QEvent::Type::Expose);
        define_qenum_value_under(rb_cQEventType, "InputMethodQuery", QEvent::Type::InputMethodQuery);
        define_qenum_value_under(rb_cQEventType, "OrientationChange", QEvent::Type::OrientationChange);
        define_qenum_value_under(rb_cQEventType, "TouchCancel", QEvent::Type::TouchCancel);
        define_qenum_value_under(rb_cQEventType, "ThemeChange", QEvent::Type::ThemeChange);
        define_qenum_value_under(rb_cQEventType, "SockClose", QEvent::Type::SockClose);
        define_qenum_value_under(rb_cQEventType, "PlatformPanel", QEvent::Type::PlatformPanel);
        define_qenum_value_under(rb_cQEventType, "StyleAnimationUpdate", QEvent::Type::StyleAnimationUpdate);
        define_qenum_value_under(rb_cQEventType, "ApplicationStateChange", QEvent::Type::ApplicationStateChange);
        define_qenum_value_under(rb_cQEventType, "WindowChangeInternal", QEvent::Type::WindowChangeInternal);
        define_qenum_value_under(rb_cQEventType, "ScreenChangeInternal", QEvent::Type::ScreenChangeInternal);
        define_qenum_value_under(rb_cQEventType, "PlatformSurface", QEvent::Type::PlatformSurface);
        define_qenum_value_under(rb_cQEventType, "Pointer", QEvent::Type::Pointer);
        define_qenum_value_under(rb_cQEventType, "TabletTrackingChange", QEvent::Type::TabletTrackingChange);
        define_qenum_value_under(rb_cQEventType, "WindowAboutToChangeInternal", QEvent::Type::WindowAboutToChangeInternal);
        define_qenum_value_under(rb_cQEventType, "DevicePixelRatioChange", QEvent::Type::DevicePixelRatioChange);
        define_qenum_value_under(rb_cQEventType, "ChildWindowAdded", QEvent::Type::ChildWindowAdded);
        define_qenum_value_under(rb_cQEventType, "ChildWindowRemoved", QEvent::Type::ChildWindowRemoved);
        define_qenum_value_under(rb_cQEventType, "ParentWindowAboutToChange", QEvent::Type::ParentWindowAboutToChange);
        define_qenum_value_under(rb_cQEventType, "ParentWindowChange", QEvent::Type::ParentWindowChange);
        define_qenum_value_under(rb_cQEventType, "SafeAreaMarginsChange", QEvent::Type::SafeAreaMarginsChange);
        define_qenum_value_under(rb_cQEventType, "User", QEvent::Type::User);
        define_qenum_value_under(rb_cQEventType, "MaxUser", QEvent::Type::MaxUser);

    rb_cQChildEvent =
        // RubyQt6::QtCore::QChildEvent
        define_class_under<QChildEvent, QEvent>(rb_mQt6QtCore, "QChildEvent")
            // Public Functions
            .define_method("added", &QChildEvent::added)
            .define_method("child", &QChildEvent::child)
            .define_method("polished", &QChildEvent::polished)
            .define_method("removed", &QChildEvent::removed);

    rb_cQTimerEvent =
        // RubyQt6::QtCore::QTimerEvent
        define_class_under<QTimerEvent, QEvent>(rb_mQt6QtCore, "QTimerEvent")
            // Public Functions
            .define_method("id", &QTimerEvent::id)
            .define_method("matches", &QTimerEvent::matches, Arg("timer"))
            .define_method("timer_id", &QTimerEvent::timerId);

    rb_cQDynamicPropertyChangeEvent =
        // RubyQt6::QtCore::QDynamicPropertyChangeEvent
        define_class_under<QDynamicPropertyChangeEvent, QEvent>(rb_mQt6QtCore, "QDynamicPropertyChangeEvent")
            // Public Functions
            .define_method("property_name", &QDynamicPropertyChangeEvent::propertyName);
}
