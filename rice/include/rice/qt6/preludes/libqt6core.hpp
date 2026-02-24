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

#ifndef RICE_QT6_PRELUDES_LIBQT6CORE_HPP
#define RICE_QT6_PRELUDES_LIBQT6CORE_HPP

#include <QMetaObject>
#include <QByteArray>
#include <QChar>
#include <QString>
#include <QEvent>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDir>
#include <QFileInfo>
#include <QLine>
#include <QLineF>
#include <QLocale>
#include <QMargins>
#include <QMarginsF>
#include <QMimeType>
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
#include <QCoreApplication>
#include <QItemSelectionModel>
#include <QIODevice>
#include <QFileDevice>
#include <QList>
#include <bando/common.hpp>

void declare_qlass_under_libqt6core(Module rb_mQt6)
{
    Module rb_mQt6QtCore = define_module_under(rb_mQt6, "QtCore");
    declare_qlass_under<QMetaObject>(rb_mQt6QtCore, "QMetaObject");
    declare_qlass_under<QByteArray>(rb_mQt6QtCore, "QByteArray");
    declare_qlass_under<QChar>(rb_mQt6QtCore, "QChar");
    declare_qlass_under<QString>(rb_mQt6QtCore, "QString");
    declare_qlass_under<QEvent>(rb_mQt6QtCore, "QEvent");
    declare_qlass_under<QChildEvent>(rb_mQt6QtCore, "QChildEvent");
    declare_qlass_under<QDynamicPropertyChangeEvent>(rb_mQt6QtCore, "QDynamicPropertyChangeEvent");
    declare_qlass_under<QTimerEvent>(rb_mQt6QtCore, "QTimerEvent");
    declare_qlass_under<QDateTime>(rb_mQt6QtCore, "QDateTime");
    declare_qlass_under<QDate>(rb_mQt6QtCore, "QDate");
    declare_qlass_under<QTime>(rb_mQt6QtCore, "QTime");
    declare_qlass_under<QDir>(rb_mQt6QtCore, "QDir");
    declare_qlass_under<QFileInfo>(rb_mQt6QtCore, "QFileInfo");
    declare_qlass_under<QLine>(rb_mQt6QtCore, "QLine");
    declare_qlass_under<QLineF>(rb_mQt6QtCore, "QLineF");
    declare_qlass_under<QLocale>(rb_mQt6QtCore, "QLocale");
    declare_qlass_under<QMargins>(rb_mQt6QtCore, "QMargins");
    declare_qlass_under<QMarginsF>(rb_mQt6QtCore, "QMarginsF");
    declare_qlass_under<QMimeType>(rb_mQt6QtCore, "QMimeType");
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
    declare_qlass_under<QCoreApplication>(rb_mQt6QtCore, "QCoreApplication");
    declare_qlass_under<QItemSelectionModel>(rb_mQt6QtCore, "QItemSelectionModel");
    declare_qlass_under<QIODevice>(rb_mQt6QtCore, "QIODevice");

    Module rb_mQt = define_module_under(rb_mQt6QtCore, "Qt");
    declare_qlass_under<Qt::AlignmentFlag>(rb_mQt, "AlignmentFlag");
    declare_qlass_under<Qt::ApplicationState>(rb_mQt, "ApplicationState");
    declare_qlass_under<Qt::ArrowType>(rb_mQt, "ArrowType");
    declare_qlass_under<Qt::AspectRatioMode>(rb_mQt, "AspectRatioMode");
    declare_qlass_under<Qt::Axis>(rb_mQt, "Axis");
    declare_qlass_under<Qt::BGMode>(rb_mQt, "BGMode");
    declare_qlass_under<Qt::BrushStyle>(rb_mQt, "BrushStyle");
    declare_qlass_under<Qt::CheckState>(rb_mQt, "CheckState");
    declare_qlass_under<Qt::ClipOperation>(rb_mQt, "ClipOperation");
    declare_qlass_under<Qt::ColorScheme>(rb_mQt, "ColorScheme");
    declare_qlass_under<Qt::ContextMenuPolicy>(rb_mQt, "ContextMenuPolicy");
    declare_qlass_under<Qt::ContextMenuTrigger>(rb_mQt, "ContextMenuTrigger");
    declare_qlass_under<Qt::Corner>(rb_mQt, "Corner");
    declare_qlass_under<Qt::CursorMoveStyle>(rb_mQt, "CursorMoveStyle");
    declare_qlass_under<Qt::CursorShape>(rb_mQt, "CursorShape");
    declare_qlass_under<Qt::DayOfWeek>(rb_mQt, "DayOfWeek");
    declare_qlass_under<Qt::DockWidgetArea>(rb_mQt, "DockWidgetArea");
    declare_qlass_under<Qt::DropAction>(rb_mQt, "DropAction");
    declare_qlass_under<Qt::FillRule>(rb_mQt, "FillRule");
    declare_qlass_under<Qt::FocusPolicy>(rb_mQt, "FocusPolicy");
    declare_qlass_under<Qt::FocusReason>(rb_mQt, "FocusReason");
    declare_qlass_under<Qt::GestureType>(rb_mQt, "GestureType");
    declare_qlass_under<Qt::GlobalColor>(rb_mQt, "GlobalColor");
    declare_qlass_under<Qt::HighDpiScaleFactorRoundingPolicy>(rb_mQt, "HighDpiScaleFactorRoundingPolicy");
    declare_qlass_under<Qt::InputMethodQuery>(rb_mQt, "InputMethodQuery");
    declare_qlass_under<Qt::ItemSelectionMode>(rb_mQt, "ItemSelectionMode");
    declare_qlass_under<Qt::ItemSelectionOperation>(rb_mQt, "ItemSelectionOperation");
    declare_qlass_under<Qt::LayoutDirection>(rb_mQt, "LayoutDirection");
    declare_qlass_under<Qt::MaskMode>(rb_mQt, "MaskMode");
    declare_qlass_under<Qt::MouseButton>(rb_mQt, "MouseButton");
    declare_qlass_under<Qt::NativeGestureType>(rb_mQt, "NativeGestureType");
    declare_qlass_under<Qt::Orientation>(rb_mQt, "Orientation");
    declare_qlass_under<Qt::PenCapStyle>(rb_mQt, "PenCapStyle");
    declare_qlass_under<Qt::PenJoinStyle>(rb_mQt, "PenJoinStyle");
    declare_qlass_under<Qt::PenStyle>(rb_mQt, "PenStyle");
    declare_qlass_under<Qt::ScreenOrientation>(rb_mQt, "ScreenOrientation");
    declare_qlass_under<Qt::ScrollBarPolicy>(rb_mQt, "ScrollBarPolicy");
    declare_qlass_under<Qt::ScrollPhase>(rb_mQt, "ScrollPhase");
    declare_qlass_under<Qt::ShortcutContext>(rb_mQt, "ShortcutContext");
    declare_qlass_under<Qt::SizeMode>(rb_mQt, "SizeMode");
    declare_qlass_under<Qt::SortOrder>(rb_mQt, "SortOrder");
    declare_qlass_under<Qt::TabFocusBehavior>(rb_mQt, "TabFocusBehavior");
    declare_qlass_under<Qt::TextElideMode>(rb_mQt, "TextElideMode");
    declare_qlass_under<Qt::TextFormat>(rb_mQt, "TextFormat");
    declare_qlass_under<Qt::ToolBarArea>(rb_mQt, "ToolBarArea");
    declare_qlass_under<Qt::ToolButtonStyle>(rb_mQt, "ToolButtonStyle");
    declare_qlass_under<Qt::TransformationMode>(rb_mQt, "TransformationMode");
    declare_qlass_under<Qt::UIEffect>(rb_mQt, "UIEffect");
    declare_qlass_under<Qt::WidgetAttribute>(rb_mQt, "WidgetAttribute");
    declare_qlass_under<Qt::WindowModality>(rb_mQt, "WindowModality");
    declare_qlass_under<Qt::WindowState>(rb_mQt, "WindowState");
    declare_qlass_under<Qt::WindowType>(rb_mQt, "WindowType");
    declare_qlass_under<QFlags<Qt::AlignmentFlag>>(rb_mQt, "Alignment");
    declare_qlass_under<QFlags<Qt::DockWidgetArea>>(rb_mQt, "DockWidgetAreas");
    declare_qlass_under<QFlags<Qt::DropAction>>(rb_mQt, "DropActions");
    declare_qlass_under<QFlags<Qt::Edge>>(rb_mQt, "Edges");
    declare_qlass_under<QFlags<Qt::FindChildOption>>(rb_mQt, "FindChildOptions");
    declare_qlass_under<QFlags<Qt::GestureFlag>>(rb_mQt, "GestureFlags");
    declare_qlass_under<QFlags<Qt::ImageConversionFlag>>(rb_mQt, "ImageConversionFlags");
    declare_qlass_under<QFlags<Qt::InputMethodQuery>>(rb_mQt, "InputMethodQueries");
    declare_qlass_under<QFlags<Qt::ItemFlag>>(rb_mQt, "ItemFlags");
    declare_qlass_under<QFlags<Qt::InputMethodHint>>(rb_mQt, "InputMethodHints");
    declare_qlass_under<QFlags<Qt::KeyboardModifier>>(rb_mQt, "KeyboardModifiers");
    declare_qlass_under<QFlags<Qt::MatchFlag>>(rb_mQt, "MatchFlags");
    declare_qlass_under<QFlags<Qt::MouseButton>>(rb_mQt, "MouseButtons");
    declare_qlass_under<QFlags<Qt::MouseEventFlag>>(rb_mQt, "MouseEventFlags");
    declare_qlass_under<QFlags<Qt::Orientation>>(rb_mQt, "Orientations");
    declare_qlass_under<QFlags<Qt::TextInteractionFlag>>(rb_mQt, "TextInteractionFlags");
    declare_qlass_under<QFlags<Qt::ToolBarArea>>(rb_mQt, "ToolBarAreas");
    declare_qlass_under<QFlags<Qt::WindowState>>(rb_mQt, "WindowStates");
    declare_qlass_under<QFlags<Qt::WindowType>>(rb_mQt, "WindowFlags");

    Class rb_cQDir = rb_mQt6QtCore.const_get("QDir").value();
    Class rb_cQFileDevice = rb_mQt6QtCore.const_get("QFileDevice").value();
    declare_qlass_under<QFlags<QDir::Filter>>(rb_cQDir, "Filters");
    declare_qlass_under<QFlags<QFileDevice::Permission>>(rb_cQFileDevice, "Permissions");

    Module rb_mQt6T = define_module_under(rb_mQt6, "T");
    declare_qlass_under<QList<QByteArray>>(rb_mQt6T, "QList≺QByteArray≻");
    declare_qlass_under<QList<QFileInfo>>(rb_mQt6T, "QList≺QFileInfo≻");
    declare_qlass_under<QList<QModelIndex>>(rb_mQt6T, "QList≺QModelIndex≻");
    declare_qlass_under<QList<QString>>(rb_mQt6T, "QList≺QString≻");
    declare_qlass_under<QList<QUrl>>(rb_mQt6T, "QList≺QUrl≻");
    declare_qlass_under<QList<QVariant>>(rb_mQt6T, "QList≺QVariant≻");
    declare_qlass_under<QList<QObject*>>(rb_mQt6T, "QList≺QObject∗≻");
    declare_qlass_under<QMap<QString, QVariant>>(rb_mQt6T, "QMap≺QString‚ QVariant≻");

    Module rb_mQt6Bando = define_module_under(rb_mQt6, "Bando");
    declare_qlass_under<bando_FunctionName>(rb_mQt6Bando, "FunctionName");
}

#endif
