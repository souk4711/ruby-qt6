#include "qevent-rb.hpp"
#include <qevent.h>

#include <QAction>
#include <QFile>
#include <QList>
#include <QMimeData>
#include <QPointer>
#include <QWindow>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQActionEvent;
Class rb_cQApplicationStateChangeEvent;
Class rb_cQChildWindowEvent;
Class rb_cQCloseEvent;
Class rb_cQDragLeaveEvent;
Class rb_cQDropEvent;
Class rb_cQDragMoveEvent;
Class rb_cQDragEnterEvent;
Class rb_cQExposeEvent;
Class rb_cQFileOpenEvent;
Class rb_cQFocusEvent;
Class rb_cQHelpEvent;
Class rb_cQHideEvent;
Class rb_cQIconDragEvent;
Class rb_cQInputEvent;
Class rb_cQInputMethodEvent;
Class rb_cQInputMethodQueryEvent;
Class rb_cQMoveEvent;
Class rb_cQPaintEvent;
Class rb_cQPlatformSurfaceEvent;
Class rb_cQResizeEvent;
Class rb_cQScreenOrientationChangeEvent;
Class rb_cQScrollEvent;
Class rb_cQScrollPrepareEvent;
Class rb_cQShortcutEvent;
Class rb_cQShowEvent;
Class rb_cQStatusTipEvent;
Class rb_cQToolBarChangeEvent;
Class rb_cQWhatsThisClickedEvent;
Class rb_cQWindowStateChangeEvent;
Class rb_cQContextMenuEvent;
Class rb_cQKeyEvent;
Class rb_cQPointerEvent;
Class rb_cQSinglePointEvent;
Class rb_cQEnterEvent;
Class rb_cQHoverEvent;
Class rb_cQMouseEvent;
Class rb_cQNativeGestureEvent;
Class rb_cQTabletEvent;
Class rb_cQWheelEvent;
Class rb_cQTouchEvent;

