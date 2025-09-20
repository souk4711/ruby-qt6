#include "qevent-rb.hpp"
#include <qevent.h>

using namespace Rice;

Rice::Class rb_cQActionEvent;
Rice::Class rb_cQApplicationStateChangeEvent;
Rice::Class rb_cQChildWindowEvent;
Rice::Class rb_cQCloseEvent;
Rice::Class rb_cQContextMenuEvent;
Rice::Class rb_cQDragEnterEvent;
Rice::Class rb_cQDragLeaveEvent;
Rice::Class rb_cQDragMoveEvent;
Rice::Class rb_cQDropEvent;
Rice::Class rb_cQEnterEvent;
Rice::Class rb_cQExposeEvent;
Rice::Class rb_cQFileOpenEvent;
Rice::Class rb_cQFocusEvent;
Rice::Class rb_cQHelpEvent;
Rice::Class rb_cQHideEvent;
Rice::Class rb_cQHoverEvent;
Rice::Class rb_cQIconDragEvent;
Rice::Class rb_cQInputEvent;
Rice::Class rb_cQInputMethodEvent;
Rice::Class rb_cQInputMethodEventAttribute;
Rice::Class rb_cQInputMethodQueryEvent;
Rice::Class rb_cQKeyEvent;
Rice::Class rb_cQMouseEvent;
Rice::Class rb_cQMoveEvent;
Rice::Class rb_cQNativeGestureEvent;
Rice::Class rb_cQPaintEvent;
Rice::Class rb_cQPlatformSurfaceEvent;
Rice::Class rb_cQPointerEvent;
Rice::Class rb_cQResizeEvent;
Rice::Class rb_cQScreenOrientationChangeEvent;
Rice::Class rb_cQScrollEvent;
Rice::Class rb_cQScrollPrepareEvent;
Rice::Class rb_cQShortcutEvent;
Rice::Class rb_cQShowEvent;
Rice::Class rb_cQSinglePointEvent;
Rice::Class rb_cQStatusTipEvent;
Rice::Class rb_cQTabletEvent;
Rice::Class rb_cQToolBarChangeEvent;
Rice::Class rb_cQTouchEvent;
Rice::Class rb_cQWhatsThisClickedEvent;
Rice::Class rb_cQWheelEvent;
Rice::Class rb_cQWindowStateChangeEvent;

