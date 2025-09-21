#include "qvariant-rb.hpp"
#include <qvariant.h>

#include <QBitArray>
#include <QByteArray>
#include <QChar>
#include <QDate>
#include <QDateTime>
#include <QEasingCurve>
#include <QHash>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QLine>
#include <QLineF>
#include <QList>
#include <QLocale>
#include <QMap>
#include <QMetaType>
#include <QModelIndex>
#include <QPersistentModelIndex>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRectF>
#include <QRegularExpression>
#include <QSize>
#include <QSizeF>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QUrl>
#include <QUuid>

using namespace Rice;

Rice::Class rb_cQVariant;

void Init_qvariant(Rice::Module rb_mQt6QtCore)
{
    rb_cQVariant =
        // RubyQt6::QtCore::QVariant
        define_class_under<QVariant>(rb_mQt6QtCore, "QVariant")
            // Constructor
            .define_constructor(Constructor<QVariant, bool>(), Arg("b"))
            .define_constructor(Constructor<QVariant, int>(), Arg("i"))
            .define_constructor(Constructor<QVariant, double>(), Arg("d"))
            .define_constructor(Constructor<QVariant, QChar>(), Arg("qchar"))
            .define_constructor(Constructor<QVariant, QDate>(), Arg("date"))
            .define_constructor(Constructor<QVariant, QLine>(), Arg("line"))
            .define_constructor(Constructor<QVariant, QLineF>(), Arg("line"))
            .define_constructor(Constructor<QVariant, QPoint>(), Arg("pt"))
            .define_constructor(Constructor<QVariant, QPointF>(), Arg("pt"))
            .define_constructor(Constructor<QVariant, QRect>(), Arg("rect"))
            .define_constructor(Constructor<QVariant, QRectF>(), Arg("rect"))
            .define_constructor(Constructor<QVariant, QSize>(), Arg("size"))
            .define_constructor(Constructor<QVariant, QSizeF>(), Arg("size"))
            .define_constructor(Constructor<QVariant, QTime>(), Arg("time"))
            .define_constructor(Constructor<QVariant, QUuid>(), Arg("uuid"))
            .define_constructor(Constructor<QVariant, const char *>(), Arg("str"))
            // .define_constructor(Constructor<QVariant, const QBitArray &>(), Arg("bitarray"))
            .define_constructor(Constructor<QVariant, const QByteArray &>(), Arg("bytearray"))
            .define_constructor(Constructor<QVariant, const QDateTime &>(), Arg("datetime"))
            // .define_constructor(Constructor<QVariant, const QEasingCurve &>(), Arg("easing"))
            // .define_constructor(Constructor<QVariant, const QHash &>(), Arg("hash"))
            // .define_constructor(Constructor<QVariant, const QJsonArray &>(), Arg("json_array"))
            // .define_constructor(Constructor<QVariant, const QJsonDocument &>(), Arg("json_document"))
            // .define_constructor(Constructor<QVariant, const QJsonObject &>(), Arg("json_object"))
            // .define_constructor(Constructor<QVariant, const QJsonValue &>(), Arg("json_value"))
            // .define_constructor(Constructor<QVariant, const QList &>(), Arg("list"))
            // .define_constructor(Constructor<QVariant, const QLocale &>(), Arg("locale"))
            // .define_constructor(Constructor<QVariant, const QMap &>(), Arg("map"))
            // .define_constructor(Constructor<QVariant, const QRegularExpression &>(), Arg("re"))
            .define_constructor(Constructor<QVariant, const QString &>(), Arg("string"))
            .define_constructor(Constructor<QVariant, const QStringList &>(), Arg("stringlist"))
            .define_constructor(Constructor<QVariant, const QUrl &>(), Arg("url"))
            // .define_constructor(Constructor<QVariant, const QModelIndex &>(), Arg("model_index"))
            // .define_constructor(Constructor<QVariant, const QPersistentModelIndex &>(), Arg("model_index"))
            // Public Functions
            .define_method<bool (QVariant::*)(QMetaType) const>("can_convert", &QVariant::canConvert, Arg("target_type"))
            // .define_method("can_view", &QVariant::canView, Arg("target_type"))
            .define_method("clear", &QVariant::clear)
            .define_method("const_data", &QVariant::constData)
            .define_method<bool (QVariant::*)(QMetaType)>("convert", &QVariant::convert, Arg("type"))
            .define_method<const void *(QVariant::*)() const>("data", &QVariant::data)
            .define_method<void *(QVariant::*)()>("data", &QVariant::data)
            .define_method("detach", &QVariant::detach)
            .define_method("detached?", &QVariant::isDetached)
            .define_method("null?", &QVariant::isNull)
            .define_method("valid?", &QVariant::isValid)
            .define_method("load", &QVariant::load, Arg("ds"))
            .define_method("meta_type", &QVariant::metaType)
            .define_method("save", &QVariant::save, Arg("ds"))
            .define_method<void (QVariant::*)(QVariant &&)>("set_value", &QVariant::setValue, Arg("avalue"))
            .define_method<void (QVariant::*)(const QVariant &)>("set_value", &QVariant::setValue, Arg("avalue"))
            .define_method("swap", &QVariant::swap, Arg("other"))
            .define_method("to_bit_array", &QVariant::toBitArray)
            .define_method("to_bool", &QVariant::toBool)
            .define_method("to_byte_array", &QVariant::toByteArray)
            .define_method("to_char", &QVariant::toChar)
            .define_method("to_date", &QVariant::toDate)
            .define_method("to_date_time", &QVariant::toDateTime)
            .define_method("to_double", &QVariant::toDouble, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_easing_curve", &QVariant::toEasingCurve)
            .define_method("to_float", &QVariant::toFloat, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_hash", &QVariant::toHash)
            .define_method("to_int", &QVariant::toInt, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_json_array", &QVariant::toJsonArray)
            .define_method("to_json_document", &QVariant::toJsonDocument)
            .define_method("to_json_object", &QVariant::toJsonObject)
            .define_method("to_json_value", &QVariant::toJsonValue)
            .define_method("to_line", &QVariant::toLine)
            .define_method("to_line_f", &QVariant::toLineF)
            .define_method("to_list", &QVariant::toList)
            .define_method("to_locale", &QVariant::toLocale)
            .define_method("to_long_long", &QVariant::toLongLong, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_map", &QVariant::toMap)
            .define_method("to_model_index", &QVariant::toModelIndex)
            .define_method("to_persistent_model_index", &QVariant::toPersistentModelIndex)
            .define_method("to_point", &QVariant::toPoint)
            .define_method("to_point_f", &QVariant::toPointF)
            .define_method("to_real", &QVariant::toReal, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_rect", &QVariant::toRect)
            .define_method("to_rect_f", &QVariant::toRectF)
            .define_method("to_regular_expression", &QVariant::toRegularExpression)
            .define_method("to_size", &QVariant::toSize)
            .define_method("to_size_f", &QVariant::toSizeF)
            .define_method("to_string", &QVariant::toString)
            .define_method("to_string_list", &QVariant::toStringList)
            .define_method("to_time", &QVariant::toTime)
            .define_method("to_u_int", &QVariant::toUInt, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_u_long_long", &QVariant::toULongLong, Arg("ok") = static_cast<bool *>(nullptr))
            .define_method("to_url", &QVariant::toUrl)
            .define_method("to_uuid", &QVariant::toUuid)
            .define_method("type_id", &QVariant::typeId)
            .define_method("type_name", &QVariant::typeName)
            .define_method("user_type", &QVariant::userType)
            // Static Public Members
            .define_singleton_function("compare", &QVariant::compare, Arg("lhs"), Arg("rhs"))
            .define_singleton_function("from_meta_type", &QVariant::fromMetaType, Arg("type"), Arg("copy") = static_cast<const void *>(nullptr));
}