void Init_qevent(Module rb_mQt6QtGui)
{
    rb_cQActionEvent =
        // RubyQt6::QtGui::QActionEvent
        define_class_under<QActionEvent, QEvent>(rb_mQt6QtGui, "QActionEvent")
            // Public Functions
            .define_method("action", &QActionEvent::action)
            .define_method("before", &QActionEvent::before);

    rb_cQApplicationStateChangeEvent =
        // RubyQt6::QtGui::QApplicationStateChangeEvent
        define_class_under<QApplicationStateChangeEvent, QEvent>(rb_mQt6QtGui, "QApplicationStateChangeEvent")
            // Public Functions
            .define_method("application_state", &QApplicationStateChangeEvent::applicationState);

    rb_cQChildWindowEvent =
        // RubyQt6::QtGui::QChildWindowEvent
        define_class_under<QChildWindowEvent, QEvent>(rb_mQt6QtGui, "QChildWindowEvent")
            // Public Functions
            .define_method("child", &QChildWindowEvent::child);

    rb_cQCloseEvent =
        // RubyQt6::QtGui::QCloseEvent
        define_class_under<QCloseEvent, QEvent>(rb_mQt6QtGui, "QCloseEvent");

    rb_cQDragLeaveEvent =
        // RubyQt6::QtGui::QDragLeaveEvent
        define_class_under<QDragLeaveEvent, QEvent>(rb_mQt6QtGui, "QDragLeaveEvent");

    rb_cQDropEvent =
        // RubyQt6::QtGui::QDropEvent
        define_class_under<QDropEvent, QEvent>(rb_mQt6QtGui, "QDropEvent")
            // Public Functions
            .define_method("accept_proposed_action", &QDropEvent::acceptProposedAction)
            .define_method("buttons", &QDropEvent::buttons)
            .define_method("drop_action", &QDropEvent::dropAction)
            .define_method("mime_data", &QDropEvent::mimeData)
            .define_method("modifiers", &QDropEvent::modifiers)
            .define_method("position", &QDropEvent::position)
            .define_method("possible_actions", &QDropEvent::possibleActions)
            .define_method("proposed_action", &QDropEvent::proposedAction)
            .define_method("set_drop_action", &QDropEvent::setDropAction, Arg("action"))
            .define_method("source", &QDropEvent::source);

    rb_cQDragMoveEvent =
        // RubyQt6::QtGui::QDragMoveEvent
        define_class_under<QDragMoveEvent, QDropEvent>(rb_mQt6QtGui, "QDragMoveEvent")
            // Public Functions
            .define_method<void (QDragMoveEvent::*)()>("accept", &QDragMoveEvent::accept)
            .define_method<void (QDragMoveEvent::*)(const QRect &)>("accept", &QDragMoveEvent::accept, Arg("r"))
            .define_method("answer_rect", &QDragMoveEvent::answerRect)
            .define_method<void (QDragMoveEvent::*)()>("ignore", &QDragMoveEvent::ignore)
            .define_method<void (QDragMoveEvent::*)(const QRect &)>("ignore", &QDragMoveEvent::ignore, Arg("r"));

    rb_cQDragEnterEvent =
        // RubyQt6::QtGui::QDragEnterEvent
        define_class_under<QDragEnterEvent, QDragMoveEvent>(rb_mQt6QtGui, "QDragEnterEvent");

    rb_cQExposeEvent =
        // RubyQt6::QtGui::QExposeEvent
        define_class_under<QExposeEvent, QEvent>(rb_mQt6QtGui, "QExposeEvent");

    rb_cQFileOpenEvent =
        // RubyQt6::QtGui::QFileOpenEvent
        define_class_under<QFileOpenEvent, QEvent>(rb_mQt6QtGui, "QFileOpenEvent")
            // Public Functions
            .define_method("file", &QFileOpenEvent::file)
            .define_method("url", &QFileOpenEvent::url);

    rb_cQFocusEvent =
        // RubyQt6::QtGui::QFocusEvent
        define_class_under<QFocusEvent, QEvent>(rb_mQt6QtGui, "QFocusEvent")
            // Public Functions
            .define_method("got_focus", &QFocusEvent::gotFocus)
            .define_method("lost_focus", &QFocusEvent::lostFocus)
            .define_method("reason", &QFocusEvent::reason);

    rb_cQHelpEvent =
        // RubyQt6::QtGui::QHelpEvent
        define_class_under<QHelpEvent, QEvent>(rb_mQt6QtGui, "QHelpEvent")
            // Public Functions
            .define_method("global_pos", &QHelpEvent::globalPos)
            .define_method("global_x", &QHelpEvent::globalX)
            .define_method("global_y", &QHelpEvent::globalY)
            .define_method("pos", &QHelpEvent::pos)
            .define_method("x", &QHelpEvent::x)
            .define_method("y", &QHelpEvent::y);

    rb_cQHideEvent =
        // RubyQt6::QtGui::QHideEvent
        define_class_under<QHideEvent, QEvent>(rb_mQt6QtGui, "QHideEvent");

    rb_cQIconDragEvent =
        // RubyQt6::QtGui::QIconDragEvent
        define_class_under<QIconDragEvent, QEvent>(rb_mQt6QtGui, "QIconDragEvent");

    rb_cQInputEvent =
        // RubyQt6::QtGui::QInputEvent
        define_class_under<QInputEvent, QEvent>(rb_mQt6QtGui, "QInputEvent")
            // Public Functions
            .define_method("device", &QInputEvent::device)
            .define_method("device_type", &QInputEvent::deviceType)
            .define_method("modifiers", &QInputEvent::modifiers)
            .define_method("set_modifiers", &QInputEvent::setModifiers, Arg("modifiers"))
            .define_method("set_timestamp", &QInputEvent::setTimestamp, Arg("timestamp"))
            .define_method("timestamp", &QInputEvent::timestamp);

    rb_cQInputMethodEvent =
        // RubyQt6::QtGui::QInputMethodEvent
        define_class_under<QInputMethodEvent, QEvent>(rb_mQt6QtGui, "QInputMethodEvent")
            // Public Functions
            .define_method("attributes", &QInputMethodEvent::attributes)
            .define_method("commit_string", &QInputMethodEvent::commitString)
            .define_method("preedit_string", &QInputMethodEvent::preeditString)
            .define_method("replacement_start", &QInputMethodEvent::replacementStart)
            .define_method("replacement_length", &QInputMethodEvent::replacementLength)
            .define_method("set_commit_string", &QInputMethodEvent::setCommitString, Arg("commit_string"), Arg("replace_from") = static_cast<int>(0), Arg("replace_length") = static_cast<int>(0));

    rb_cQInputMethodQueryEvent =
        // RubyQt6::QtGui::QInputMethodQueryEvent
        define_class_under<QInputMethodQueryEvent, QEvent>(rb_mQt6QtGui, "QInputMethodQueryEvent")
            // Public Functions
            .define_method("queries", &QInputMethodQueryEvent::queries)
            .define_method("set_value", &QInputMethodQueryEvent::setValue, Arg("query"), Arg("value"))
            .define_method("value", &QInputMethodQueryEvent::value, Arg("query"));

    rb_cQMoveEvent =
        // RubyQt6::QtGui::QMoveEvent
        define_class_under<QMoveEvent, QEvent>(rb_mQt6QtGui, "QMoveEvent")
            // Public Functions
            .define_method("old_pos", &QMoveEvent::oldPos)
            .define_method("pos", &QMoveEvent::pos);

    rb_cQPaintEvent =
        // RubyQt6::QtGui::QPaintEvent
        define_class_under<QPaintEvent, QEvent>(rb_mQt6QtGui, "QPaintEvent")
            // Public Functions
            .define_method("rect", &QPaintEvent::rect)
            .define_method("region", &QPaintEvent::region);

    rb_cQPlatformSurfaceEvent =
        // RubyQt6::QtGui::QPlatformSurfaceEvent
        define_class_under<QPlatformSurfaceEvent, QEvent>(rb_mQt6QtGui, "QPlatformSurfaceEvent");

    rb_cQResizeEvent =
        // RubyQt6::QtGui::QResizeEvent
        define_class_under<QResizeEvent, QEvent>(rb_mQt6QtGui, "QResizeEvent")
            // Public Functions
            .define_method("old_size", &QResizeEvent::oldSize)
            .define_method("size", &QResizeEvent::size);

    rb_cQScreenOrientationChangeEvent =
        // RubyQt6::QtGui::QScreenOrientationChangeEvent
        define_class_under<QScreenOrientationChangeEvent, QEvent>(rb_mQt6QtGui, "QScreenOrientationChangeEvent")
            // Public Functions
            .define_method("orientation", &QScreenOrientationChangeEvent::orientation)
            .define_method("screen", &QScreenOrientationChangeEvent::screen);

    rb_cQScrollEvent =
        // RubyQt6::QtGui::QScrollEvent
        define_class_under<QScrollEvent, QEvent>(rb_mQt6QtGui, "QScrollEvent")
            // Public Functions
            .define_method("content_pos", &QScrollEvent::contentPos)
            .define_method("overshoot_distance", &QScrollEvent::overshootDistance)
            .define_method("scroll_state", &QScrollEvent::scrollState);

    rb_cQScrollPrepareEvent =
        // RubyQt6::QtGui::QScrollPrepareEvent
        define_class_under<QScrollPrepareEvent, QEvent>(rb_mQt6QtGui, "QScrollPrepareEvent")
            // Public Functions
            .define_method("content_pos", &QScrollPrepareEvent::contentPos)
            .define_method("content_pos_range", &QScrollPrepareEvent::contentPosRange)
            .define_method("set_content_pos", &QScrollPrepareEvent::setContentPos, Arg("pos"))
            .define_method("set_content_pos_range", &QScrollPrepareEvent::setContentPosRange, Arg("rect"))
            .define_method("set_viewport_size", &QScrollPrepareEvent::setViewportSize, Arg("size"))
            .define_method("start_pos", &QScrollPrepareEvent::startPos)
            .define_method("viewport_size", &QScrollPrepareEvent::viewportSize);

    rb_cQShortcutEvent =
        // RubyQt6::QtGui::QShortcutEvent
        define_class_under<QShortcutEvent, QEvent>(rb_mQt6QtGui, "QShortcutEvent")
            // Public Functions
            .define_method("ambiguous?", &QShortcutEvent::isAmbiguous)
            .define_method("key", &QShortcutEvent::key)
            .define_method("shortcut_id", &QShortcutEvent::shortcutId);

    rb_cQShowEvent =
        // RubyQt6::QtGui::QShowEvent
        define_class_under<QShowEvent, QEvent>(rb_mQt6QtGui, "QShowEvent");

    rb_cQStatusTipEvent =
        // RubyQt6::QtGui::QStatusTipEvent
        define_class_under<QStatusTipEvent, QEvent>(rb_mQt6QtGui, "QStatusTipEvent")
            // Public Functions
            .define_method("tip", &QStatusTipEvent::tip);

    rb_cQToolBarChangeEvent =
        // RubyQt6::QtGui::QToolBarChangeEvent
        define_class_under<QToolBarChangeEvent, QEvent>(rb_mQt6QtGui, "QToolBarChangeEvent")
            // Public Functions
            .define_method("toggle", &QToolBarChangeEvent::toggle);

    rb_cQWhatsThisClickedEvent =
        // RubyQt6::QtGui::QWhatsThisClickedEvent
        define_class_under<QWhatsThisClickedEvent, QEvent>(rb_mQt6QtGui, "QWhatsThisClickedEvent")
            // Public Functions
            .define_method("href", &QWhatsThisClickedEvent::href);

    rb_cQWindowStateChangeEvent =
        // RubyQt6::QtGui::QWindowStateChangeEvent
        define_class_under<QWindowStateChangeEvent, QEvent>(rb_mQt6QtGui, "QWindowStateChangeEvent")
            // Public Functions
            .define_method("override?", &QWindowStateChangeEvent::isOverride)
            .define_method("old_state", &QWindowStateChangeEvent::oldState);

    rb_cQContextMenuEvent =
        // RubyQt6::QtGui::QContextMenuEvent
        define_class_under<QContextMenuEvent, QInputEvent>(rb_mQt6QtGui, "QContextMenuEvent")
            // Public Functions
            .define_method("global_pos", &QContextMenuEvent::globalPos)
            .define_method("global_x", &QContextMenuEvent::globalX)
            .define_method("global_y", &QContextMenuEvent::globalY)
            .define_method("pos", &QContextMenuEvent::pos)
            .define_method("x", &QContextMenuEvent::x)
            .define_method("y", &QContextMenuEvent::y)
            .define_method("reason", &QContextMenuEvent::reason);

    rb_cQKeyEvent =
        // RubyQt6::QtGui::QKeyEvent
        define_class_under<QKeyEvent, QInputEvent>(rb_mQt6QtGui, "QKeyEvent")
            // Public Functions
            .define_method("count", &QKeyEvent::count)
            .define_method("auto_repeat?", &QKeyEvent::isAutoRepeat)
            .define_method("key", &QKeyEvent::key)
            .define_method("key_combination", &QKeyEvent::keyCombination)
            .define_method("matches", &QKeyEvent::matches, Arg("key"))
            .define_method("modifiers", &QKeyEvent::modifiers)
            .define_method("native_scan_code", &QKeyEvent::nativeScanCode)
            .define_method("native_virtual_key", &QKeyEvent::nativeVirtualKey)
            .define_method("native_modifiers", &QKeyEvent::nativeModifiers)
            .define_method("text", &QKeyEvent::text);

    rb_cQPointerEvent =
        // RubyQt6::QtGui::QPointerEvent
        define_class_under<QPointerEvent, QInputEvent>(rb_mQt6QtGui, "QPointerEvent")
            // Public Functions
            .define_method("add_passive_grabber", &QPointerEvent::addPassiveGrabber, Arg("point"), Arg("grabber"))
            .define_method("all_points_accepted", &QPointerEvent::allPointsAccepted)
            .define_method("all_points_grabbed", &QPointerEvent::allPointsGrabbed)
            .define_method("clear_passive_grabbers", &QPointerEvent::clearPassiveGrabbers, Arg("point"))
            .define_method("exclusive_grabber", &QPointerEvent::exclusiveGrabber, Arg("point"))
            .define_method("begin_event?", &QPointerEvent::isBeginEvent)
            .define_method("end_event?", &QPointerEvent::isEndEvent)
            .define_method("update_event?", &QPointerEvent::isUpdateEvent)
            .define_method("passive_grabbers", &QPointerEvent::passiveGrabbers, Arg("point"))
            .define_method("point", &QPointerEvent::point, Arg("i"))
            .define_method("point_by_id", &QPointerEvent::pointById, Arg("id"))
            .define_method("point_count", &QPointerEvent::pointCount)
            .define_method("pointer_type", &QPointerEvent::pointerType)
            .define_method("pointing_device", &QPointerEvent::pointingDevice)
            .define_method("points", &QPointerEvent::points)
            .define_method("remove_passive_grabber", &QPointerEvent::removePassiveGrabber, Arg("point"), Arg("grabber"))
            .define_method("set_accepted", &QPointerEvent::setAccepted, Arg("accepted"))
            .define_method("set_exclusive_grabber", &QPointerEvent::setExclusiveGrabber, Arg("point"), Arg("exclusive_grabber"))
            .define_method("set_timestamp", &QPointerEvent::setTimestamp, Arg("timestamp"));

    rb_cQSinglePointEvent =
        // RubyQt6::QtGui::QSinglePointEvent
        define_class_under<QSinglePointEvent, QPointerEvent>(rb_mQt6QtGui, "QSinglePointEvent")
            // Public Functions
            .define_method("button", &QSinglePointEvent::button)
            .define_method("buttons", &QSinglePointEvent::buttons)
            .define_method("exclusive_point_grabber", &QSinglePointEvent::exclusivePointGrabber)
            .define_method("global_position", &QSinglePointEvent::globalPosition)
            .define_method("begin_event?", &QSinglePointEvent::isBeginEvent)
            .define_method("end_event?", &QSinglePointEvent::isEndEvent)
            .define_method("update_event?", &QSinglePointEvent::isUpdateEvent)
            .define_method("position", &QSinglePointEvent::position)
            .define_method("scene_position", &QSinglePointEvent::scenePosition)
            .define_method("set_exclusive_point_grabber", &QSinglePointEvent::setExclusivePointGrabber, Arg("exclusive_grabber"));

    rb_cQEnterEvent =
        // RubyQt6::QtGui::QEnterEvent
        define_class_under<QEnterEvent, QSinglePointEvent>(rb_mQt6QtGui, "QEnterEvent");

    rb_cQHoverEvent =
        // RubyQt6::QtGui::QHoverEvent
        define_class_under<QHoverEvent, QSinglePointEvent>(rb_mQt6QtGui, "QHoverEvent")
            // Public Functions
            .define_method("old_pos", &QHoverEvent::oldPos)
            .define_method("old_pos_f", &QHoverEvent::oldPosF)
            .define_method("update_event?", &QHoverEvent::isUpdateEvent);

    rb_cQMouseEvent =
        // RubyQt6::QtGui::QMouseEvent
        define_class_under<QMouseEvent, QSinglePointEvent>(rb_mQt6QtGui, "QMouseEvent")
            // Public Functions
            .define_method("source", &QMouseEvent::source)
            .define_method("flags", &QMouseEvent::flags);

    rb_cQNativeGestureEvent =
        // RubyQt6::QtGui::QNativeGestureEvent
        define_class_under<QNativeGestureEvent, QSinglePointEvent>(rb_mQt6QtGui, "QNativeGestureEvent")
            // Public Functions
            .define_method("delta", &QNativeGestureEvent::delta)
            .define_method("finger_count", &QNativeGestureEvent::fingerCount)
            .define_method("gesture_type", &QNativeGestureEvent::gestureType)
            .define_method("value", &QNativeGestureEvent::value);

    rb_cQTabletEvent =
        // RubyQt6::QtGui::QTabletEvent
        define_class_under<QTabletEvent, QSinglePointEvent>(rb_mQt6QtGui, "QTabletEvent")
            // Public Functions
            .define_method("pressure", &QTabletEvent::pressure)
            .define_method("rotation", &QTabletEvent::rotation)
            .define_method("tangential_pressure", &QTabletEvent::tangentialPressure)
            .define_method("x_tilt", &QTabletEvent::xTilt)
            .define_method("y_tilt", &QTabletEvent::yTilt)
            .define_method("z", &QTabletEvent::z);

    rb_cQWheelEvent =
        // RubyQt6::QtGui::QWheelEvent
        define_class_under<QWheelEvent, QSinglePointEvent>(rb_mQt6QtGui, "QWheelEvent")
            // Public Functions
            .define_method("angle_delta", &QWheelEvent::angleDelta)
            .define_method("has_pixel_delta", &QWheelEvent::hasPixelDelta)
            .define_method("inverted", &QWheelEvent::inverted)
            .define_method("begin_event?", &QWheelEvent::isBeginEvent)
            .define_method("end_event?", &QWheelEvent::isEndEvent)
            .define_method("inverted?", &QWheelEvent::isInverted)
            .define_method("update_event?", &QWheelEvent::isUpdateEvent)
            .define_method("phase", &QWheelEvent::phase)
            .define_method("pixel_delta", &QWheelEvent::pixelDelta)
            .define_method("source", &QWheelEvent::source);

    rb_cQTouchEvent =
        // RubyQt6::QtGui::QTouchEvent
        define_class_under<QTouchEvent, QPointerEvent>(rb_mQt6QtGui, "QTouchEvent")
            // Public Functions
            .define_method("begin_event?", &QTouchEvent::isBeginEvent)
            .define_method("end_event?", &QTouchEvent::isEndEvent)
            .define_method("update_event?", &QTouchEvent::isUpdateEvent)
            .define_method("target", &QTouchEvent::target)
            .define_method("touch_point_states", &QTouchEvent::touchPointStates);
}
