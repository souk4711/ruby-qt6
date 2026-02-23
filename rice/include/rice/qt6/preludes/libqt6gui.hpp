// This file is part of [RubyQt6](https://github.com/souk4711/ruby-qt6).
//
// It is licensed under the LGPLv3, included below.
//
// As a special exception to the GNU Lesser General Public License version 3
// ("LGPL3"), the copyright holders of this Library give you permission to
// convey to a third party a Combined Work that links statically or dynamically
// to this Library without providing any Minimal Corresponding Source or
// Minimal Application Code as set out in 4d or providing the installation
// information set out in section 4e, provided that you comply with the other
// provisions of LGPL3 and provided that you meet, for the Application the
// terms and conditions of the license(s) which apply to the Application.
//
// Except as stated in this special exception, the provisions of LGPL3 will
// continue to comply in full to this Library. If you modify this Library, you
// may apply this exception to your version of this Library, but you are not
// obliged to do so. If you do not wish to do so, delete this exception
// statement from your version. This exception does not (and cannot) modify any
// license terms which apply to the Application, with which you must still
// comply.

#ifndef RICE_QT6_PRELUDES_LIBQT6GUI_HPP
#define RICE_QT6_PRELUDES_LIBQT6GUI_HPP

#include <QBrush>
#include <QColor>
#include <QCursor>
#include <QActionEvent>
#include <QApplicationStateChangeEvent>
#include <QChildWindowEvent>
#include <QCloseEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QExposeEvent>
#include <QFileOpenEvent>
#include <QFocusEvent>
#include <QHelpEvent>
#include <QHideEvent>
#include <QIconDragEvent>
#include <QInputEvent>
#include <QInputMethodEvent>
#include <QInputMethodQueryEvent>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QPlatformSurfaceEvent>
#include <QResizeEvent>
#include <QScreenOrientationChangeEvent>
#include <QScrollEvent>
#include <QScrollPrepareEvent>
#include <QShortcutEvent>
#include <QShowEvent>
#include <QStatusTipEvent>
#include <QToolBarChangeEvent>
#include <QWhatsThisClickedEvent>
#include <QWindowStateChangeEvent>
#include <QContextMenuEvent>
#include <QKeyEvent>
#include <QPointerEvent>
#include <QSinglePointEvent>
#include <QEnterEvent>
#include <QHoverEvent>
#include <QMouseEvent>
#include <QNativeGestureEvent>
#include <QTabletEvent>
#include <QWheelEvent>
#include <QTouchEvent>
#include <QFont>
#include <QFontInfo>
#include <QFontMetrics>
#include <QIcon>
#include <QKeySequence>
#include <QPaintDevice>
#include <QPagedPaintDevice>
#include <QPicture>
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include <QPalette>
#include <QPen>
#include <QRegion>
#include <QTextCursor>
#include <QAbstractFileIconProvider>
#include <QAction>
#include <QGuiApplication>
#include <QMovie>
#include <QScreen>
#include <QTextDocument>
#include <QValidator>
#include <QWindow>

