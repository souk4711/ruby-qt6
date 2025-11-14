#include "t-qtcore-rb.hpp"
#include <rice/qt6/qlist.hpp>

#include <QItemSelectionRange>
#include <QModelIndex>
#include <QString>
#include <QVariant>

#include <QObject>

using namespace Rice;

void Init_t_qtcore(Rice::Module rb_mQt6T)
{
    // QList<QByteArray>
    define_qlist_under<QByteArray>(rb_mQt6T);

    // QList<QItemSelectionRange> -> QItemSelection
    define_qlist_under<QItemSelectionRange>(rb_mQt6T);

    // QList<QModelIndex> -> QModelIndexList
    define_qlist_under<QModelIndex>(rb_mQt6T);

    // QList<QString> -> QStringList
    define_qlist_under<QString>(rb_mQt6T);

    // QList<QVariant>
    define_qlist_under<QVariant>(rb_mQt6T);


    // QList<QObject *>
    define_qlist_under<QObject *>(rb_mQt6T);
}
