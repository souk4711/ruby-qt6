#ifndef RICE_DLLIMPORT_QTCORE_HPP
#define RICE_DLLIMPORT_QTCORE_HPP

// #include <QMetaClassInfo>
// #include <QMetaMethod>
#include <QMetaObject>
// #include <QMetaType>

#include <QAnyStringView>
#include <QByteArray>
#include <QChar>
#include <QString>
#include <QIODevice>

#include <QBasicTimer>
#include <QEvent>
#include <QChildEvent>
#include <QTimerEvent>
#include <QDynamicPropertyChangeEvent>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QDir>
// #include <QFileInfo>
// #include <QLibraryInfo>
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
// #include <QRegularExpressionMatch>
// #include <QRegularExpressionMatchIterator>
// #include <QResource>
#include <QSize>
#include <QSizeF>
#include <QStandardPaths>
#include <QUrl>
#include <QUuid>
#include <QVariant>

#include <QObject>
#include <QAbstractItemModel>
#include <QAbstractTableModel>
#include <QAbstractListModel>
#include <QCoreApplication>
#include <QIODevice>
#include <QFileDevice>
#include <QFile>
#include <QItemSelectionModel>
// #include <QSettings>
// #include <QSignalMapper>
#include <QTimer>
// #include <QTranslator>

#include <QItemSelectionRange>
#include <QItemSelection>

inline void Init_rice_dllimport_qtcore(Rice::Module rb_mQt6QtCore)
{
    // declare_qlass_under<QMetaClassInfo>(rb_mQt6QtCore, "QMetaClassInfo");
    // declare_qlass_under<QMetaMethod>(rb_mQt6QtCore, "QMetaMethod");
    declare_qlass_under<QMetaObject>(rb_mQt6QtCore, "QMetaObject");
    // declare_qlass_under<QMetaType>(rb_mQt6QtCore, "QMetaType");

    declare_qlass_under<QAnyStringView>(rb_mQt6QtCore, "QAnyStringView");
    declare_qlass_under<QByteArray>(rb_mQt6QtCore, "QByteArray");
    declare_qlass_under<QChar>(rb_mQt6QtCore, "QChar");
    declare_qlass_under<QString>(rb_mQt6QtCore, "QString");
    declare_qlass_under<QIODeviceBase>(rb_mQt6QtCore, "QIODeviceBase");

    declare_qlass_under<QBasicTimer>(rb_mQt6QtCore, "QBasicTimer");
    declare_qlass_under<QEvent>(rb_mQt6QtCore, "QEvent");
    declare_qlass_under<QChildEvent, QEvent>(rb_mQt6QtCore, "QChildEvent");
    declare_qlass_under<QTimerEvent, QEvent>(rb_mQt6QtCore, "QTimerEvent");
    declare_qlass_under<QDynamicPropertyChangeEvent, QEvent>(rb_mQt6QtCore, "QDynamicPropertyChangeEvent");
    declare_qlass_under<QDateTime>(rb_mQt6QtCore, "QDateTime");
    declare_qlass_under<QDate>(rb_mQt6QtCore, "QDate");
    declare_qlass_under<QTime>(rb_mQt6QtCore, "QTime");
    declare_qlass_under<QDir>(rb_mQt6QtCore, "QDir");
    // declare_qlass_under<QFileInfo>(rb_mQt6QtCore, "QFileInfo");
    // declare_qlass_under<QLibraryInfo>(rb_mQt6QtCore, "QLibraryInfo");
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
    // declare_qlass_under<QRegularExpressionMatch>(rb_mQt6QtCore, "QRegularExpressionMatch");
    // declare_qlass_under<QRegularExpressionMatchIterator>(rb_mQt6QtCore, "QRegularExpressionMatchIterator");
    // declare_qlass_under<QResource>(rb_mQt6QtCore, "QResource");
    declare_qlass_under<QSize>(rb_mQt6QtCore, "QSize");
    declare_qlass_under<QSizeF>(rb_mQt6QtCore, "QSizeF");
    declare_qlass_under<QStandardPaths>(rb_mQt6QtCore, "QStandardPaths");
    declare_qlass_under<QUrl>(rb_mQt6QtCore, "QUrl");
    declare_qlass_under<QUuid>(rb_mQt6QtCore, "QUuid");
    declare_qlass_under<QVariant>(rb_mQt6QtCore, "QVariant");

    declare_qlass_under<QObject>(rb_mQt6QtCore, "QObject");
    declare_qlass_under<QAbstractItemModel, QObject>(rb_mQt6QtCore, "QAbstractItemModel");
    declare_qlass_under<QAbstractTableModel, QAbstractItemModel>(rb_mQt6QtCore, "QAbstractTableModel");
    declare_qlass_under<QAbstractListModel, QAbstractItemModel>(rb_mQt6QtCore, "QAbstractListModel");
    declare_qlass_under<QCoreApplication, QObject>(rb_mQt6QtCore, "QCoreApplication");
    declare_qlass_under<QIODevice, QObject>(rb_mQt6QtCore, "QIODevice");
    declare_qlass_under<QFileDevice, QIODevice>(rb_mQt6QtCore, "QFileDevice");
    declare_qlass_under<QFile, QFileDevice>(rb_mQt6QtCore, "QFile");
    declare_qlass_under<QItemSelectionModel, QObject>(rb_mQt6QtCore, "QItemSelectionModel");
    // declare_qlass_under<QSettings, QObject>(rb_mQt6QtCore, "QSettings");
    // declare_qlass_under<QSignalMapper, QObject>(rb_mQt6QtCore, "QSignalMapper");
    declare_qlass_under<QTimer, QObject>(rb_mQt6QtCore, "QTimer");
    // declare_qlass_under<QTranslator, QObject>(rb_mQt6QtCore, "QTranslator");

    declare_qlass_under<QItemSelectionRange>(rb_mQt6QtCore, "QItemSelectionRange");
    declare_qlass_under<QItemSelection, QList<QItemSelectionRange>>(rb_mQt6QtCore, "QItemSelection");
}

#endif