void declare_qlass_under_libqt6gui(Module rb_mQt6)
{
    Module rb_mQt6QtGui = define_module_under(rb_mQt6, "QtGui");
    declare_qlass_under<QBrush>(rb_mQt6QtGui, "QBrush");
    declare_qlass_under<QColor>(rb_mQt6QtGui, "QColor");
    declare_qlass_under<QCursor>(rb_mQt6QtGui, "QCursor");
    declare_qlass_under<QActionEvent>(rb_mQt6QtGui, "QActionEvent");
    declare_qlass_under<QApplicationStateChangeEvent>(rb_mQt6QtGui, "QApplicationStateChangeEvent");
    declare_qlass_under<QChildWindowEvent>(rb_mQt6QtGui, "QChildWindowEvent");
    declare_qlass_under<QCloseEvent>(rb_mQt6QtGui, "QCloseEvent");
    declare_qlass_under<QDragLeaveEvent>(rb_mQt6QtGui, "QDragLeaveEvent");
    declare_qlass_under<QDropEvent>(rb_mQt6QtGui, "QDropEvent");
    declare_qlass_under<QDragMoveEvent>(rb_mQt6QtGui, "QDragMoveEvent");
    declare_qlass_under<QDragEnterEvent>(rb_mQt6QtGui, "QDragEnterEvent");
    declare_qlass_under<QExposeEvent>(rb_mQt6QtGui, "QExposeEvent");
    declare_qlass_under<QFileOpenEvent>(rb_mQt6QtGui, "QFileOpenEvent");
    declare_qlass_under<QFocusEvent>(rb_mQt6QtGui, "QFocusEvent");
    declare_qlass_under<QHelpEvent>(rb_mQt6QtGui, "QHelpEvent");
    declare_qlass_under<QHideEvent>(rb_mQt6QtGui, "QHideEvent");
    declare_qlass_under<QIconDragEvent>(rb_mQt6QtGui, "QIconDragEvent");
    declare_qlass_under<QInputEvent>(rb_mQt6QtGui, "QInputEvent");
    declare_qlass_under<QInputMethodEvent>(rb_mQt6QtGui, "QInputMethodEvent");
    declare_qlass_under<QInputMethodQueryEvent>(rb_mQt6QtGui, "QInputMethodQueryEvent");
    declare_qlass_under<QMoveEvent>(rb_mQt6QtGui, "QMoveEvent");
    declare_qlass_under<QPaintEvent>(rb_mQt6QtGui, "QPaintEvent");
    declare_qlass_under<QPlatformSurfaceEvent>(rb_mQt6QtGui, "QPlatformSurfaceEvent");
    declare_qlass_under<QResizeEvent>(rb_mQt6QtGui, "QResizeEvent");
    declare_qlass_under<QScreenOrientationChangeEvent>(rb_mQt6QtGui, "QScreenOrientationChangeEvent");
    declare_qlass_under<QScrollEvent>(rb_mQt6QtGui, "QScrollEvent");
    declare_qlass_under<QScrollPrepareEvent>(rb_mQt6QtGui, "QScrollPrepareEvent");
    declare_qlass_under<QShortcutEvent>(rb_mQt6QtGui, "QShortcutEvent");
    declare_qlass_under<QShowEvent>(rb_mQt6QtGui, "QShowEvent");
    declare_qlass_under<QStatusTipEvent>(rb_mQt6QtGui, "QStatusTipEvent");
    declare_qlass_under<QToolBarChangeEvent>(rb_mQt6QtGui, "QToolBarChangeEvent");
    declare_qlass_under<QWhatsThisClickedEvent>(rb_mQt6QtGui, "QWhatsThisClickedEvent");
    declare_qlass_under<QWindowStateChangeEvent>(rb_mQt6QtGui, "QWindowStateChangeEvent");
    declare_qlass_under<QContextMenuEvent>(rb_mQt6QtGui, "QContextMenuEvent");
    declare_qlass_under<QKeyEvent>(rb_mQt6QtGui, "QKeyEvent");
    declare_qlass_under<QPointerEvent>(rb_mQt6QtGui, "QPointerEvent");
    declare_qlass_under<QSinglePointEvent>(rb_mQt6QtGui, "QSinglePointEvent");
    declare_qlass_under<QEnterEvent>(rb_mQt6QtGui, "QEnterEvent");
    declare_qlass_under<QHoverEvent>(rb_mQt6QtGui, "QHoverEvent");
    declare_qlass_under<QMouseEvent>(rb_mQt6QtGui, "QMouseEvent");
    declare_qlass_under<QNativeGestureEvent>(rb_mQt6QtGui, "QNativeGestureEvent");
    declare_qlass_under<QTabletEvent>(rb_mQt6QtGui, "QTabletEvent");
    declare_qlass_under<QWheelEvent>(rb_mQt6QtGui, "QWheelEvent");
    declare_qlass_under<QTouchEvent>(rb_mQt6QtGui, "QTouchEvent");
    declare_qlass_under<QFont>(rb_mQt6QtGui, "QFont");
    declare_qlass_under<QFontInfo>(rb_mQt6QtGui, "QFontInfo");
    declare_qlass_under<QFontMetrics>(rb_mQt6QtGui, "QFontMetrics");
    declare_qlass_under<QIcon>(rb_mQt6QtGui, "QIcon");
    declare_qlass_under<QKeySequence>(rb_mQt6QtGui, "QKeySequence");
    declare_qlass_under<QPaintDevice>(rb_mQt6QtGui, "QPaintDevice");
    declare_qlass_under<QPagedPaintDevice>(rb_mQt6QtGui, "QPagedPaintDevice");
    declare_qlass_under<QPicture>(rb_mQt6QtGui, "QPicture");
    declare_qlass_under<QPixmap>(rb_mQt6QtGui, "QPixmap");
    declare_qlass_under<QPainter>(rb_mQt6QtGui, "QPainter");
    declare_qlass_under<QPainterPath>(rb_mQt6QtGui, "QPainterPath");
    declare_qlass_under<QPalette>(rb_mQt6QtGui, "QPalette");
    declare_qlass_under<QPen>(rb_mQt6QtGui, "QPen");
    declare_qlass_under<QRegion>(rb_mQt6QtGui, "QRegion");
    declare_qlass_under<QTextCursor>(rb_mQt6QtGui, "QTextCursor");
    declare_qlass_under<QAbstractFileIconProvider>(rb_mQt6QtGui, "QAbstractFileIconProvider");
    declare_qlass_under<QAction>(rb_mQt6QtGui, "QAction");
    declare_qlass_under<QGuiApplication>(rb_mQt6QtGui, "QGuiApplication");
    declare_qlass_under<QMovie>(rb_mQt6QtGui, "QMovie");
    declare_qlass_under<QScreen>(rb_mQt6QtGui, "QScreen");
    declare_qlass_under<QTextDocument>(rb_mQt6QtGui, "QTextDocument");
    declare_qlass_under<QValidator>(rb_mQt6QtGui, "QValidator");
    declare_qlass_under<QWindow>(rb_mQt6QtGui, "QWindow");
    declare_qlass_under<QPolygon>(rb_mQt6QtGui, "QPolygon");
    declare_qlass_under<QPolygonF>(rb_mQt6QtGui, "QPolygonF");

    Class rb_cQIcon = rb_mQt6QtGui.const_get("QIcon").value();
    Class rb_cQPalette = rb_mQt6QtGui.const_get("QPalette").value();
    declare_qlass_under<QIcon::Mode>(rb_cQIcon, "Mode");
    declare_qlass_under<QPalette::ColorRole>(rb_cQPalette, "ColorRole");

    Module rb_mQt6T = define_module_under(rb_mQt6, "T");
    declare_qlass_under<QList<QPoint>>(rb_mQt6T, "QList≺QPoint≻");
    declare_qlass_under<QList<QPointF>>(rb_mQt6T, "QList≺QPointF≻");
}

#endif
