#ifndef RICE_DLLIMPORT_QTGUI_HPP
#define RICE_DLLIMPORT_QTGUI_HPP

inline void Init_rice_dllimport_qtgui(Rice::Module rb_mQt6QtGui)
{
    declare_qlass_under<QBrush>(rb_mQt6QtGui, "QBrush");
    declare_qlass_under<QColor>(rb_mQt6QtGui, "QColor");
    declare_qlass_under<QCursor>(rb_mQt6QtGui, "QCursor");
    declare_qlass_under<QDesktopServices>(rb_mQt6QtGui, "QDesktopServices");
    declare_qlass_under<QActionEvent, QEvent>(rb_mQt6QtGui, "QActionEvent");
    declare_qlass_under<QApplicationStateChangeEvent, QEvent>(rb_mQt6QtGui, "QApplicationStateChangeEvent");
    declare_qlass_under<QChildWindowEvent, QEvent>(rb_mQt6QtGui, "QChildWindowEvent");
    declare_qlass_under<QCloseEvent, QEvent>(rb_mQt6QtGui, "QCloseEvent");;
    declare_qlass_under<QDragLeaveEvent, QEvent>(rb_mQt6QtGui, "QDragLeaveEvent");;
    declare_qlass_under<QDropEvent, QEvent>(rb_mQt6QtGui, "QDropEvent");
    declare_qlass_under<QDragMoveEvent, QDropEvent>(rb_mQt6QtGui, "QDragMoveEvent");
    declare_qlass_under<QDragEnterEvent, QDragMoveEvent>(rb_mQt6QtGui, "QDragEnterEvent");;
    declare_qlass_under<QExposeEvent, QEvent>(rb_mQt6QtGui, "QExposeEvent");;
    declare_qlass_under<QFileOpenEvent, QEvent>(rb_mQt6QtGui, "QFileOpenEvent");
    declare_qlass_under<QFocusEvent, QEvent>(rb_mQt6QtGui, "QFocusEvent");
    declare_qlass_under<QHelpEvent, QEvent>(rb_mQt6QtGui, "QHelpEvent");
    declare_qlass_under<QHideEvent, QEvent>(rb_mQt6QtGui, "QHideEvent");;
    declare_qlass_under<QIconDragEvent, QEvent>(rb_mQt6QtGui, "QIconDragEvent");;
    declare_qlass_under<QInputEvent, QEvent>(rb_mQt6QtGui, "QInputEvent");
    declare_qlass_under<QInputMethodEvent, QEvent>(rb_mQt6QtGui, "QInputMethodEvent");
    declare_qlass_under<QInputMethodQueryEvent, QEvent>(rb_mQt6QtGui, "QInputMethodQueryEvent");
    declare_qlass_under<QMoveEvent, QEvent>(rb_mQt6QtGui, "QMoveEvent");
    declare_qlass_under<QPaintEvent, QEvent>(rb_mQt6QtGui, "QPaintEvent");
    declare_qlass_under<QPlatformSurfaceEvent, QEvent>(rb_mQt6QtGui, "QPlatformSurfaceEvent");;
    declare_qlass_under<QResizeEvent, QEvent>(rb_mQt6QtGui, "QResizeEvent");
    declare_qlass_under<QScreenOrientationChangeEvent, QEvent>(rb_mQt6QtGui, "QScreenOrientationChangeEvent");
    declare_qlass_under<QScrollEvent, QEvent>(rb_mQt6QtGui, "QScrollEvent");
    declare_qlass_under<QScrollPrepareEvent, QEvent>(rb_mQt6QtGui, "QScrollPrepareEvent");
    declare_qlass_under<QShortcutEvent, QEvent>(rb_mQt6QtGui, "QShortcutEvent");
    declare_qlass_under<QShowEvent, QEvent>(rb_mQt6QtGui, "QShowEvent");;
    declare_qlass_under<QStatusTipEvent, QEvent>(rb_mQt6QtGui, "QStatusTipEvent");
    declare_qlass_under<QToolBarChangeEvent, QEvent>(rb_mQt6QtGui, "QToolBarChangeEvent");
    declare_qlass_under<QWhatsThisClickedEvent, QEvent>(rb_mQt6QtGui, "QWhatsThisClickedEvent");
    declare_qlass_under<QWindowStateChangeEvent, QEvent>(rb_mQt6QtGui, "QWindowStateChangeEvent");
    declare_qlass_under<QContextMenuEvent, QInputEvent>(rb_mQt6QtGui, "QContextMenuEvent");
    declare_qlass_under<QKeyEvent, QInputEvent>(rb_mQt6QtGui, "QKeyEvent");
    declare_qlass_under<QPointerEvent, QInputEvent>(rb_mQt6QtGui, "QPointerEvent");
    declare_qlass_under<QSinglePointEvent, QPointerEvent>(rb_mQt6QtGui, "QSinglePointEvent");
    declare_qlass_under<QEnterEvent, QSinglePointEvent>(rb_mQt6QtGui, "QEnterEvent");;
    declare_qlass_under<QHoverEvent, QSinglePointEvent>(rb_mQt6QtGui, "QHoverEvent");
    declare_qlass_under<QMouseEvent, QSinglePointEvent>(rb_mQt6QtGui, "QMouseEvent");
    declare_qlass_under<QNativeGestureEvent, QSinglePointEvent>(rb_mQt6QtGui, "QNativeGestureEvent");
    declare_qlass_under<QTabletEvent, QSinglePointEvent>(rb_mQt6QtGui, "QTabletEvent");
    declare_qlass_under<QWheelEvent, QSinglePointEvent>(rb_mQt6QtGui, "QWheelEvent");
    declare_qlass_under<QTouchEvent, QPointerEvent>(rb_mQt6QtGui, "QTouchEvent");
    declare_qlass_under<QFont>(rb_mQt6QtGui, "QFont");
    declare_qlass_under<QFontDatabase>(rb_mQt6QtGui, "QFontDatabase");
    declare_qlass_under<QFontInfo>(rb_mQt6QtGui, "QFontInfo");
    declare_qlass_under<QFontMetrics>(rb_mQt6QtGui, "QFontMetrics");
    declare_qlass_under<QFontMetricsF>(rb_mQt6QtGui, "QFontMetricsF");
    declare_qlass_under<QGradient>(rb_mQt6QtGui, "QGradient");
    declare_qlass_under<QConicalGradient, QGradient>(rb_mQt6QtGui, "QConicalGradient");
    declare_qlass_under<QLinearGradient, QGradient>(rb_mQt6QtGui, "QLinearGradient");
    declare_qlass_under<QRadialGradient, QGradient>(rb_mQt6QtGui, "QRadialGradient");
    declare_qlass_under<QIcon>(rb_mQt6QtGui, "QIcon");
    declare_qlass_under<QKeySequence>(rb_mQt6QtGui, "QKeySequence");
    declare_qlass_under<QPaintDevice>(rb_mQt6QtGui, "QPaintDevice");
    declare_qlass_under<QPagedPaintDevice, QPaintDevice>(rb_mQt6QtGui, "QPagedPaintDevice");
    declare_qlass_under<QPicture, QPaintDevice>(rb_mQt6QtGui, "QPicture");
    declare_qlass_under<QPixmap, QPaintDevice>(rb_mQt6QtGui, "QPixmap");
    declare_qlass_under<QImage, QPaintDevice>(rb_mQt6QtGui, "QImage");
    declare_qlass_under<QImageWriter>(rb_mQt6QtGui, "QImageWriter");
    declare_qlass_under<QPainter>(rb_mQt6QtGui, "QPainter");
    declare_qlass_under<QPainterPath>(rb_mQt6QtGui, "QPainterPath");
    declare_qlass_under<QPainterPathStroker>(rb_mQt6QtGui, "QPainterPathStroker");
    declare_qlass_under<QPalette>(rb_mQt6QtGui, "QPalette");
    declare_qlass_under<QPen>(rb_mQt6QtGui, "QPen");
    declare_qlass_under<QRegion>(rb_mQt6QtGui, "QRegion");
    declare_qlass_under<QTextCursor>(rb_mQt6QtGui, "QTextCursor");
    declare_qlass_under<QTextFormat>(rb_mQt6QtGui, "QTextFormat");
    declare_qlass_under<QTextBlockFormat, QTextFormat>(rb_mQt6QtGui, "QTextBlockFormat");
    declare_qlass_under<QTextCharFormat, QTextFormat>(rb_mQt6QtGui, "QTextCharFormat");
    declare_qlass_under<QTextImageFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextImageFormat");
    declare_qlass_under<QTextTableCellFormat, QTextCharFormat>(rb_mQt6QtGui, "QTextTableCellFormat");
    declare_qlass_under<QTextFrameFormat, QTextFormat>(rb_mQt6QtGui, "QTextFrameFormat");
    declare_qlass_under<QTextTableFormat, QTextFrameFormat>(rb_mQt6QtGui, "QTextTableFormat");
    declare_qlass_under<QTextListFormat, QTextFormat>(rb_mQt6QtGui, "QTextListFormat");
    declare_qlass_under<QTextLength>(rb_mQt6QtGui, "QTextLength");
    declare_qlass_under<QTextLayout>(rb_mQt6QtGui, "QTextLayout");
    declare_qlass_under<QTextLayout
    declare_qlass_under<QTextList, QTextBlockGroup>(rb_mQt6QtGui, "QTextList");
    declare_qlass_under<QTextBlock>(rb_mQt6QtGui, "QTextBlock");
    declare_qlass_under<QTextOption>(rb_mQt6QtGui, "QTextOption");
    declare_qlass_under<QTransform>(rb_mQt6QtGui, "QTransform");

    declare_qlass_under<QFileSystemModel, QAbstractItemModel>(rb_mQt6QtGui, "QFileSystemModel");
    declare_qlass_under<QStandardItemModel, QAbstractItemModel>(rb_mQt6QtGui, "QStandardItemModel");
    declare_qlass_under<QStandardItem>(rb_mQt6QtGui, "QStandardItem");
    declare_qlass_under<QAction, QObject>(rb_mQt6QtGui, "QAction");
    declare_qlass_under<QActionGroup, QObject>(rb_mQt6QtGui, "QActionGroup");
    declare_qlass_under<QClipboard, QObject>(rb_mQt6QtGui, "QClipboard");
    declare_qlass_under<QGuiApplication, QCoreApplication>(rb_mQt6QtGui, "QGuiApplication");
    declare_qlass_under<QMovie, QObject>(rb_mQt6QtGui, "QMovie");
    declare_qlass_under<QScreen, QObject>(rb_mQt6QtGui, "QScreen");
    declare_qlass_under<QShortcut, QObject>(rb_mQt6QtGui, "QShortcut");
    declare_qlass_under<QStyleHints, QObject>(rb_mQt6QtGui, "QStyleHints");
    declare_qlass_under<QTextDocument, QObject>(rb_mQt6QtGui, "QTextDocument");
    declare_qlass_under<QTextObject, QObject>(rb_mQt6QtGui, "QTextObject");
    declare_qlass_under<QTextBlockGroup, QTextObject>(rb_mQt6QtGui, "QTextBlockGroup");
    declare_qlass_under<QTextFrame, QTextObject>(rb_mQt6QtGui, "QTextFrame");
    declare_qlass_under<QTextTable, QTextFrame>(rb_mQt6QtGui, "QTextTable");
    declare_qlass_under<QTextTableCell>(rb_mQt6QtGui, "QTextTableCell");
    declare_qlass_under<QValidator, QObject>(rb_mQt6QtGui, "QValidator");
    declare_qlass_under<QDoubleValidator, QValidator>(rb_mQt6QtGui, "QDoubleValidator");
    declare_qlass_under<QIntValidator, QValidator>(rb_mQt6QtGui, "QIntValidator");
    declare_qlass_under<QRegularExpressionValidator, QValidator>(rb_mQt6QtGui, "QRegularExpressionValidator");
    declare_qlass_under<QWindow, QObject>(rb_mQt6QtGui, "QWindow");

    declare_qlass_under<QPolygon, QList<QPoint>>(rb_mQt6QtGui, "QPolygon");
    declare_qlass_under<QPolygonF, QList<QPointF>>(rb_mQt6QtGui, "QPolygonF");
}

#endif
