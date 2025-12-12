#include "t-qtcore-rb.hpp"
#include <rice/qt6/qlist.hpp>
#include <rice/qt6/qmap.hpp>

#include <QItemSelectionRange>
#include <QModelIndex>
#include <QString>
#include <QUrl>
#include <QVariant>
#include <QObject>

RICE4RUBYQT6_USE_NAMESPACE

void Init_t_qtcore(Module rb_mQt6T)
{
    // QList<QByteArray>
    define_qlist_under<QByteArray>(rb_mQt6T);

    // QList<QItemSelectionRange> -> QItemSelection
    define_qlist_under<QItemSelectionRange>(rb_mQt6T);

    // QList<QModelIndex> -> QModelIndexList
    define_qlist_under<QModelIndex>(rb_mQt6T);

    // QList<QString> -> QStringList
    define_qlist_under<QString>(rb_mQt6T);

    // QList<QUrl>
    define_qlist_under<QUrl>(rb_mQt6T);

    // QList<QVariant>
    define_qlist_under<QVariant>(rb_mQt6T);

    // QList<QObject *>
    define_qlist_under<QObject *>(rb_mQt6T);

    // QMap<QString, QVariant>
    define_qmap_under<QString, QVariant>(rb_mQt6T);
}
