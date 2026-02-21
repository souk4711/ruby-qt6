#include "qmetatype-rb.hpp"
#include <qmetatype.h>
#include <rice/qt6/qenum.hpp>

RICE4RUBYQT6_USE_NAMESPACE

Class rb_cQMetaType;

void Init_qmetatype(Module rb_mQt6QtCore)
{
    rb_cQMetaType =
        // RubyQt6::QtCore::QMetaType
        define_qlass_under<QMetaType>(rb_mQt6QtCore, "QMetaType")
            // RubyQt6-Defined Functions
            .define_singleton_function("from_name", [](const char *name) -> QMetaType { return QMetaType::fromName(name); })
            // Constructor
            .define_constructor(Constructor<QMetaType, int>(), Arg("type_id"))
            // Public Functions
            .define_method("id", &QMetaType::id, Arg("_") = static_cast<int>(0))
            .define_method("name", &QMetaType::name);

    Data_Type<QMetaType::Type> rb_cQMetaTypeType =
        // RubyQt6::QtCore::QMetaType::Type
        define_qenum_under<QMetaType::Type>(rb_cQMetaType, "Type");
        define_qenum_value_under(rb_cQMetaTypeType, "Bool", QMetaType::Type::Bool);
        define_qenum_value_under(rb_cQMetaTypeType, "Char", QMetaType::Type::Char);
        define_qenum_value_under(rb_cQMetaTypeType, "Char16", QMetaType::Type::Char16);
        define_qenum_value_under(rb_cQMetaTypeType, "Char32", QMetaType::Type::Char32);
        define_qenum_value_under(rb_cQMetaTypeType, "SChar", QMetaType::Type::SChar);
        define_qenum_value_under(rb_cQMetaTypeType, "UChar", QMetaType::Type::UChar);
        define_qenum_value_under(rb_cQMetaTypeType, "Int", QMetaType::Type::Int);
        define_qenum_value_under(rb_cQMetaTypeType, "Long", QMetaType::Type::Long);
        define_qenum_value_under(rb_cQMetaTypeType, "LongLong", QMetaType::Type::LongLong);
        define_qenum_value_under(rb_cQMetaTypeType, "Short", QMetaType::Type::Short);
        define_qenum_value_under(rb_cQMetaTypeType, "UInt", QMetaType::Type::UInt);
        define_qenum_value_under(rb_cQMetaTypeType, "ULong", QMetaType::Type::ULong);
        define_qenum_value_under(rb_cQMetaTypeType, "ULongLong", QMetaType::Type::ULongLong);
        define_qenum_value_under(rb_cQMetaTypeType, "UShort", QMetaType::Type::UShort);
        define_qenum_value_under(rb_cQMetaTypeType, "Double", QMetaType::Type::Double);
        define_qenum_value_under(rb_cQMetaTypeType, "Float", QMetaType::Type::Float);
        define_qenum_value_under(rb_cQMetaTypeType, "Float16", QMetaType::Type::Float16);
        define_qenum_value_under(rb_cQMetaTypeType, "Nullptr", QMetaType::Type::Nullptr);
        define_qenum_value_under(rb_cQMetaTypeType, "Void", QMetaType::Type::Void);
        define_qenum_value_under(rb_cQMetaTypeType, "VoidStar", QMetaType::Type::VoidStar);
        define_qenum_value_under(rb_cQMetaTypeType, "QObjectStar", QMetaType::Type::QObjectStar);
        define_qenum_value_under(rb_cQMetaTypeType, "QBitArray", QMetaType::Type::QBitArray);
        define_qenum_value_under(rb_cQMetaTypeType, "QBitmap", QMetaType::Type::QBitmap);
        define_qenum_value_under(rb_cQMetaTypeType, "QBrush", QMetaType::Type::QBrush);
        define_qenum_value_under(rb_cQMetaTypeType, "QByteArray", QMetaType::Type::QByteArray);
        define_qenum_value_under(rb_cQMetaTypeType, "QByteArrayList", QMetaType::Type::QByteArrayList);
        define_qenum_value_under(rb_cQMetaTypeType, "QCborArray", QMetaType::Type::QCborArray);
        define_qenum_value_under(rb_cQMetaTypeType, "QCborMap", QMetaType::Type::QCborMap);
        define_qenum_value_under(rb_cQMetaTypeType, "QCborSimpleType", QMetaType::Type::QCborSimpleType);
        define_qenum_value_under(rb_cQMetaTypeType, "QCborValue", QMetaType::Type::QCborValue);
        define_qenum_value_under(rb_cQMetaTypeType, "QChar", QMetaType::Type::QChar);
        define_qenum_value_under(rb_cQMetaTypeType, "QColor", QMetaType::Type::QColor);
        define_qenum_value_under(rb_cQMetaTypeType, "QColorSpace", QMetaType::Type::QColorSpace);
        define_qenum_value_under(rb_cQMetaTypeType, "QCursor", QMetaType::Type::QCursor);
        define_qenum_value_under(rb_cQMetaTypeType, "QDate", QMetaType::Type::QDate);
        define_qenum_value_under(rb_cQMetaTypeType, "QDateTime", QMetaType::Type::QDateTime);
        define_qenum_value_under(rb_cQMetaTypeType, "QEasingCurve", QMetaType::Type::QEasingCurve);
        define_qenum_value_under(rb_cQMetaTypeType, "QFont", QMetaType::Type::QFont);
        define_qenum_value_under(rb_cQMetaTypeType, "QIcon", QMetaType::Type::QIcon);
        define_qenum_value_under(rb_cQMetaTypeType, "QImage", QMetaType::Type::QImage);
        define_qenum_value_under(rb_cQMetaTypeType, "QJsonArray", QMetaType::Type::QJsonArray);
        define_qenum_value_under(rb_cQMetaTypeType, "QJsonDocument", QMetaType::Type::QJsonDocument);
        define_qenum_value_under(rb_cQMetaTypeType, "QJsonObject", QMetaType::Type::QJsonObject);
        define_qenum_value_under(rb_cQMetaTypeType, "QJsonValue", QMetaType::Type::QJsonValue);
        define_qenum_value_under(rb_cQMetaTypeType, "QKeySequence", QMetaType::Type::QKeySequence);
        define_qenum_value_under(rb_cQMetaTypeType, "QLine", QMetaType::Type::QLine);
        define_qenum_value_under(rb_cQMetaTypeType, "QLineF", QMetaType::Type::QLineF);
        define_qenum_value_under(rb_cQMetaTypeType, "QLocale", QMetaType::Type::QLocale);
        define_qenum_value_under(rb_cQMetaTypeType, "QMatrix4x4", QMetaType::Type::QMatrix4x4);
        define_qenum_value_under(rb_cQMetaTypeType, "QModelIndex", QMetaType::Type::QModelIndex);
        define_qenum_value_under(rb_cQMetaTypeType, "QPalette", QMetaType::Type::QPalette);
        define_qenum_value_under(rb_cQMetaTypeType, "QPen", QMetaType::Type::QPen);
        define_qenum_value_under(rb_cQMetaTypeType, "QPersistentModelIndex", QMetaType::Type::QPersistentModelIndex);
        define_qenum_value_under(rb_cQMetaTypeType, "QPixmap", QMetaType::Type::QPixmap);
        define_qenum_value_under(rb_cQMetaTypeType, "QPoint", QMetaType::Type::QPoint);
        define_qenum_value_under(rb_cQMetaTypeType, "QPointF", QMetaType::Type::QPointF);
        define_qenum_value_under(rb_cQMetaTypeType, "QPolygon", QMetaType::Type::QPolygon);
        define_qenum_value_under(rb_cQMetaTypeType, "QPolygonF", QMetaType::Type::QPolygonF);
        define_qenum_value_under(rb_cQMetaTypeType, "QQuaternion", QMetaType::Type::QQuaternion);
        define_qenum_value_under(rb_cQMetaTypeType, "QRect", QMetaType::Type::QRect);
        define_qenum_value_under(rb_cQMetaTypeType, "QRectF", QMetaType::Type::QRectF);
        define_qenum_value_under(rb_cQMetaTypeType, "QRegion", QMetaType::Type::QRegion);
        define_qenum_value_under(rb_cQMetaTypeType, "QRegularExpression", QMetaType::Type::QRegularExpression);
        define_qenum_value_under(rb_cQMetaTypeType, "QSizePolicy", QMetaType::Type::QSizePolicy);
        define_qenum_value_under(rb_cQMetaTypeType, "QSize", QMetaType::Type::QSize);
        define_qenum_value_under(rb_cQMetaTypeType, "QSizeF", QMetaType::Type::QSizeF);
        define_qenum_value_under(rb_cQMetaTypeType, "QStringList", QMetaType::Type::QStringList);
        define_qenum_value_under(rb_cQMetaTypeType, "QString", QMetaType::Type::QString);
        define_qenum_value_under(rb_cQMetaTypeType, "QTextFormat", QMetaType::Type::QTextFormat);
        define_qenum_value_under(rb_cQMetaTypeType, "QTextLength", QMetaType::Type::QTextLength);
        define_qenum_value_under(rb_cQMetaTypeType, "QTime", QMetaType::Type::QTime);
        define_qenum_value_under(rb_cQMetaTypeType, "QTransform", QMetaType::Type::QTransform);
        define_qenum_value_under(rb_cQMetaTypeType, "QUrl", QMetaType::Type::QUrl);
        define_qenum_value_under(rb_cQMetaTypeType, "QUuid", QMetaType::Type::QUuid);
        define_qenum_value_under(rb_cQMetaTypeType, "QVariantHash", QMetaType::Type::QVariantHash);
        define_qenum_value_under(rb_cQMetaTypeType, "QVariantList", QMetaType::Type::QVariantList);
        define_qenum_value_under(rb_cQMetaTypeType, "QVariantMap", QMetaType::Type::QVariantMap);
        define_qenum_value_under(rb_cQMetaTypeType, "QVariantPair", QMetaType::Type::QVariantPair);
        define_qenum_value_under(rb_cQMetaTypeType, "QVariant", QMetaType::Type::QVariant);
        define_qenum_value_under(rb_cQMetaTypeType, "QVector2D", QMetaType::Type::QVector2D);
        define_qenum_value_under(rb_cQMetaTypeType, "QVector3D", QMetaType::Type::QVector3D);
        define_qenum_value_under(rb_cQMetaTypeType, "QVector4D", QMetaType::Type::QVector4D);
        define_qenum_value_under(rb_cQMetaTypeType, "User", QMetaType::Type::User);
        define_qenum_value_under(rb_cQMetaTypeType, "UnknownType", QMetaType::Type::UnknownType);
}
