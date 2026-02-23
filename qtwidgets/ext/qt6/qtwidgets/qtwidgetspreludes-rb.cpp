#include "qtwidgetspreludes-rb.hpp"

#include <QByteArray>
#include <QString>
#include <QEvent>
#include <QDateTime>
#include <QDir>
#include <QFileInfo>
#include <QLine>
#include <QLineF>
#include <QLocale>
#include <QMargins>
#include <QMarginsF>
#include <QModelIndex>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QRegularExpression>
#include <QSize>
#include <QSizeF>
#include <QUrl>
#include <QVariant>
#include <QObject>
#include <QAbstractItemModel>

RICE4RUBYQT6_USE_NAMESPACE

void Init_qtwidgetspreludes(Module rb_mQt6)
{
    Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");
    declare_qlass_under<QByteArray>(rb_mQt6QtCore, "QByteArray");
    declare_qlass_under<QString>(rb_mQt6QtCore, "QString");
    declare_qlass_under<QEvent>(rb_mQt6QtCore, "QEvent");
    declare_qlass_under<QDateTime>(rb_mQt6QtCore, "QDateTime");
    declare_qlass_under<QDir>(rb_mQt6QtCore, "QDir");
    declare_qlass_under<QFileInfo>(rb_mQt6QtCore, "QFileInfo");
    declare_qlass_under<QLine>(rb_mQt6QtCore, "QLine");
    declare_qlass_under<QLineF>(rb_mQt6QtCore, "QLineF");
    declare_qlass_under<QLocale>(rb_mQt6QtCore, "QLocale");
    declare_qlass_under<QMargins>(rb_mQt6QtCore, "QMargins");
    declare_qlass_under<QMarginsF>(rb_mQt6QtCore, "QMarginsF");
    declare_qlass_under<QModelIndex>(rb_mQt6QtCore, "QModelIndex");
    declare_qlass_under<QPoint>(rb_mQt6QtCore, "QPoint");
    declare_qlass_under<QPointF>(rb_mQt6QtCore, "QPointF");
    declare_qlass_under<QRect>(rb_mQt6QtCore, "QRect");
    declare_qlass_under<QRectF>(rb_mQt6QtCore, "QRectF");
    declare_qlass_under<QRegularExpression>(rb_mQt6QtCore, "QRegularExpression");
    declare_qlass_under<QSize>(rb_mQt6QtCore, "QSize");
    declare_qlass_under<QSizeF>(rb_mQt6QtCore, "QSizeF");
    declare_qlass_under<QUrl>(rb_mQt6QtCore, "QUrl");
    declare_qlass_under<QVariant>(rb_mQt6QtCore, "QVariant");
    declare_qlass_under<QObject>(rb_mQt6QtCore, "QObject");
    declare_qlass_under<QAbstractItemModel>(rb_mQt6QtCore, "QAbstractItemModel");

    Module rb_mQt = define_module_under(rb_mQt6QtCore, "Qt");
    declare_qlass_under<Qt::AlignmentFlag>(rb_mQt, "AlignmentFlag");
    declare_qlass_under<Qt::ArrowType>(rb_mQt, "ArrowType");
    declare_qlass_under<Qt::AspectRatioMode>(rb_mQt, "AspectRatioMode");
    declare_qlass_under<Qt::CheckState>(rb_mQt, "CheckState");
    declare_qlass_under<Qt::ContextMenuPolicy>(rb_mQt, "ContextMenuPolicy");
    declare_qlass_under<Qt::Corner>(rb_mQt, "Corner");
    declare_qlass_under<Qt::CursorMoveStyle>(rb_mQt, "CursorMoveStyle");
    declare_qlass_under<Qt::DayOfWeek>(rb_mQt, "DayOfWeek");
    declare_qlass_under<Qt::DockWidgetArea>(rb_mQt, "DockWidgetArea");
    declare_qlass_under<Qt::DropAction>(rb_mQt, "DropAction");
    declare_qlass_under<Qt::FillRule>(rb_mQt, "FillRule");
    declare_qlass_under<Qt::FocusPolicy>(rb_mQt, "FocusPolicy");
    declare_qlass_under<Qt::FocusReason>(rb_mQt, "FocusReason");
    declare_qlass_under<Qt::GestureType>(rb_mQt, "GestureType");
    declare_qlass_under<Qt::ItemSelectionMode>(rb_mQt, "ItemSelectionMode");
    declare_qlass_under<Qt::ItemSelectionOperation>(rb_mQt, "ItemSelectionOperation");
    declare_qlass_under<Qt::LayoutDirection>(rb_mQt, "LayoutDirection");
    declare_qlass_under<Qt::Orientation>(rb_mQt, "Orientation");
    declare_qlass_under<Qt::PenStyle>(rb_mQt, "PenStyle");
    declare_qlass_under<Qt::ScrollBarPolicy>(rb_mQt, "ScrollBarPolicy");
    declare_qlass_under<Qt::ShortcutContext>(rb_mQt, "ShortcutContext");
    declare_qlass_under<Qt::SortOrder>(rb_mQt, "SortOrder");
    declare_qlass_under<Qt::TextElideMode>(rb_mQt, "TextElideMode");
    declare_qlass_under<Qt::TextFormat>(rb_mQt, "TextFormat");
    declare_qlass_under<Qt::ToolBarArea>(rb_mQt, "ToolBarArea");
    declare_qlass_under<Qt::ToolButtonStyle>(rb_mQt, "ToolButtonStyle");
    declare_qlass_under<Qt::TransformationMode>(rb_mQt, "TransformationMode");
    declare_qlass_under<Qt::UIEffect>(rb_mQt, "UIEffect");
    declare_qlass_under<Qt::WidgetAttribute>(rb_mQt, "WidgetAttribute");
    declare_qlass_under<Qt::WindowModality>(rb_mQt, "WindowModality");
    declare_qlass_under<Qt::WindowType>(rb_mQt, "WindowType");
    declare_qlass_under<QFlags<Qt::AlignmentFlag>>(rb_mQt, "Alignment");
    declare_qlass_under<QFlags<Qt::DockWidgetArea>>(rb_mQt, "DockWidgetAreas");
    declare_qlass_under<QFlags<Qt::FindChildOption>>(rb_mQt, "FindChildOptions");
    declare_qlass_under<QFlags<Qt::GestureFlag>>(rb_mQt, "GestureFlags");
    declare_qlass_under<QFlags<Qt::ItemFlag>>(rb_mQt, "ItemFlags");
    declare_qlass_under<QFlags<Qt::InputMethodHint>>(rb_mQt, "InputMethodHints");
    declare_qlass_under<QFlags<Qt::KeyboardModifier>>(rb_mQt, "KeyboardModifiers");
    declare_qlass_under<QFlags<Qt::MatchFlag>>(rb_mQt, "MatchFlags");
    declare_qlass_under<QFlags<Qt::MouseButton>>(rb_mQt, "MouseButtons");
    declare_qlass_under<QFlags<Qt::Orientation>>(rb_mQt, "Orientations");
    declare_qlass_under<QFlags<Qt::TextInteractionFlag>>(rb_mQt, "TextInteractionFlags");
    declare_qlass_under<QFlags<Qt::ToolBarArea>>(rb_mQt, "ToolBarAreas");
    declare_qlass_under<QFlags<Qt::WindowState>>(rb_mQt, "WindowStates");
    declare_qlass_under<QFlags<Qt::WindowType>>(rb_mQt, "WindowFlags");

    Class rb_cQDir = rb_mQt6QtCore.const_get("QDir").value();
    declare_qlass_under<QFlags<QDir::Filter>>(rb_cQDir, "Filters");
}
