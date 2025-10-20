#include "qvariant-rb.hpp"
#include <qvariant.h>

#include <QString>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QLine>
#include <QLineF>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QSizeF>
#include <QSizeF>

using namespace Rice;

Rice::Class rb_cQVariant;

void Init_qvariant(Rice::Module rb_mQt6QtCore)
{
    rb_cQVariant =
        // RubyQt6::QtCore::QVariant
        define_class_under<QVariant>(rb_mQt6QtCore, "QVariant")
            // RubyQt6-Defined Functions
            .define_singleton_function("from_bool", [](bool value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_int", [](int value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_double", [](double value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qstring", [](const char *value) -> QVariant { return QVariant(QString(value)); })
            .define_singleton_function("from_qstring", [](const QString &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qdatetime", [](const QDateTime &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qdate", [](const QDate &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qtime", [](const QTime &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qline", [](const QLine &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qlinef", [](const QLine &value) -> QVariant { return QVariant(QLineF(value)); })
            .define_singleton_function("from_qlinef", [](const QLineF &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qpoint", [](const QPoint &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qpointf", [](const QPoint &value) -> QVariant { return QVariant(QPointF(value)); })
            .define_singleton_function("from_qpointf", [](const QPointF &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qrect", [](const QRect &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qrectf", [](const QRect &value) -> QVariant { return QVariant(QRectF(value)); })
            .define_singleton_function("from_qrectf", [](const QRectF &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qsize", [](const QSize &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qsizef", [](const QSize &value) -> QVariant { return QVariant(QSizeF(value)); })
            .define_singleton_function("from_qsizef", [](const QSizeF &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qstringlist", [](const QStringList &value) -> QVariant { return QVariant(value); })
            .define_singleton_function("from_qobject", [](const QObject *value) -> QVariant { return QVariant::fromValue(value); })
            .define_singleton_function("to_bool", [](const QVariant &qvariant) -> bool { return qvariant.toBool(); })
            .define_singleton_function("to_int", [](const QVariant &qvariant) -> int { return qvariant.toInt(); })
            .define_singleton_function("to_double", [](const QVariant &qvariant) -> double { return qvariant.toDouble(); })
            .define_singleton_function("to_qstring", [](const QVariant &qvariant) -> QString { return qvariant.toString(); })
            .define_singleton_function("to_qdatetime", [](const QVariant &qvariant) -> QDateTime { return qvariant.toDateTime(); })
            .define_singleton_function("to_qdate", [](const QVariant &qvariant) -> QDate { return qvariant.toDate(); })
            .define_singleton_function("to_qtime", [](const QVariant &qvariant) -> QTime { return qvariant.toTime(); })
            .define_singleton_function("to_qline", [](const QVariant &qvariant) -> QLine { return qvariant.toLine(); })
            .define_singleton_function("to_qlinef", [](const QVariant &qvariant) -> QLineF { return qvariant.toLineF(); })
            .define_singleton_function("to_qpoint", [](const QVariant &qvariant) -> QPoint { return qvariant.toPoint(); })
            .define_singleton_function("to_qpointf", [](const QVariant &qvariant) -> QPointF { return qvariant.toPointF(); })
            .define_singleton_function("to_qrect", [](const QVariant &qvariant) -> QRect { return qvariant.toRect(); })
            .define_singleton_function("to_qrectf", [](const QVariant &qvariant) -> QRectF { return qvariant.toRectF(); })
            .define_singleton_function("to_qsize", [](const QVariant &qvariant) -> QSize { return qvariant.toSize(); })
            .define_singleton_function("to_qsizef", [](const QVariant &qvariant) -> QSizeF { return qvariant.toSizeF(); })
            .define_singleton_function("to_qstringlist", [](const QVariant &qvariant) -> QStringList { return qvariant.toStringList(); })
            .define_singleton_function("_to_qobject", [](const QVariant &qvariant) -> QObject * { return qvariant.value<QObject *>(); })
            // Public Functions
            .define_method("valid?", &QVariant::isValid)
            .define_method("type_id", &QVariant::typeId)
            .define_method("type_name", &QVariant::typeName);
}