void Init_qevent(Rice::Module rb_mQt6QtGui)
{
    rb_cQActionEvent =
        // RubyQt6::QtGui::QActionEvent
        define_class_under<QActionEvent, QEvent>(rb_mQt6QtGui, "QActionEvent");

    rb_cQApplicationStateChangeEvent =
        // RubyQt6::QtGui::QApplicationStateChangeEvent
        define_class_under<QApplicationStateChangeEvent, QEvent>(rb_mQt6QtGui, "QApplicationStateChangeEvent");

    rb_cQChildWindowEvent =
        // RubyQt6::QtGui::QChildWindowEvent
        define_class_under<QChildWindowEvent, QEvent>(rb_mQt6QtGui, "QChildWindowEvent");

    rb_cQCloseEvent =
        // RubyQt6::QtGui::QCloseEvent
        define_class_under<QCloseEvent, QEvent>(rb_mQt6QtGui, "QCloseEvent");

    rb_cQDragLeaveEvent =
        // RubyQt6::QtGui::QDragLeaveEvent
        define_class_under<QDragLeaveEvent, QEvent>(rb_mQt6QtGui, "QDragLeaveEvent");

    rb_cQDropEvent =
        // RubyQt6::QtGui::QDropEvent
        define_class_under<QDropEvent, QEvent>(rb_mQt6QtGui, "QDropEvent");

    rb_cQDragMoveEvent =
        // RubyQt6::QtGui::QDragMoveEvent
        define_class_under<QDragMoveEvent, QDropEvent>(rb_mQt6QtGui, "QDragMoveEvent");

    rb_cQDragEnterEvent =
        // RubyQt6::QtGui::QDragEnterEvent
        define_class_under<QDragEnterEvent, QDragMoveEvent>(rb_mQt6QtGui, "QDragEnterEvent");

    rb_cQExposeEvent =
        // RubyQt6::QtGui::QExposeEvent
        define_class_under<QExposeEvent, QEvent>(rb_mQt6QtGui, "QExposeEvent");

    rb_cQFileOpenEvent =
        // RubyQt6::QtGui::QFileOpenEvent
        define_class_under<QFileOpenEvent, QEvent>(rb_mQt6QtGui, "QFileOpenEvent");

    rb_cQFocusEvent =
        // RubyQt6::QtGui::QFocusEvent
        define_class_under<QFocusEvent, QEvent>(rb_mQt6QtGui, "QFocusEvent");

    rb_cQHelpEvent =
        // RubyQt6::QtGui::QHelpEvent
        define_class_under<QHelpEvent, QEvent>(rb_mQt6QtGui, "QHelpEvent");

    rb_cQHideEvent =
        // RubyQt6::QtGui::QHideEvent
        define_class_under<QHideEvent, QEvent>(rb_mQt6QtGui, "QHideEvent");

    rb_cQIconDragEvent =
        // RubyQt6::QtGui::QIconDragEvent
        define_class_under<QIconDragEvent, QEvent>(rb_mQt6QtGui, "QIconDragEvent");

    rb_cQInputEvent =
        // RubyQt6::QtGui::QInputEvent
        define_class_under<QInputEvent, QEvent>(rb_mQt6QtGui, "QInputEvent");

    rb_cQInputMethodEvent =
        // RubyQt6::QtGui::QInputMethodEvent
        define_class_under<QInputMethodEvent, QEvent>(rb_mQt6QtGui, "QInputMethodEvent");

    rb_cQInputMethodQueryEvent =
        // RubyQt6::QtGui::QInputMethodQueryEvent
        define_class_under<QInputMethodQueryEvent, QEvent>(rb_mQt6QtGui, "QInputMethodQueryEvent");

    rb_cQMoveEvent =
        // RubyQt6::QtGui::QMoveEvent
        define_class_under<QMoveEvent, QEvent>(rb_mQt6QtGui, "QMoveEvent");

    rb_cQPaintEvent =
        // RubyQt6::QtGui::QPaintEvent
        define_class_under<QPaintEvent, QEvent>(rb_mQt6QtGui, "QPaintEvent");

    rb_cQPlatformSurfaceEvent =
        // RubyQt6::QtGui::QPlatformSurfaceEvent
        define_class_under<QPlatformSurfaceEvent, QEvent>(rb_mQt6QtGui, "QPlatformSurfaceEvent");

    rb_cQResizeEvent =
        // RubyQt6::QtGui::QResizeEvent
        define_class_under<QResizeEvent, QEvent>(rb_mQt6QtGui, "QResizeEvent");

    rb_cQScreenOrientationChangeEvent =
        // RubyQt6::QtGui::QScreenOrientationChangeEvent
        define_class_under<QScreenOrientationChangeEvent, QEvent>(rb_mQt6QtGui, "QScreenOrientationChangeEvent");

    rb_cQScrollEvent =
        // RubyQt6::QtGui::QScrollEvent
        define_class_under<QScrollEvent, QEvent>(rb_mQt6QtGui, "QScrollEvent");

    rb_cQScrollPrepareEvent =
        // RubyQt6::QtGui::QScrollPrepareEvent
        define_class_under<QScrollPrepareEvent, QEvent>(rb_mQt6QtGui, "QScrollPrepareEvent");

    rb_cQShortcutEvent =
        // RubyQt6::QtGui::QShortcutEvent
        define_class_under<QShortcutEvent, QEvent>(rb_mQt6QtGui, "QShortcutEvent");

    rb_cQShowEvent =
        // RubyQt6::QtGui::QShowEvent
        define_class_under<QShowEvent, QEvent>(rb_mQt6QtGui, "QShowEvent");

    rb_cQStatusTipEvent =
        // RubyQt6::QtGui::QStatusTipEvent
        define_class_under<QStatusTipEvent, QEvent>(rb_mQt6QtGui, "QStatusTipEvent");

    rb_cQToolBarChangeEvent =
        // RubyQt6::QtGui::QToolBarChangeEvent
        define_class_under<QToolBarChangeEvent, QEvent>(rb_mQt6QtGui, "QToolBarChangeEvent");

    rb_cQWhatsThisClickedEvent =
        // RubyQt6::QtGui::QWhatsThisClickedEvent
        define_class_under<QWhatsThisClickedEvent, QEvent>(rb_mQt6QtGui, "QWhatsThisClickedEvent");

    rb_cQWindowStateChangeEvent =
        // RubyQt6::QtGui::QWindowStateChangeEvent
        define_class_under<QWindowStateChangeEvent, QEvent>(rb_mQt6QtGui, "QWindowStateChangeEvent");

    rb_cQContextMenuEvent =
        // RubyQt6::QtGui::QContextMenuEvent
        define_class_under<QContextMenuEvent, QInputEvent>(rb_mQt6QtGui, "QContextMenuEvent");

    rb_cQKeyEvent =
        // RubyQt6::QtGui::QKeyEvent
        define_class_under<QKeyEvent, QInputEvent>(rb_mQt6QtGui, "QKeyEvent");

    rb_cQPointerEvent =
        // RubyQt6::QtGui::QPointerEvent
        define_class_under<QPointerEvent, QInputEvent>(rb_mQt6QtGui, "QPointerEvent");

    rb_cQSinglePointEvent =
        // RubyQt6::QtGui::QSinglePointEvent
        define_class_under<QSinglePointEvent, QPointerEvent>(rb_mQt6QtGui, "QSinglePointEvent");

    rb_cQEnterEvent =
        // RubyQt6::QtGui::QEnterEvent
        define_class_under<QEnterEvent, QSinglePointEvent>(rb_mQt6QtGui, "QEnterEvent");

    rb_cQHoverEvent =
        // RubyQt6::QtGui::QHoverEvent
        define_class_under<QHoverEvent, QSinglePointEvent>(rb_mQt6QtGui, "QHoverEvent");

    rb_cQMouseEvent =
        // RubyQt6::QtGui::QMouseEvent
        define_class_under<QMouseEvent, QSinglePointEvent>(rb_mQt6QtGui, "QMouseEvent");

    rb_cQNativeGestureEvent =
        // RubyQt6::QtGui::QNativeGestureEvent
        define_class_under<QNativeGestureEvent, QSinglePointEvent>(rb_mQt6QtGui, "QNativeGestureEvent");

    rb_cQTabletEvent =
        // RubyQt6::QtGui::QTabletEvent
        define_class_under<QTabletEvent, QSinglePointEvent>(rb_mQt6QtGui, "QTabletEvent");

    rb_cQWheelEvent =
        // RubyQt6::QtGui::QWheelEvent
        define_class_under<QWheelEvent, QSinglePointEvent>(rb_mQt6QtGui, "QWheelEvent");

    rb_cQTouchEvent =
        // RubyQt6::QtGui::QTouchEvent
        define_class_under<QTouchEvent, QPointerEvent>(rb_mQt6QtGui, "QTouchEvent");
}
